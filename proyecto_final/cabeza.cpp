//
// Created by diego on 30/11/22.
//

#include "cabeza.h"
Cabeza::Cabeza() {
    tLengua.first=0;
    tLengua.second=0;
    cuello = new Cilindro(2, 5);
    cabeza = new Esfera(5);
    cabeza->calcCordText();
    lengua = new Esfera(2.5);

}
void Cabeza::draw() {
    glPushMatrix();
        cuello->draw();
        glPushMatrix();
            glTranslatef(0,8,0);
            glRotatef(10, 1, 0, 0);
            glRotatef(-70, 0, 1, 0);

            cabeza->draw();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0,7,3+tLengua.first);
            glScalef(0.7,0.3,1);
            lengua->draw();
        glPopMatrix();
    glPopMatrix();
}
void Cabeza::modificarTLengua(float desplazamiento/*, float velocidad*/) {
    /*if(tLengua.first+desplazamiento>1.5)
        tLengua.second=1;
    if(tLengua.first+desplazamiento<0)
        tLengua.second=2;
    if(tLengua.second==1)
        desplazamiento=-desplazamiento;
    if(tLengua.second==2)
        desplazamiento=0;*/
    //desplazamiento*=velocidad;
    //if(tLengua.first+desplazamiento<=1.5 && tLengua.first+desplazamiento>=0)
        tLengua.first+=desplazamiento;
}
float Cabeza::getLengua() {
    return tLengua.first;
}
void Cabeza::setLengua(float valor) {
    tLengua.first=valor;
}
void Cabeza::setTextura(const std::string & archivo) {
    cabeza->setTextura(archivo);
}