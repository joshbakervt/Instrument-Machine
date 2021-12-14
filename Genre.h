//
// Created by Josh Baker on 11/30/21.
//


#ifndef BEATPAD_GENRE_H
#define BEATPAD_GENRE_H

#include <string>

class Genre {
private:
    int bpm, number_buttons;
    std::string title, filename;
public:


    // Constructors
    Genre();
    Genre(int bpm, std::string title, int number_buttons, std::string filename);

    int getBPM() const;
    std::string getTitle() const;
    int getNumberButtons() const;
    std::string getFilename() const;

    void setBPM(int bpm);
    void setTitle(std::string title);
    void setNumberButtons(int number_buttons);
    void setFilename(std::string filename);

};



#endif //BEATPAD_GENRE_H
