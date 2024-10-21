//
// Created by diego on 1/11/22.
//

#include "material.h"
Material::Material(Tupla4f mdifuso, Tupla4f mespecular, Tupla4f mambiente, float brillo) {
    ambiente=mambiente;
    difuso=mdifuso;
    especular=mespecular;
    this->brillo=brillo;

}
void Material::aplicar() {
    Tupla4f  aux = {0.5,0.5,0,1};
    //glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, aux);
    //glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, aux);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuso);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, especular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambiente);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, brillo);
}
