#include "auxiliar.h"
#include "cono.h"

Cono::Cono(const float r, const float h)
{
    std::vector<Tupla3f> perfil;
    perfil.resize(4);
    //perfil[0]={r/2, h/2,0};
    perfil[0]={0,0,0};
    perfil[1]={r, 0, 0};
    perfil[2]={r/16, h-h/16, 0};
    perfil[3]={0, h, 0};

    crearMalla(perfil, 40);

    setColor(azul, magenta, amarillo);
    //añadimos el color de selcción
    cs.resize(v.size());
    colorS={1,1,0};
    for(int i=0; i< v.size(); i++) {
        cs[i]=colorS;
    }
    calcularNormales();

}

