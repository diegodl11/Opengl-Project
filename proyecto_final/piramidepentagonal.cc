#include "auxiliar.h"
#include "malla.h"
#include "piramidepentagonal.h"
PiramidePentagonal::PiramidePentagonal(float h, float r)
{
    float lPen, aPen, mPen, nPen;
    lPen=2*r*sin(36*pi/180); //lado pentagono
    mPen=lPen*cos(54*pi/180);
    nPen=lPen*sin(54*pi/180);
    aPen=lPen*tan(54*pi/180)/2; //apotema pentágono
    v.resize(6);
    f.resize(8);
   // inicializar la tabla de vértices
   v[0]={0,0,r};
   v[1]={nPen, 0, r-mPen};
   v[2]={lPen/2, 0, -aPen};
   v[3]={-lPen/2, 0, -aPen};
   v[4]={-nPen, 0, r-mPen};
   v[5]={0, h, 0};
   // inicializar la tabla de caras o triángulos:
   f[0]={5, 0, 1};
    f[1]={5, 1, 2};
    f[2]={5, 2, 3};
    f[3]={5, 3, 4};
    f[4]={5, 4, 0};
    f[5]={0, 3, 2};
    f[6]={0, 2, 1};
    f[7]={0,4,3};
   // (es importante en cada cara ordenar los vértices en sentido contrario
   //  de las agujas del reloj, cuando esa cara se observa desde el exterior del cubo)



   // inicializar la/s tabla/s de colores
    setColor(amarillo,magenta, azul);
    calcularNormales();
}

