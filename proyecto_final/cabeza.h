//
// Created by diego on 30/11/22.
//

#ifndef PLANTILLA_PRACTICASD_CABEZA_H
#define PLANTILLA_PRACTICASD_CABEZA_H
#include "esfera.h"
#include "cilindro.h"
#include "auxiliar.h"

class Cabeza {
private:
    std::pair<float, int>
        tLengua;
    Cilindro * cuello = nullptr;
    Esfera * cabeza = nullptr;
    Esfera * lengua = nullptr;
public:
    Cabeza();
    void draw();
    void setTextura(const std::string & archivo);
    void modificarTLengua(float desplazamiento/*, float velocidad*/);
    float getLengua();
    void setLengua(float valor);
};


#endif //PLANTILLA_PRACTICASD_CABEZA_H
