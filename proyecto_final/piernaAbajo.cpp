//
// Created by diego on 29/11/22.
//

#include "piernaAbajo.h"

PiernaAbajo::PiernaAbajo() {
    pie = new Cilindro(1,4);
    gemelo = new Cilindro(1.5,6);
    rodilla = new Esfera(2);
}
void PiernaAbajo::draw() {
    glPushMatrix();
        rodilla->draw();
        glPushMatrix();
            glTranslatef(0, -6.5, 0);
            gemelo->draw();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0,-6.5,2);
            glRotatef(90, 1, 0, 0);
            glTranslatef(0,-2,0); //centrar el cilindro en el 0,0,0
            pie->draw();
        glPopMatrix();
    glPopMatrix();
}
void PiernaAbajo::setModo(int mode) {
    pie->setModo(mode);
    gemelo->setModo(mode);
    rodilla->setModo(mode);
}