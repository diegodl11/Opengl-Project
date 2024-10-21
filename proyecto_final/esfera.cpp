//
// Created by diego on 18/10/22.
//
#include "esfera.h"


Esfera::Esfera(const float r) {
    std::vector <Tupla3f> perfil;
    int num_instancias = 40;
    Tupla3f aux = {0, r, 0}, aux1;
    float x, y, angulo;
    perfil.push_back(aux);
    for (int i = 1; i < num_instancias / 2; i++) {
        angulo = 2 * pi * i / num_instancias;
        x = aux(0) * cos(angulo) - aux(1) * sin(angulo);
        y = aux(0) * sin(angulo) + aux(1) * cos(angulo);
        aux1 = {x, y, 0};
        perfil.push_back(aux1);
    }
    aux={0,-r,0};
    perfil.push_back(aux);
    crearMalla(perfil, num_instancias);
    setColor(azul, magenta, amarillo);
    calcularNormales();

}