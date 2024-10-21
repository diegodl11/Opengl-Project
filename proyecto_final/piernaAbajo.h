//
// Created by diego on 29/11/22.
//

#ifndef PLANTILLA_PRACTICASD_PIERNAABAJO_H
#define PLANTILLA_PRACTICASD_PIERNAABAJO_H
#include "cilindro.h"
#include "esfera.h"
#include "auxiliar.h"

class PiernaAbajo {
private:
    Cilindro * pie = nullptr;
    Cilindro * gemelo =nullptr;
    Esfera * rodilla = nullptr;
public:
    PiernaAbajo();
    void draw();
    void setModo(int mode);

};


#endif //PLANTILLA_PRACTICASD_PIERNAABAJO_H
