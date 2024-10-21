//
// Created by diego on 29/11/22.
//

#ifndef PLANTILLA_PRACTICASD_BRAZO_H
#define PLANTILLA_PRACTICASD_BRAZO_H
#include "cilindro.h"
#include "esfera.h"
#include "auxiliar.h"

class Brazo {
private:
    Esfera * hombro = nullptr;
    Cilindro * brazoArriba = nullptr;
    Esfera * codo = nullptr;
    Cilindro * anteBrazo = nullptr;
    Cilindro * mano = nullptr;
public:
    Brazo();
    void draw();
    void setModo(int mode);
};


#endif //PLANTILLA_PRACTICASD_BRAZO_H
