//
// Created by diego on 23/10/22.
//

#include "luzposicional.h"
LuzPosicional::LuzPosicional(Tupla3f posicion, GLenum idLuzOpenGL,
        Tupla4f colorAmbiente, Tupla4f colorEspecular, Tupla4f colorDifuso){
    Tupla4f aux = {posicion(0),posicion(1),posicion(2),1};
    this->posicion=aux;
    this->colorAmbiente=colorAmbiente;
    this->colorDifuso=colorDifuso;
    this->colorEspecular=colorEspecular;
    this->id=idLuzOpenGL;
    derecha=true;
}

void LuzPosicional::animar() {
    if(derecha)
        posicion(0)=posicion(0)+5;
    else
        posicion(0)=posicion(0)-5;
    if(posicion(0)==300)
        derecha=false;
    if(posicion(0)==-300)
        derecha=true;
}