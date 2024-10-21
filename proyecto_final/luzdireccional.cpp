//
// Created by diego on 23/10/22.
//

#include "luzdireccional.h"
LuzDireccional::LuzDireccional(Tupla2f direccion, GLenum idLuzOpenGL,
                               Tupla4f colorAmbiente, Tupla4f colorEspecular,
                               Tupla4f colorDifuso) {
    float x=0, y=0, z=1;
    alpha=direccion(0)*pi/180;
    beta=direccion(1)*pi/180;
    x=sin(alpha)*cos(beta);
    y=-sin(beta);
    z=cos(beta)*cos(alpha);
    Tupla4f aux = {x, y, z,0};
    this->posicion=aux;
    this->colorAmbiente=colorAmbiente;
    this->colorDifuso=colorDifuso;
    this->colorEspecular=colorEspecular;
    this->id=idLuzOpenGL;
    cont=1;
}

void LuzDireccional::variarAnguloAlpha(float incremento) {
    incremento=incremento*pi/180;
    if(incremento+alpha>=2*pi){
        incremento=incremento-(2*pi-alpha);
        alpha=incremento;
    }else
        alpha=incremento+alpha;
    float x=0, y=0, z=1;
    x=sin(alpha)*cos(beta);
    y=-sin(beta);
    z=cos(beta)*cos(alpha);
    Tupla4f aux = {x, y, z,0};
    this->posicion=aux;
}

void LuzDireccional::variarAnguloBeta(float incremento) {
    incremento=incremento*pi/180;
    if(incremento+beta>=2*pi){
        incremento=incremento-(2*pi-beta);
        beta=incremento;
    }else
        beta=incremento+beta;
    float x=0, y=0, z=1;
    x=sin(alpha)*cos(beta);
    y=-sin(beta);
    z=cos(beta)*cos(alpha);
    Tupla4f aux = {x, y, z,0};
    this->posicion=aux;
}
void LuzDireccional::animar() {
    switch (cont) {
        case 1:
            colorAmbiente={1,0,0,1};
            colorDifuso={1,0,0,1};
            colorEspecular={1,0,0,1};
            break;
        case 2:
            colorAmbiente={0,1,0,1};
            colorDifuso={0,1,0,1};
            colorEspecular={0,1,0,1};
            break;
        case 3:
            colorAmbiente={0,0,1,1};
            colorDifuso={0,0,1,1};
            colorEspecular={0,0,1,1};
            break;
        case 4:
            colorAmbiente={1,1,0,1};
            colorDifuso={1,1,0,1};
            colorEspecular={1,1,0,1};
            break;
        case 5:
            colorAmbiente={1,0,1,1};
            colorDifuso={1,0,1,1};
            colorEspecular={1,0,1,1};
            break;
        case 6:
            colorAmbiente={0,1,1,1};
            colorDifuso={0,1,1,1};
            colorEspecular={0,1,1,1};
            break;
        case 7:
            colorAmbiente={0,0,0,1};
            colorDifuso={1,1,1,1};
            colorEspecular={1,1,1,1};
            cont=0;
            break;

    }
    cont++;
}