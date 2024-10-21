//
// Created by diego on 12/12/22.
//

#ifndef PLANTILLA_PRACTICASD_TEXTURA_H
#define PLANTILLA_PRACTICASD_TEXTURA_H

#include "auxiliar.h"
#include "jpg_imagen.hpp"

class Textura {
private:
    GLuint textura_id=0;
    unsigned char * data;
    int width, height;
public:
    Textura(const std::string & archivo);
    void activar();
};


#endif //PLANTILLA_PRACTICASD_TEXTURA_H
