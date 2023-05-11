#include <iostream>
#include "Piece.h"
#include "Player.h"
#include "Board.h"

std::string promptUser() {
    std::cout << "\nPick a piece to move: ";
    std::string coordinates;
    std::cin >> coordinates; // Input example: 'a4' or 'A4'
    return coordinates;
}

std::string parseCoordinates(const std::string& coordinates) {
    // Making the ascii numbers correspond with a column
    int letter = std::tolower(coordinates[0]) - 'a';

    // Adjusting the number to fit the array index
    std::string temp = coordinates.substr(1);
    int number = std::stoi(temp) - 1;

    return std::to_string(letter) + std::to_string(number);
}

void validateInput(std::string& coord, const Board& board, bool turn) {
    bool valid = true;
    if(coord.length() != 2) valid = false;

    std::string temp = parseCoordinates(coord);

    std::string colStr = temp.substr(0,1);
    int letter = std::stoi(colStr);

    std::string rowStr = temp.substr(1);
    int number = std::stoi(rowStr);

    if(letter < 0 or letter >= 8) valid = false;
    if(number < 0 or number >= 8) valid = false;

    while(!valid) {
        std::cout << "\nInvalid input" << std::endl;
        std::cout << "Please choose a coordinate on the board between 'a'-'f' and 1-8" << std::endl;
        coord = promptUser();
        if(coord.length() != 2) continue;

        // Making the ascii numbers correspond with a column
        letter = std::tolower(coord[0]) - 'a';

        // Adjusting the number to fit the array index
        temp = coord.substr(1);
        number = std::stoi(temp) - 1;

        if(letter < 0 or letter >= 8) continue;
        if(number < 0 or number >= 8) continue;

        valid = true;
    }

    int** tempBoard = board.getBoard();

    int pieceType = tempBoard[number][letter];

    // true == White's turn
    // false == Black's turn
    if(turn) {
        if(pieceType == 1 or pieceType == 3 or pieceType == 5 or pieceType == 7 or pieceType == 9 or pieceType == -2); // White's piece values
        else valid = false;
    }
    else {
        if(pieceType == 2 or pieceType == 4 or pieceType == 6 or pieceType == 8 or pieceType == 10 or pieceType == -1); // Black's piece values
        else valid = false;
    }

    if(!valid) {
        while(!valid) {
            std::cout << "\nInvalid input" << std::endl;
            std::cout << "That's not your piece" << std::endl;
            coord = promptUser();
            if(coord.length() != 2) continue;

            // Making the ascii numbers correspond with a column
            letter = std::tolower(coord[0]) - 'a';

            // Adjusting the number to fit the array index
            temp = coord.substr(1);
            number = std::stoi(temp) - 1;

            if(letter < 0 or letter >= 8) continue;
            if(number < 0 or number >= 8) continue;

            pieceType = board.getBoard()[number][letter];

            // true == White's turn
            // false == Black's turn
            if(turn) {
                if(pieceType == 1 or pieceType == 3 or pieceType == 5 or pieceType == 7 or pieceType == 9 or pieceType == -2) valid = true;
                else continue;
            }
            else {
                if(pieceType == 2 or pieceType == 4 or pieceType == 6 or pieceType == 8 or pieceType == 10 or pieceType == -1) valid = true;
                else continue;
            }
        }
    }

}

bool canMovePiece(const std::string& coordinates, Board board, const std::vector<Piece*>& pieces) {
    std::string parsedCoords = parseCoordinates(coordinates);

    std::string colStr = parsedCoords.substr(0,1);
    int col = std::stoi(colStr);

    std::string rowStr = parsedCoords.substr(1);
    int row = std::stoi(rowStr);

    int pieceValue = board.getBoard()[row][col];

    for(Piece* piece: pieces) {
        if(piece->value == pieceValue - piece->team) {
            if(piece->getRow() == row and piece->getColumn() == col) return board.canMovePiece(piece);
        }
    }

    return false;
}


int main() {
    Player white = Player(WHITE);
    Player black = Player(BLACK);

    Board board = Board();
    board.populateBoard(white, black);

    board.printBoard();

    bool winning = false;
    bool turn = true;

    // true == White's turn
    // false == Black's turn
    while(!winning)
    {
        if(turn) std::cout << "White's";
        else std::cout <<"Black's";
        std::cout << " turn";

        std::string coordinates;
        coordinates = promptUser();

        validateInput(coordinates, board, turn);

        if(turn) {
            bool movable = canMovePiece(coordinates, board, white.getPieces());

            board.printBoard();
            while(!movable) {
                std::cout << "You can't move that piece" << std::endl;
                coordinates = promptUser();
                validateInput(coordinates, board, turn);
                movable = canMovePiece(coordinates, board, white.getPieces());
            }

            // Show the possible moves keeping Check in mind

            // Validate where the piece moves

            // Confirm if they want to move there

            // Update board and mask
        }
        else {
            bool movable = canMovePiece(coordinates, board, black.getPieces());

            board.printBoard();
            while(!movable) {
                std::cout << "You can't move that piece" << std::endl;
                coordinates = promptUser();
                validateInput(coordinates, board, turn);
                movable = canMovePiece(coordinates, board, black.getPieces());
            }

            // Show the possible moves keeping Check in mind

            // Validate where the piece moves

            // Confirm if they want to move there

            // Update board and mask
        }

        if(!turn) winning = true;

        turn = !turn;
    }

    return 0;
}
