#ifndef game
#define game

#include <iostream>
#include <vector>
#include <cmath>

class tic_tac_toe {
    std::vector<char> area;

public:
    tic_tac_toe(size_t size);

    void print();

};

#endif