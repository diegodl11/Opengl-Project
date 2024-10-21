//
// Created by diego on 23/10/22.
//

#ifndef PLANTILLA_PRACTICASD_LUZPOSICIONAL_H
#define PLANTILLA_PRACTICASD_LUZPOSICIONAL_H
#include "luz.h"
#include "auxiliar.h"

class LuzPosicional : public Luz{
private:
    bool derecha;
public:
    LuzPosicional(Tupla3f posicion, GLenum idLuzOpenGL,
            Tupla4f colorAmbiente, Tupla4f colorEspecular,
            Tupla4f colorDifuso);
    void animar();
};


#endif //PLANTILLA_PRACTICASD_LUZPOSICIONAL_H
