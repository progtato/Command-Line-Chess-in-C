It's a simple chess game that runs in the terminal.
You can choose a chess piece and the game will preview possible moves of the chosen piece.
Then you can commit your move or not and choose a different piece.
The game was developed before I started my first year of uni as the uni had a module that made us learn coding in c.
So I made a small game over a summer of 2025 to learn most of basics of c.
## DISCLAIMER: Because I was Lazy (the project kinda died after I started going to uni)
* The checkmate is not fully implemented and so the game has no end (there's some implementation of it in the code but was never fully implemented)
* There are no special moves such as tower and kind swap or en passant even if the data structure of a chesspiece could allow for such moves to be implemented.
* The terminal doesn't clear itself so you end up with a cluttered terminal after playing a single game.

No dynamic memory allocation was used in this game.
To change the chesspieces layout got to main function and edit the struct that defines the whole chessboard.
Then just recompile the game with your preferred c compiler.

Most importantly of all,
Enjoy playing chess on your terminal :)
