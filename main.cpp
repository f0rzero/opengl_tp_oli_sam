#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "sdlglutils.h"


bool isRunning = true;
SDL_Window* win;
SDL_GLContext ctx;
//tatami et environement
GLuint idBrick;
GLuint idHerb;
GLuint left;
GLuint fwd;
GLuint bot;
GLuint top;
GLuint right;
GLuint back;
//tete naruto
GLuint nHLeft;
GLuint nHRight;
GLuint nHTop;
GLuint nHFront;
GLuint nHBack;
//body naruto
GLuint nBLeft;
GLuint nBRight;
GLuint nBFront;
GLuint nBBack;
//pied naruto
GLuint nPCote;
GLuint nPFront;
GLuint nPBack;

//corp sasuke
GLuint sDos;
GLuint sDevant;
GLuint sDroit;
GLuint sGauche;
//tete sasuke
GLuint sLeft;
GLuint sFront;
GLuint sBot;
GLuint sTop;
GLuint sRight;
GLuint sBack;
//pied sasuke
GLuint sPDevant;
GLuint sPDroit;
GLuint sPDos;
GLuint sPGauche;

void skyBox() {
    //dessous
    glBindTexture(GL_TEXTURE_2D, bot);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glTexCoord2d(0, 0);
    glVertex3i(-500, -500, 0);
    glTexCoord2d(0, 1);
    glVertex3i(-500, 500, 0);
    glTexCoord2d(1, 1);
    glVertex3i(500, 500, 0);
    glTexCoord2d(1, 0);
    glVertex3i(500, -500, 0);
    glEnd();

    //forward
    glBindTexture(GL_TEXTURE_2D, fwd);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glTexCoord2d(0, 0);
    glVertex3i(-500, -500, 0);
    glTexCoord2d(0, 1);
    glVertex3i(-500, -500, 1000);
    glTexCoord2d(1, 1);
    glVertex3i(-500, 500, 1000);
    glTexCoord2d(1, 0);
    glVertex3i(-500, 500, 0);
    glEnd();

    //left
    glBindTexture(GL_TEXTURE_2D, left);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glTexCoord2d(0, 0);
    glVertex3i(500, -500, 0);
    glTexCoord2d(0, 1);
    glVertex3i(500, -500, 1000);
    glTexCoord2d(1, 1);
    glVertex3i(-500, -500, 1000);
    glTexCoord2d(1, 0);
    glVertex3i(-500, -500, 0);
    glEnd();

    //right
    glBindTexture(GL_TEXTURE_2D, right);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glTexCoord2d(0, 0);
    glVertex3i(-500, 500, 0);
    glTexCoord2d(0, 1);
    glVertex3i(-500, 500, 1000);
    glTexCoord2d(1, 1);
    glVertex3i(500, 500, 1000);
    glTexCoord2d(1, 0);
    glVertex3i(500, 500, 0);
    glEnd();

    //back
    glBindTexture(GL_TEXTURE_2D, back);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glTexCoord2d(0, 0);
    glVertex3i(500, 500, 0);
    glTexCoord2d(0, 1);
    glVertex3i(500, 500, 1000);
    glTexCoord2d(1, 1);
    glVertex3i(500, -500, 1000);
    glTexCoord2d(1, 0);
    glVertex3i(500, -500, 0);
    glEnd();

    //back
    glBindTexture(GL_TEXTURE_2D, top);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glTexCoord2d(0, 0);
    glVertex3i(-500, -500, 0);
    glTexCoord2d(0, 1);
    glVertex3i(-500, 500, 0);
    glTexCoord2d(1, 1);
    glVertex3i(500, 500, 0);
    glTexCoord2d(1, 0);
    glVertex3i(500, -500, 0);
    glEnd();



}

void dessinerTatami() {
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glTexCoord2d(0, 0);
    glVertex3i(-75, -75, 0);
    glTexCoord2d(0, 1);
    glVertex3i(-75, 75, 0);
    glTexCoord2d(5, 1);
    glVertex3i(75, 75, 0);
    glTexCoord2d(5, 0);
    glVertex3i(75, -75, 0);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, idBrick);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glTexCoord2d(0, 0);
    glVertex3i(75, -75, 0);
    glTexCoord2d(0, 1);
    glVertex3i(75, -75, 10);
    glTexCoord2d(5, 1);
    glVertex3i(75, 75, 10);
    glTexCoord2d(5, 0);
    glVertex3i(75, 75, 0);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, idBrick);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glTexCoord2d(0, 0);
    glVertex3i(75, -75, 0);
    glTexCoord2d(0, 1);
    glVertex3i(75, -75, 10);
    glTexCoord2d(5, 1);
    glVertex3i(-75, -75, 10);
    glTexCoord2d(5, 0);
    glVertex3i(-75, -75, 0);
    glEnd();


    glBindTexture(GL_TEXTURE_2D, idBrick);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glTexCoord2d(0, 0);
    glVertex3i(-75, -75, 0);
    glTexCoord2d(0, 1);
    glVertex3i(-75, -75, 10);
    glTexCoord2d(5, 1);
    glVertex3i(-75, 75, 10);
    glTexCoord2d(5, 0);
    glVertex3i(-75, 75, 0);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, idBrick);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glTexCoord2d(0, 0);
    glVertex3i(75, 75, 0);
    glTexCoord2d(0, 1);
    glVertex3i(75, 75, 10);
    glTexCoord2d(5, 1);
    glVertex3i(-75, 75, 10);
    glTexCoord2d(5, 0);
    glVertex3i(-75, 75, 0);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, idHerb);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glTexCoord2d(0, 1);
    glVertex3i(-75, -75, 10);
    glTexCoord2d(0, 0);
    glVertex3i(-75, 75, 10);
    glTexCoord2d(1, 0);
    glVertex3i(75, 75, 10);
    glTexCoord2d(1, 1);
    glVertex3i(75, -75, 10);
    glEnd();
}

void dessinerPetitCube() {
    glBegin(GL_QUADS);
    glColor3ub(255, 0, 0);
    glVertex3i(-4, -4, 10);
    glVertex3i(-4, 4, 20);
    glVertex3i(4, 4, 20);
    glVertex3i(4, -4, 10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 0, 0);
    glVertex3i(4, -4, 10);
    glVertex3i(4, -4, 20);
    glVertex3i(4, 4, 20);
    glVertex3i(4, 4, 10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 0, 0);
    glVertex3i(4, -4, 10);
    glVertex3i(4, -4, 20);
    glVertex3i(-4, -4, 20);
    glVertex3i(-4, -4, 10);
    glEnd();



    glBegin(GL_QUADS);
    glColor3ub(255, 0, 0);
    glVertex3i(-4, -4, 10);
    glVertex3i(-4, -4, 20);
    glVertex3i(-4, 4, 20);
    glVertex3i(-4, 4, 10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 0, 0);
    glVertex3i(4, 4, 10);
    glVertex3i(4, 4, 20);
    glVertex3i(-4, 4, 20);
    glVertex3i(-4, 4, 10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 0, 0);
    glVertex3i(-4, -4, 20);
    glVertex3i(-4, 4, 20);
    glVertex3i(4, 4, 20);
    glVertex3i(4, -4, 20);
    glEnd();

}

void dessinerPyramide() {
    glBegin(GL_QUADS);
    glColor3ub(0, 255, 10);
    glVertex3i(-4, 4, 10);
    glVertex3i(-4, -4, 10);
    glVertex3i(4, -4, 10);
    glVertex3i(4, 4, 10);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 255, 10);
    glVertex3i(-4, -4, 10);
    glVertex3i(-4, 4, 10);
    glVertex3i(0, 0, 20);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 255, 10);
    glVertex3i(-4, -4, 10);
    glVertex3i(4, -4, 10);
    glVertex3i(0, 0, 20);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 255, 0);
    glVertex3i(-4, 4, 10);
    glVertex3i(4, 4, 10);
    glVertex3i(0, 0, 20);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 255, 0);
    glVertex3i(4, 4, 10);
    glVertex3i(4, -4, 10);
    glVertex3i(0, 0, 20);
    glEnd();

}

void personnageSasuke()  {

    glBegin(GL_QUADS);
      glColor3ub(255, 255, 255);
      glVertex3i(-4, -4, 10);
      glVertex3i(-4, 4, 20);
      glVertex3i(4, 4, 20);
      glVertex3i(4, -4, 10);
      glEnd();
glBindTexture(GL_TEXTURE_2D, sPDos);
      glBegin(GL_QUADS);
      glColor3ub(255, 255, 255);
      glTexCoord2d(0, 0);
      glVertex3i(4, -4, 10);
      glTexCoord2d(0, 1);
      glVertex3i(4, -4, 20);
      glTexCoord2d(1, 1);
      glVertex3i(4, 4, 20);
      glTexCoord2d(1, 0);
      glVertex3i(4, 4, 10);
      glEnd();
glBindTexture(GL_TEXTURE_2D, sPDroit);
      glBegin(GL_QUADS);
      glColor3ub(255, 255, 255);
      glTexCoord2d(0, 0);
      glVertex3i(4, -4, 10);
      glTexCoord2d(0, 1);
      glVertex3i(4, -4, 20);
      glTexCoord2d(1, 1);
      glVertex3i(-4, -4, 20);
      glTexCoord2d(1, 0);
      glVertex3i(-4, -4, 10);
      glEnd();


glBindTexture(GL_TEXTURE_2D, sPDevant);
      glBegin(GL_QUADS);
      glColor3ub(255, 255, 255);
      glTexCoord2d(0, 0);
      glVertex3i(-4, -4, 10);
      glTexCoord2d(0, 1);
      glVertex3i(-4, -4, 20);
      glTexCoord2d(1, 1);
      glVertex3i(-4, 4, 20);
      glTexCoord2d(1, 0);
      glVertex3i(-4, 4, 10);
      glEnd();
      
glBindTexture(GL_TEXTURE_2D, sPGauche);
      glBegin(GL_QUADS);
      glColor3ub(255, 255, 255);
      glTexCoord2d(0, 0);
      glVertex3i(4, 4, 10);
      glTexCoord2d(0, 1);
      glVertex3i(4, 4, 20);
      glTexCoord2d(1, 1);
      glVertex3i(-4, 4, 20);
      glTexCoord2d(1, 0);
      glVertex3i(-4, 4, 10);
      glEnd();

      glBegin(GL_QUADS);
      glColor3ub(255, 255, 255);
      glVertex3i(-4, -4, 20);
      glVertex3i(-4, 4, 20);
      glVertex3i(4, 4, 20);
      glVertex3i(4, -4, 20);
      glEnd();
        

      //tron
      //bottom
    //glBindTexture(GL_TEXTURE_2D, sBot);
      glBegin(GL_QUADS);
      glColor3ub(255,255,255);
       glTexCoord2d(0, 0);
      glVertex3i(-6, -8, 20);
       glTexCoord2d(0, 1);
      glVertex3i(-6, 8, 20);
       glTexCoord2d(1, 1);
      glVertex3i(6, 8, 20);
       glTexCoord2d(1, 0);
      glVertex3i(6, -8, 20);
      glEnd();
      //left
     glBindTexture(GL_TEXTURE_2D, sDos);
            glBegin(GL_QUADS);
      glColor3ub(255, 255, 255);
       glTexCoord2d(0, 0);
      glVertex3i(6, -8, 20);
       glTexCoord2d(0, 1);
      glVertex3i(6, -8, 40);
       glTexCoord2d(1, 1);
      glVertex3i(6, 8, 40);
       glTexCoord2d(1, 0);
      glVertex3i(6, 8, 20);
      glEnd();

      //back
      glBindTexture(GL_TEXTURE_2D, sDroit);
      glBegin(GL_QUADS);
      glColor3ub(255, 255, 255);
       glTexCoord2d(0, 0);
      glVertex3i(6, -8, 20);
       glTexCoord2d(0, 1);
      glVertex3i(6, -8, 40);
       glTexCoord2d(1, 1);
      glVertex3i(-6, -8, 40);
       glTexCoord2d(1, 0);
      glVertex3i(-6, -8, 20);
      glEnd();


       //front
      glBindTexture(GL_TEXTURE_2D, sDevant);
      glBegin(GL_QUADS);
      glColor3ub(255, 255, 255);
       glTexCoord2d(0, 0);
      glVertex3i(-6, -8, 20);
       glTexCoord2d(0, 1);
      glVertex3i(-6, -8, 40);
       glTexCoord2d(1, 1);
      glVertex3i(-6, 8, 40);
       glTexCoord2d(1, 0);
      glVertex3i(-6, 8, 20);
      glEnd();

      //right
      glBindTexture(GL_TEXTURE_2D, sGauche);
      glBegin(GL_QUADS);
      glColor3ub(255, 255, 255);
       glTexCoord2d(0, 0);
      glVertex3i(6, 8, 20);
       glTexCoord2d(0, 1);
      glVertex3i(6, 8, 40);
       glTexCoord2d(1, 1);
      glVertex3i(-6, 8, 40);
       glTexCoord2d(1, 0);
      glVertex3i(-6, 8, 20);
      glEnd();
          
      //top
      glBindTexture(GL_TEXTURE_2D, sTop);
      glBegin(GL_QUADS);
      glColor3ub(255, 255, 255);
       glTexCoord2d(0, 0);
      glVertex3i(-6, -8, 40);
       glTexCoord2d(0, 1);
      glVertex3i(-6, 8, 40);
       glTexCoord2d(1, 1);
      glVertex3i(6, 8, 40);
       glTexCoord2d(1, 0);
      glVertex3i(6, -8, 40);
      glEnd();
        
     

    //tete     
    //down
    glBindTexture(GL_TEXTURE_2D, sBot);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glTexCoord2d(0, 0);
    glVertex3i(-10, -10, 40);
    glTexCoord2d(0, 1);
    glVertex3i(-10, 10, 40);
    glTexCoord2d(1, 1);
    glVertex3i(10, 10, 40);
    glTexCoord2d(1, 0);
    glVertex3i(10, -10, 40);
    glEnd();
    //left
    glBindTexture(GL_TEXTURE_2D, sRight);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glTexCoord2d(0, 0);
    glVertex3i(10, -10, 40);
    glTexCoord2d(0, 1);
    glVertex3i(10, -10, 60);
    glTexCoord2d(1, 1);
    glVertex3i(10, 10, 60);
    glTexCoord2d(1, 0);
    glVertex3i(10, 10, 40);
    glEnd();

    //back
    glBindTexture(GL_TEXTURE_2D, sBack);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glTexCoord2d(0, 0);
    glVertex3i(10, -10, 40);
    glTexCoord2d(0, 1);
    glVertex3i(10, -10, 60);
    glTexCoord2d(1, 1);
    glVertex3i(-10, -10, 60);
    glTexCoord2d(1, 0);
    glVertex3i(-10, -10, 40);
    glEnd();


    //
    glBindTexture(GL_TEXTURE_2D, sFront);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glTexCoord2d(0, 0);
    glVertex3i(-10, -10, 40);
    glTexCoord2d(0, 1);
    glVertex3i(-10, -10, 60);
    glTexCoord2d(1, 1);
    glVertex3i(-10, 10, 60);
    glTexCoord2d(1, 0);
    glVertex3i(-10, 10, 40);
    glEnd();

    //right
    glBindTexture(GL_TEXTURE_2D, sLeft);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glTexCoord2d(0, 0);
    glVertex3i(10, 10, 40);
    glTexCoord2d(0, 1);
    glVertex3i(10, 10, 60);
    glTexCoord2d(1, 1);
    glVertex3i(-10, 10, 60);
    glTexCoord2d(1, 0);
    glVertex3i(-10, 10, 40);
    glEnd();

    //top
    glBindTexture(GL_TEXTURE_2D, sTop);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glTexCoord2d(0, 0);
    glVertex3i(-10, -10, 60);
    glTexCoord2d(0, 1);
    glVertex3i(-10, 10, 60);
    glTexCoord2d(1, 1);
    glVertex3i(10, 10, 60);
    glTexCoord2d(1, 0);
    glVertex3i(10, -10, 60);
    glEnd();

}

void personnageNaruto(){
    
    glBegin(GL_QUADS);
      glColor3ub(255, 255, 255);
      glVertex3i(-4, -4, 10);
      glVertex3i(-4, 4, 20);
      glVertex3i(4, 4, 20);
      glVertex3i(4, -4, 10);
      glEnd();
      
glBindTexture(GL_TEXTURE_2D, nPBack);
      glBegin(GL_QUADS);
      glColor3ub(255, 255, 255);
      glTexCoord2d(0, 0);
      glVertex3i(4, -4, 10);
      glTexCoord2d(0, 1);
      glVertex3i(4, -4, 20);
      glTexCoord2d(1, 1);
      glVertex3i(4, 4, 20);
      glTexCoord2d(1, 0);
      glVertex3i(4, 4, 10);
      glEnd();
glBindTexture(GL_TEXTURE_2D, nPCote);
      glBegin(GL_QUADS);
      glColor3ub(255, 255, 255);
      glTexCoord2d(0, 0);
      glVertex3i(4, -4, 10);
      glTexCoord2d(0, 1);
      glVertex3i(4, -4, 20);
      glTexCoord2d(1, 1);
      glVertex3i(-4, -4, 20);
      glTexCoord2d(1, 0);
      glVertex3i(-4, -4, 10);
      glEnd();


glBindTexture(GL_TEXTURE_2D, nPFront);
      glBegin(GL_QUADS);
      glColor3ub(255, 255, 255);
      glTexCoord2d(0, 0);
      glVertex3i(-4, -4, 10);
      glTexCoord2d(0, 1);
      glVertex3i(-4, -4, 20);
      glTexCoord2d(1, 1);
      glVertex3i(-4, 4, 20);
      glTexCoord2d(1, 0);
      glVertex3i(-4, 4, 10);
      glEnd();
      
glBindTexture(GL_TEXTURE_2D, nPCote);
      glBegin(GL_QUADS);
      glColor3ub(255, 255, 255);
      glTexCoord2d(0, 0);
      glVertex3i(4, 4, 10);
      glTexCoord2d(0, 1);
      glVertex3i(4, 4, 20);
      glTexCoord2d(1, 1);
      glVertex3i(-4, 4, 20);
      glTexCoord2d(1, 0);
      glVertex3i(-4, 4, 10);
      glEnd();

      glBegin(GL_QUADS);
      glColor3ub(255, 255, 255);
      glVertex3i(-4, -4, 20);
      glVertex3i(-4, 4, 20);
      glVertex3i(4, 4, 20);
      glVertex3i(4, -4, 20);
      glEnd();
        

      //tron
      //bottom
    //glBindTexture(GL_TEXTURE_2D, sBot);
      glBegin(GL_QUADS);
      glColor3ub(255,255,255);
       glTexCoord2d(0, 0);
      glVertex3i(-6, -8, 20);
       glTexCoord2d(0, 1);
      glVertex3i(-6, 8, 20);
       glTexCoord2d(1, 1);
      glVertex3i(6, 8, 20);
       glTexCoord2d(1, 0);
      glVertex3i(6, -8, 20);
      glEnd();
      //left
     glBindTexture(GL_TEXTURE_2D, nBBack);
            glBegin(GL_QUADS);
      glColor3ub(255, 255, 255);
       glTexCoord2d(0, 0);
      glVertex3i(6, -8, 20);
       glTexCoord2d(0, 1);
      glVertex3i(6, -8, 40);
       glTexCoord2d(1, 1);
      glVertex3i(6, 8, 40);
       glTexCoord2d(1, 0);
      glVertex3i(6, 8, 20);
      glEnd();

      //back
      glBindTexture(GL_TEXTURE_2D, nBRight);
      glBegin(GL_QUADS);
      glColor3ub(255, 255, 255);
       glTexCoord2d(0, 0);
      glVertex3i(6, -8, 20);
       glTexCoord2d(0, 1);
      glVertex3i(6, -8, 40);
       glTexCoord2d(1, 1);
      glVertex3i(-6, -8, 40);
       glTexCoord2d(1, 0);
      glVertex3i(-6, -8, 20);
      glEnd();


       //front
      glBindTexture(GL_TEXTURE_2D, nBFront);
      glBegin(GL_QUADS);
      glColor3ub(255, 255, 255);
       glTexCoord2d(0, 0);
      glVertex3i(-6, -8, 20);
       glTexCoord2d(0, 1);
      glVertex3i(-6, -8, 40);
       glTexCoord2d(1, 1);
      glVertex3i(-6, 8, 40);
       glTexCoord2d(1, 0);
      glVertex3i(-6, 8, 20);
      glEnd();

      //right
      glBindTexture(GL_TEXTURE_2D, nBLeft);
      glBegin(GL_QUADS);
      glColor3ub(255, 255, 255);
       glTexCoord2d(0, 0);
      glVertex3i(6, 8, 20);
       glTexCoord2d(0, 1);
      glVertex3i(6, 8, 40);
       glTexCoord2d(1, 1);
      glVertex3i(-6, 8, 40);
       glTexCoord2d(1, 0);
      glVertex3i(-6, 8, 20);
      glEnd();
          
      //top
     // glBindTexture(GL_TEXTURE_2D, sTop);
      glBegin(GL_QUADS);
      glColor3ub(255, 255, 255);
       glTexCoord2d(0, 0);
      glVertex3i(-6, -8, 40);
       glTexCoord2d(0, 1);
      glVertex3i(-6, 8, 40);
       glTexCoord2d(1, 1);
      glVertex3i(6, 8, 40);
       glTexCoord2d(1, 0);
      glVertex3i(6, -8, 40);
      glEnd();
        
     

    //tete     
    //down
    //glBindTexture(GL_TEXTURE_2D, sBot);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glTexCoord2d(0, 0);
    glVertex3i(-10, -10, 40);
    glTexCoord2d(0, 1);
    glVertex3i(-10, 10, 40);
    glTexCoord2d(1, 1);
    glVertex3i(10, 10, 40);
    glTexCoord2d(1, 0);
    glVertex3i(10, -10, 40);
    glEnd();
    //left
    glBindTexture(GL_TEXTURE_2D, nHBack);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glTexCoord2d(0, 0);
    glVertex3i(10, -10, 40);
    glTexCoord2d(0, 1);
    glVertex3i(10, -10, 60);
    glTexCoord2d(1, 1);
    glVertex3i(10, 10, 60);
    glTexCoord2d(1, 0);
    glVertex3i(10, 10, 40);
    glEnd();

    //back
    glBindTexture(GL_TEXTURE_2D, nHLeft);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glTexCoord2d(1, 0);
    glVertex3i(10, -10, 40);
    glTexCoord2d(1, 1);
    glVertex3i(10, -10, 60);
    glTexCoord2d(0, 1);
    glVertex3i(-10, -10, 60);
    glTexCoord2d(0, 0);
    glVertex3i(-10, -10, 40);
    glEnd();


    //
    glBindTexture(GL_TEXTURE_2D, nHFront);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glTexCoord2d(0, 0);
    glVertex3i(-10, -10, 40);
    glTexCoord2d(0, 1);
    glVertex3i(-10, -10, 60);
    glTexCoord2d(1, 1);
    glVertex3i(-10, 10, 60);
    glTexCoord2d(1, 0);
    glVertex3i(-10, 10, 40);
    glEnd();

    //right
    glBindTexture(GL_TEXTURE_2D, nHRight);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glTexCoord2d(0, 0);
    glVertex3i(10, 10, 40);
    glTexCoord2d(0, 1);
    glVertex3i(10, 10, 60);
    glTexCoord2d(1, 1);
    glVertex3i(-10, 10, 60);
    glTexCoord2d(1, 0);
    glVertex3i(-10, 10, 40);
    glEnd();

    //top
    glBindTexture(GL_TEXTURE_2D, nHTop);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glTexCoord2d(0, 0);
    glVertex3i(-10, -10, 60);
    glTexCoord2d(0, 1);
    glVertex3i(-10, 10, 60);
    glTexCoord2d(1, 1);
    glVertex3i(10, 10, 60);
    glTexCoord2d(1, 0);
    glVertex3i(10, -10, 60);
    glEnd();
}
int main(int argc, char** argv) {
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_JPG);
    win = SDL_CreateWindow("ma super fenetre", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1400, 800, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

    ctx = SDL_GL_CreateContext(win);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50, (double) 1400 / 800, 1, 10000);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    
    //img de naruto 
    //img de la tete
    std::string narutoHLeft = "naruto_head_gauche.jpg";
    std::string narutoHRight = "naruto_head_right.jpg";
    std::string narutoHFront = "naruto_head_front.jpg";
    std::string narutoHTop = "naruto_head_top.jpg";
    std::string narutoHBack = "naruto_head_back.jpg";
     //img du corp
    
    std::string narutoBLeft = "naruto_body_left.jpg";
    std::string narutoBRight = "naruto_body_right.jpg";
    std::string narutoBFront = "naruto_body_front.jpg";
    std::string narutoBBack = "naruto_body_back.jpg";
   
       //img des pieds
    std::string narutoPCote = "naruto_pied_cote.jpg";
    std::string narutoPFront = "naruto_pied_devant.jpg";
    std::string narutoPBack = "naruto_pied_back.jpg";
    
 
    
    
    //img de la tete
 std::string sasukeLeft = "sasuke_left.jpg";
    std::string sasukeFront = "sasuke_front.jpg";
    std::string sasukeBottom = "sasuke_bottom.jpg";
    std::string sasukeTop = "sasuke_top.jpg";
    std::string sasukeRight = "sasuke_right.jpg";
    std::string sasukeBack = "sasuke_backward.jpg";
    
    //img du corp
    std::string sasukeDevant = "sasuke_devant.jpg";
    std::string sasukeDos = "sasuke_dos.jpg";
    std::string sasukeGauche = "sasuke_coter_gauche.jpg";
    std::string sasukeDroit = "sasuke_coter_droit.jpg";
    
    
    //img de la map
    std::string fichierBrick = "brick.jpg";
    std::string fichierHerb = "herb.jpg";
    std::string fichierLeft = "troubled-waters_lf.jpg";
    std::string fichierFwd = "troubled-waters_bk.jpg";
    std::string fichierBot = "troubled-waters_dn.jpg";
    std::string fichierTop = "troubled-waters_up.jpg";
    std::string fichierRight = "troubled-waters_rt.jpg";
    std::string fichierBack = "troubled-waters_ft.jpg";

   //img des pied
     std::string sasukePiedDevant = "sasuke_pied_devant.jpg";
    std::string sasukePiedDos = "sasuke_pied_dos.jpg";
    std::string sasukePiedGauche = "sasuke_pied_gauche.jpg";
    std::string sasukePiedDroit = "sasuke_pied_gauche.jpg";

    
    //naruto casting
    //naruto tete
    nHBack = loadTexture(narutoHBack.c_str());
    nHFront = loadTexture(narutoHFront.c_str());
    nHLeft = loadTexture(narutoHLeft.c_str());
    nHRight = loadTexture(narutoHRight.c_str());
    nHTop = loadTexture(narutoHTop.c_str());
            
    //naruto corp
    nBRight = loadTexture(narutoBRight.c_str());
    nBLeft = loadTexture(narutoBLeft.c_str());
    nBFront = loadTexture(narutoBFront.c_str());
    nBBack = loadTexture(narutoBBack.c_str());
    //naruto pied
    nPCote = loadTexture(narutoPCote.c_str());
    nPBack = loadTexture(narutoPBack.c_str());
    nPFront = loadTexture(narutoPFront.c_str());
    
    
    //sasuke pied 
    sPDevant = loadTexture(sasukePiedDevant.c_str());
    sPDos = loadTexture(sasukePiedDos.c_str());
    sPDroit = loadTexture(sasukePiedDroit.c_str());
    sPGauche = loadTexture(sasukePiedGauche.c_str());
    
    
    
//sasuke tete
       sLeft = loadTexture(sasukeLeft.c_str());
    sFront = loadTexture(sasukeFront.c_str());
    sBot = loadTexture(sasukeBottom.c_str());
    sTop = loadTexture(sasukeTop.c_str());
    sRight = loadTexture(sasukeRight.c_str());
    sBack = loadTexture(sasukeBack.c_str());
    
    
    //sasuke corp
    sDos = loadTexture(sasukeDos.c_str());
    sDevant = loadTexture(sasukeDevant.c_str());
    sGauche = loadTexture(sasukeGauche.c_str());
    sDroit = loadTexture(sasukeDroit.c_str());
    
    //tatami et environement
    idBrick = loadTexture(fichierBrick.c_str());
    idHerb = loadTexture(fichierHerb.c_str());
    left = loadTexture(fichierLeft.c_str());
    fwd = loadTexture(fichierFwd.c_str());
    bot = loadTexture(fichierBot.c_str());
    top = loadTexture(fichierTop.c_str());
    right = loadTexture(fichierRight.c_str());
    back = loadTexture(fichierBack.c_str());

 


    glClearColor(0, 0, 0, 1);
    int x = 100;
    int y = 100;
    int z = 0;
    int q = 0;
    int r = 0;
    int t = 0;
    const Uint8* statesk;
    SDL_Event event;
    while (isRunning) {
        SDL_PollEvent(&event);
        statesk = SDL_GetKeyboardState(NULL);
        if (event.type == SDL_QUIT)
            isRunning = false;
        if (statesk[SDL_SCANCODE_UP])
            x += 4;
        if (statesk[SDL_SCANCODE_DOWN])
            x -= 4;
        if (statesk[SDL_SCANCODE_LEFT])
            y += 4;
        if (statesk[SDL_SCANCODE_RIGHT])
            y -= 4;
        if (statesk[SDL_SCANCODE_W])
            z--;
        if (statesk[SDL_SCANCODE_A])
            q--;
        if (statesk[SDL_SCANCODE_S])
            z++;
        if (statesk[SDL_SCANCODE_D])
            q++;
        if (statesk[SDL_SCANCODE_I])
            r--;
        if (statesk[SDL_SCANCODE_J])
            t--;
        if (statesk[SDL_SCANCODE_K])
            r++;
        if (statesk[SDL_SCANCODE_L])
            t++;

        //effacer ecran

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        gluLookAt(x, y, 150, 0, 0, 0, 0, 0, 1);
        glPushMatrix();

        skyBox();
        //tatami

        dessinerTatami();

        glPopMatrix();
        //petit cube
        glPushMatrix();
         
        glTranslated(r, 0, 0);
        glRotated(t,0,0,1);
        personnageSasuke();

        //dessinerPetitCube();
        glPopMatrix();

        //personnage


        //petit pyramide
        glPushMatrix();

        glTranslated(z, q, 0);

        //dessinerPyramide();
        personnageNaruto();

        glPopMatrix();
        glLoadIdentity();

        //mettre a jour l ecran
        SDL_GL_SwapWindow(win);
    }
    glDeleteTextures(1,&sBack);
     glDeleteTextures(1,&sTop);
      glDeleteTextures(1,&sLeft);
       glDeleteTextures(1,&sRight);
        glDeleteTextures(1,&sBot);
         glDeleteTextures(1,&sFront);
    glDeleteTextures(1, &idHerb);
    glDeleteTextures(1, &idBrick);

    SDL_GL_DeleteContext(ctx);
    SDL_DestroyWindow(win);
    IMG_Quit();
    SDL_Quit();
    return 0;
}

