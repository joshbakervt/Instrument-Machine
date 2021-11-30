//
// Created by Josh Baker on 11/30/21.
//

#include "Genre.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <stdlib.h>

// These will be used for playing the file
std::string const python = "python3";
std::string command;

Genre::Genre(){
    bpm = 0;
    number_buttons = 1;
    title = "Genre";
}

Genre::Genre(int bpm, std::string title, int number_buttons){
    this->bpm = bpm;
    this->title = title;
    this->number_buttons = number_buttons;
}

int Genre::getBPM() const {
    return bpm;
}

std::string Genre::getTitle() const {
    return title;
}
int Genre::getNumberButtons() const {
    return number_buttons;
}

void Genre::setBPM(int bpm){
    this->bpm = bpm;
}
void Genre::setTitle(std::string title){
    this->title = title;
}
void Genre::setNumberButtons(int number_buttons){
    this->number_buttons = number_buttons;
}
void Genre::play(std::string file) const {
    command = python + " " + file;
    system(command.c_str());
}
