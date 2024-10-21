//
// Created by diego on 29/11/22.
//

#include "brazo.h"

Brazo::Brazo() {
    hombro = new Esfera(2);
    brazoArriba = new Cilindro(1.5, 5);
    codo = new Esfera(2);
    anteBrazo = new Cilindro(1.5, 5);
    mano = new Cilindro(1, 4);

}

void Brazo::draw() {

    glPushMatrix();
        hombro->draw();
        glPushMatrix();
            glTranslatef(0,-5.5, 0);
            brazoArriba->draw();
        glPopMatrix();
        glPushMatrix(); //no le hago otra clase porque el codo no rota
            glTranslatef(0,-5.5, 0);
            glPushMatrix();
                codo->draw();
                glPushMatrix();
                    glTranslatef(0, -5.5, 0);
                    anteBrazo->draw();
                glPopMatrix();
                glPushMatrix();
                    glTranslatef(0,-5.5,2);
                    glRotatef(135, 1, 0, 0);
                    glTranslatef(0,-2,0); //centrar el cilindro en el 0,0,0
                    mano->draw();
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();

}
void Brazo::setModo(int mode) {
    mano->setModo(mode);
    anteBrazo->setModo(mode);
    brazoArriba->setModo(mode);
    codo->setModo(mode);
    hombro->setModo(mode);
}
