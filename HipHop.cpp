//
// Created by Josh Baker on 11/30/21.
//

#include "HipHop.h"
#include "graphics.h"
using namespace std;

HipHop::HipHop() {
    setBPM(80);
    setTitle("HipHop Track");
    setNumberButtons(4);
    setFilename("hiphop.mp3");
}

HipHop::HipHop(int hiphop_bpm, std::string hiphop_title, int number_buttons, std::string filename) {
    setBPM(hiphop_bpm);
    setTitle(hiphop_title);
    setNumberButtons(number_buttons);
    setFilename(filename);
}

//void HipHop::play(std::string file, int time) const {

//}
