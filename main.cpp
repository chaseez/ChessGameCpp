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

void validateInput(std::string& coord) {
    bool invalid = true;
    if(coord.length() != 2) invalid = false;

    while(!invalid) {
        std::cout << "\nInvalid input" << std::endl;
        std::cout << "Please enter in the coordinate format like: 'a4'" << std::endl;
        coord = promptUser();
        if(coord.length() != 2) continue;

        invalid = true;
    }

    // Making the ascii numbers correspond with a column
    int letter = std::tolower(coord[0]) - 'a';

    // Adjusting the number to fit the array index
    std::string temp = coord.substr(1);
    int number = std::stoi(temp) - 1;

    if(letter < 0 or letter >= 8) invalid = false;
    if(number < 0 or number >= 8) invalid = false;

    while(!invalid) {
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

        invalid = true;
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

    while(!winning)
    {
        std::string coordinates;
        coordinates = promptUser();

        validateInput(coordinates);



        turn = !turn;
        winning = true;
    }

    return 0;
}
