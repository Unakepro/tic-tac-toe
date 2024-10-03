#include "game.hpp"

tic_tac_toe::tic_tac_toe(size_t size) {
    if(size < 9 || size != (sqrt(size) * sqrt(size))) {
        throw std::logic_error("Wrong size");
    }

    area = std::vector<char>(size, 'n');
}

void tic_tac_toe::print() {
    std::cout << "\n\n";
    
    for(size_t i = 0; i < sqrt(area.size()); ++i) {
        std::cout << ' ';
        for(size_t j = 0; j < sqrt(area.size()); ++j) {
            
            
            char element = area.at(i * sqrt(area.size()) + j);
            if(element == 'X' || element == '0') {
                std::cout << element;
            }
            else {
                std::cout << '-';
            }

            if(j != sqrt(area.size())-1) {
               std::cout << " | ";
            }
        }

        std::cout << '\n';
        
        for(size_t j = 0; j < (i != sqrt(area.size())-1) * ((sqrt(area.size()) + (sqrt(area.size())-1) * 3) + 2); ++j) {
           std::cout << '-';
        }
        
        std::cout << '\n';

    }

    std::cout << "\n\n";
}