#include "Cyber_cube/Algorithms.h"
#include <iostream>

int main(){
    PuzzleSolver A(true);
    std::string res = A.puzzle_solution();
    std::cout << "Неоптимизированная строка:\n" << res << std::endl;
    std::cout << "Оптимизированная строка:\n" << A.optimization_of_the_result(res) << std::endl;
    std::cout << "   ===   Result   ===   \n";
    std::cout << *(A.rubic); 
}
