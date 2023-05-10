//
// Created by chaseez on 5/9/2023.
//

#include "Board.h"


void Board::updateBoard(int x, int y) {

}

bool Board::validMove(int x, int y) {
    return 0 <= x and x < BOARD_HEIGHT and 0 <= y and y < BOARD_WIDTH;
}

void Board::printBoard() const {
    for(int i = 0; i < BOARD_HEIGHT; ++i) {
        for(int j = 0; j < BOARD_WIDTH; ++j) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Board::printMask() const {
    for(int i = 0; i < MASK_HEIGHT; ++i) {
        for(int j = 0; j < MASK_WIDTH; ++j) {
            std::cout << mask[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Board::populateBoard(const Player& white, const Player& black) {
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
    for(int j = 0; j < BOARD_WIDTH; ++j) board[belowTopRow][j] = pieces.at(++idx)->value + teamColor;

    // Initializing the rooks: 'a1','h1'
    board[topRow][firstColumn + rookColumn] = pieces.at(++idx)->value + teamColor;
    board[topRow][lastColumn - rookColumn] = pieces.at(++idx)->value + teamColor;

    // Initializing the knights: 'b1', 'g1'
    board[topRow][firstColumn + knightColumn] = pieces.at(++idx)->value + teamColor;
    board[topRow][lastColumn - knightColumn] = pieces.at(++idx)->value + teamColor;

    // Initializing the bishops 'c1', 'f1':
    board[topRow][firstColumn + bishopColumn] = pieces.at(++idx)->value + teamColor;
    board[topRow][lastColumn - bishopColumn] = pieces.at(++idx)->value + teamColor;

    // Initializing the queen: 'd1'
    board[topRow][firstColumn + royaltyColumn] = pieces.at(++idx)->value + teamColor;

    // Initializing the king: 'e1'
    board[topRow][lastColumn - royaltyColumn] = pieces.at(++idx)->value + teamColor;


    idx = -1;
    teamColor = BLACK;
    pieces = black.getPieces();

    // Initializing the pawns: 'a7' - 'h7'
    for(int j = 0; j < BOARD_WIDTH; ++j) board[aboveBottomRow][j] = pieces.at(++idx)->value + teamColor;

    // Initializing the rooks: 'a8','h8'
    board[bottomRow][firstColumn + rookColumn] = pieces.at(++idx)->value + teamColor;
    board[bottomRow][lastColumn - rookColumn] = pieces.at(++idx)->value + teamColor;

    // Initializing the knights: 'b8', 'g8'
    board[bottomRow][firstColumn + knightColumn] = pieces.at(++idx)->value + teamColor;
    board[bottomRow][lastColumn - knightColumn] = pieces.at(++idx)->value + teamColor;

    // Initializing the bishops: 'c8', 'f8'
    board[bottomRow][firstColumn + bishopColumn] = pieces.at(++idx)->value + teamColor;
    board[bottomRow][lastColumn - bishopColumn] = pieces.at(++idx)->value + teamColor;

    // Initializing the queen: 'd8'
    board[bottomRow][firstColumn + royaltyColumn] = pieces.at(++idx)->value + teamColor;

    // Initializing the king: 'e8'
    board[bottomRow][lastColumn - royaltyColumn] = pieces.at(++idx)->value + teamColor;

}

void Board::populateMask() {

}

int** Board::getBoard() const { return board; }

int** Board::getMask() const { return mask; }