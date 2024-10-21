#ifndef _ESCENA_H
#define _ESCENA_H


#include "ejes.h"
#include "malla.h"
#include "cubo.h"
#include "piramidepentagonal.h"
#include "objply.h"
#include "objrevolucion.h"
#include "cono.h"
#include "cilindro.h"
#include "esfera.h"
#include "luzdireccional.h"
#include "luzposicional.h"
#include "material.h"
#include "modeloJerarquico.h"
#include "Cuadro.h"
#include "camara.h"


typedef enum {NADA, MODOANIMACION, MODOMANUAL, SELVISUALIZACION, MODOCAMARAS} menu;
//typedef enum {NINGUNO, CUBO, PIRAMIDE} objetoVisible;
typedef enum {MOVIENDO_CAMARA_FIRSTPERSON, MOVIMIENDO_CAMARA_EXAMINAR, NINGUNO} EstadoRaton;
class Escena
{

   private:

   

 // ** PARÁMETROS DE LA CÁMARA (PROVISIONAL)


    // Transformación de cámara
	void change_projection( );
	void change_observer();
    


   void clear_window();

   menu modoMenu=NADA;
   EstadoRaton estadoRaton= MOVIENDO_CAMARA_FIRSTPERSON;
   // Objetos de la escena
   Ejes ejes;
   Cubo * cubo = nullptr ; // es importante inicializarlo a 'nullptr'
   PiramidePentagonal * piramide= nullptr ; // es importante inicializarlo a 'nullptr'
   ObjPLY * plyo = nullptr;
   Cono * cono=nullptr;
   Cilindro * cilindro=nullptr;
    Esfera * esfera = nullptr;
    ObjRevolucion * plyRevolucion = nullptr;
    ObjRevolucion * vectorPRevolucion = nullptr;
    LuzDireccional * luz0 = nullptr;
    LuzPosicional * luz1 = nullptr;
    ModeloJerarquico * persona = nullptr;
    Cuadro * cuadro = nullptr;
    Cubo * suelo = nullptr;
    std::vector<Camara *> camaras;

    bool objetoPinchado=false;
   int modoVisualizacion[4], gradoAumentado, gradosAumentados[8], contLuces; //la posición 0 activo o desactivado el sólido, la 1 las líneas  y la dos los puntos
   bool desactivarLuces;
    int camaraActiva;
    int xant=0, yant=0;

    Tupla4f colorAmbiente, colorEspecular, colorDifuso, colorAmbiente1, colorEspecular1, colorDifuso1;
    int numLuz[7];
    bool variacionAlfa, variacionBeta, sumarAngulo, restarAngulo, animarModelo, animarLuces;
    Material * material1= nullptr,
        * material2= nullptr, * material3= nullptr, * material4= nullptr, * material5= nullptr, * materialPiel= nullptr,
        *materialBlanco=nullptr, *materialMarron=nullptr;
   void inicializarTexturas();
   public:

    Escena();
    ~Escena();
    void clickRaton(int boton, int estado, int x, int y);
    void ratonMovido (int x, int y);
	void inicializar( int UI_window_width, int UI_window_height );
	void redimensionar( int newWidth, int newHeight ) ;
    void crearMateriales();
    void animar();
	// Dibujar
	void dibujar() ;
    void modificarModeloJerarquico();
	// Interacción con la escena
	bool teclaPulsada( unsigned char Tecla1, int x, int y ) ;
	void teclaEspecial( int Tecla1, int x, int y );
    void crearSuelo();
    void inicializarCamaras();
    void dibujarSeleccion();
    void processPick(int x, int y);
    void procesarCambioObjetoSeleccionado(Malla3D * malla);
    void texturizarCubo();

};
#endif
