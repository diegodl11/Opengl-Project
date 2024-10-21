//
// Created by diego on 23/10/22.
//

#include "luz.h"

void Luz::activar() {
    glEnable(id);
    glLightfv(id,GL_DIFFUSE, colorDifuso);
    glLightfv(id,GL_SPECULAR, colorEspecular);
    glLightfv(id,GL_AMBIENT, colorAmbiente);
    glLightfv(id,GL_POSITION,  posicion);
}
void Luz::desactivar() {
    glDisable(id);
}