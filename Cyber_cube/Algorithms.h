#pragma once
#ifndef _ALGORITHMS_H_
#define _ALGORITHMS_H_

#include "CYber_cube.h"
#include <string>


/*
    Данная программа собирает кубик Рубика методом Фридрих
    
    цвета грани определяются центральным элементом
    Y - желтый цвет
    B - синий цвет
    R - красный цвет
    O - оранжевый цвет
    G - зеленый цвеь
    W - белый цвет

    Существует специальный алфавит, описывающий алгоритмы данной головоломки
        Большая буква (предположим N) - поворот грани по часовой стрелке.
        Большая буква со штрихом (предположим N`) - поворот грани против часовой стрелки.
        Большая буква и цифра 2 (предположим F2) - поворот грани два раза. На 180 градусов. 
        Буквы в скобочках умножить на цифру (пример (R L F B)x3) - повторить алгоритм (R L F B) три раза.
        Буква + w (пример Fw) - поворот фронтальной грани со средним слоем. - в программе использоваться не будет
    Пусть alf - буква данного алфавита. Обозначим alf = "N", alf' = "n" чтоб описывать данный алфавит одним символом
    R/r - правая грань
    L/l - левая грань
    F/f - передняя грань
    B/b - задняя грань
    D/d - Нижняя грань
    U/u - передняя грань
    
    ________________________________________________________________
    cross - сборка "правильного креста" на белой грани
    пример "правильного креста на белой стороне" в развертке кубика
            _____
           |_|_|_|
           |_|Y|_|
           |_|_|_|
    _____   _____   _____
   |_|_|_| |_|_|_| |_|_|_|
   |_|O|_| |_|B|_| |_|R|_|
   |_|O|_| |_|B|_| |_|R|_|
            _____
           |_|W|_|
           |W|W|W|
           |_|W|_|
            _____
           |_|G|_|
           |_|G|_|
           |_|_|_|

    
    
    ________________________________________________________________
    F2L - сборка полностью двух нижних слоев кубика
    В данной программе делится еще на два этапа:
        1) подбор боковых ребер
                 _____
                |_|_|_|
                |_|Y|_|
                |_|_|_|
         _____   _____   _____
        |_|_|_| |_|_|_| |_|_|_|
        |O|O|O| |B|B|B| |R|R|R|
        |_|O|_| |_|B|_| |_|R|_|
                 _____
                |_|W|_|
                |W|W|W|
                |_|W|_|
                 _____
                |_|G|_|
                |G|G|G|
                |_|_|_|

        2) подстановка углов на свои места в правильное положение
                 _____
                |_|_|_|
                |_|Y|_|
                |_|_|_|
         _____   _____   _____
        |_|_|_| |_|_|_| |_|_|_|
        |O|O|O| |B|B|B| |R|R|R|
        |O|O|O| |B|B|B| |R|R|R|
                 _____
                |W|W|W|
                |W|W|W|
                |W|W|W|
                 _____
                |G|G|G|
                |G|G|G|
                |_|_|_|
    
    ________________________________________________________________
    OLL - сборка верхнего слоя до полностью желтой шапки
    Ради упрощения алгоритма и уменьшения затрат на память, используется
    ограниченное количество формул: "Галка", "Палка", и 2 "Рыбки"(левая и правая)
    Также проводится в два этапа: 1 - сборка креста при виде сверху
                                  2 - полностью собранный желтый квадрат

        1) Галка:
                 _____                                     _____
                |_|Y|_|                                   |_|Y|_|
                |Y|Y|_|    -   F R u r u R U r f  ==>     |Y|Y|Y|
                |_|_|_|                                   |_|Y|_|

        2) Палка:
                 _____                                     _____
                |_|_|_|                                   |_|Y|_|
                |Y|Y|Y|    -   R U r u r F R f    ==>     |Y|Y|Y|
                |_|_|_|                                   |_|Y|_|
        
*/



class PuzzleSolver{
    bool find_white(size_t lvl);
    bool find_yellow();
    bool wrong = false;
public:
    RubicsCube* rubic = nullptr;
    /*
    #d конструктор-полумолчанию
    */
    PuzzleSolver() : rubic(new RubicsCube()) {};
    PuzzleSolver(bool flag) : rubic(new RubicsCube(flag)){
        char s;
        std::cin >> s;
        while(std::cin.good() && !std::cin.eof()){
            if(s != 'R' && s != 'L' && s != 'U' && s != 'D' && s != 'F' && s != 'B' &&
                s != 'r' && s != 'l' && s != 'u' && s != 'd' && s != 'f' && s != 'b'){
                wrong = true;
                break;
            }
            rubic->move(s);
            std::cin >> s;
        }
        std::cin.ignore();
    }
    ~PuzzleSolver() {
        delete rubic;
    }

    std::string puzzle_solution();

    std::string get_algorithm_cross();
    std::string get_algorithm_F2L();
    std::string get_algorithm_OLL();
    std::string get_algorithm_PLL();

    std::string optimization_of_the_result(std::string prev);

    std::string get_state();

};



#endif