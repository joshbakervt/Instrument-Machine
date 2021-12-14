#include "graphics.h"
#include "Button.h"
#include "Genre.h"
#include "House.h"
#include "HipHop.h"
#include <iostream>
#include <time.h>
#include <string>
#include <vector>
#include <filesystem>
using namespace std;

GLdouble width, height;
int wd;
enum Stage {starting, spawning, ending};
Stage stage = starting;
vector<Genre> genre_choices;

vector<string>random_sounds;

// python will be used for calling the command line execution of playback.py
string const python = "python3";
string command;

// Create enum for Window
enum Window {launch, house, hiphop, create};

// This will allow us to shorten the length of the code
// Rather than run a conditional on the status of the window to determine the file to play
// We can concatenate the file path alongside the string implementation of the enum
static const char *enum_str[] = {"Launch", "House", "Hip_Hop","Create"};
Window window = launch;
string display_title;
// House(int bpm, std::string title, int number_buttons)
House house_genre(120, "House", 8, "House_Sample.mp3");
HipHop hiphop_genre(80, "HipHop", 8, "HipHop_Sample.mp3");

// Create strings for Launch
string title = "BeatPad Pro";
string welcome = "Welcome! Please Select an Option Below";
string create_string = "Random!";
string redirect = "Press for a random sound! :)";

Button go_back({1, 1, 1}, {50, 30}, 60, 30, "BACK");

vector<Button>metronome;
vector<Button>equalizer;

Button house_button({1, 1, 1}, {125, 250}, 200, 100, house_genre.getTitle());
Button hiphop_button({1, 1, 1}, {375, 250}, 200, 100, hiphop_genre.getTitle());
// Create your own buttons!
Button create_button({1, 1, 1}, {250, 400}, 200, 100, create_string);
int random_select;
string decision;
string file_path;
string enum_for_string;

// 120 bpm = 4 seconds
// 80 bpm = 6 seconds
int bpm = 0;


// TODO: Create Buttons for beat pads
Button melody({0, 1, 0}, {250, 50}, 100, 50, "W");
Button bass({1, 1, 0}, {100, 150}, 100, 50, "A");
Button tops({0, 1, 1}, {250, 150}, 100, 50, "S");
Button drums({1, 0, 1}, {400, 150}, 100, 50, "D");

Button melody_h({0, 0, 0}, {250, 50}, 110, 55, "W");
Button bass_h({0, 0, 0}, {100, 150}, 110, 55, "A");
Button tops_h({0, 0, 0}, {250, 150}, 110, 55, "S");
Button drums_h({0, 0, 0}, {400, 150}, 110, 55, "D");

// Create a button to play a beat sample
Button sample_h({0, 0, 0}, {250, 350}, 310, 70, " ");
Button sample({1, 0, 0}, {250, 350}, 300, 60, "SPACE");

// Create a button to play a random noise
Button random_h({0, 0, 0}, {250, 250}, 215, 215, " ");
Button random_sound({1, 0, 0}, {250, 250}, 200, 200, "RANDOM");

void initGenres(){
    // Push the genres back to a vector
    genre_choices.push_back(house_genre);
    genre_choices.push_back(hiphop_genre);

    // Push back the vector of sounds
    random_sounds.push_back("Bonk.mp3");
    random_sounds.push_back("Boom.mp3");
    random_sounds.push_back("Bruh.mp3");
    random_sounds.push_back("Boing.mp3");
    random_sounds.push_back("Bababooey.mp3");
    random_sounds.push_back("Mr_Krabs.mp3");
    random_sounds.push_back("Windows.mp3");

}

void initMetronome(){
    int total_metronome_width = 25;
    for(int i = 1; i < 9; i++) {
        metronome.push_back(Button({0, 0, 0}, {total_metronome_width, 250}, 60, 60, " "));
        metronome.push_back(Button({1, 1, 1}, {total_metronome_width, 250}, 50, 50, to_string(i)));
        total_metronome_width += 65;
    }
}

void initEqualizer(){
    int total_equal_width = 185;
    for(int i = 1; i < 11; i++) {
        equalizer.push_back(Button({0, .6, 0}, {total_equal_width, 450}, 10, rand() % 50 + 20, " "));
        total_equal_width += 15;
    }
}

void init() {
    initGenres();
    initMetronome();
    initEqualizer();
    width = 500;
    height = 500;
    srand(time(0));
}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(0.3, 0.3, 0.3, 0); // Black and opaque
}

/* Handler for window-repaint event. Call back when the window first appears and
 whenever the window needs to be re-painted. */
void display() {
    // tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height);

    // do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    switch(window){
        case launch:

            // Draw the background
            glColor3f(0.1, 0.1, 0.1);
            glBegin(GL_QUAD_STRIP);
            glVertex2i(0, 500); // Left top
            glVertex2i(500, 500); // Right top
            glVertex2i(0, 0); // Left bottom
            glColor3f(0.4, 0.4, 0.4);
            glVertex2i(500, 0); // Right bottom
            glEnd();

            // Welcome user
            glColor3f(1,1,1);
            glRasterPos2i(width/2 - (4 * title.length()), height/6);
            for(const char & text : title) {
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text);
            }
            glRasterPos2i(width/2 - (4 * welcome.length()), height/4);
            for(const char & text : welcome) {
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text);
            }
            // Add selection for either house or hip hop
            house_button.draw();
            hiphop_button.draw();
            create_button.draw();
            break;
        case create:
            // Draw the background
            glColor3f(0.1, 0.1, 0.1);
            glBegin(GL_QUAD_STRIP);
            glVertex2i(0, 500); // Left top
            glVertex2i(500, 500); // Right top
            glVertex2i(0, 0); // Left bottom
            glColor3f(0.4, 0.4, 0.4);
            glVertex2i(500, 0); // Right bottom
            glEnd();

            // Welcome user
            glColor3f(1,1,1);
            glRasterPos2i(width/2 - (4 * title.length()), height/6);
            for(const char & text : title) {
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text);
            }
            glRasterPos2i(width/2 - (4 * redirect.length()), height/4);
            for(const char & text : redirect) {
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text);
            }
            go_back.draw();

            random_h.draw();
            random_sound.draw();

            break;
        case house:
            // Implement functions for playback
            // Draw the background
            glColor3f(0.1, 0.1, 0.1);
            glBegin(GL_QUAD_STRIP);
            glVertex2i(0, 500); // Left top
            glVertex2i(500, 500); // Right top
            glVertex2i(0, 0); // Left bottom
            glColor3f(0.4, 0.4, 0.4);
            glVertex2i(500, 0); // Right bottom
            glEnd();

            // Set background title
            display_title = house_genre.getTitle();

            // Draw the title
            glRasterPos2i(width/2 - (4 * display_title.length()), 110);
            for(const char & text : display_title) {
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text);
            }

            // Class implementation
            bpm = house_genre.getBPM();

            // Draw the button highlighter
            melody_h.draw();
            bass_h.draw();
            tops_h.draw();
            drums_h.draw();

            // Draw the equalizer
            for (Button &e : equalizer) {
                e.draw();
            }

            // Draw the beatkeeper
            for (Button &m : metronome) {
                m.draw();
            }

            // Draw highlights
            sample_h.draw();
            sample.draw();

            // Additional buttons
            go_back.draw();
            melody.draw();
            bass.draw();
            tops.draw();
            drums.draw();
            break;

        case hiphop:
            // Implement functions for playback
            // Create a vector of objects, draw all

            // Draw background
            glColor3f(0.1, 0.1, 0.1);
            glBegin(GL_QUAD_STRIP);
            glVertex2i(0, 500); // Left top
            glVertex2i(500, 500); // Right top
            glVertex2i(0, 0); // Left bottom
            glColor3f(0.4, 0.4, 0.4);
            glVertex2i(500, 0); // Right bottom
            glEnd();

            // Get the background title
            display_title = hiphop_genre.getTitle();

            glRasterPos2i(width/2 - (4 * display_title.length()), 110);
            for(const char & text : display_title) {
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text);
            }

            // Class implementation
            bpm = hiphop_genre.getBPM();

            // Draw the equalizer
            for (Button &e : equalizer) {
                e.draw();
            }

            // Draw the beatkeeper
            for (Button &m : metronome) {
                  m.draw();
            }

            sample_h.draw();
            sample.draw();

            // Additional buttons
            go_back.draw();
            melody.draw();
            bass.draw();
            tops.draw();
            drums.draw();
            break;
    }
    glFlush();  // Render now
    glutPostRedisplay();
}

// http://www.theasciicode.com.ar/ascii-control-characters/escape-ascii-code-27.html
void kbd(unsigned char key, int x, int y) {
    // escape
    if (key == 27) {
        glutDestroyWindow(wd);
        exit(0);
    }
    switch(key) {
            case 's':
                // Tops
                if(window == house) {
                    tops_h.hover();
                    std::__fs::filesystem::path p("c:/dir/dir/House_Tops.mp3");
                    play(p.filename());
                    tops_h.release();
                } else if(window == hiphop) {
                    tops_h.hover();
                    std::__fs::filesystem::path p("c:/dir/dir/Hip_Hop_Top.mp3");
                    play(p.filename());
                    tops_h.release();
                }
            break;
            case 'w':
                // Melody
                if(window == house) {
                    melody_h.hover();
                    std::__fs::filesystem::path p("c:/dir/dir/House_Melody.mp3");
                    play(p.filename());
                    melody_h.release();
                } else if(window == hiphop) {
                    melody_h.hover();
                    std::__fs::filesystem::path p("c:/dir/dir/Hip_Hop_Melody.mp3");
                    play(p.filename());
                    melody_h.release();
                }
            break;
            case 'a':
                // Bass
                if(window == house) {
                    bass_h.hover();
                    std::__fs::filesystem::path p("c:/dir/dir/House_Bass.mp3");
                    play(p.filename());
                    bass_h.release();
                } else if(window == hiphop) {
                    bass_h.hover();
                    std::__fs::filesystem::path p("c:/dir/dir/Hip_Hop_Bass.mp3");
                    play(p.filename());
                    bass_h.release();
                }
            break;
            case 'd':
                // Drums
                if(window == house) {
                    drums_h.hover();
                    std::__fs::filesystem::path p("c:/dir/dir/House_Drums.mp3");
                    play(p.filename());
                    drums_h.release();
                } else if(window == hiphop) {
                    drums_h.hover();
                    std::__fs::filesystem::path p("c:/dir/dir/Hip_Hop_Drums.mp3");
                    play(p.filename());
                    drums_h.release();
                }
            break;
            case ' ':
                // Full sample of track, or random noise
                if(window == house || window == house) {
                    sample_h.hover();
                    enum_for_string = getStringForEnum(window);
                    file_path = ("c:/dir/dir/" + enum_for_string + "_Sample.mp3");
                    std::__fs::filesystem::path p(file_path);
                    play(p.filename());
                    sample_h.release();
                } else if (window == create) {
                    random_select = rand() % 7 + 1;
                    decision = "c:/dir/dir/" + random_sounds[random_select];
                    cout << decision << endl;
                    std::__fs::filesystem::path p(decision);
                    play(p.filename());
                }
                break;
            case '1':
                // Drums
                if(window == house || window == hiphop) {
                    metronome[0].hover();
                    enum_for_string = getStringForEnum(window);
                    file_path = ("c:/dir/dir/" + enum_for_string + "_1.mp3");
                    std::__fs::filesystem::path p(file_path);
                    play(p.filename());
                    metronome[0].release();
                }
                break;
            case '2':
                if(window == house || window == hiphop) {
                    metronome[2].hover();
                    enum_for_string = getStringForEnum(window);
                    file_path = ("c:/dir/dir/" + enum_for_string + "_2.mp3");
                    std::__fs::filesystem::path p(file_path);
                    play(p.filename());
                    metronome[2].release();
                }
                break;
            case '3':
                if(window == house || window == hiphop) {
                    metronome[4].hover();
                    enum_for_string = getStringForEnum(window);
                    file_path = ("c:/dir/dir/" + enum_for_string + "_3.mp3");
                    std::__fs::filesystem::path p(file_path);
                    play(p.filename());
                    metronome[4].release();
                }
                break;
            case '4':
                if(window == house || window == hiphop) {
                    metronome[6].hover();
                    enum_for_string = getStringForEnum(window);
                    file_path = ("c:/dir/dir/" + enum_for_string + "_4.mp3");
                    std::__fs::filesystem::path p(file_path);
                    play(p.filename());
                    metronome[6].release();
                }
                break;
            case '5':
                if(window == house || window == hiphop) {
                    metronome[8].hover();
                    enum_for_string = getStringForEnum(window);
                    file_path = ("c:/dir/dir/" + enum_for_string + "_5.mp3");
                    std::__fs::filesystem::path p(file_path);
                    play(p.filename());
                    metronome[8].release();
                }
                break;
            case '6':
                if(window == house || window == hiphop) {
                    metronome[10].hover();
                    enum_for_string = getStringForEnum(window);
                    file_path = ("c:/dir/dir/" + enum_for_string + "_6.mp3");
                    std::__fs::filesystem::path p(file_path);
                    play(p.filename());
                    metronome[10].release();
                }
                break;
            case '7':
                if(window == house || window == hiphop) {
                    metronome[12].hover();
                    enum_for_string = getStringForEnum(window);
                    file_path = ("c:/dir/dir/" + enum_for_string + "_7.mp3");
                    std::__fs::filesystem::path p(file_path);
                    play(p.filename());
                    metronome[12].release();
                }
                break;
            case '8':
                if(window == house || window == hiphop) {
                    metronome[14].hover();
                    enum_for_string = getStringForEnum(window);
                    file_path = ("c:/dir/dir/" + enum_for_string + "_8.mp3");
                    std::__fs::filesystem::path p(file_path);
                    play(p.filename());
                    metronome[14].release();
                }
                break;
    }


    glutPostRedisplay();
}

//void kbdS(int key, int x, int y) {
//    switch(key) {
//        case GLUT_KEY_DOWN:
////            if(stage == spawning){
////                if(spawn.getBottomY() != height) {
////                    spawn.move(0, 1);
////                }
////            }
//            break;
//        case GLUT_KEY_LEFT:
////            if(stage == spawning){
////                if(spawn.getLeftX() > 0) {
////                    spawn.move(-1, 0);
////                }
////            }
//            break;
//        case GLUT_KEY_RIGHT:
////            if(stage == spawning){
////                if(spawn.getLeftX() < width) {
////                    spawn.move(1, 0);
////                }
////            }
//            break;
//        case GLUT_KEY_UP:
////            if(stage == spawning){
////                if(spawn.getBottomY() != 0) {
////                    spawn.move(0, -1);
////                }
////            }
//            break;
//    }
//
//    glutPostRedisplay();
//}

void cursor(int x, int y) {
    // If the Button is overlapping with the (x, y) coordinate passed in, call the hover method. Otherwise, call the release method.
    if(house_button.isOverlapping(x, y)) {
        house_button.hover();

    } else if(hiphop_button.isOverlapping(x, y)) {
        hiphop_button.hover();
    } else if(create_button.isOverlapping(x, y)) {
        create_button.hover();
    } else if(random_sound.isOverlapping(x,y)) {
        random_h.hover();
    }
    else {
            house_button.release();
            hiphop_button.release();
            create_button.release();
            glutPostRedisplay();
        }
    }

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
void mouse(int button, int state, int x, int y) {
    // If the left button is down and the cursor is overlapping with the Button, call the pressDown method. Otherwise, call the release method.
    if (GLUT_KEY_DOWN && house_button.isOverlapping(x, y)) {
        window = house;
    }
    if (GLUT_KEY_DOWN && hiphop_button.isOverlapping(x, y)) {
            window = hiphop;
    }
    if (GLUT_KEY_DOWN && go_back.isOverlapping(x, y)) {
        window = launch;
    }
    if (GLUT_KEY_DOWN && create_button.isOverlapping(x, y)) {
        window = create;
    }
    glutPostRedisplay();
}

void timer(int dummy) {

    glutPostRedisplay();
    glutTimerFunc(30, timer, dummy);
}

void play(std::string title){
    command = python + " playback.py " + title;
    cout << command << endl;
    system(command.c_str());

}

// For determining which file to play, and of which genre
string getStringForEnum(int enum_val)
{
    string tmp(enum_str[enum_val]);
    return tmp;
}

// Controls the equalizer animation
void equalTimer(int dummy) {
    for(int i = 0; i < equalizer.size();++i){
        equalizer[i].resize(10, rand() % 35 + 20);
        if(equalizer[i].getHeight() > 50){
            equalizer[i].setColor(1,0,0);
        }else if(equalizer[i].getHeight() < 50 && equalizer[i].getHeight() > 40){
            equalizer[i].setColor(1,0.7,0);
        }else if(equalizer[i].getHeight() < 50){
            equalizer[i].setColor(0,.8,0);
        }
    }
    glutPostRedisplay();
    glutTimerFunc(30, equalTimer, dummy);
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {


    init();

    glutInit(&argc, argv);          // Initialize GLUT

    glutInitDisplayMode(GLUT_RGBA);

    glutInitWindowSize((int)width, (int)height);
    glutInitWindowPosition(100, 200); // Position the window's initial top-left corner
    /* create the window and store the handle to it */
    wd = glutCreateWindow("BEAT PAD PRO" /* title */ );

    // Register callback handler for window re-paint event
    glutDisplayFunc(display);

    // Our own OpenGL initialization
    initGL();

    // register keyboard press event processing function
    // works for numbers, letters, spacebar, etc.
    glutKeyboardFunc(kbd);

    // register special event: function keys, arrows, etc.
    glutSpecialFunc(kbdS);

    // handles mouse movement
    glutPassiveMotionFunc(cursor);

    // handles mouse click
    glutMouseFunc(mouse);

    // handles timer
    glutTimerFunc(0, timer, 0);
    glutTimerFunc(0, equalTimer, 0);

    // Enter the event-processing loop
    glutMainLoop();


    return 0;
}
