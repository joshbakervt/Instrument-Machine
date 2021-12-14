//
// Created by Josh Baker on 11/30/21.
//

#ifndef BEATPAD_HOUSE_H
#define BEATPAD_HOUSE_H

#include "Genre.h"
#include <string>

class House: public Genre {

private:
    int bpm, number_buttons;
    std::string title, filename;

public:

    // Constructors
    House();
    House(int bpm, std::string title, int number_buttons, std::string filename);

};


#endif //BEATPAD_HOUSE_H
