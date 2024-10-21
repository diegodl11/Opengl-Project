//
// Created by diego on 12/12/22.
//

#include "textura.h"
Textura::Textura(const std::string & archivo) {
    jpg::Imagen * img = NULL;
    img = new jpg::Imagen(archivo);

    //unsigned char * leidos;

    width = img->tamX();
    height = img->tamY();
    data=img->leerPixels();
    /*for (unsigned i = 0; i < height; i++){
        for (unsigned j = 0; j < width; j++){
            leidos = img->leerPixel(j, height - i - 1);
            // introducimos R
            data.push_back(*leidos);
            leidos++;

            // introducimos G
            data.push_back(*leidos);
            leidos++;

            // introducimos B
            data.push_back(*leidos);
            leidos++;
        }


    }*/

    glGenTextures(1, &textura_id);
    glBindTexture(GL_TEXTURE_2D, textura_id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL, GL_SEPARATE_SPECULAR_COLOR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

}
void Textura::activar() {
    glEnable(GL_TEXTURE_2D);
    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, width, height,
                 GL_RGB, GL_UNSIGNED_BYTE, data);
}