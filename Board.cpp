//
// Created by chaseez on 5/9/2023.
//

#include "Board.h"


void Board::updateBoard(int x, int y) {

}

bool Board::validMove(int x, int y) {
    return 0 <= x and x < BOARD_HEIGHT and 0 <= y and y < BOARD_WIDTH;
}

/**
 * Checking the immediate surrounding of the piece for 1 open space
 * @param piece
 * @return
 */
bool Board::canMovePiece(Piece* piece) const {
    int row = piece->getRow();
    int col = piece->getColumn();
    int pieceValue = piece->value;

    bool movable = false;

    switch(pieceValue) {
        case 1: // Pawn
            if(piece->team) { // White Team
                if(board[row-1][col] == 0) movable = true;
            }
            else { // Black Team
                if(board[row+1][col] == 0) movable = true;
            }
            break;
        case 3: // Rook
            // Check 1 above/below/right/left
            if(validMove(row+1,col)) {
                if(board[row+1][col] == 0) {
                    movable = true;
                    break;
                }
            }
            if(validMove(row,col+1)) {
                if(board[row][col+1] == 0) {
                    movable = true;
                    break;
                }
            }
            if(validMove(row-1,col)) {
                if(board[row-1][col] == 0) {
                    movable = true;
                    break;
                }
            }
            if(validMove(row,col-1)) {
                if(board[row][col-1] == 0) {
                    movable = true;
                    break;
                }
            }
            break;
        case 5: // Knight
            if(validMove(row+2, col+1)) { // Up 2, Right 1
                if(board[row+2][col+1] == 0) {
                    movable = true;
                    break;
                }
            }
            if(validMove(row+2, col-1)) { // Up 2, Left 1
                if(board[row+2][col-1] == 0) {
                    movable = true;
                    break;
                }
            }
            if(validMove(row-2, col+1)) { // Down 2, Right 1
                if(board[row-2][col+1] == 0) {
                    movable = true;
                    break;
                }
            }
            if(validMove(row-2, col-1)) { // Down 2, Left 1
                if(board[row-2][col-1] == 0) {
                    movable = true;
                    break;
                }
            }
            if(validMove(row-1, col+2)) { // Down 1, Right 2
                if(board[row-1][col+2] == 0) {
                    movable = true;
                    break;
                }
            }
            if(validMove(row+1, col+2)) { // Up 1, Right 2
                if(board[row+1][col+2] == 0) {
                    movable = true;
                    break;
                }
            }
            if(validMove(row-1, col-2)) { // Down 1, Left 2
                if(board[row-1][col-2] == 0) {
                    movable = true;
                    break;
                }
            }
            if(validMove(row+1, col-2)) { // Up 1, Left 2
                if(board[row+1][col-2] == 0) {
                    movable = true;
                    break;
                }
            }
            break;
        case 7: // Bishop
            for(int r = row - 1; r < row + 2; ++r)
                for(int c = col - 1; c < col + 2; ++c) {
                    if(!validMove(r,c)) continue;
                    if(r == row and c == col) continue;
                    if(abs(r) == abs(c))  {
                        movable = true;
                        break;
                    }
                }
            break;
        case 9: // King and Queen logic
        case-2:
            for(int r = row - 1; r < row + 2; ++r)
                for(int c = col - 1; c < col + 2; ++c) {
                    if(!validMove(r,c)) continue; // Out-of-bounds check
                    if(r == row and c == col) continue; // Self check
                    if(board[r][c] == 0) movable = true; // 1 open spot check
                }
            break;
        default: // Make the compiler happy
            break;
    }
    return movable; // If the piece doesn't have 1 free space
}

void Board::printBoard() const {
    for(int i = 0; i < BOARD_HEIGHT; ++i) {
        for(int j = 0; j < BOARD_WIDTH; ++j) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Board::printMask() const {
    for(int i = 0; i < MASK_HEIGHT; ++i) {
        for(int j = 0; j < MASK_WIDTH; ++j) {
            std::cout << mask[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Board::showPossibleMoves(Piece* piece) const {
    std::cout << "Entering Board::showPossibleMoves()" << std::endl;

}

void Board::populateBoard(const Player& white, const Player& black) const {
    std::vector<Piece*> pieces = white.getPieces();
    int firstColumn = 0;
    int rookColumn = 0;
    int knightColumn = 1;
    int bishopColumn = 2;
    int royaltyColumn = 3;
    int lastColumn = 7;

    int topRow = 0;
    int belowTopRow = 1;
    int aboveBottomRow = 6;
    int bottomRow = 7;

    int teamColor = WHITE;
    int idx = -1;

    // Initializing the pawns: 'a2' - 'h2'
    for(int j = 0; j < BOARD_WIDTH; ++j) {
        board[belowTopRow][j] = pieces.at(++idx)->value + teamColor;
        pieces.at(idx)->setRow(belowTopRow);
        pieces.at(idx)->setColumn(j);
    }

    // Initializing the rooks: 'a1','h1'
    board[topRow][firstColumn + rookColumn] = pieces.at(++idx)->value + teamColor;
    pieces.at(idx)->setRow(topRow);
    pieces.at(idx)->setColumn(firstColumn + rookColumn);

    board[topRow][lastColumn - rookColumn] = pieces.at(++idx)->value + teamColor;
    pieces.at(idx)->setRow(topRow);
    pieces.at(idx)->setColumn(lastColumn - rookColumn);

    // Initializing the knights: 'b1', 'g1'
    board[topRow][firstColumn + knightColumn] = pieces.at(++idx)->value + teamColor;
    pieces.at(idx)->setRow(topRow);
    pieces.at(idx)->setColumn(firstColumn + knightColumn);

    board[topRow][lastColumn - knightColumn] = pieces.at(++idx)->value + teamColor;
    pieces.at(idx)->setRow(topRow);
    pieces.at(idx)->setColumn(lastColumn - knightColumn);

    // Initializing the bishops 'c1', 'f1':
    board[topRow][firstColumn + bishopColumn] = pieces.at(++idx)->value + teamColor;
    pieces.at(idx)->setRow(topRow);
    pieces.at(idx)->setColumn(firstColumn + bishopColumn);

    board[topRow][lastColumn - bishopColumn] = pieces.at(++idx)->value + teamColor;
    pieces.at(idx)->setRow(topRow);
    pieces.at(idx)->setColumn(lastColumn - bishopColumn);

    // Initializing the queen: 'd1'
    board[topRow][firstColumn + royaltyColumn] = pieces.at(++idx)->value + teamColor;
    pieces.at(idx)->setRow(topRow);
    pieces.at(idx)->setColumn(firstColumn + royaltyColumn);

    // Initializing the king: 'e1'
    board[topRow][lastColumn - royaltyColumn] = pieces.at(++idx)->value + teamColor;
    pieces.at(idx)->setRow(topRow);
    pieces.at(idx)->setColumn(lastColumn - royaltyColumn);


    idx = -1;
    teamColor = BLACK;
    pieces = black.getPieces();

    // Initializing the pawns: 'a7' - 'h7'
    for(int j = 0; j < BOARD_WIDTH; ++j){
        board[aboveBottomRow][j] = pieces.at(++idx)->value + teamColor;
        pieces.at(idx)->setRow(aboveBottomRow);
        pieces.at(idx)->setColumn(j);
    }

    // Initializing the rooks: 'a8','h8'
    board[bottomRow][firstColumn + rookColumn] = pieces.at(++idx)->value + teamColor;
    pieces.at(idx)->setRow(bottomRow);
    pieces.at(idx)->setColumn(firstColumn + rookColumn);

    board[bottomRow][lastColumn - rookColumn] = pieces.at(++idx)->value + teamColor;
    pieces.at(idx)->setRow(bottomRow);
    pieces.at(idx)->setColumn(lastColumn - rookColumn);

    // Initializing the knights: 'b8', 'g8'
    board[bottomRow][firstColumn + knightColumn] = pieces.at(++idx)->value + teamColor;
    pieces.at(idx)->setRow(bottomRow);
    pieces.at(idx)->setColumn(firstColumn + knightColumn);

    board[bottomRow][lastColumn - knightColumn] = pieces.at(++idx)->value + teamColor;
    pieces.at(idx)->setRow(bottomRow);
    pieces.at(idx)->setColumn(lastColumn - knightColumn);

    // Initializing the bishops: 'c8', 'f8'
    board[bottomRow][firstColumn + bishopColumn] = pieces.at(++idx)->value + teamColor;
    pieces.at(idx)->setRow(bottomRow);
    pieces.at(idx)->setColumn(firstColumn + bishopColumn);

    board[bottomRow][lastColumn - bishopColumn] = pieces.at(++idx)->value + teamColor;
    pieces.at(idx)->setRow(bottomRow);
    pieces.at(idx)->setColumn(lastColumn - bishopColumn);

    // Initializing the queen: 'd8'
    board[bottomRow][firstColumn + royaltyColumn] = pieces.at(++idx)->value + teamColor;
    pieces.at(idx)->setRow(bottomRow);
    pieces.at(idx)->setColumn(firstColumn + royaltyColumn);

    // Initializing the king: 'e8'
    board[bottomRow][lastColumn - royaltyColumn] = pieces.at(++idx)->value + teamColor;
    pieces.at(idx)->setRow(bottomRow);
    pieces.at(idx)->setColumn(lastColumn - royaltyColumn);

}

void Board::populateMask() {
    for(int i = 4; i < BOARD_WIDTH + 4; ++i)
        for(int j = 4; j < BOARD_HEIGHT + 4; ++j) mask[i][j] = board[i-4][j-4];

}

Piece* Board::getPieceAt(std::string coordinates, const std::vector<Piece*>& pieces) const {
    // Making the ascii numbers correspond with a column
    int col = std::tolower(coordinates[0]) - 'a';

    // Adjusting the number to fit the array index
    std::string temp = coordinates.substr(1);
    int row = std::stoi(temp) - 1;

    int pieceValue = board[row][col];

    for(Piece* piece: pieces) {
        if(piece->value == pieceValue - piece->team) {
            if(piece->getRow() == row and piece->getColumn() == col) return piece;
        }
    }
}

int** Board::getBoard() const { return board; }

int** Board::getMask() const { return mask; }