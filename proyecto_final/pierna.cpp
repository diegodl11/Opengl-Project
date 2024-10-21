//
// Created by diego on 29/11/22.
//

#include "pierna.h"

Pierna::Pierna() {
    rRodilla.first=0;
    rRodilla.second=0;
    piernaAbajo = new PiernaAbajo();
    muslo = new Cilindro(1.5, 6);
    cadera = new Esfera(2);
}
void Pierna::draw(){
    glPushMatrix();
        cadera->draw();
        glPushMatrix();
            glTranslatef(0,-6.5,0);
            muslo->draw();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0,-7,0); //se translada para poner ahora la pierna
            glRotatef(rRodilla.first, 1, 0, 0);
            piernaAbajo->draw();
        glPopMatrix();
    glPopMatrix();

}
void Pierna::modificarRRodilla(float angulo/*, float velocidad*/) {
    /*if(rRodilla.first+angulo>60)
        rRodilla.second=1;
    if(rRodilla.first+angulo<0)
        rRodilla.second=2;
    if(rRodilla.second==1)
        angulo=-angulo;
    if(rRodilla.second==2)
        angulo=0;*/
    //angulo*=velocidad;
    //if(rRodilla.first+angulo>=0 && rRodilla.first+angulo<=60)
        rRodilla.first= rRodilla.first+angulo;
}
float Pierna::getGiro() {
    return rRodilla.first;
}
void Pierna::setGiro(float valor) {
    rRodilla.first=valor;
}
void Pierna::setModo(int mode) {
    muslo->setModo(mode);
    cadera->setModo(mode);
    piernaAbajo->setModo(mode);
}