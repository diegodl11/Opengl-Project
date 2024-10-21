//
// Created by diego on 18/10/22.
//
#include "cilindro.h"
Cilindro::Cilindro(const float r, const float h) {
    std::vector<Tupla3f> perfil;
    perfil.resize(4);
    perfil[0]={0,0,0};
    perfil[1]={r,0,0};
    perfil[2]={r, h, 0};

    perfil[3]={0,h,0};
    crearMalla(perfil, 40);
    //calcCordText();
    setColor(azul, magenta, amarillo);

    calcularNormales();


}
