#include "auxiliar.h"
#include "malla.h"
#include "cubo.h"

Cubo::Cubo(const float lado)
{

   // inicializar la tabla de vértices
    v.resize(10);
    f.resize(12);
    v[0] = {-lado/2, lado, lado/2};
    v[1] = {-lado/2, 0.0f, lado/2};
    v[2] = {lado/2, 0.0f, lado/2};
    v[3] = {lado/2, lado, lado/2};
    v[4] = {-lado/2, lado, -lado/2};
    v[5] = {lado/2, 0.0f, -lado/2};
    v[6] = {-lado/2, 0.0f, -lado/2};
    v[7] = {lado/2, lado, -lado/2};
    // inicializar la tabla de caras o triángulos:

    // cara delantera
    f[0] = {0, 1, 2};
    f[1] = {3, 0, 2};

    //cara lateral derecha
    f[2] = {3, 2, 5};
    f[3] = {7, 3, 5};

    // cara trasera
    f[4] = {7, 5, 6};
    f[5] = {4, 7, 6};

    //cara lateral izquierda
    f[6] = {4, 6, 1};
    f[7] = {0, 4, 1};


    //cara superior
    f[8] = {0, 3, 7};
    f[9] = {4, 0, 7};

    //cara inferior
    f[10] = {1, 5, 2};
    f[11] = {5, 1, 6};



   // (es importante en cada cara ordenar los vértices en sentido contrario
   //  de las agujas del reloj, cuando esa cara se observa desde el exterior del cubo)

    setColor(magenta, azul, amarillo);
    cs.resize(v.size());
    colorS={1,0,0};
    for(int i=0; i< v.size(); i++) {
        cs[i]=colorS;
    }
    calcularNormales();


}

