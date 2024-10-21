//
// Created by diego on 18/12/22.
//

#include "torso.h"


Torso::Torso(const float lado)
{

    // inicializar la tabla de vértices
    v.resize(14);
    f.resize(12);
    float a=lado/2, l=lado;
    v[0] = {a,l,a};
    v[1] = {-a, l, a};
    v[2] = {-a, 0, a};
    v[3] = {a, 0, a};
    v[4] = {a, 0, -a};
    v[5] = {a, l, -a};
    v[6] = {-a, l, -a};
    v[7] = {-a, 0, -a};
    v[8] = {a, l, -a};
    v[9] = {a, 0, -a};

    //tapas
    v[10] = {a, l, -a};
    v[11] = {-a, l, -a};
    v[12] = {a, 0, -a};
    v[13] = {-a, 0, -a};

    // inicializar la tabla de caras o triángulos:

    // cara delantera
    f[0] = {0, 1, 2};
    f[1] = {3, 0, 2};

    //cara lateral derecha
    f[2] = {0, 3, 5};
    f[3] = {5, 3, 4};

    // cara trasera
    f[4] = {7, 6, 8};
    f[5] = {8, 9, 7};

    //cara lateral izquierda
    f[6] = {1, 6, 2};
    f[7] = {6, 7, 2};


    //cara superior
    f[8] = {5, 6, 1};
    f[9] = {5, 1, 0};

    //cara inferior
    f[10] = {2, 13, 12};
    f[11] = {2, 12, 3};



    // (es importante en cada cara ordenar los vértices en sentido contrario
    //  de las agujas del reloj, cuando esa cara se observa desde el exterior del cubo)

    setColor(magenta, azul, amarillo);
    calcularNormales();


}
