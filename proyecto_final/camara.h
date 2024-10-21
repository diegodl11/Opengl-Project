//
// Created by diego on 19/12/22.
//

#ifndef PLANTILLA_PRACTICASD_CAMARA_H
#define PLANTILLA_PRACTICASD_CAMARA_H
#include "auxiliar.h"
/**
 * Como el AT siempre es el 0,0 se gira entorno al centro
 * en examinar el centro tiene que ser una coordenada de un objeto
 * rotar en y y rotar en x a la camara tiene que ser modificar el valor del eye para girar en torno a ese AT
 * Lo más fácil es calcular un vector eye - at, lo roto y vuelvo a calcular el nuevo eye.
 * Cuando la camara está en modo primera persona, el eye está fijo y lo que se mueve es el at.
 *
 * Cuando tú mueves la cámara el sistema de coordenadas no es el del mundo, es el del observador. En los dos modos
 *
 * Le puedo poner la posibilidad de moverse a la camara.
 *
 * Si una camara está en perspectiva u ortogonal, son parámetros intrinsecos de la cámara.
 *
 * Los parametros extrinsecos se hacen con el modelview
 *
 * La matriz que está activa cuando se calcula la proyeccion es la de gl_projection
 *
 * cada vez que cambies la camara hay que cambiar de gl_projection
 *
 * Para hacer un zoom hay que hacer más pequeño el campo de visión es decir cambiar los valores left top bottom y tal a más pequeños.
 *
 * Al redimnensionar la ventana hay que hacer que esta tenga las mismas proporciones de la ventana entonces, hay que hacer que no se estiren
 * los objetos si no que ahora veamos la escena más grande, en vez de cuadrada, panorámica.
 *
 * Hay que hacer que al seleccionar el objeto cambie a modo líneas o algo así. Y hay que hacer que se siga viendo la iluminación.
 */
class Camara {
private:
    //parámetros extrinsecos
    Tupla3f eye ;
    Tupla3f at ;
    Tupla3f up ;
    //parámetros intrínsecos
    //tipo 1 perspectiva, tipo 0 ortogonal
    int tipo ; // ORTOGONAL o Perspectiva
    float left , right , near , far, top, bottom ;
public:
    Camara (const Tupla3f & eye, const Tupla3f & at, const Tupla3f & up,
            const int & tipo, const float near, const float far) ; // con los parametros necesarios
    void rotarXExaminar ( float angle );
    void rotarYExaminar ( float angle );
    void rotarZExaminar ( float angle );
    void rotarXFirstPerson ( float angle );
    void rotarYFirstPerson ( float angle );
    void rotarZFirstPerson ( float angle );
    void mover ( float x, float y, float z );
    void zoom ( float factor );
    void girar(int x, int y);
    void girarExaminar(int x, int y);
    //posicionar la cámara es solo con esta función camara3.setObserver se posiciona. Parámetros extrínsecos de la camara (no tienen que ver con la fabricación).
    void setObserver ();
    void setProyeccion ();
    void setLeft(float valor);
    void setRight(float valor);
    void setBottom(float valor);
    void setTop(float valor);
    void setAt(Tupla3f valor);
    float getBottom();
    float getTop();

};


#endif //PLANTILLA_PRACTICASD_CAMARA_H
