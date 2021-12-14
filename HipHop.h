//
// Created by Josh Baker on 11/30/21.
//

#ifndef BEATPAD_HIPHOP_H
#define BEATPAD_HIPHOP_H

#include "Genre.h"
#include <string>

class HipHop: public Genre {
private:
    int bpm, number_buttons;
    std::string title, filename;
public:
    // Constructors
    HipHop();
    HipHop(int bpm, std::string title, int number_buttons, std::string filename);
};


#endif //BEATPAD_HIPHOP_H
