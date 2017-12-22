#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <string>
#include "sdlglutils.h"


bool isRunning = true;
SDL_Window* win;
SDL_GLContext ctx;

class MyCube {
public:
    GLuint idList;

    int alpha;

    MyCube() {
        idList = glGenLists(1);
        glNewList(idList, GL_COMPILE);

        glBegin(GL_QUADS);
        glColor3ub(255, 0, 0);
        glVertex3i(-1, -1, 0);
        glVertex3i(-1, 1, 0);
        glVertex3i(1, 1, 0);
        glVertex3i(1, -1, 0);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(255, 255, 0);
        glVertex3i(1, -1, 0);
        glVertex3i(1, -1, 1);
        glVertex3i(1, 1, 1);
        glVertex3i(1, 1, 0);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(255, 0, 255);
        glVertex3i(1, -1, 0);
        glVertex3i(1, -1, 1);
        glVertex3i(-1, -1, 1);
        glVertex3i(-1, -1, 0);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(0, 255, 0);
        glVertex3i(-1, -1, 0);
        glVertex3i(-1, -1, 1);
        glVertex3i(-1, 1, 1);
        glVertex3i(-1, 1, 0);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(0, 0, 255);
        glVertex3i(1, 1, 0);
        glVertex3i(1, 1, 1);
        glVertex3i(-1, 1, 1);
        glVertex3i(-1, 1, 0);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(0, 255, 255);
        glVertex3i(-1, -1, 1);
        glVertex3i(-1, 1, 1);
        glVertex3i(1, 1, 1);
        glVertex3i(1, -1, 1);
        glEnd();

        glEndList();
    }

    ~MyCube() {
        glDeleteLists(idList, 1);
    }

    void render() {
        glRotatef(alpha, 1, 0, 1);
        glCallList(idList);
    }

    void rotate() {
        alpha += 1;
    }

};

class MySphere {
public:
    GLuint idList;
    GLuint idHerbe;
    GLUquadric* quadric;


    int alpha;
    int x, y;

    MySphere(std::string nomJutsu) {

        idHerbe = loadTexture(nomJutsu.c_str());

        idList = glGenLists(1);
        glNewList(idList, GL_COMPILE);
        glPushMatrix();
        glTranslated(x,y,10);
        glRotated(alpha,0,0,1);
        
        glColor3ub(255,255,255);
        glBindTexture(GL_TEXTURE_2D, idHerbe);
        quadric = gluNewQuadric();
        gluQuadricDrawStyle(quadric, GLU_FILL);
        gluQuadricTexture(quadric, GL_TRUE);

        gluSphere(quadric, 5, 20, 20);


        gluDeleteQuadric(quadric);
        glPopMatrix();
        glEndList();
    }

    ~MySphere() {
        glDeleteLists(idList, 1);
        glDeleteTextures(1, &idHerbe);
    }

    void render() {
        glRotatef(alpha, 0, 0, 1);
        glCallList(idList);
    }

    void rotate() {
        alpha += 1;
    }

};

int main(int argc, char** argv) {
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_JPG);
    win = SDL_CreateWindow("ma super fenetre", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

    ctx = SDL_GL_CreateContext(win);

    GLuint idHerbe;
    //    GLUquadric* quadric;
    //    quadric = gluNewQuadric();
    //    gluQuadricDrawStyle(quadric, GLU_FILL);
    //    gluQuadricTexture(quadric, GL_TRUE);

    //    idHerbe = loadTexture("herbe.jpg");
    MySphere sphere = MySphere("rasengan.jpg");
    MyCube cube;
    MySphere sphere2 = MySphere("katon.jpg");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70, (double) 600 / 600, 1, 1000);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);

    glClearColor(0, 0, 0, 1);
    int x = 50;
    int y = 50;
    const Uint8* states;
    SDL_Event event;
    while (isRunning) {
        SDL_PollEvent(&event);
        states = SDL_GetKeyboardState(NULL);
        if (event.type == SDL_QUIT)
            isRunning = false;
        if(states[SDL_SCANCODE_LEFT])
            sphere.x++;
        if(states[SDL_SCANCODE_RIGHT])
            sphere.x--;
        if(states[SDL_SCANCODE_UP])
            sphere.y--;
        if(states[SDL_SCANCODE_DOWN])
            sphere.y++;

        //effacer ecran
//test git hub
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        gluLookAt(x, y, 50, 0, 0, 0, 0, 0, 1);

        glPushMatrix();

        glScaled(100, 100, 1);
       // cube.render();
        glPopMatrix();

        glPushMatrix();
//        glScaled(20, 20, 1);
        glTranslated(sphere.x,sphere.y,0);
        sphere.rotate();
        sphere.render();

        glPopMatrix();
        
        sphere2.rotate();
        sphere2.render();
        glPopMatrix();
        //mettre a jour l ecran
        SDL_GL_SwapWindow(win);
    }

    //    gluDeleteQuadric(quadric);
    //    glDeleteTextures(1,&idHerbe);
    SDL_GL_DeleteContext(ctx);
    SDL_DestroyWindow(win);
    IMG_Quit();
    SDL_Quit();
    return 0;
}

