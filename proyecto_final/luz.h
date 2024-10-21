//
// Created by diego on 23/10/22.
//

#ifndef PLANTILLA_PRACTICASD_LUZ_H
#define PLANTILLA_PRACTICASD_LUZ_H
#include "auxiliar.h"
#define  pi 3.14159265
class Luz {
protected:
    Tupla4f posicion;
    GLenum id;
    Tupla4f colorAmbiente;
    Tupla4f colorDifuso;
    Tupla4f colorEspecular;
public:
    void activar();
    void desactivar();
};


#endif //PLANTILLA_PRACTICASD_LUZ_H
