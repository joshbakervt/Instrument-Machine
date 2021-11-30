//
// Created by Josh Baker on 11/30/21.
//


#ifndef BEATPAD_GENRE_H
#define BEATPAD_GENRE_H


#include <string>

class Genre {
private:
    int bpm, number_buttons;
    std::string title;
public:
    // Constructors
    Genre();
    Genre(int bpm, std::string title, int number_buttons);

    int getBPM() const;
    std::string getTitle() const;
    int getNumberButtons() const;

    void setBPM(int bpm);
    void setTitle(std::string title);
    void setNumberButtons(int number_buttons);

    virtual void play(std::string file) const;
};



#endif //BEATPAD_GENRE_H
