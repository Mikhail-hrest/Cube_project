#pragma once
#ifndef _CYBER_CUBE_H_
#define _CYBER_CUBE_H_

#include <vector>
#include <string>
#include <regex>
#include <iostream>
#include <ostream>

/*
#d класс грани
*/
class FaceOfCube{
    /*
    #d вектор цветов от верхнего левого угла до нижнего правого
    */
    std::vector<char> matr;
    FaceOfCube* _up = nullptr;
    FaceOfCube* _right = nullptr;
    FaceOfCube* _left = nullptr;
    FaceOfCube* _down = nullptr;
public:
    /*
    #d конструктор поумолчанию
    */
    FaceOfCube(bool is_asm = false, char clr = 'w');// done

    /*
    #d установка значений в вектор цветов
    */
    void set_colors(std::vector<char> new_colors);// done

    /*
    #d установка цвета в определенную позицию
    */
    void set_color(size_t position, char color);// done

    /*
    #d получить цвет центра
    #r char - буквунный символ цвета
    */
    char get_center();// done

    /*
    #d выдает цвет по индексу
    #r возвращает цвет
    */
    char get_color(size_t index);
    /*
    #d выдает указатель на грань заданную направлением буквой u/r/l/d
    #r указатель на класс грани
    */
    FaceOfCube* get_ptr(char direction);// done

    /*
    #d устанавливает в направление заданное одной из букв u/r/l/d указатель на соответствующую грань
    */
    void set_ptr(char direction, FaceOfCube* ptr);// done

    /*
    #d поворот по часовой стрелке
    */
    void clockwise_rotation();// done not all

    /*
    #d поворот против часовой стрелке
    */
    void counterclockwise_rotation();// done not all

    /*
    #d двойной поворот
    */
   void double_rotation();// done not all

    /*
    #d перегрузка оператора вывода для грани
    #r поток с удобным видом на матрицу
    */
   friend std::ostream& operator << (std::ostream& s, const FaceOfCube& r){
        for(size_t i = 0; i < 9; ++i){
            s << r.matr[i] << " ";
            if(i == 2 || i == 5 || i == 8) s << '\n';
        }
        return s;
   }
};


/*
#d класс для кубика
*/
class RubicsCube{
public:
    // грани куба, 6 шт
    FaceOfCube* Yellow;
    FaceOfCube* White;
    FaceOfCube* Red;
    FaceOfCube* Blue;
    FaceOfCube* Green;
    FaceOfCube* Orange;
    /*
    #d конструктор, он же и поумолчанию
    #b is_asm - готовое состояние, т.е. собранная головоломка
    */
    RubicsCube(bool is_asm = false);
    
    /*
    #d деструктор
    */
    ~RubicsCube(){
        delete Yellow;
        delete White;
        delete Blue;
        delete Red;
        delete Green;
        delete Orange;
    }
    
    /*
    #d реализация простейших действий алфавита кубика-рубика
    */
    void move(char c);

    friend std::ostream& operator << (std::ostream& s, const RubicsCube& r){
        s << "       " << r.Yellow->get_color(0) << " " << r.Yellow->get_color(1) << " " << r.Yellow->get_color(2) << '\n'
          << "       " << r.Yellow->get_color(3) << " " << r.Yellow->get_color(4) << " " << r.Yellow->get_color(5) << '\n'
          << "       " << r.Yellow->get_color(6) << " " << r.Yellow->get_color(7) << " " << r.Yellow->get_color(8) << "\n\n"
          << r.Orange->get_color(0) << " " << r.Orange->get_color(1) << " " << r.Orange->get_color(2) << "  " <<  r.Blue->get_color(0) << " " << r.Blue->get_color(1) << " " << r.Blue->get_color(2)
          << "  " << r.Red->get_color(0) << " " << r.Red->get_color(1) << " " << r.Red->get_color(2) << '\n'
          << r.Orange->get_color(3) << " " << r.Orange->get_color(4) << " " << r.Orange->get_color(5) << "  " <<  r.Blue->get_color(3) << " " << r.Blue->get_color(4) << " " << r.Blue->get_color(5)
          << "  " << r.Red->get_color(3) << " " << r.Red->get_color(4) << " " << r.Red->get_color(5) << '\n'
          << r.Orange->get_color(6) << " " << r.Orange->get_color(7) << " " << r.Orange->get_color(8) << "  " <<  r.Blue->get_color(6) << " " << r.Blue->get_color(7) << " " << r.Blue->get_color(8)
          << "  " << r.Red->get_color(6) << " " << r.Red->get_color(7) << " " << r.Red->get_color(8) << "\n\n"
          << "       " << r.White->get_color(0) << " " << r.White->get_color(1) << " " << r.White->get_color(2) << '\n'
          << "       " << r.White->get_color(3) << " " << r.White->get_color(4) << " " << r.White->get_color(5) << '\n'
          << "       " << r.White->get_color(6) << " " << r.White->get_color(7) << " " << r.White->get_color(8) << "\n\n"
          << "       " << r.Green->get_color(8) << " " << r.Green->get_color(7) << " " << r.Green->get_color(6) << '\n'
          << "       " << r.Green->get_color(5) << " " << r.Green->get_color(4) << " " << r.Green->get_color(3) << '\n'
          << "       " << r.Green->get_color(2) << " " << r.Green->get_color(1) << " " << r.Green->get_color(0) << '\n';
          
        return s; 
    }
};


#endif 