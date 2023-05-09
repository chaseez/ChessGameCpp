//
// Created by chaseez on 5/9/2023.
//

#ifndef CHESSGAMECPP_PIECE_H
#define CHESSGAMECPP_PIECE_H

enum PieceValue {
    PAWN=1,
    ROOK=3,
    KNIGHT=5,
    BISHOP=7,
    QUEEN=9,
    KING=-1
};

enum Color {
    BLACK=1,
    WHITE=0
};

class Piece {
public:
    PieceValue value;
    Color color;
    virtual void move();
    virtual void take();
    virtual void checkForCheck();
};


#endif //CHESSGAMECPP_PIECE_H
