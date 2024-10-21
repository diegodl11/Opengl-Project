//
// Created by diego on 23/10/22.
//

#ifndef PLANTILLA_PRACTICASD_LUZDIRECCIONAL_H
#define PLANTILLA_PRACTICASD_LUZDIRECCIONAL_H
#include "luz.h"
#include "auxiliar.h"

class LuzDireccional : public Luz{
protected:
    float alpha;
    float beta;
    int cont;
public:
    LuzDireccional(Tupla2f direccion, GLenum idLuzOpenGL,
                   Tupla4f colorAmbiente, Tupla4f colorEspecular,
                   Tupla4f colorDifuso);
    void variarAnguloAlpha(float incremento);
    void variarAnguloBeta(float incremento);
    void animar();
};


#endif //PLANTILLA_PRACTICASD_LUZDIRECCIONAL_H
