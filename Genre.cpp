//
// Created by Josh Baker on 11/30/21.
//

#include "Genre.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <stdlib.h>

// python will be used for calling the command line execution of playback.py

Genre::Genre(){
    bpm = 0;
    number_buttons = 1;
    title = "Genre";
    filename = "path/to/filename.mp3";

}

Genre::Genre(int genre_bpm, std::string genre_title, int genre_number_buttons, std::string filename){
    //this->bpm = bpm;
    setBPM(genre_bpm);
    this->title = genre_title;
    this->number_buttons = genre_number_buttons;
    this->filename = filename;
}

int Genre::getBPM() const {
    return bpm;
}

std::string Genre::getTitle() const {
    return title;
}
std::string Genre::getFilename() const {
    return filename;
}
int Genre::getNumberButtons() const {
    return number_buttons;
}

void Genre::setBPM(int genre_bpm){
    this->bpm = genre_bpm;
}
void Genre::setTitle(std::string genre_title){
    this->title = genre_title;
}

void Genre::setFilename(std::string filename){
    this->filename = filename;
}

void Genre::setNumberButtons(int genre_number_buttons){
    this->number_buttons = genre_number_buttons;
}
