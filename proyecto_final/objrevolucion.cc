#include "auxiliar.h"
#include "objrevolucion.h"




// *****************************************************************************
//
// Clase ObjRevolucion (práctica 2)
//
// *****************************************************************************


// *****************************************************************************
// objeto de revolución obtenido a partir de un perfil (en un PLY)
using namespace std;
ObjRevolucion::ObjRevolucion() {}

ObjRevolucion::ObjRevolucion(const std::string & archivo, int num_instancias) {
   // completar ......(práctica 2)
    std::vector<Tupla3f> perfil;
    ply::read_vertices( archivo, perfil);

    crearMalla(perfil, num_instancias);
    setColor(azul, magenta, amarillo);
    calcularNormales();
}

// *****************************************************************************
// objeto de revolución obtenido a partir de un perfil (en un vector de puntos)

 
ObjRevolucion::ObjRevolucion(std::vector<Tupla3f> archivo, int num_instancias) {

    crearMalla(archivo, num_instancias);
    setColor(azul, magenta, amarillo);
    calcularNormales();
}

void ObjRevolucion::crearMalla(std::vector<Tupla3f> perfil_original, int num_instancias) {
    //con esta primera parte de código obtenemos el perfil sin polos
    //std::cout<<"hey1"<<std::endl;
    std::vector<Tupla3f> polo, perfilNuevo;
    float  epsilon=0.000001;

    //obtener polos
    if (fabs(perfil_original[0](0)) < epsilon && fabs(perfil_original[0](2)) < epsilon ) { //mirar si los polos están en el eje y
        polo.push_back(perfil_original[0]);
        perfil_original.erase(perfil_original.begin());
    }
    if( fabs(perfil_original[perfil_original.size()-1](0)) < epsilon && fabs(perfil_original[perfil_original.size()-1](2)) < epsilon){
        polo.push_back(perfil_original[perfil_original.size()-1]);
        perfil_original.erase(--perfil_original.end());
    }
    //creamos el nuevo perfil.
    if(perfil_original[0](1)<perfil_original[perfil_original.size()-1](1))  //si esta ordenado de abajo a arriba se introduce normal
        perfilNuevo=perfil_original;
    else
        for (int i = perfil_original.size()-1; i >=0; i--) //si está ordenado de arriba a abajo se da la vuelta
            perfilNuevo.push_back(perfil_original[i]);



    if(polo.size() !=0)
        if(polo[0](1)>polo[1](1)){
            poloNorte=polo[0];
            poloSur=polo[1];
        }else{
            poloNorte=polo[1];
            poloSur=polo[0];
        }

    /*
     * sacamos por pantalla los puntos*/

    /*for(std::vector<Tupla3f>::iterator it=perfilNuevo.begin() ; it!=perfilNuevo.end(); ++it){
            std::cout<<(*it)<<" ";
        }

        std::cout<<poloSur<<" ";

        std::cout<<poloNorte<<" ";
        std::cout<<std::endl;*/



    //ahora vamos a comenzar a generar lo que es la malla
    M=perfilNuevo.size();
    N=num_instancias;
    float angulo, x1, y1, z1;
    int a, b;
    Tupla3f tAux2;
    Tupla3i tAux3;
    //generamos el vector de puntos
    v.resize(N*M);

    for (int i = 0; i < N; ++i) {
        angulo=2*pi*i/N; //simplificado de (360/N)*pi/180
        for (int j = 0; j < M; ++j) {
            x1=perfilNuevo[j](0)*cos(angulo)+perfilNuevo[j](2)*sin(angulo);
            y1=perfilNuevo[j](1);
            z1=-perfilNuevo[j](0)*sin(angulo)+perfilNuevo[j](2)*cos(angulo);
            tAux2 = {x1,y1, z1};
            v[M*i+j]=tAux2;
            if(i==0) {
                v.push_back(tAux2);
            }
        }
    }

   /* for(std::vector<Tupla3f>::iterator it=v.begin() ; it!=v.end(); ++it){
        std::cout<<(*it)<<" ";
    }
    std::cout<<std::endl;*/
    //generamos el vector de triángulos
    f.resize(0);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M-1; ++j) {
            a=M*i+j;
            b= M*(i+1)+j;
            tAux3={a,b,b+1};
            //std::cout << "(" << a << ", " <<b<< ", " << b+1 << ")" << std::endl;
            f.push_back(tAux3);
            tAux3={a,b+1,a+1};
            //std::cout << "(" << a << ", " <<b+1<< ", " << a+1<< ")" << std::endl;
            f.push_back(tAux3);
        }

    }




    //generamos las tapas
    if(polo.size()!=0) {
        Tupla3i tAux4;

        v.push_back(poloSur);

        v.push_back(poloNorte);

        for (int i = 0; i <N; ++i) {
                //triángulos conectados con el polo sur
                a = (M * i);
                b =  M * (i + 1) ;
                //std::cout << "(" << a << ", " << N * M << ", " << b << ")" << std::endl;
                tAux4 = {b, a,N * M+M };
                f.push_back(tAux4);

                // triangulos conectdos con el polo norte
                a = (M * i) + M - 1;
                b =  M *(i + 1)  + M - 1;
                tAux4 = {N*M+M+1,a, b};
                f.push_back(tAux4);
        }
    }
    /*for(std::vector<Tupla3i>::iterator it=f.begin() ; it!=f.end(); ++it){
        std::cout<<(*it)<<" ";
    }
    std::cout<<std::endl;*/
    N++; //sumamos a n uno porque tiene un perfil más.
    float c,d,e;
    distancias.push_back(0.0);
    for(int i = 1; i < M; i++){
        c = perfilNuevo[i][0] - perfilNuevo[i-1][0];
        d = perfilNuevo[i][1] - perfilNuevo[i-1][1];
        e = perfilNuevo[i][2] - perfilNuevo[i-1][2];
        distancias.push_back(sqrt(c*c + d*d + e*e) + distancias[i-1]);
    }





}
void ObjRevolucion::calcCordText() {
    float x;
    for(int i = 0; i <N; i++){
        x = (i*1.0)/(N-1);
        for(int j = 0; j < M; j++)
            ct.push_back({x, 1 - distancias[j]/distancias[distancias.size()-1]});

    }
    /*for(std::vector<Tupla2f>::iterator it=ct.begin() ; it!=ct.end(); ++it){
        std::cout<<(*it)<<" ";
    }
    std::cout<<std::endl;*/
}
