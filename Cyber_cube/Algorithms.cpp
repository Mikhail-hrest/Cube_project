#include "Algorithms.h"


bool PuzzleSolver::find_white(size_t lvl){
    if(lvl == 1){
        return rubic->White->get_color(1) == 'w' || rubic->White->get_color(3) == 'w' ||
                rubic->White->get_color(5) == 'w' || rubic->White->get_color(7) == 'w' ||
                rubic->Blue->get_color(7) == 'w' || rubic->Red->get_color(7) == 'w' ||
                rubic->Orange->get_color(7) == 'w' || rubic->Green->get_color(7) == 'w';
    }else if(lvl == 2){
        return rubic->Blue->get_color(3) == 'w' ||rubic->Blue->get_color(5) == 'w' ||
                rubic->Red->get_color(3) == 'w' ||rubic->Red->get_color(5) == 'w' ||
                rubic->Green->get_color(3) == 'w' ||rubic->Green->get_color(5) == 'w' ||
                rubic->Orange->get_color(3) == 'w' ||rubic->Orange->get_color(5) == 'w';
    }
}

bool PuzzleSolver::find_yellow(){
    return rubic->Yellow->get_color(1) == 'y' || rubic->Yellow->get_color(3) == 'y' ||
                rubic->Yellow->get_color(5) == 'y' || rubic->Yellow->get_color(7) == 'y' ||
                rubic->Blue->get_color(1) == 'y' || rubic->Red->get_color(1) == 'y' ||
                rubic->Orange->get_color(1) == 'y' || rubic->Green->get_color(1) == 'y';
}

std::string PuzzleSolver::get_algorithm_cross(){
    std::cout << *rubic <<"\nRunning cross...\n";
    std::string result = "";
    
    for(size_t cnt = 0; cnt < 4;++cnt){
        if(find_white(2)){
            while(rubic->Yellow->get_color(3) == 'w' || rubic->Orange->get_color(1) == 'w'){
                rubic->move('U');
                result = result + "U";
            }
            rubic->move('l');
            result = result + "l";
        }
    }
    for(size_t cnt = 0; cnt < 4;++cnt){
        if(find_white(2)){
            while(rubic->Yellow->get_color(5) == 'w' || rubic->Red->get_color(1) == 'w'){
                rubic->move('U');
                result = result + "U";
            }
            rubic->move('R');
            result = result + "R";
        }
    }
    for(size_t cnt = 0; cnt < 4; ++cnt){
        if(find_white(1)){
            while(rubic->Yellow->get_color(7) == 'w' || rubic->Blue->get_color(1) == 'w'){
                rubic->move('U');
                result = result + "U";
            }
            rubic->move('F');
            rubic->move('F');
            result = result + "FF";
        }
        rubic->move('d');
        result = result + "d";
    }
    // F u R U
    for(size_t i = 0; i < 4; ++i){
        if(rubic->Blue->get_color(1) == 'w'){
            rubic->move('F');
            rubic->move('u');
            rubic->move('R');
            rubic->move('U');
            result = result + "FuRU";
        }
        rubic->move('U');
        result = result + "U";
    }
    
    while(rubic->Blue->get_color(1) != 'r'){
        rubic->move('U');
        result = result + "U";
    }
    rubic->move('F');
    rubic->move('F');
    rubic->move('d');
    result = result + "FFd";

    while(rubic->Blue->get_color(1) != 'g' || rubic->Yellow->get_color(7) != 'w'){
        rubic->move('U');
        result = result + "U";
    }
    rubic->move('F');
    rubic->move('F');
    rubic->move('d');
    result = result + "FFd";

    while(rubic->Blue->get_color(1) != 'o' || rubic->Yellow->get_color(7) != 'w'){
        rubic->move('U');
        result = result + "U";
    }
    rubic->move('F');
    rubic->move('F');
    rubic->move('d');
    result = result + "FFd";
    
    while(rubic->Blue->get_color(1) != 'b' || rubic->Yellow->get_color(7) != 'w'){
        rubic->move('U');
        result = result + "U";
    }
    rubic->move('F');
    rubic->move('F');
    result = result + "FF";


    return result;
};


/*
    сразу можно исключить проверку нижнего слоя на наличие боковых ребер,
    останется только проверить всего восемь позиций по 2 цвета
    можно сделать так: поставить в бока все грани с желтым цветом,
    тогда нужные элементы будут наверху
*/
std::string PuzzleSolver::get_algorithm_F2L(){
    std::cout << *rubic <<"\nRunning f2l...\n";
    std::string result = "";
    while(find_yellow()){
        if(rubic->Blue->get_color(3) != 'y' && rubic->Orange->get_color(5) != 'y'){
            while(rubic->Blue->get_color(1) != 'y' && rubic->Yellow->get_color(7) != 'y'){
                rubic->move('U');
                result = result + "U";
            }
            rubic->move('l');
            rubic->move('U');
            rubic->move('L');
            result = result + "lUL";
        }else if(rubic->Orange->get_color(3) != 'y' && rubic->Green->get_color(5) != 'y'){
            while(rubic->Orange->get_color(1) != 'y' && rubic->Yellow->get_color(3) != 'y'){
                rubic->move('U');
                result = result + "U";
            }
            rubic->move('b');
            rubic->move('U');
            rubic->move('B');
            result = result + "bUB";
        }else if(rubic->Green->get_color(3) != 'y' && rubic->Red->get_color(5) != 'y'){
            while(rubic->Green->get_color(1) != 'y' && rubic->Yellow->get_color(1) != 'y'){
                rubic->move('U');
                result = result + "U";
            }
            rubic->move('r');
            rubic->move('U');
            rubic->move('R');
            result = result + "rUR";
        }else{
            while(rubic->Red->get_color(1) != 'y' && rubic->Yellow->get_color(5) != 'y'){
                rubic->move('U');
                result = result + "U";
            }
            rubic->move('f');
            rubic->move('U');
            rubic->move('F');
            result = result + "fUF";
        }
    }
    for(size_t i = 0; i < 2; ++ i){
        while((rubic->Blue->get_color(1) != 'b' && rubic->Yellow->get_color(7) != 'b') || rubic->Blue->get_color(1) == 'y' || rubic->Yellow->get_color(7) == 'y'){
            rubic->move('U');
            result = result + "U";
        }
        if(rubic->Blue->get_color(1) == 'b'){
            if(rubic->Yellow->get_color(7) == 'r'){
                rubic->move('F');
                rubic->move('r');
                rubic->move('f');
                rubic->move('R');
                result = result + "FrfR";
            }else{
                rubic->move('f');
                rubic->move('L');
                rubic->move('F');
                rubic->move('l');
                result = result + "fLFl";
            }
        }else if(rubic->Yellow->get_color(7) == 'b'){
            if(rubic->Blue->get_color(1) == 'r'){
                rubic->move('R');
                rubic->move('u');
                rubic->move('r');
                result = result + "Rur";
            }else{
                rubic->move('l');
                rubic->move('U');
                rubic->move('L');
                result = result + "lUL";
            }
        }
    }
    for(size_t i = 0; i < 2; ++ i){
        while((rubic->Green->get_color(1) != 'g' && rubic->Yellow->get_color(1) != 'g') || (rubic->Green->get_color(1) == 'y' || rubic->Yellow->get_color(1) == 'y')){
            rubic->move('U');
            result = result + "U";
        }
        if(rubic->Green->get_color(1) == 'g'){
            if(rubic->Yellow->get_color(1) == 'r'){
                rubic->move('b');
                rubic->move('R');
                rubic->move('B');
                rubic->move('r');
                result = result + "bRBr";
            }else{
                rubic->move('B');
                rubic->move('l');
                rubic->move('b');
                rubic->move('L');
                result = result + "BlbL";
            }
        }else if(rubic->Yellow->get_color(1) == 'g'){
            if(rubic->Green->get_color(1) == 'r'){
                rubic->move('r');
                rubic->move('U');
                rubic->move('R');
                result = result + "rUR";
            }else{
                rubic->move('L');
                rubic->move('u');
                rubic->move('l');
                result = result + "Lul";
            }
        }
    }
    //на этом этапе собран "экватор" кубика,
    //теперь нужно расставить белые углы поместам
    // все также поднимим все углы с белой стороной на верх
    // std::cout << "\nСoбран экватор" << *rubic;

    for(size_t i = 0; i < 4; ++i){
        if(rubic->Blue->get_color(8) == 'w' || rubic->Red->get_color(6) == 'w' || rubic->White->get_color(2) == 'w'){
            while(rubic->Yellow->get_color(8) == 'w' || rubic->Blue->get_color(2) == 'w' || rubic->Red->get_color(0) == 'w'){
                rubic->move('U');
                result = result + "U";
            }
            rubic->move('R');
            rubic->move('U');
            rubic->move('r');
            rubic->move('u');
            rubic->move('R');
            rubic->move('U');
            rubic->move('r');
            rubic->move('u');
            rubic->move('R');
            rubic->move('U');
            rubic->move('r');
            rubic->move('u');
            result = result + "RUruRUruRUru";
        }
        rubic->move('d');
        result = result + "d";
    }

    while(!((rubic->Blue->get_color(2) == 'w' && rubic->Red->get_color(0) == 'r' && rubic->Yellow->get_color(8) == 'b') ||
            (rubic->Blue->get_color(2) == 'b' && rubic->Red->get_color(0) == 'w' && rubic->Yellow->get_color(8) == 'r') ||
            (rubic->Blue->get_color(2) == 'r' && rubic->Red->get_color(0) == 'b' && rubic->Yellow->get_color(8) == 'w'))){
        rubic->move('U');
        result = result + "U";
    }
    if((rubic->Blue->get_color(2) == 'w' && rubic->Red->get_color(0) == 'r' && rubic->Yellow->get_color(8) == 'b')){
        rubic->move('u');
        rubic->move('R');
        rubic->move('u');
        rubic->move('r');
        rubic->move('u');
        rubic->move('u');
        rubic->move('R');
        rubic->move('u');
        rubic->move('r');
        result = result + "uRuruuRur";
    }else if((rubic->Blue->get_color(2) == 'b' && rubic->Red->get_color(0) == 'w' && rubic->Yellow->get_color(8) == 'r')){
        rubic->move('U');
        rubic->move('R');
        rubic->move('U');
        rubic->move('r');
        rubic->move('u');
        rubic->move('u');
        rubic->move('R');
        rubic->move('U');
        rubic->move('r');
        result = result + "URUruuRUr";
    }else if((rubic->Blue->get_color(2) == 'r' && rubic->Red->get_color(0) == 'b' && rubic->Yellow->get_color(8) == 'w')){
        rubic->move('R');
        rubic->move('U');
        rubic->move('r');
        rubic->move('u');
        rubic->move('R');
        rubic->move('U');
        rubic->move('r');
        rubic->move('u');
        rubic->move('R');
        rubic->move('U');
        rubic->move('r');
        rubic->move('u');
        result = result + "RUruRUruRUru";
    }

    while(!((rubic->Blue->get_color(0) == 'w' && rubic->Orange->get_color(2) == 'o' && rubic->Yellow->get_color(6) == 'b') ||
            (rubic->Blue->get_color(0) == 'b' && rubic->Orange->get_color(2) == 'w' && rubic->Yellow->get_color(6) == 'o') ||
            (rubic->Blue->get_color(0) == 'o' && rubic->Orange->get_color(2) == 'b' && rubic->Yellow->get_color(6) == 'w'))){
        rubic->move('U');
        result = result + "U";
    }
    if((rubic->Blue->get_color(0) == 'w' && rubic->Orange->get_color(2) == 'o' && rubic->Yellow->get_color(6) == 'b')){
        rubic->move('U');
        rubic->move('l');
        rubic->move('U');
        rubic->move('L');
        rubic->move('u');
        rubic->move('u');
        rubic->move('l');
        rubic->move('U');
        rubic->move('L');
        result = result + "UlULuulUL";
    }else if((rubic->Blue->get_color(0) == 'b' && rubic->Orange->get_color(2) == 'w' && rubic->Yellow->get_color(6) == 'o')){
        rubic->move('u');
        rubic->move('l');
        rubic->move('u');
        rubic->move('L');
        rubic->move('u');
        rubic->move('u');
        rubic->move('l');
        rubic->move('u');
        rubic->move('L');
        result = result + "uluLuuluL";
    }else if((rubic->Blue->get_color(0) == 'o' && rubic->Orange->get_color(2) == 'b' && rubic->Yellow->get_color(6) == 'w')){
        rubic->move('l');
        rubic->move('u');
        rubic->move('L');
        rubic->move('U');
        rubic->move('l');
        rubic->move('u');
        rubic->move('L');
        rubic->move('U');
        rubic->move('l');
        rubic->move('u');
        rubic->move('L');
        rubic->move('U');
        result = result + "luLUluLUluLU";
    }

    while(!((rubic->Green->get_color(2) == 'w' && rubic->Orange->get_color(0) == 'o' && rubic->Yellow->get_color(0) == 'g') ||
            (rubic->Green->get_color(2) == 'g' && rubic->Orange->get_color(0) == 'w' && rubic->Yellow->get_color(0) == 'o') ||
            (rubic->Green->get_color(2) == 'o' && rubic->Orange->get_color(0) == 'g' && rubic->Yellow->get_color(0) == 'w'))){
        rubic->move('U');
        result = result + "U";
    }
    if((rubic->Green->get_color(2) == 'w' && rubic->Orange->get_color(0) == 'o' && rubic->Yellow->get_color(0) == 'g')){
        rubic->move('u');
        rubic->move('L');
        rubic->move('u');
        rubic->move('l');
        rubic->move('u');
        rubic->move('u');
        rubic->move('L');
        rubic->move('u');
        rubic->move('l');
        result = result + "uLuluuLul";
    }else if((rubic->Green->get_color(2) == 'g' && rubic->Orange->get_color(0) == 'w' && rubic->Yellow->get_color(0) == 'o')){
        rubic->move('U');
        rubic->move('L');
        rubic->move('U');
        rubic->move('l');
        rubic->move('u');
        rubic->move('u');
        rubic->move('L');
        rubic->move('U');
        rubic->move('l');
        result = result + "ULUluuLUl";
    }else if((rubic->Green->get_color(2) == 'o' && rubic->Orange->get_color(0) == 'g' && rubic->Yellow->get_color(0) == 'w')){
        rubic->move('L');
        rubic->move('U');
        rubic->move('l');
        rubic->move('u');
        rubic->move('L');
        rubic->move('U');
        rubic->move('l');
        rubic->move('u');
        rubic->move('L');
        rubic->move('U');
        rubic->move('l');
        rubic->move('u');
        result = result + "LUluLUluLUlu";
    }


    while(!((rubic->Green->get_color(0) == 'w' && rubic->Red->get_color(2) == 'r' && rubic->Yellow->get_color(2) == 'g') ||
            (rubic->Green->get_color(0) == 'g' && rubic->Red->get_color(2) == 'w' && rubic->Yellow->get_color(2) == 'r') ||
            (rubic->Green->get_color(0) == 'r' && rubic->Red->get_color(2) == 'g' && rubic->Yellow->get_color(2) == 'w'))){
        rubic->move('U');
        result = result + "U";
    }
    if((rubic->Green->get_color(0) == 'w' && rubic->Red->get_color(2) == 'r' && rubic->Yellow->get_color(2) == 'g')){
        rubic->move('U');
        rubic->move('r');
        rubic->move('U');
        rubic->move('R');
        rubic->move('u');
        rubic->move('u');
        rubic->move('r');
        rubic->move('U');
        rubic->move('R');
        result = result + "UrURuurUR";
    }else if((rubic->Green->get_color(0) == 'g' && rubic->Red->get_color(2) == 'w' && rubic->Yellow->get_color(2) == 'r')){
        rubic->move('u');
        rubic->move('r');
        rubic->move('u');
        rubic->move('R');
        rubic->move('u');
        rubic->move('u');
        rubic->move('r');
        rubic->move('u');
        rubic->move('R');
        result = result + "uruRuuruR";
    }else if((rubic->Green->get_color(0) == 'r' && rubic->Red->get_color(2) == 'g' && rubic->Yellow->get_color(2) == 'w')){
        rubic->move('r');
        rubic->move('u');
        rubic->move('R');
        rubic->move('U');
        rubic->move('r');
        rubic->move('u');
        rubic->move('R');
        rubic->move('U');
        rubic->move('r');
        rubic->move('u');
        rubic->move('R');
        rubic->move('U');
        result = result + "ruRUruRUruRU";
    }
    
    return result;
}

std::string PuzzleSolver::get_algorithm_OLL(){
    std::cout << *rubic <<"\nRunning oll...\n";
    std::string result = "";

    while(!(rubic->Yellow->get_color(1) == 'y' && rubic->Yellow->get_color(3) == 'y' &&
             rubic->Yellow->get_color(5) == 'y' && rubic->Yellow->get_color(7) == 'y')){
        if(rubic->Yellow->get_color(1) != 'y' && rubic->Yellow->get_color(3) != 'y' &&
             rubic->Yellow->get_color(5) != 'y' && rubic->Yellow->get_color(7) != 'y'){
            rubic->move('R');
            rubic->move('U');
            rubic->move('r');
            rubic->move('u');
            rubic->move('r');
            rubic->move('F');
            rubic->move('R');
            rubic->move('f');

            rubic->move('u');
            rubic->move('u');

            rubic->move('F');
            rubic->move('R');
            rubic->move('u');
            rubic->move('r');
            rubic->move('u');
            rubic->move('R');
            rubic->move('U');
            rubic->move('r');
            rubic->move('f');
            result = result + "RUrurFRfuuFRuruRUrf";
        }else if(rubic->Yellow->get_color(3) == 'y' && rubic->Yellow->get_color(5) == 'y'){
            //палка
            rubic->move('R');
            rubic->move('U');
            rubic->move('r');
            rubic->move('u');
            rubic->move('r');
            rubic->move('F');
            rubic->move('R');
            rubic->move('f');
            result = result + "RUrurFRf";
        }else if(rubic->Yellow->get_color(1) == 'y' && rubic->Yellow->get_color(7) == 'y'){
            //вертикальная палка
            rubic->move('u');
            rubic->move('R');
            rubic->move('U');
            rubic->move('r');
            rubic->move('u');
            rubic->move('r');
            rubic->move('F');
            rubic->move('R');
            rubic->move('f');
            result = result + "uRUrurFRf";
        }else{
            while(rubic->Yellow->get_color(1) != 'y' || rubic->Yellow->get_color(3) != 'y'){
                rubic->move('U');
                result = result + "U";
            }
            rubic->move('F');
            rubic->move('R');
            rubic->move('u');
            rubic->move('r');
            rubic->move('u');
            rubic->move('R');
            rubic->move('U');
            rubic->move('r');
            rubic->move('f');
            result = result + "FRuruRUrf";
        }
    }

    // std::cout << "Crest was created : \n" << *rubic;
    //построили крест на желтой грани, осталось расставить углы
    while(rubic->Yellow->get_color(0) != 'y' || rubic->Yellow->get_color(2) != 'y' ||
             rubic->Yellow->get_color(6) != 'y' || rubic->Yellow->get_color(8) != 'y'){

        if(rubic->Yellow->get_color(0) != 'y' && rubic->Yellow->get_color(2) != 'y' &&
             rubic->Yellow->get_color(6) == 'y' && rubic->Yellow->get_color(8) != 'y' && rubic->Blue->get_color(2) == 'y'){
            rubic->move('R');
            rubic->move('U');
            rubic->move('r');
            rubic->move('U');
            rubic->move('R');
            rubic->move('U');
            rubic->move('U');
            rubic->move('r');
            result = result + "RUrURUUr";
        }else if(rubic->Yellow->get_color(0) != 'y' && rubic->Yellow->get_color(2) != 'y' &&
             rubic->Yellow->get_color(6) != 'y' && rubic->Yellow->get_color(8) == 'y' && rubic->Blue->get_color(0) == 'y'){
            rubic->move('l');
            rubic->move('u');
            rubic->move('L');
            rubic->move('u');
            rubic->move('l');
            rubic->move('u');
            rubic->move('u');
            rubic->move('L');
            result = result + "luLuluuL";
        }else if(rubic->Yellow->get_color(0) != 'y' && rubic->Yellow->get_color(2) != 'y' &&
             rubic->Yellow->get_color(6) != 'y' && rubic->Yellow->get_color(8) != 'y' && 
             rubic->Blue->get_color(0) == 'y' && rubic->Green->get_color(2) == 'y' &&
             rubic->Blue->get_color(2) == 'y' && rubic->Green->get_color(0) == 'y'){
            rubic->move('F');
            rubic->move('R');
            rubic->move('U');
            rubic->move('r');
            rubic->move('u');
            rubic->move('R');
            rubic->move('U');
            rubic->move('r');
            rubic->move('u');
            rubic->move('R');
            rubic->move('U');
            rubic->move('r');
            rubic->move('u');
            rubic->move('f');
            result = result + "FRUruRUruRUruf";
        }else if(rubic->Yellow->get_color(0) != 'y' && rubic->Yellow->get_color(2) != 'y' &&
             rubic->Yellow->get_color(6) != 'y' && rubic->Yellow->get_color(8) != 'y' && 
             rubic->Blue->get_color(0) != 'y' && rubic->Green->get_color(2) != 'y' &&
             rubic->Blue->get_color(2) == 'y' && rubic->Green->get_color(0) == 'y'){
            rubic->move('R');
            rubic->move('U');
            rubic->move('U');
            rubic->move('r');
            rubic->move('r');
            rubic->move('u');
            rubic->move('R');
            rubic->move('R');
            rubic->move('u');
            rubic->move('R');
            rubic->move('R');
            rubic->move('u');
            rubic->move('u');
            rubic->move('R');
            result = result + "RUURRuRRuRRuuR";
        }else if(rubic->Yellow->get_color(0) == 'y' && rubic->Yellow->get_color(2) == 'y' &&
             rubic->Yellow->get_color(6) != 'y' && rubic->Yellow->get_color(8) != 'y' && rubic->Blue->get_color(0) == 'y'){
            rubic->move('R');
            rubic->move('R');
            rubic->move('D');
            rubic->move('r');
            rubic->move('U');
            rubic->move('U');
            rubic->move('R');
            rubic->move('d');
            rubic->move('r');
            rubic->move('U');
            rubic->move('U');
            rubic->move('r');
            result = result + "RRDrUURdrUUr";
        }else if(rubic->Yellow->get_color(0) == 'y' && rubic->Yellow->get_color(2) == 'y' &&
             rubic->Yellow->get_color(6) != 'y' && rubic->Yellow->get_color(8) != 'y' && rubic->Blue->get_color(0) != 'y'){
            rubic->move('U');
            rubic->move('U');
            rubic->move('R');
            rubic->move('U');
            rubic->move('R');
            rubic->move('D');
            rubic->move('r');
            rubic->move('u');
            rubic->move('R');
            rubic->move('d');
            rubic->move('R');
            rubic->move('R');
            result = result + "UURURDruRdRR";
        }else if(rubic->Yellow->get_color(0) != 'y' && rubic->Yellow->get_color(2) == 'y' &&
             rubic->Yellow->get_color(6) == 'y' && rubic->Yellow->get_color(8) != 'y' && rubic->Blue->get_color(2) == 'y'){
            rubic->move('R');
            rubic->move('R');
            rubic->move('D');
            rubic->move('r');
            rubic->move('U');
            rubic->move('R');
            rubic->move('d');
            rubic->move('r');
            rubic->move('u');
            rubic->move('r');
            result = result + "RRDrURdrur";
        }
        rubic->move('U');
        result = result + "U";
    }
    return result;
}

std::string PuzzleSolver::get_algorithm_PLL(){
    std::cout << *rubic <<"\nRunning pll...\n";
    std::string result = "";
    while(!(rubic->Blue->get_color(0) == rubic->Blue->get_color(2) && rubic->Blue->get_color(0) == rubic->Blue->get_color(1) &&
        rubic->Red->get_color(0) == rubic->Red->get_color(2) && rubic->Red->get_color(0) == rubic->Red->get_color(1) &&
        rubic->Green->get_color(0) == rubic->Green->get_color(2) && rubic->Green->get_color(0) == rubic->Green->get_color(1) &&
        rubic->Orange->get_color(0) == rubic->Orange->get_color(2) && rubic->Orange->get_color(0) == rubic->Orange->get_color(1))){//проверка что кубик может быть уже собран

        if((rubic->Green->get_color(0) == rubic->Green->get_color(1) && rubic->Green->get_color(0) == rubic->Green->get_color(2) &&
            rubic->Red->get_color(2) == rubic->Red->get_color(0) && rubic->Orange->get_color(2) == rubic->Orange->get_color(0)) ||

            (rubic->Blue->get_color(0) == rubic->Blue->get_color(1) && rubic->Blue->get_color(0) == rubic->Blue->get_color(2) &&
            rubic->Red->get_color(2) == rubic->Red->get_color(0) && rubic->Orange->get_color(2) == rubic->Orange->get_color(0)) ||

            (rubic->Red->get_color(0) == rubic->Red->get_color(1) && rubic->Red->get_color(0) == rubic->Red->get_color(2) &&
            rubic->Blue->get_color(2) == rubic->Blue->get_color(0) && rubic->Green->get_color(2) == rubic->Green->get_color(0)) ||

            (rubic->Orange->get_color(0) == rubic->Orange->get_color(1) && rubic->Orange->get_color(0) == rubic->Orange->get_color(2) &&
            rubic->Blue->get_color(2) == rubic->Blue->get_color(0) && rubic->Green->get_color(2) == rubic->Green->get_color(0))){
            while(rubic->Green->get_color(0) != rubic->Green->get_color(1) || rubic->Green->get_color(0) != rubic->Green->get_color(2)){
                rubic->move('U');
                result = result + "U";
            }
            while(rubic->Blue->get_color(0) != rubic->Blue->get_color(1)){
                rubic->move('R');
                rubic->move('U');
                rubic->move('r');
                rubic->move('U');
                rubic->move('R');
                rubic->move('u');
                rubic->move('u');
                rubic->move('r');
                rubic->move('U');
                rubic->move('l');
                rubic->move('u');
                rubic->move('L');
                rubic->move('u');
                rubic->move('l');
                rubic->move('u');
                rubic->move('u');
                rubic->move('L');
                rubic->move('u');
                result = result + "RUrURuurUluLuluuLu";
            }
        }else if(rubic->Blue->get_color(0) == rubic->Blue->get_color(2) &&
                 rubic->Green->get_color(0) == rubic->Green->get_color(2) &&
                 rubic->Red->get_color(0) == rubic->Red->get_color(2) &&
                 rubic->Orange->get_color(0) == rubic->Orange->get_color(2) &&
                 rubic->Orange->get_color(1) == rubic->Red->get_color(2) &&
                 rubic->Red->get_color(1) == rubic->Orange->get_color(2) &&
                 rubic->Green->get_color(1) == rubic->Blue->get_color(2) &&
                 rubic->Blue->get_color(1) == rubic->Green->get_color(2)){
            rubic->move('R');
            rubic->move('R');
            rubic->move('L');
            rubic->move('L');
            rubic->move('d');
            rubic->move('R');
            rubic->move('R');
            rubic->move('L');
            rubic->move('L');
            rubic->move('U');
            rubic->move('U');
            rubic->move('R');
            rubic->move('R');
            rubic->move('L');
            rubic->move('L');
            rubic->move('d');
            rubic->move('R');
            rubic->move('R');
            rubic->move('L');
            rubic->move('L');
            result = result + "RRLLdRRLLUURRLLdRRLL";
        }else if(rubic->Blue->get_color(0) == rubic->Blue->get_color(2) &&
                 rubic->Green->get_color(0) == rubic->Green->get_color(2) &&
                 rubic->Red->get_color(0) == rubic->Red->get_color(2) &&
                 rubic->Orange->get_color(0) == rubic->Orange->get_color(2)){
            rubic->move('R');
            rubic->move('R');
            rubic->move('L');
            rubic->move('L');
            rubic->move('d');
            rubic->move('R');
            rubic->move('R');
            rubic->move('L');
            rubic->move('L');
            rubic->move('u');
            rubic->move('r');
            rubic->move('L');
            rubic->move('f');
            rubic->move('f');
            rubic->move('R');
            rubic->move('R');
            rubic->move('L');
            rubic->move('L');
            rubic->move('b');
            rubic->move('b');
            rubic->move('r');
            rubic->move('L');
            rubic->move('U');
            rubic->move('U');
            result = result + "RRLLdRRLLurLffRRLLbbrLUU";
            
        }else if(rubic->Orange->get_color(0) == rubic->Orange->get_color(2)){
            rubic->move('R');
            rubic->move('U');
            rubic->move('r');
            rubic->move('u');
            rubic->move('r');
            rubic->move('F');
            rubic->move('R');

            rubic->move('R');
            rubic->move('u');
            rubic->move('r');
            rubic->move('u');
            rubic->move('R');
            rubic->move('U');
            rubic->move('r');
            rubic->move('f');
            result = result + "RUrurFRRuruRUrf";
        }else if(rubic->Orange->get_color(0) != rubic->Orange->get_color(2) &&
                rubic->Green->get_color(0) != rubic->Green->get_color(2) && 
                rubic->Red->get_color(0) == rubic->Red->get_color(2) &&
                rubic->Blue->get_color(0) == rubic->Blue->get_color(2)){
            rubic->move('F');
            rubic->move('R');
            rubic->move('u');
            rubic->move('r');
            rubic->move('u');
            rubic->move('R');
            rubic->move('U');
            rubic->move('r');
            rubic->move('f');
            
            rubic->move('R');
            rubic->move('U');
            rubic->move('r');
            rubic->move('u');
            rubic->move('r');
            rubic->move('F');
            rubic->move('R');
            rubic->move('f');
            result = result + "FRuruRUrfRUrurFRF";
        }
        rubic->move('U');
        result = result + "U";
        std::cout << "u";
    }

    while(rubic->Blue->get_color(4) != rubic->Blue->get_color(1)){
        rubic->move('U');
        result = result + "U";
    }

    return result;
}

std::string PuzzleSolver::optimization_of_the_result(std::string prev){
    std::string result = prev;
    std::vector<std::pair<char, char>> A{{'U', 'u'},{'R', 'r'},{'L', 'l'},{'F', 'f'},{'B', 'b'},{'D', 'd'},
                                        {'u', 'U'}, {'r', 'R'}, {'l', 'L'}, {'f', 'F'}, {'b', 'B'}, {'d', 'D'}};
    std::vector<std::pair<std::string, std::string>> changer{{"UUUU", ""}, {"RRRR", ""}, {"LLLL", ""}, {"FFFF", ""}, {"BBBB", ""}, {"DDDD", ""},
                                                            {"uuuu", ""}, {"rrrr", ""}, {"llll", ""}, {"ffff", ""}, {"bbbb", ""}, {"dddd", ""},
                                                            {"UUU", "u"}, {"RRR", "r"}, {"LLL", "l"}, {"FFF", "f"}, {"BBB", "b"}, {"DDD", "d"},
                                                            {"uuu", "U"}, {"rrr", "R"}, {"lll", "L"}, {"fff", "F"}, {"bbb", "B"}, {"ddd", "D"},
                                                            {"Uu", ""}, {"Rr", ""}, {"Ll", ""}, {"Ff", ""}, {"Bb", ""}, {"Dd", ""},
                                                            {"uU", ""}, {"rR", ""}, {"lL", ""}, {"fF", ""}, {"bB", ""}, {"dD", ""}};
    for(auto i : changer){
        std::string old_str = i.first;  // какую подстроку заменить
        std::string new_str = i.second;  // на какую строку заменить
        size_t start {result.find(old_str)};            // находим позицию подстроки
        while (start != std::string::npos) // находим и заменяем все вхождения строки old_str
        {
            result.replace(start, old_str.length(), new_str); // Замена old_str на new_str
            start = result.find(old_str, start + new_str.length());
        }
    }

    return result;
}

std::string PuzzleSolver::puzzle_solution(){
    if(wrong) return "";
    std::string result = get_algorithm_cross();
    result += get_algorithm_F2L();
    result += get_algorithm_OLL();
    result += get_algorithm_PLL();
    return result;
}

std::string PuzzleSolver::get_state(){
    return rubic->get_state();
}