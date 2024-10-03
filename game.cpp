#include "game.hpp"

tic_tac_toe::tic_tac_toe(size_t size) {
    if(size < 9 || size != (sqrt(size) * sqrt(size))) {
        throw std::logic_error("Wrong size");
    }

    area = std::vector<char>{
        'X', 's', 'X',
        'K', 'X', '0',
        'X', '0', 'x',
    };
}

int16_t tic_tac_toe::checkRows() {
    size_t sq_root = sqrt(area.size());
    for(size_t i = 0; i < sq_root; ++i) {
        
        char element = area.at(i * sq_root);
        
        size_t j = 0;
        for(; j < sq_root; ++j) {
            if(element != area.at(i * sq_root + j)) {
                break;
            }
        }

        if(j == sq_root) {
            if(element == 'X') {
                return -1;
            }
            else if(element == '0') {
                return 1;
            }
        }
    }

    return 0;
}

int16_t tic_tac_toe::checkCols() {
    size_t sq_root = sqrt(area.size());
    for(size_t i = 0; i < sq_root; ++i) {
        
        char element = area.at(i);
        
        size_t j = 0;
        for(; j < sq_root; ++j) {
            if(element != area.at(i + j * sq_root)) {
                break;
            }
        }

        if(j == sq_root) {
            if(element == 'X') {
                return -1;
            }
            else if(element == '0') {
                return 1;
            }
        }
    }

    return 0;
}

int16_t tic_tac_toe::checkDiagonals() {
    size_t sq_root = sqrt(area.size());

    char element = area.at(0);
    
    size_t i = 0;
    for(; i < sq_root; ++i) {
        
        if(element != area.at(i + i * sq_root)) {
            break;
        }
    }

    if(i == sq_root) {
        if(element == 'X') {
            return -1;
        }
        else if(element == '0') {
            return 1;
        }
    }

    i = 0;

    element = area.at(sq_root-1);
    for(; i < sq_root; ++i) {
        if(element != area.at(sq_root-1 - i  + sq_root * i)) {
            break;
        }
    }

    if(i == sq_root) {
        if(element == 'X') {
            return -1;
        }
        else if(element == '0') {
            return 1;
        }
    }



    return 0;
}


int16_t tic_tac_toe::getResult() {
    int16_t r_w = checkRows();
    int16_t c_w = checkCols();
    int16_t d_w = checkDiagonals();
  

    if(r_w) {
        return r_w;
    }
    if(c_w) {
        return c_w;
    }   
    if(d_w) {
        return d_w;
    }

    return 0;
}

void tic_tac_toe::print() {
    std::cout << "\n\n";
    
    size_t sq_root = sqrt(area.size());
    for(size_t i = 0; i < sq_root; ++i) {
        std::cout << ' ';
        for(size_t j = 0; j < sq_root; ++j) {
            
            
            char element = area.at(i * sq_root + j);
            if(element == 'X' || element == '0') {
                std::cout << element;
            }
            else {
                std::cout << '-';
            }

            if(j != sq_root-1) {
               std::cout << " | ";
            }
        }

        std::cout << '\n';
        
        for(size_t j = 0; j < (i != sq_root - 1) * ((sq_root + (sq_root - 1) * 3) + 2); ++j) {
           std::cout << '-';
        }
        
        std::cout << '\n';

    }

    std::cout << "\n\n";
}

// void minmax() {

// }