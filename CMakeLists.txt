cmake_minimum_required(VERSION 3.25)
project(ChessGameCpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(ChessGameCpp main.cpp Piece.h Pawn.cpp Pawn.h Player.cpp Player.h Knight.cpp Knight.h Rook.cpp Rook.h Bishop.cpp Bishop.h Queen.cpp Queen.h King.cpp King.h)
