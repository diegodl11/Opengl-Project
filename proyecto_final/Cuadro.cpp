//
// Created by diego on 18/12/22.
//

#include "Cuadro.h"

Cuadro::Cuadro(float lado) {
    v.resize(4);
    f.resize(4);

    v[0]={lado/2, 0, lado/2};
    v[1]={lado/2, 0, -lado/2};
    v[2]={-lado/2, 0, -lado/2};
    v[3]={-lado/2, 0, lado/2};

    f[0]={0,1,2};
    f[1]={2,3,0};
    f[2]={0,3,2};
    f[3]={2,1,0};

    setColor(magenta, azul, amarillo);
    calcularNormales();


}