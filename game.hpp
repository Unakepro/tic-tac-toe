#ifndef game
#define game

#include <iostream>
#include <vector>
#include <cmath>

class tic_tac_toe {
    std::vector<char> area;

public:
    tic_tac_toe(size_t size);

    //bool isTerminal() {

    //}
    int16_t checkRows(); 
    int16_t checkCols(); 
    int16_t checkDiagonals(); 

    int16_t getResult();
    


    void print();

};

#endif