#include "graphics.h"
#include "Button.h"
#include "Genre.h"
#include <iostream>
#include <time.h>
#include <vector>
using namespace std;

GLdouble width, height;
int wd;
Genre house_genre();
Genre hiphop_genre();
enum Stage {starting, spawning, ending};
Stage stage = starting;

// Create enum for Window
enum Window {launch, house, hiphop};
Window window = launch;

Button house_button({1, 1, 1}, {125, 250}, 200, 100, "House");
Button hiphop_button({1, 1, 1}, {375, 250}, 200, 100, "Hip Hop");
Button go_back({1, 1, 1}, {50, 30}, 60, 30, "BACK");


vector<Button>metronome;


// Controls Speed of timer
// 120 bpm = 4 seconds
// 80 bpm = 6 seconds
int bpm = 0;

// Create strings for Launch
string title = "BeatPad";
string welcome = "Welcome! Please Select an Option Below";
string launch_1 = "House";
string launch_2 = "Hip Hop";

// Create strings for House and Hip Hop
string house_title = "House";
string hiphop_title = "Hip Hop";

// TODO: Create Buttons for beat pads
Button melody({0, 0, 1}, {250, 100}, 100, 50, "Melody");
Button bass({0, 0, 1}, {100, 200}, 100, 50, "Bass");
Button tops({0, 0, 1}, {250, 200}, 100, 50, "Tops");
Button drums({0, 0, 1}, {400, 200}, 100, 50, "Drums");


void initMetronome(){
    int total_metronome_width = 25;
    for(int i = 0; i < 4; i++) {
        metronome.push_back(Button({.9, .9, .9}, {total_metronome_width, 450}, 50, 50, " "));
        total_metronome_width += 150;
    }
}

void init() {
    initMetronome();
    width = 500;
    height = 500;
    srand(time(0));
}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(.2, 0, .6, 0); // Black and opaque
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

    /*
     * Draw here
     */
    // Call the Button's draw method.
    switch(window){
        case launch:

            glColor3f(.2, 0, .6);
            glBegin(GL_QUAD_STRIP);
            glVertex2i(0, 350); // Left top
            glVertex2i(500, 350); // Right top
            glColor3f(.4, 0, .4);
            glVertex2i(0, 0); // Left bottom
            glVertex2i(500, 0); // Right bottom
            glEnd();

            // TODO: Welcome user
            glColor3f(1,1,1);
            glRasterPos2i(width/2 - (4 * title.length()), height/6);
            for(const char & text : title) {
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text);
            }
            glRasterPos2i(width/2 - (4 * welcome.length()), height/4);
            for(const char & text : welcome) {
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text);
            }
            // TODO: Add selection for either house or hip hop
            house_button.draw();
            hiphop_button.draw();
            break;
        case house:
            // TODO: Implement functions for playback
            // Create a vector of objects, draw all

            glColor3f(.2, 0, .6);
            glBegin(GL_QUAD_STRIP);
            glVertex2i(0, 350); // Left top
            glVertex2i(500, 350); // Right top
            glColor3f(0, 0, 1);
            glVertex2i(0, 0); // Left bottom
            glVertex2i(500, 0); // Right bottom
            glEnd();

            bpm = 8;
            // Draw the beatkeeper
            for (Button &m : metronome) {
                m.draw();
            }
            go_back.draw();
            melody.draw();
            bass.draw();
            tops.draw();
            drums.draw();
            break;
        case hiphop:
            // TODO: Implement functions for playback
            // Create a vector of objects, draw all

            glColor3f(.2, 0, .6);
            glBegin(GL_QUAD_STRIP);
            glVertex2i(0, 350); // Left top
            glVertex2i(500, 350); // Right top
            glColor3f(0, 0, 1);
            glVertex2i(0, 0); // Left bottom
            glVertex2i(500, 0); // Right bottom
            glEnd();

            bpm = 12;
            // Draw the beatkeeper
            for (Button &m : metronome) {
                  m.draw();
            }
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
                tops.hover();


            break;
            case 'w':
                // Melody
                melody.hover();
            break;
            case 'a':
                // Bass
                bass.hover();
            break;
            case 'd':
                // Drums
                drums.hover();
            break;
    }
//    switch(key) {
//        case 's':
//            stage = spawning;
//            break;
//    }


    glutPostRedisplay();
}

void kbdS(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_DOWN:
//            if(stage == spawning){
//                if(spawn.getBottomY() != height) {
//                    spawn.move(0, 1);
//                }
//            }
            break;
        case GLUT_KEY_LEFT:
//            if(stage == spawning){
//                if(spawn.getLeftX() > 0) {
//                    spawn.move(-1, 0);
//                }
//            }
            break;
        case GLUT_KEY_RIGHT:
//            if(stage == spawning){
//                if(spawn.getLeftX() < width) {
//                    spawn.move(1, 0);
//                }
//            }
            break;
        case GLUT_KEY_UP:
//            if(stage == spawning){
//                if(spawn.getBottomY() != 0) {
//                    spawn.move(0, -1);
//                }
//            }
            break;
    }

    glutPostRedisplay();
}

void cursor(int x, int y) {
    // If the Button is overlapping with the (x, y) coordinate passed in, call the hover method. Otherwise, call the release method.
    if(house_button.isOverlapping(x, y)) {
        house_button.hover();

    } else if(hiphop_button.isOverlapping(x, y)) {
        hiphop_button.hover();
    } else {
        house_button.release();
        hiphop_button.release();
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
    // If the left button is up and the cursor is overlapping with the Button, call spawnConfetti.
//    if (GLUT_KEY_UP && spawn.isOverlapping(x, y)) {
//        spawnConfetti();
//    }
    glutPostRedisplay();
}

void timer(int dummy) {

    glutPostRedisplay();
    glutTimerFunc(30, timer, dummy);
}

void metronomeTimer(int dummy) {
    glutPostRedisplay();
    glutTimerFunc(30, metronomeTimer, dummy);
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
    // glutTimerFunc(0, metronomeTimer, 0);

    // Enter the event-processing loop
    glutMainLoop();
    return 0;
}
