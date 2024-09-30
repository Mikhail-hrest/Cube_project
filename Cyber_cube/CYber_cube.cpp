#include "CYber_cube.h"

/*
===============================================
#               ____                          #
#    |  / \  / |___  |  | |  /                #
#    |<    \/  |   \ | /| |<                  #
#    |  \  /   |___/ |/ | |  \                #
#     __        ____                          #
#    |  \ \  / |___  |  | |  /   /\           #
#    |__/  \/  |   \ | /| |<    /__\          #
#    |     /   |___/ |/ | |  \ /    \         #
#                                             #
#              _________                      #
#             /__/__/__/|                     #
#            /__/__/__/||                     #
#           /__/__/__/|||                     #
#           |__|__|__||||                     #
#           |__|__|__||/                      #
#           |__|__|__|/                       #
#                                             #
#   Khristoforov MA                           #
#   Khristoforov VA                           #
===============================================

представление граней в виде вектора
    0   1   2
    3   4   5
    6   7   8
*/


FaceOfCube::FaceOfCube(bool is_asm, char clr){
    matr.reserve(9);
    if(!is_asm){
        for(size_t i = 0; i < 9; ++i){
            char c;
            std::cin >> c;
            matr.push_back(c);
        }
    }else{
        for(size_t i = 0; i < 9; ++i){
            matr.push_back(clr);
        }
    }
}

char FaceOfCube::get_center() {return matr[4];}

char FaceOfCube::get_color(size_t index) {
    if(index > 8) return char(0);
    return matr[index];
}

FaceOfCube* FaceOfCube::get_ptr(char direction){
    switch(direction){
        case 'u': return _up;
        case 'r': return _right;
        case 'l': return _left;
        case 'd': return _down;
    }
}

void FaceOfCube::set_ptr(char direction, FaceOfCube* ptr){
    switch(direction){
        case 'u':{
            _up = ptr;
            return ;
        }
        case 'r':{
            _right = ptr;
            return ;
        }
        case 'l':{
            _left = ptr;
            return ;
        }
        case 'd':{
            _down = ptr;
            return ;
        }
    }
}

void FaceOfCube::set_color(size_t position, char color){
    matr[position] = color;
}

void FaceOfCube::set_colors(std::vector<char> new_colors){
    matr.clear();
    matr = new_colors;
}

void FaceOfCube::clockwise_rotation(){
    std::vector<char> buf = matr;
    matr[0] = buf[6];
    matr[1] = buf[3];
    matr[2] = buf[0];
    matr[3] = buf[7];
    matr[5] = buf[1];
    matr[6] = buf[8];
    matr[7] = buf[5];
    matr[8] = buf[2];
    std::vector<char> up;
    std::vector<char> right;
    std::vector<char> left;
    std::vector<char> down;

    if(matr[4] == 'y'){
        for(size_t i = 0; i < 3; ++i){
            up.push_back(_up->matr[i]);
            right.push_back(_right->matr[i]);
            left.push_back(_left->matr[i]);
            down.push_back(_down->matr[i]);
        }
        for(size_t i = 0; i < 3; ++i){
            _up->matr[i] = left[i];//
            _right->matr[i] = up[i];//
            _left->matr[i] = down[i];//
            _down->matr[i] = right[i];//
        }
    }
    if(matr[4] == 'b'){
        for(size_t i = 0; i < 3; ++i){
            up.push_back(_up->matr[6+i]);
            right.push_back(_right->matr[i*3]);
            left.push_back(_left->matr[i*3+2]);
            down.push_back(_down->matr[i]);
        }
        for(size_t i = 0; i < 3; ++i){
            _up->matr[i+6] = left[2-i];//
            _right->matr[i*3] = up[i];//
            _left->matr[i*3+2] = down[i];//
            _down->matr[i] = right[2-i];//
        }
    }
    if(matr[4] == 'r'){
        for(size_t i = 0; i < 3; ++i){
            up.push_back(_up->matr[2+3*i]);
            right.push_back(_right->matr[3*i]);
            left.push_back(_left->matr[3*i+2]);
            down.push_back(_down->matr[3*i+2]);
        }
        for(size_t i = 0; i < 3; ++i){
            _up->matr[3*i+2] = left[i];
            _right->matr[i*3] = up[2-i];
            _left->matr[i*3+2] = down[i];
            _down->matr[i*3+2] = right[2-i];
        }
    }
    if(matr[4] == 'o'){
        for(size_t i = 0; i < 3; ++i){
            up.push_back(_up->matr[i*3]);
            right.push_back(_right->matr[i*3]);
            left.push_back(_left->matr[i*3+2]);
            down.push_back(_down->matr[i*3]);
        }
        for(size_t i = 0; i < 3; ++i){
            _up->matr[i*3] = left[2-i];
            _right->matr[i*3] = up[i];
            _left->matr[i*3+2] = down[2-i];
            _down->matr[i*3] = right[i];
        }
    }
    if(matr[4] == 'g'){
        for(size_t i = 0; i < 3; ++i){
            up.push_back(_up->matr[i]);
            right.push_back(_right->matr[i*3]);
            left.push_back(_left->matr[i*3+2]);
            down.push_back(_down->matr[6+i]);
        }
        for(size_t i = 0; i < 3; ++i){
            _up->matr[i] = left[i];
            _right->matr[i*3] = up[2-i];
            _left->matr[i*3+2] = down[2-i];
            _down->matr[i+6] = right[i];
        }
    }
    if(matr[4] == 'w'){
        for(size_t i = 0; i < 3; ++i){
            up.push_back(_up->matr[6+i]);
            right.push_back(_right->matr[6+i]);
            left.push_back(_left->matr[6+i]);
            down.push_back(_down->matr[6+i]);
        }
        for(size_t i = 0; i < 3; ++i){
            _up->matr[6+i] = left[i];
            _right->matr[6+i] = up[i];
            _left->matr[6+i] = down[i];
            _down->matr[6+i] = right[i];
        }
    }
    up.clear();
    right.clear();
    left.clear();
    down.clear();
    buf.clear();
}

void FaceOfCube::counterclockwise_rotation(){
    std::vector<char> buf = matr;
    matr[0] = buf[2];
    matr[1] = buf[5];
    matr[2] = buf[8];
    matr[3] = buf[1];
    matr[5] = buf[7];
    matr[6] = buf[0];
    matr[7] = buf[3];
    matr[8] = buf[6];
    std::vector<char> up;
    std::vector<char> right;
    std::vector<char> left;
    std::vector<char> down;
    if(matr[4] == 'y'){
        for(size_t i = 0; i < 3; ++i){
            up.push_back(_up->matr[i]);
            right.push_back(_right->matr[i]);
            left.push_back(_left->matr[i]);
            down.push_back(_down->matr[i]);
        }
        for(size_t i = 0; i < 3; ++i){
            _up->matr[i] = right[i];//
            _right->matr[i] = down[i];//
            _left->matr[i] = up[i];//
            _down->matr[i] = left[i];//
        }
    }
    if(matr[4] == 'b'){
        for(size_t i = 0; i < 3; ++i){
            up.push_back(_up->matr[6+i]);
            right.push_back(_right->matr[i*3]);
            left.push_back(_left->matr[i*3+2]);
            down.push_back(_down->matr[i]);
        }
        for(size_t i = 0; i < 3; ++i){
            _up->matr[i+6] = right[i];//
            _right->matr[i*3] = down[2-i];//
            _left->matr[i*3+2] = up[2-i];//
            _down->matr[i] = left[i];//
        }
    }
    if(matr[4] == 'r'){
        for(size_t i = 0; i < 3; ++i){
            up.push_back(_up->matr[2+3*i]);
            right.push_back(_right->matr[3*i]);
            left.push_back(_left->matr[3*i+2]);
            down.push_back(_down->matr[3*i+2]);
        }
        for(size_t i = 0; i < 3; ++i){
            _up->matr[3*i+2] = right[2-i];
            _right->matr[i*3] = down[2-i];
            _left->matr[i*3+2] = up[i];
            _down->matr[i*3+2] = left[i];
        }
    }
    if(matr[4] == 'o'){
        for(size_t i = 0; i < 3; ++i){
            up.push_back(_up->matr[i*3]);
            right.push_back(_right->matr[i*3]);
            left.push_back(_left->matr[i*3+2]);
            down.push_back(_down->matr[i*3]);
        }
        for(size_t i = 0; i < 3; ++i){
            _up->matr[i*3] = right[i];
            _right->matr[i*3] = down[i];
            _left->matr[i*3+2] = up[2-i];
            _down->matr[i*3] = left[2-i];
        }
    }
    if(matr[4] == 'g'){
        for(size_t i = 0; i < 3; ++i){
            up.push_back(_up->matr[i]);
            right.push_back(_right->matr[i*3]);
            left.push_back(_left->matr[i*3+2]);
            down.push_back(_down->matr[6+i]);
        }
        for(size_t i = 0; i < 3; ++i){
            _up->matr[i] = right[2-i];
            _right->matr[i*3] = down[i];
            _left->matr[i*3+2] = up[i];
            _down->matr[i+6] = left[2-i];
        }
    }
    if(matr[4] == 'w'){
        for(size_t i = 0; i < 3; ++i){
            up.push_back(_up->matr[6+i]);
            right.push_back(_right->matr[6+i]);
            left.push_back(_left->matr[6+i]);
            down.push_back(_down->matr[6+i]);
        }
        for(size_t i = 0; i < 3; ++i){
            _up->matr[6+i] = right[i];
            _right->matr[6+i] = down[i];
            _left->matr[6+i] = up[i];
            _down->matr[6+i] = left[i];
        }
    }
    up.clear();
    right.clear();
    left.clear();
    down.clear();
    buf.clear();
}

//возможно не нужен
void FaceOfCube::double_rotation(){
    clockwise_rotation();
    clockwise_rotation();
}

RubicsCube::RubicsCube(bool is_asm){
    std::cout << "Enter Yellow face:\n"; 
    Yellow = new FaceOfCube(is_asm, 'y');
    std::cout << "Enter White face:\n";
    White = new FaceOfCube(is_asm);
    std::cout << "Enter Red face:\n";
    Red = new FaceOfCube(is_asm, 'r');
    std::cout << "Enter Blue face:\n";
    Blue = new FaceOfCube(is_asm, 'b');
    std::cout << "Enter Green face:\n";
    Green = new FaceOfCube(is_asm, 'g');
    std::cout << "Enter Orange face:\n";
    Orange = new FaceOfCube(is_asm, 'o');

    //пусть фронтальная грань - синяя
    Yellow->set_ptr('u', Green);
    Yellow->set_ptr('r', Red);
    Yellow->set_ptr('d', Blue);
    Yellow->set_ptr('l', Orange);

    Blue->set_ptr('u',Yellow);
    Blue->set_ptr('r',Red);
    Blue->set_ptr('d',White);
    Blue->set_ptr('l',Orange);

    Red->set_ptr('u',Yellow);
    Red->set_ptr('r',Green);
    Red->set_ptr('d',White);
    Red->set_ptr('l',Blue);

    Green->set_ptr('u',Yellow);
    Green->set_ptr('r',Orange);
    Green->set_ptr('d',White);
    Green->set_ptr('l',Red);

    Orange->set_ptr('u',Yellow);
    Orange->set_ptr('r',Blue);
    Orange->set_ptr('d',White);
    Orange->set_ptr('l',Green);

    White->set_ptr('u',Blue);
    White->set_ptr('r',Red);
    White->set_ptr('d',Green);
    White->set_ptr('l',Orange);
};


//пусть alf = "N", alf' = "n"
void RubicsCube::move(char c){
    switch(c){
        case 'r':
            Red->counterclockwise_rotation();
            break;
        case 'R':
            Red->clockwise_rotation();
            break;
        case 'l':
            Orange->counterclockwise_rotation();
            break;
        case 'L':
            Orange->clockwise_rotation();
            break;
        case 'b':
            Green->counterclockwise_rotation();
            break;
        case 'B':
            Green->clockwise_rotation();
            break;
        case 'f':
            Blue->counterclockwise_rotation();
            break;
        case 'F':
            Blue->clockwise_rotation();
            break;
        case 'u':
            Yellow->counterclockwise_rotation();
            break;
        case 'U':
            Yellow->clockwise_rotation();
            break;
        case 'd':
            White->counterclockwise_rotation();
            break;
        case 'D':
            White->clockwise_rotation();
            break;
        default:
            break;
    }
}