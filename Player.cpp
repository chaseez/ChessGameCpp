//
// Created by chaseez on 5/9/2023.
//

#include "Player.h"


void Player::fillPieces() {
    for(int i = 0; i < NUM_PIECES; ++i) {
        if(i < 8) pieces[i] = new Pawn(team);
        if(i >= 8 and i < 10) pieces[i] = new Rook(team);
        if(i >= 10 and i < 12) pieces[i] = new Knight(team);
        if(i >= 12 and i < 14) pieces[i] = new Bishop(team);
        if(i == 14) pieces[i] = new Queen(team);
        if(i == 15) pieces[i] = new King(team);
//        std::cout << i << std::endl;
//        pieces[i]->showMoves();
//        pieces[i]->move();
//        pieces[i]->take();
//        pieces[i]->checkForCheck();
    }
}

std::vector<Piece*> Player::getPieces() const { return pieces; }

bool Player::inCheck() const {

}

