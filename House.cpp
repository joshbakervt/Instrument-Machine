//
// Created by Josh Baker on 11/30/21.
//

#include "House.h"
#include "graphics.h"
using namespace std;

House::House() {
    setBPM(120);
    setTitle("House Track");
    setNumberButtons(4);
    setFilename("house.mp3");
}

House::House(int house_bpm, std::string house_title, int number_buttons, std::string filename) {
    setBPM(house_bpm);
    setTitle(house_title);
    setNumberButtons(number_buttons);
    setFilename(filename);
}

//void House::play(std::string filename, int time) const {

//}
