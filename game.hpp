#ifndef game
#define game

#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>

class tic_tac_toe {
    std::vector<char> area;

public:
    tic_tac_toe(size_t size);
    tic_tac_toe(const tic_tac_toe& obj);

    int16_t checkRows(); 
    int16_t checkCols(); 
    int16_t checkDiagonals(); 
    int16_t getResult();    

    void start_game(bool start_min = true);

    std::vector<tic_tac_toe> all_new_moves(bool min_turn = true);

    void print();

    size_t size(); 
    size_t size_left();   

    char& operator[](int16_t index);
    char& at(int16_t index);


};

#endif
