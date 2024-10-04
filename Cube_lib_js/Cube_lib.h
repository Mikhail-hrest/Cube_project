#pragma once
#ifndef _CUBE_LIB_H_
#define _CUBE_LIB_H_
#include "../Cyber_cube/Algorithms.h"

std::string do_move(std::string start_state, char mv){
    RubicsCube A(true, start_state);
    A.move(mv);
    return A.get_state();
}

#endif