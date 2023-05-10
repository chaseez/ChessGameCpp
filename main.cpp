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

void validateInput(std::string& coord, const Board& board, bool turn) {
    bool valid = true;
    if(coord.length() != 2) valid = false;

    // Making the ascii numbers correspond with a column
    int letter = std::tolower(coord[0]) - 'a';

    // Adjusting the number to fit the array index
    std::string temp = coord.substr(1);
    int number = std::stoi(temp) - 1;

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

    int pieceType = board.getBoard()[number][letter];

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
        std::string coordinates;
        coordinates = promptUser();

        validateInput(coordinates, board, turn);


        if(!turn) winning = true;

        turn = !turn;
    }

    return 0;
}
