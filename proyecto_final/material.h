//
// Created by diego on 1/11/22.
//

#ifndef PLANTILLA_PRACTICASD_MATERIAL_H
#define PLANTILLA_PRACTICASD_MATERIAL_H
#include "auxiliar.h"

class Material {
private:
    Tupla4f difuso;
    Tupla4f especular;
    Tupla4f ambiente;
    float brillo;
public:
    Material(Tupla4f mdifuso, Tupla4f mespecular, Tupla4f mambiente, float brillo);
    void aplicar();
};


#endif //PLANTILLA_PRACTICASD_MATERIAL_H
