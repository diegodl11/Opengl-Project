//
// Created by diego on 29/11/22.
//

#ifndef PLANTILLA_PRACTICASD_PIERNA_H
#define PLANTILLA_PRACTICASD_PIERNA_H
#include "piernaAbajo.h"
#include "auxiliar.h"
#include "esfera.h"
#include "cilindro.h"


class Pierna {
private:
    std::pair<float, int>
        rRodilla;
    PiernaAbajo * piernaAbajo= nullptr;
    Cilindro * muslo = nullptr;
    Esfera * cadera = nullptr;
    Esfera * cabeza = nullptr;

public:
    Pierna();
    void draw();
    void modificarRRodilla(float angulo/*, float velocidad*/);
    float getGiro();
    void setGiro(float valor);
    void setModo(int mode);
};


#endif //PLANTILLA_PRACTICASD_PIERNA_H
