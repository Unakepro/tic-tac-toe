#include "game.hpp"

tic_tac_toe::tic_tac_toe(size_t size) {
    if(size < 9 || size != (sqrt(size) * sqrt(size))) {
        throw std::logic_error("Wrong size");
    }

    area = std::vector<char>(size, 'n');
}

tic_tac_toe::tic_tac_toe(const tic_tac_toe& obj) {
    area = obj.area;
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
                return 1;
            }
            else if(element == '0') {
                return -1;
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
                return 1;
            }
            else if(element == '0') {
                return -1;
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
            return 1;
        }
        else if(element == '0') {
            return -1;
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
            return 1;
        }
        else if(element == '0') {
            return -1;
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


std::vector<tic_tac_toe> tic_tac_toe::all_new_moves(bool max_turn) {
    std::vector<tic_tac_toe> new_moves;
    
    for(size_t i = 0; i < size(); ++i) {
        if(at(i) != '0' && at(i) != 'X') {
            auto tmp = *this;
            tmp[i] = (max_turn ? 'X' : '0');
            new_moves.emplace_back(std::move(tmp));
        } 
    }

    return new_moves;
}

int16_t minimax(tic_tac_toe& position, bool isMax) {
    int16_t result = position.getResult();

    if(result || position.size_left() == 0) {
        return result;
    }

    auto solutions = position.all_new_moves(isMax);
    

    if(isMax) {
        int16_t value = -100;
        tic_tac_toe result_position(position.size());

        for(size_t i = 0; i < solutions.size(); ++i) {
            value = std::max(value, minimax(solutions[i], false));
        }
        return value;
    }
    else {
        int16_t value = 100;

        for(size_t i = 0; i < solutions.size(); ++i) {
            value = std::min(value, (minimax(solutions[i], true)));
        }
        return value;
    }

     
}

void tic_tac_toe::start_game(bool isMax) {
    std::cout << "Hello to the tic-tac-toe game!!!!! \n";

    while (true) {
        print();

        std::unordered_set<size_t> possible_moves;
        std::cout << "Choose your move ";

        for(size_t i = 0; i < area.size(); ++i) {
            if(area[i] != 'X' && area[i] != '0') {
                possible_moves.insert(i+1);
                std::cout << i+1 << ' ';
            }
        }
        std::cout << std::endl;

        size_t ans = 0;
        while (true) {
            std::cout << "Enter your move\n";
            
            std::cin >> ans;

            if(possible_moves.find(ans) != possible_moves.end()) {
                break;
            }
        }

        area.at(ans-1) = (isMax ? 'X' : '0');
        print();

        if(getResult() == 1) {
            std::cout << "You won!! \n";
            return;
        }
        if(size_left() == 0) {
            break;
        }
        
        auto solutions = all_new_moves(!isMax);


        int16_t value = 100;
        tic_tac_toe result_position = solutions[0];

        for(size_t i = 0; i < solutions.size(); ++i) {
            auto tmp_value = minimax(solutions[i], true);
            if(tmp_value < value) {
                value = tmp_value;
                result_position = solutions[i];
            }
        }

        area = result_position.area;
        print();

        if(getResult() == -1) {
            std::cout << "You Lost!! \n";
            return;
        }
    }

    std::cout << "Tie \n";

}


size_t tic_tac_toe::size() {
    return area.size();
}

size_t tic_tac_toe::size_left() {
    size_t cap = area.size();
    for(size_t i = 0; i < area.size(); ++i) {
        if(area[i] == '0' || area[i] == 'X') {
            --cap;
        }
    }

    return cap;
}


char& tic_tac_toe::operator[](int16_t index) {
    return area[index];
}

char& tic_tac_toe::at(int16_t index) {
    if(index < 0 || index > area.size()-1) {
        throw std::logic_error("Wrong size");
    }
    return area[index];
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