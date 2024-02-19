Pa2 Helping Function
1. Find Opponent
    for returning the target is opponent or not

2. Belongs To Different Player
3. Count Black Pieces
4. Count Red Pieces
5. Print Map
6. Copy Map
7. Check Capturable Pieces
8. Check if valid
int checkIfValid(const int map[NUM_ROWS][NUM_COLS], int currentRow, int currentCol, int destinationRow, int destinationCol)

9. Move
10. Check if Valid Move Exists For Player only be used in check game conditions


3 Tasks in total

First, int move
	check if the move is valid
	if yes, excuse
    If invalid print 

    cout << "Please enter a valid move" << endl; then return invalid

    If capture happens, remove the captured piece
    If applicable promote the man to king, => king = man +2, then return capture

    If excuse but no capture, return valid


int move(int map[NUM_ROWS][NUM_COLS], int currentRow, int currentCol, int destinationRow, int destinationCol)



int findOpponent(int player) returns the opponent for a given player.

bool belongsToDifferentPlayer(int piece1, int piece2) returns true if the given two pieces belongs to different players. This is useful for determining if a capture is possible.

int countBlackPieces(const int map[NUM_ROWS][NUM_COLS])

int countRedPieces(const int map[NUM_ROWS][NUM_COLS])

void printMap(const int map[NUM_ROWS][NUM_COLS]) is a function that can convert the 2D array map[NUM_ROWS][NUM_COLS] to the grid shown to the terminal. You are NOT allowed to modify this fuction to make sure we have the same output format for grading.

void copyMap(const int map[NUM_ROWS][NUM_COLS], int map_copy[NUM_ROWS][NUM_COLS]) may be useful in your Recursive Solver.

bool checkCapturablePieces(const int map[NUM_ROWS][NUM_COLS], int currentRow, int currentCol)

Given a location on the board, it will return true if and only if there is a piece in the given location and this piece is possible to capture an opponents piece nearby.

int checkIfValid(const int map[NUM_ROWS][NUM_COLS], int currentRow, int currentCol, int destinationRow, int destinationCol)
Given a current location and a destination location on the board, the function will help to check whether the move is allowed by the rule. It will return INVALID if this movement is not allowed. Otherwise, it will return some integers less than 0 to help with other functions. Please check the code and also the Addtional Move Status Constants for details.

You are allowed to modify this helper function to return some other integers to help you. Just remember that if a piece is able to capture, it must capture and it is not allowed to do a normal move.

bool move(int map[NUM_ROWS][NUM_COLS], char *current, char *destination) will convert the input location in string format to the location indices for the 2D array. And it will then call the move function to execute the move or capture.

int checkIfValidMoveExists(const int map[NUM_ROWS][NUM_COLS], int currentRow, int currentCol) just combines checkIfValid() and checkCapturablePieces() together to check if there exists a valid move or capture for a given piece. It will return CAPTURE, VALID(for a normal move) or INVALID. 
UPDATE (03/11/2022 17:10): We have updated the skeleton code to make a change on line 473, you can now pass the constants RED (0) for the red player and BLACK (1) for the black player. You can still keep using the old version of skeleton code, but you should pass 2 for the red player and 1 for the black player.

int checkIfValidMoveExistsForPlayer(const int map[NUM_ROWS][NUM_COLS], int player) can check if a valid move or capture exists for a given player by scanning the whole board and calls checkIfValidMoveExists(). The returned value of this function is CAPTURE (if there exists a piece among this player's that can perform capture); VALID (if no piece of this player's can capture, but some pieces may make valid move) or INVALID. It may be helpful for the implementation of checkEndGameConditions().



int move(int map[NUM_ROWS][NUM_COLS], int currentRow, int currentCol, int destinationRow, int destinationCol)
{
    /* TASK: 4.1 Move the Piece */
    /* Please write your code here: */
    if (whoseTurn == RED && map[currentRow][currentCol] == RED_MAN && destinationRow == currentRow+1){
        cout << "Please enter a valid move" << endl;
        return INVALID;
    }     
    if (whoseTurn == BLACK && map[currentRow][currentCol] == BLACK_MAN && destinationRow == currentRow-1){
        cout << "Please enter a valid move" << endl;
        return INVALID;
    } 

    switch(checkIfValid(map, currentRow, currentCol, destinationRow, destinationCol)){
        case INVALID:
            cout << "Please enter a valid move" << endl;
            return INVALID;
        case VALID:
            if (whoseTurn == RED && destinationRow == 0) map[currentRow][currentCol] = RED_KING;
            if (whoseTurn == BLACK && destinationRow == 5) map[currentRow][currentCol] = BLACK_KING;
            map[destinationRow][destinationCol] = map[currentRow][currentCol];
            map[currentRow][currentCol] = EMPTY;
            return VALID;
        case RIGHT_CAPTURE:
            if (whoseTurn == RED && destinationRow == 0) map[currentRow][currentCol] = RED_KING;
            if (whoseTurn == BLACK && destinationRow == 5) map[currentRow][currentCol] = BLACK_KING;
            map[destinationRow][destinationCol] = map[currentRow][currentCol];
            map[destinationRow][destinationCol-1] = EMPTY;
            map[currentRow][currentCol] = EMPTY;
            return CAPTURE;
        case LEFT_CAPTURE:
            if (whoseTurn == RED && destinationRow == 0) map[currentRow][currentCol] = RED_KING;
            if (whoseTurn == BLACK && destinationRow == 5) map[currentRow][currentCol] = BLACK_KING;
            map[destinationRow][destinationCol] = map[currentRow][currentCol];
            map[destinationRow][destinationCol+1] = EMPTY;
            map[currentRow][currentCol] = EMPTY;
            return CAPTURE;
        case UP_CAPTURE:
            if (whoseTurn == RED && destinationRow == 0) map[currentRow][currentCol] = RED_KING;
            if (whoseTurn == BLACK && destinationRow == 5) map[currentRow][currentCol] = BLACK_KING;
            map[destinationRow][destinationCol] = map[currentRow][currentCol];
            map[destinationRow+1][destinationCol] = EMPTY;
            map[currentRow][currentCol] = EMPTY;
            return CAPTURE;
        case DOWN_CAPTURE:
            if (whoseTurn == RED && destinationRow == 0) map[currentRow][currentCol] = RED_KING;
            if (whoseTurn == BLACK && destinationRow == 5) map[currentRow][currentCol] = BLACK_KING;
            map[destinationRow][destinationCol] = map[currentRow][currentCol];
            map[destinationRow-1][destinationCol] = EMPTY;
            map[currentRow][currentCol] = EMPTY;
            return CAPTURE;
    }

    return VALID;
}