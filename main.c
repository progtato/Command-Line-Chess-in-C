#include <stdio.h>

struct ChessPiece{
	int id;
	int displayId;
	int x;
	int y;
	int isFirstMove;
	int isAlive;
};

struct MoveList{
	int tail;
	int xValues[27];
	int yValues[27];
};

struct Coords{
	int x;
	int y;
};

void loadMovesToDisplayBuffer(struct MoveList moves, int buffer[8][8]){
	int i;
	int x;
	int y;
	for (i = 0; i < moves.tail; i++){
		x = moves.xValues[i];
		y = moves.yValues[i];
		if (buffer[y][x] == 0 ){
			buffer[y][x] = -1;
		} else{
			buffer[y][x] = (-10 - (buffer[y][x] % 10));
		}
	}
}

void verticalMoves(int x, int y,  int player,  int buffer[8][8], int (*xValues)[27], int  (*yValues)[27], int *size){
	int min;
	int max;
	int oldY = y;
	if (player == 0){
		min = 16;
		max = 31;
	}else if (player == 1){
		min = 0;
		max = 15;
	}
	int validCheck = 1;
	while (validCheck == 1){
		++y;
		if (y <= -1 || y >= 8){
			validCheck = 0;
			continue;
		}
		if (buffer[y][x] == -1){
			(*xValues)[*size] = x;
			(*yValues)[*size] = y;
			++*size;
			continue;
		} else if (buffer[y][x] >= min && buffer[y][x] <= max){
			(*xValues)[*size] = x;
			(*yValues)[*size] = y;
			++*size;
			validCheck = 0;
			continue;
		} else {
			validCheck = 0;
			continue;
		}
	}
	validCheck = 1;
	y = oldY;
	while (validCheck == 1){
		--y;
		if (y <= -1 || y >= 8){
			validCheck = 0;
			continue;
		}
		if (buffer[y][x] == -1){
			(*xValues)[*size] = x;
			(*yValues)[*size] = y;
			++*size;
			continue;
		} else if (buffer[y][x] >= min && buffer[y][x] <= max){
			(*xValues)[*size] = x;
			(*yValues)[*size] = y;
			++*size;
			validCheck = 0;
			continue;
		} else {
			validCheck = 0;
			continue;
		}
	}
}

void horizontalMoves(int x, int y,  int player,  int buffer[8][8], int (*xValues)[27], int  (*yValues)[27], int *size){
	int min;
	int max;
	int oldX = x;
	if (player == 0){
		min = 16;
		max = 31;
	}else if (player == 1){
		min = 0;
		max = 15;
	}
	int validCheck = 1;
	while (validCheck == 1){
		++x;
		if (x <= -1 || x >= 8){
			validCheck = 0;
			continue;
		}
		if (buffer[y][x] == -1){
			(*xValues)[*size] = x;
			(*yValues)[*size] = y;
			++*size;
			continue;
		} else if (buffer[y][x] >= min && buffer[y][x] <= max){
			(*xValues)[*size] = x;
			(*yValues)[*size] = y;
			++*size;
			validCheck = 0;
			continue;
		} else {
			validCheck = 0;
			continue;
		}
	}
	validCheck = 1;
	x = oldX;
	while (validCheck == 1){
		--x;
		if (x <= -1 || x >= 8){
			validCheck = 0;
			continue;
		}
		if (buffer[y][x] == -1){
			(*xValues)[*size] = x;
			(*yValues)[*size] = y;
			++*size;
			continue;
		} else if (buffer[y][x] >= min && buffer[y][x] <= max){
			(*xValues)[*size] = x;
			(*yValues)[*size] = y;
			++*size;
			validCheck = 0;
			continue;
		} else {
			validCheck = 0;
			continue;
		}
	}
}

void acrossUpMoves(int x, int y,  int player,  int buffer[8][8], int (*xValues)[27], int  (*yValues)[27], int *size){
	int min;
	int max;
	int oldX = x;
	int oldY = y;
	if (player == 0){
		min = 16;
		max = 31;
	}else if (player == 1){
		min = 0;
		max = 15;
	}
	int validCheck = 1;
	while (validCheck == 1){
	++x;
	++y;
	if (x <= -1 || x >= 8 || y <= -1 || y >= 8){
			validCheck = 0;
			continue;
		}
		if (buffer[y][x] == -1){
			(*xValues)[*size] = x;
			(*yValues)[*size] = y;
			++*size;
			continue;
		} else if (buffer[y][x] >= min && buffer[y][x] <= max){
			(*xValues)[*size] = x;
			(*yValues)[*size] = y;
			++*size;
			validCheck = 0;
			continue;
		} else {
			validCheck = 0;
			continue;
		}
	}
	
	validCheck = 1;
	x = oldX;
	y = oldY;
	while (validCheck == 1){
	--x;
	++y;
	if (x <= -1 || x >= 8 || y <= -1 || y >= 8){
			validCheck = 0;
			continue;
		}
		if (buffer[y][x] == -1){
			(*xValues)[*size] = x;
			(*yValues)[*size] = y;
			++*size;
			continue;
		} else if (buffer[y][x] >= min && buffer[y][x] <= max){
			(*xValues)[*size] = x;
			(*yValues)[*size] = y;
			++*size;
			validCheck = 0;
			continue;
		} else {
			validCheck = 0;
			continue;
		}
	}

}

void acrossDownMoves(int x, int y,  int player,  int buffer[8][8], int (*xValues)[27], int  (*yValues)[27], int *size){
	int min;
	int max;
	int oldX = x;
	int oldY = y;
	if (player == 0){
		min = 16;
		max = 31;
	}else if (player == 1){
		min = 0;
		max = 15;
	}
	int validCheck = 1;
	while (validCheck == 1){
	++x;
	--y;
	if (x <= -1 || x >= 8 || y <= -1 || y >= 8){
			validCheck = 0;
			continue;
		}
		if (buffer[y][x] == -1){
			(*xValues)[*size] = x;
			(*yValues)[*size] = y;
			++*size;
			continue;
		} else if (buffer[y][x] >= min && buffer[y][x] <= max){
			(*xValues)[*size] = x;
			(*yValues)[*size] = y;
			++*size;
			validCheck = 0;
			continue;
		} else {
			validCheck = 0;
			continue;
		}
	}
	
	validCheck = 1;
	x = oldX;
	y = oldY;
	while (validCheck == 1){
	--x;
	--y;
	if (x <= -1 || x >= 8 || y <= -1 || y >= 8){
			validCheck = 0;
			continue;
		}
		if (buffer[y][x] == -1){
			(*xValues)[*size] = x;
			(*yValues)[*size] = y;
			++*size;
			continue;
		} else if (buffer[y][x] >= min && buffer[y][x] <= max){
			(*xValues)[*size] = x;
			(*yValues)[*size] = y;
			++*size;
			validCheck = 0;
			continue;
		} else {
			validCheck = 0;
			continue;
		}
	}
}
		
struct MoveList getPawnMoves(int  x, int y,int player, int firstMove, int buffer[8][8], int attack){

	struct MoveList moveList;
	moveList.tail = 0;
	int min;
	int max;
	int mod;
	if (player == 0){
		min = 16;
		max = 31;
		mod = 1;
	}else if (player == 1){
		min = 0;
		max = 15;
		mod = -1;
	}

	// Checking advancing moves
	if (attack == 0){
		if (buffer[y+(1*mod)][x] == -1 && y+(1*mod) <= 7 && y >= 0){
			moveList.xValues[moveList.tail] = x;
			moveList.yValues[moveList.tail] = y+(1*mod);
			moveList.tail = moveList.tail + 1;
		
			if (buffer[y+(2*mod)][x] == -1 & firstMove == 0){
				moveList.xValues[moveList.tail] = x;
				moveList.yValues[moveList.tail] = y+(2*mod);
				moveList.tail = moveList.tail + 1;
			}
		}
	}
	//Checking attacking moves
	if (buffer[y+(1*mod)][x+1] >= min && buffer[y+(1*mod)][x] <= max && y+(1*mod) >= 0 && y+(1*mod) <= 7 && x+1 >= 0 && x+1 <= 7){
		moveList.xValues[moveList.tail] = x+1;
		moveList.yValues[moveList.tail] = y+(1*mod);
		moveList.tail = moveList.tail + 1;
	}
	if (buffer[y+(1*mod)][x-1] >= min && buffer[y+(1*mod)][x] <= max && y+(1*mod) >= 0 && y+(1*mod) <= 7 && x-1 >= 0 && x-1 <= 7){
		moveList.xValues[moveList.tail] = x-1;
		moveList.yValues[moveList.tail] = y+(1*mod);
		moveList.tail = moveList.tail + 1;
	}
	return moveList;
}


struct MoveList getTowerMoves(int x, int y, int  player, int  buffer[8][8]){
	struct MoveList moveList;
	moveList.tail = 0;
	verticalMoves(x, y, player, buffer, &moveList.xValues, &moveList.yValues, &moveList.tail);
	horizontalMoves(x, y, player, buffer, &moveList.xValues, &moveList.yValues, &moveList.tail);
	return moveList;
}

struct MoveList getHorseMoves(int x, int y, int player, int buffer[8][8]){
	struct MoveList moveList;
	int *size = &moveList.tail;
	*size = 0;
	int min;
	int max;
	int oldX = x;
	int oldY = y;
	if (player == 0){
		min = 16;
		max = 31;
	}else if (player == 1){
		min = 0;
		max = 15;
	}
	x = x + 1;
	y = y + 2;
	if (x >= 0 && x <= 7 && y >= 0 && y <= 7){
		if (buffer[y][x] == -1 || (buffer[y][x] >= min && buffer[y][x] <= max)){
		moveList.xValues[*size] = x;
		moveList.yValues[*size] = y;
		++*size;
		}
	}
	x = oldX;
	y = oldY;
	x = x -1;
	y = y + 2;
	if (x >= 0 && x <= 7 && y >= 0 && y <= 7){
		if (buffer[y][x] == -1 || (buffer[y][x] >= min && buffer[y][x] <= max)){
		moveList.xValues[*size] = x;
		moveList.yValues[*size] = y;
		++*size;
		}
	}
	x = oldX;
	y = oldY;
	x = x + 1;
	y = y - 2;
	if (x >= 0 && x <= 7 && y >= 0 && y <= 7){
		if (buffer[y][x] == -1 || (buffer[y][x] >= min && buffer[y][x] <= max)){
		moveList.xValues[*size] = x;
		moveList.yValues[*size] = y;
		++*size;
		}
	}
	x = oldX;
	y = oldY;
	x = x - 1;
	y = y - 2;
	if (x >= 0 && x <= 7 && y >= 0 && y <= 7){
		if (buffer[y][x] == -1 || (buffer[y][x] >= min && buffer[y][x] <= max)){
		moveList.xValues[*size] = x;
		moveList.yValues[*size] = y;
		++*size;
		}
	}
	return moveList;
}

struct MoveList getBishopMoves(int x, int y, int player, int buffer[8][8]){
	struct MoveList moveList;
	moveList.tail = 0;
	acrossUpMoves(x, y, player, buffer, &moveList.xValues, &moveList.yValues, &moveList.tail);
	acrossDownMoves(x, y, player, buffer, &moveList.xValues, &moveList.yValues, &moveList.tail);
	return moveList;
}

struct MoveList getQueenMoves(int x, int y, int player, int buffer[8][8]){
	struct MoveList moveList;
	moveList.tail = 0;
	acrossUpMoves(x, y, player, buffer, &moveList.xValues, &moveList.yValues, &moveList.tail);
	acrossDownMoves(x, y, player, buffer, &moveList.xValues, &moveList.yValues, &moveList.tail);
	verticalMoves(x, y, player, buffer, &moveList.xValues, &moveList.yValues, &moveList.tail);
	horizontalMoves(x, y, player, buffer, &moveList.xValues, &moveList.yValues, &moveList.tail);
	return moveList;
}

struct MoveList getKingMoves(int x, int y, int player, int buffer[8][8]){
	struct MoveList moveList;
	int *size = &moveList.tail;
	*size = 0;
	int min;
	int max;
	if (player == 0){
		min = 16;
		max = 30;
	}else if (player == 1){
		min = 0;
		max = 14;
	}
	if (x >= 0 && x <= 7 && y+1 >= 0 && y+1 <= 7){
		if (buffer[y+1][x] == -1 || (buffer[y+1][x] >= min && buffer[y+1][x] <= max)){
			moveList.xValues[*size] = x;
			moveList.yValues[*size]= y+1;
			++*size;
		}
	}
	if (x+1 >= 0 && x+1 <= 7 && y+1 >= 0 && y+1 <= 7){
		if (buffer[y+1][x+1] == -1 || (buffer[y+1][x+1] >= min && buffer[y+1][x+1] <= max)){
			moveList.xValues[*size] = x+1;
			moveList.yValues[*size] = y+1;
			++*size;
		}
	}
	if (x-1 >= 0 && x-1 <= 7 && y+1 >= 0 && y+1 <= 7){
		if (buffer[y+1][x-1] == -1 || (buffer[y+1][x-1] >= min && buffer[y+1][x-1] <= max)){
			moveList.xValues[*size] = x-1;
			moveList.yValues[*size] = y+1;
			++*size;
		}
	}
	if (x+1 >= 0 && x+1 <= 7 && y >= 0 && y <= 7){
		if (buffer[y][x+1] == -1 || (buffer[y][x+1] >= min && buffer[y][x+1] <= max)){
			moveList.xValues[*size] = x+1;
			moveList.yValues[*size] = y;
			++*size;
		}
	}
	if (x-1 >= 0 && x-1 <= 7 && y >= 0 && y <= 7){
		if (buffer[y][x-1] == -1 || (buffer[y][x-1] >= min && buffer[y][x-1] <= max)){
			moveList.xValues[*size] = x-1;
			moveList.yValues[*size] = y;
			++*size;
		}
	}
	if (x >= 0 && x <= 7 && y-1 >= 0 && y-1 <= 7){
		if (buffer[y-1][x] == -1 || (buffer[y-1][x] >= min && buffer[y-1][x] <= max)){
			moveList.xValues[*size] = x;
			moveList.yValues[*size] = y-1;
			++*size;
		}
	}
	if (x+1 >= 0 && x+1 <= 7 && y-1 >= 0 && y-1 <= 7){
		if (buffer[y-1][x+1] == -1 || (buffer[y-1][x+1] >= min && buffer[y-1][x+1] <= max)){
			moveList.xValues[*size] = x+1;
			moveList.yValues[*size] = y-1;
			++*size;
		}
	}
	if (x-1 >= 0 && x-1 <= 7 && y-1 >= 0 && y-1 <= 7){
		if (buffer[y-1][x-1] == -1 || (buffer[y-1][x-1] >= min && buffer[y-1][x-1] <= max)){
			moveList.xValues[*size] = x-1;
			moveList.yValues[*size] = y-1;
			++*size;
		}
	}
	return moveList;
}

struct MoveList getMovesOfChosenPiece(int displayId, int x, int y, int firstMove,  int player, int buffer[8][8]){
	switch (displayId){
		case 1:
		case 11:
			return getPawnMoves(x, y, player, firstMove, buffer, 0);
		case 2:
		case 12:
			return getTowerMoves(x, y, player, buffer);
		case 3:
		case 13:
			return getHorseMoves(x, y, player, buffer);
		case 4:
		case 14:
			return getBishopMoves(x, y, player, buffer);
		case 5:
		case 15:
			return getQueenMoves(x, y, player, buffer);
		case 6:
		case 16:
			return getKingMoves(x, y, player, buffer);
	}
}
	
void printDisplayBuffer(int array[8][8]){
	int i = 0;
	int j = 0;
	printf("   A    B    C    D    E    F    G    H");
	printf("\n -----------------------------------------");
	for(i=0; i<=7; i++){
		printf("\n%d|", i+1);
		for(j=0; j<=7; j++){
			switch(array[i][j]){
				case -1:
					printf(" >< |");
					break;
				case 0:
					printf("    |");
					break;
				case 1:
					printf("WPwn|");
					break;
				case 2:
					printf("WTwr|");
					break;
				case 3:
					printf("WHrs|");
					break;
				case 4:
					printf("WBis|");
					break;
				case 5:
					printf("WQun|");
					break;
				case 6:
					printf("WKng|");
					break;
				case 11:
					printf("BPwn|");
					break;
				case 12:
					printf("BTwr|");
					break;
				case 13:
					printf("BHrs|");
					break;
				case 14:
					printf("BBis|");
					break;
				case 15:
					printf("BQun|");
					break;
				case 16:
					printf("BKng|");
					break;
				case -11:
					printf(">Pwn|");
					break;
				case -12:
					printf(">Twr|");
					break;
				case -13:
					printf(">Hrs|");
					break;
				case -14:
					printf(">Bis|");
					break;
				case -15:
					printf(">Qun|");
					break;
				case -16:
					printf(">Kng|");
					break;
				default:
					printf("-N/A|");
					break;
				
			}
		}
		printf("\n -----------------------------------------");
	}
	printf("\n");
}
 
void loadLogicBuffer(struct ChessPiece Pieces[32], int Buffer[8][8]){
	int i;
	int x;
	int y;
	for (i = 0; i < 32; i++){
		if (Pieces[i].isAlive == 1){
			x = Pieces[i].x;
			y = Pieces[i].y;
			Buffer[y][x] = Pieces[i].id;	
			}
	}

}

void resetDisplayBuffer(int buffer[8][8]){
	int i;
	int j;
	for (i = 0; i < 8; i++){
		for (j = 0; j < 8; j++){
			buffer[i][j] = 0;
		}
	}
}

void resetLogicBuffer(int buffer[8][8]){
		int i;
		int j;
		for (i = 0; i < 8; i++){
			for (j = 0; j < 8; j++){
				buffer[i][j] = -1;
			}
		}
}

//No longer in use!
void loadLogicBufferInPathtrackMode(struct ChessPiece Pieces[32],  int buffer[8][8], int player){
	int i;
	int x;
	int y;
	if (player == 0){
		for (i = 0; i < 32; i++){
			if (Pieces[i].isAlive == 1){
				x = Pieces[i].x;
				y = Pieces[i].y;
				if (Pieces[i].id < 17){
				buffer[y][x] = 0;	
				} else {
					buffer[y][x] = 1;
				}	
			}
		}
	} else {
		for (i = 0; i < 32; i++){
			if (Pieces[i].isAlive == 1){
				x = Pieces[i].x;
				y = Pieces[i].y;
				if (Pieces[i].id > 16){
					buffer[y][x] = 0;
				} else{
					buffer[y][x] = 1;	
				}	
			}
		}
	}
}
	

void loadDisplayBuffer(struct ChessPiece Pieces[32],int Buffer[8][8]){
	int i;
	int x;
	int y;
	for (i = 0; i < 32; i++){
		if (Pieces[i].isAlive == 1){
			x = Pieces[i].x;
			y = Pieces[i].y;
			Buffer[y][x] = Pieces[i].displayId;	
			}
	}
}


int checkIfChessPieceIsValid(int y, int x, int player, int buffer[8][8]){
	//printf("%d",buffer[y][x]);
	if (buffer[y][x] > -1){
		if (player == 0 && buffer[y][x] < 16){
			return buffer[y][x];
		} else if(player == 1 && buffer[y][x] > 15){
			return buffer[y][x];
		} else {
			printf("The ChessPiece is from the other player \n");
			return -1;
		}
	} else {
		printf("There is no ChessPiece at this location \n");
		return -1;
	}
}


struct Coords getUserInputCoords(){
	int validInput = 0;
	int yInput;
	char xInput;
	int newX;
	while (validInput == 0){
		printf("Type the location (Example A1)\n");
		scanf("%c %d", &xInput, &yInput);
		while ((getchar()) != '\n');
		yInput = yInput - 1;
		switch (xInput){
			case 'A':
			case 'a':
				newX = 0;
				break;
			case 'B':
			case 'b':
				newX = 1;
				break;
			case 'C':
			case 'c':
				newX = 2;
				break;
			case 'D':
			case 'd':
				newX = 3;
				break;
			case 'E':
			case 'e':
				newX = 4;
				break;
			case 'F':
			case 'f':
				newX = 5;
				break;
			case 'G':
			case 'g':
				newX = 6;
				break;
			case 'H':
			case 'h':
				newX = 7;
				break;
			default:
				newX = -1;
				break;
		}
		if (yInput > -1 && yInput < 8 && newX > -1 && newX < 8){
			validInput = 1;
		} else {
			printf("Invalid Input, try again \n");
		}
	}	
	struct Coords c;
	c.x = newX;
	c.y = yInput;
	return c;
}


// No longer in use!
int getCoordinateUserInput(int buffer[8][8], int player){
	int validInput = 0;
	int yInput;
	char xInput;
	int newX;
	while (validInput == 0){
		printf("Type the location (Example A1)\n");
		scanf("%c %d", &xInput, &yInput);
		while ((getchar()) != '\n');
		yInput = yInput - 1;
		switch (xInput){
			case 'A':
			case 'a':
				newX = 0;
				break;
			case 'B':
			case 'b':
				newX = 1;
				break;
			case 'C':
			case 'c':
				newX = 2;
				break;
			case 'D':
			case 'd':
				newX = 3;
				break;
			case 'E':
			case 'e':
				newX = 4;
				break;
			case 'F':
			case 'f':
				newX = 5;
				break;
			case 'G':
			case 'g':
				newX = 6;
				break;
			case 'H':
			case 'h':
				newX = 7;
				break;
			default:
				newX = -1;
				break;
		}
		if (yInput > -1 && yInput < 8 && newX > -1 && newX < 8){
			validInput = 1;
		} else {
			printf("Invalid Input, try again \n");
		}
	}	
	return checkIfChessPieceIsValid(yInput, newX, player, buffer);
	
}

int performAMove(struct ChessPiece Pieces[32], int id, int x[27], int y[27], int size, int xInput, int yInput, int buffer[8][8]){
	int flag;
	int i;
	for (i = 0; i < size; i++){
		flag = 0;
		if (x[i] == xInput){
			++flag;
		}
		if (y[i] == yInput){
			++flag;
		}
		if (flag == 2){
			break;
		}
	}
	if (flag != 2){
		return 0;
	}
	if (buffer[yInput][xInput] == -1){
		Pieces[id].x = xInput;
		Pieces[id].y = yInput;
		if (Pieces[id].isFirstMove == 0){
			Pieces[id].isFirstMove = 1;
		}
		return 1;
	} else {
		int pieceToDelete = buffer[yInput][xInput];
		Pieces[pieceToDelete].isAlive = 0;
		Pieces[id].x = xInput;
		Pieces[id].y = yInput;
		if (Pieces[id].isFirstMove == 0){
			Pieces[id].isFirstMove = 1;
		}
		return 1;
	}	

}

void removeKingMoves(struct MoveList enemyList, struct MoveList kingList){
}

void checkMateCheck(int kX, int kY, struct ChessPiece Pieces[32], int player, int buffer[8][8]){
	int min;
	int max;
	if (player == 0){
		min = 16;
		max = 31;
	}else if (player == 1){
		min = 0;
		max = 15;
	}
	int i;
	int dId;
	int x;
	int y;
	for (i = min; i <= max; i++){
		dId = Pieces[i].displayId;
		switch(dId){
		case 1:
		case 11:
			if ((Pieces[i].x == kX+1 || Pieces[i].x == kX-1) && Pieces[i].y == kY-1){
			struct MoveList moves = getPawnMoves(Pieces[i].x, Pieces[i].y , player, 1, buffer, 1);
			}
			continue;
		case 2:
		case 12:
			if (Pieces[i].x == kX || Pieces[i].y == kY){
			struct MoveList moves = getTowerMoves(Pieces[i].x, Pieces[i].y, player, buffer);
			}
			continue;
		case 3:
		case 13:
			struct MoveList moves = getHorseMoves(Pieces[i].x, Pieces[i].y, player, buffer);
			continue;
		case 4:
		case 14:
			//int x;
			//int y;
			x = kX-Pieces[i].x;
			y = kY-Pieces[i].y;
			if (x < 0){
				x *= -1;
			}
			if (y < 0){
				y *= -1;
			}
			if (x == y){
			struct MoveList moves = getBishopMoves(x, y, player, buffer);
			}
			continue;
		case 5:
		case 15:
			//int x;
			//int y;
			x = kX-Pieces[i].x;
			y = kY-Pieces[i].y;
			if (x < 0){
				x *= -1;
			}
			if (y < 0){
				y *= -1;
			}

			if ((Pieces[i].x == kX || Pieces[i].y == kY)&&(y==x)){
			struct MoveList moves = getQueenMoves(x, y, player, buffer);
			}
			continue;
		}
	}	
}
	
int main(void){
	int displayBuffer[8][8];
	int logicBuffer[8][8];

	struct ChessPiece Pieces[32] = {
             //  id  dId x  y  f  a
		{ 0,  1, 0, 1, 0, 1},
		{ 1,  1, 1, 1, 0, 1},
		{ 2,  1, 2, 1, 0, 1},
		{ 3,  1, 3, 1, 0, 1},
		{ 4,  1, 4, 1, 0, 1},
		{ 5,  1, 5, 1, 0, 1},
		{ 6,  1, 6, 1, 0, 1},
		{ 7,  1, 7, 1, 0, 1},
		{ 8,  2, 0, 0, 0, 1},
		{ 9,  2, 7, 0, 0, 1},
		{10,  3, 1, 0, 1, 1},
		{11,  3, 6, 0, 1, 1},
		{12,  4, 2, 0, 1, 1},
		{13,  4, 5, 0, 1, 1},
		{14,  5, 3, 0, 0, 1},
		{15,  6, 4, 0, 1, 1},
		{16, 11, 0, 6, 0, 1},
		{17, 11, 1, 6, 0, 1},
		{18, 11, 2, 6, 0, 1},
		{19, 11, 3, 6, 0, 1},
		{20, 11, 4, 6, 0, 1},
		{21, 11, 5, 6, 0, 1},
		{22, 11, 6, 6, 0, 1},
		{23, 11, 7, 6, 0, 1},
		{24, 12, 0, 7, 0, 1},
		{25, 12, 7, 7, 0, 1},	
		{26, 13, 1, 7, 1, 1},	
		{27, 13, 6, 7, 1, 1},		
		{28, 14, 2, 7, 1, 1},		
		{29, 14, 5, 7, 1, 1},		
		{30, 15, 4, 7, 0, 1},		
		{31, 16, 3, 7, 1, 1}
	};
				
	int gameRuntime = 1;
	int player = 0;
	int chosenPiece = -1;
	char option;
	// Zeros both buffers
	resetDisplayBuffer(displayBuffer);
	resetLogicBuffer(logicBuffer);

	loadDisplayBuffer(Pieces, displayBuffer);
	printDisplayBuffer(displayBuffer);

	loadLogicBuffer(Pieces, logicBuffer);

	while (gameRuntime == 1){
		printf("Player %d turn!\n", (player+1));
		struct MoveList listOfMoves;
		struct Coords userInput;
		resetLogicBuffer(logicBuffer);
		loadLogicBuffer(Pieces, logicBuffer);
		int kingX;
		int kingY;
		if (player == 0){
			kingX = Pieces[11].x;
			kingY = Pieces[11].y;
		} 
		if (player == 1){
			kingX = Pieces[31].x;
			kingY = Pieces[31].y;
		}
		listOfMoves = getKingMoves(kingX, kingY, player, logicBuffer);
		checkMateCheck(kingX, kingY, Pieces, player, logicBuffer);
		if (listOfMoves.tail == 0 /*&& check*/){
		}
		//Check for Checkmate
		//Check for special moves
		chosenPiece = -1;
		while (chosenPiece == -1){
			printf("Choose your chess piece\n");
			userInput = getUserInputCoords();
			chosenPiece = checkIfChessPieceIsValid(userInput.y, userInput.x, player, logicBuffer);
			if (chosenPiece == -1){
				continue;
			}
			listOfMoves = getMovesOfChosenPiece(Pieces[chosenPiece].displayId , Pieces[chosenPiece].x, Pieces[chosenPiece].y, Pieces[chosenPiece].isFirstMove  ,player, logicBuffer);
			if (listOfMoves.tail == 0){
				printf("There are no availble moves for the chosen piece\n");
				chosenPiece = -1;
				continue;
			}
			loadMovesToDisplayBuffer(listOfMoves, displayBuffer);
			printDisplayBuffer(displayBuffer);
			printf("Do you want to make a move (y/n)?\n");
			scanf("%c",&option);
			while ((getchar()) != '\n');

			if (option == 'y'){
				printf("Chose a valid move\n");
			} else { 
				resetDisplayBuffer(displayBuffer);
				loadDisplayBuffer(Pieces, displayBuffer);
				printDisplayBuffer(displayBuffer);
				chosenPiece = -1;
			}
		}
		//Confirm Move
		int isMoveValid = 0;
		while (isMoveValid == 0){
			printf("Eneter the coordinates of the move you wish to perform\n");
			userInput = getUserInputCoords();
			isMoveValid = performAMove(Pieces, chosenPiece, listOfMoves.xValues, listOfMoves.yValues, listOfMoves.tail, userInput.x, userInput.y, logicBuffer);	
		}
		//printf("displaying");

		resetDisplayBuffer(displayBuffer);
		loadDisplayBuffer(Pieces, displayBuffer);
		printDisplayBuffer(displayBuffer);
		//Change player
		if (player == 0){
			player = 1;
		} else if (player == 1){
			player = 0;
		}
		//printf("End Of the Game!\n");
		//gameRuntime = 0;
	}

	return 0;
}
