#include <iostream>
#include "game.hpp"

int main() {
    tic_tac_toe curr_game(9);
    curr_game.print();


    std::cout << curr_game.getResult() << std::endl;
    curr_game.start_game();
    return 0;
}