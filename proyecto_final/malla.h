// #############################################################################
//
// Informática Gráfica D (Grado Informática)
//
// Archivo: Malla3D.h
// -- declaraciones de clase Malla3D (mallas indexadas) y derivados
//
// #############################################################################

#ifndef MALLA3D_H_INCLUDED
#define MALLA3D_H_INCLUDED

#include "auxiliar.h"
#include "textura.h"
// *****************************************************************************
//
// clase para objetos 3D (mallas indexadas)
//
// *****************************************************************************
#define  pi 3.14159265
class Malla3D
{
   public:

   // función que dibuja el objeto en modo diferido (usando VBOs)
        Malla3D();
        ~Malla3D();
        void draw() ;
        GLuint CrearVBO ( GLuint tipo_vbo , GLuint tam ,
                          GLvoid * puntero_ram );
        void colorear(Tupla3f color1, Tupla3f color2, Tupla3f color3);
        void setColor(Tupla3f color1, Tupla3f color2, Tupla3f color3);
        void setModo(int mode){modo=mode;}
        void calcularNormales();
        void setTextura(const std::string & archivo);
        void setTextura(const std::string & archivo1, const std::string & archivo2);
        void crearVectorTexturas(std::vector<Tupla2f> tex);
        Tupla3f getColorS();
        void setCentro(Tupla3f cent);
        Tupla3f getCentro();
        int getModo();
        void setModoSeleccion(int valor);
        int getModoSeleccion();
   protected:

        GLuint id_vbo_c, id_vbo_ver, id_vbo_tri, id_vbo_c1, id_vbo_c2, id_vbo_n, id_vbo_tex, id_vbo_cs;
        std::vector<Tupla3f> v ;   // tabla de coordenadas de vértices (una tupla por vértice, con tres floats)
        std::vector<Tupla3i> f ; // una terna de 3 enteros por cada cara o triángulo
        std::vector<Tupla3f> c ; // una terna de 3 floats que represantan el RGB
        std::vector<Tupla3f> c1 ; // una terna de 3 floats que represantan el RGB
        std::vector<Tupla3f> c2 ; // una terna de 3 floats que represantan el RGB
        std::vector<Tupla3f> nv; //normales de los vértices
        std::vector<Tupla2f> ct; //normales de texturas
        std::vector<Tupla3f> cs; //color selcción
        Tupla3f colorS;
        Tupla3f azul={0,1,1};
        Tupla3f magenta={1,0,1};
        Tupla3f amarillo={1,1,0};
        Textura * textura1 = nullptr, *textura2=nullptr;

        Tupla3f centro;
        int modo=0, modoSeleccion=0;
       // completar P1: tabla de colores
       // Completar P1: vbo y método asociado

} ;


#endif
