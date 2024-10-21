//
// Created by diego on 29/11/22.
//

#ifndef PLANTILLA_PRACTICASD_MODELOJERARQUICO_H
#define PLANTILLA_PRACTICASD_MODELOJERARQUICO_H
#include "cilindro.h"
#include "esfera.h"
#include "torso.h"
#include "auxiliar.h"
#include "pierna.h"
#include "brazo.h"
#include "cabeza.h"


class ModeloJerarquico {
private:
    std::pair<float, int>
        rPierna1,
        rPierna2,
        rBrazo1,
        rBrazo2,
        salto;
    float velocidadAnimacion;
    Pierna * pierna2=nullptr;
    Pierna * pierna1=nullptr;
    Torso * torso = nullptr;
    Brazo * brazo1=nullptr;
    Brazo * brazo2= nullptr;
    Cabeza * cabeza = nullptr;
    bool finSalto, giroRodillas, giroPiernas, primeraParte, movBrazo1, movBrazo2, movLengua, giroBrazos, finLengua;

public:
    ModeloJerarquico();
    void draw();
    void modificarRRodilla1(float angulo);
    void modificarRRodilla2(float angulo);
    void modificarRPierna1(float angulo);
    void modificarRPierna2(float angulo);
    void modificarRBrazo1(float angulo);
    void modificarRBrazo2(float angulo);
    void modificarTLengua(float desplazamiento);
    void modificarSalto(float desplazamiento);
    void modificarVelocidadAnimacion(float velocidad);
    void animar();
    void setModo(int mode);
    void setTextura (const std::string & texCabeza, const std::string & texTorso);
};


#endif //PLANTILLA_PRACTICASD_MODELOJERARQUICO_H
