#include "auxiliar.h"
#include "malla.h"

// *****************************************************************************
//
// IG_D Clase Malla3D
//
// *****************************************************************************
// -----------------------------------------------------------------------------
// Función de visualización de la malla,
using namespace std;
Malla3D::Malla3D() {
    id_vbo_c=id_vbo_c1=id_vbo_c2=id_vbo_tri=id_vbo_ver=id_vbo_n=id_vbo_tex=id_vbo_cs=0;

}
void Malla3D::draw()
{

   // (la primera vez, se deben crear los VBOs y guardar sus identificadores en el objeto)
   // completar (práctica 1)
   // .....
   glShadeModel(GL_SMOOTH);
    if ( id_vbo_c == 0 )
        id_vbo_c = CrearVBO(GL_ARRAY_BUFFER, 3*c.size()*sizeof(float), c.data());
    if( id_vbo_ver == 0)
        id_vbo_ver= CrearVBO(GL_ARRAY_BUFFER, 3*v.size()*sizeof(float), v.data());
    if( id_vbo_tri == 0)
        id_vbo_tri= CrearVBO(GL_ARRAY_BUFFER, 3*f.size()*sizeof(int), f.data());
    if ( id_vbo_c1 == 0 )
        id_vbo_c1 = CrearVBO(GL_ARRAY_BUFFER, 3*c.size()*sizeof(float), c1.data());
    if ( id_vbo_c2 == 0 )
        id_vbo_c2 = CrearVBO(GL_ARRAY_BUFFER, 3*c.size()*sizeof(float), c2.data());
    if(id_vbo_n==0)
        id_vbo_n=CrearVBO(GL_ARRAY_BUFFER, 3*nv.size()*sizeof(float), nv.data());
    if(id_vbo_tex==0)
        id_vbo_tex=CrearVBO(GL_ARRAY_BUFFER, 3*ct.size()*sizeof(float), ct.data());
    if(id_vbo_cs==0 && cs.size()>0)
        id_vbo_cs= CrearVBO(GL_ARRAY_BUFFER, 3*cs.size()*sizeof(float), cs.data());
    if ( !id_vbo_c || !id_vbo_ver || !id_vbo_tri || !id_vbo_c1 || !id_vbo_c2 || !id_vbo_n || !id_vbo_tex ) return;

    // habilitar uso de array de colores
    glEnableClientState ( GL_COLOR_ARRAY );
    // habilitar uso de array de vértices
    glEnableClientState ( GL_VERTEX_ARRAY );
    // habilitar uso de array de normales
    glEnableClientState ( GL_NORMAL_ARRAY );
    // especifícar cual es el VBO que vamos a usar
    glBindBuffer ( GL_ARRAY_BUFFER , id_vbo_ver );

    glVertexPointer ( 3 , GL_FLOAT , 0 , 0 );

    glBindBuffer ( GL_ARRAY_BUFFER , 0);

    // especifícar cual es el VBO que vamos a usar
    if(modo==0)
        glBindBuffer ( GL_ARRAY_BUFFER , id_vbo_c );
    else if(modo==1)
        glBindBuffer ( GL_ARRAY_BUFFER , id_vbo_c1 );
    else if(modo==2)
        glBindBuffer ( GL_ARRAY_BUFFER , id_vbo_c2);
    else if(modo==3) { //modo de selección
        glBindBuffer(GL_ARRAY_BUFFER, id_vbo_cs);
    }
    /*
     * El stride te dice el desplazamiento entre zonas de color
     * el último argumento donde empieza
     * con un getter del polygon mode puedo sacar el lugar donde empiezo en el vector
     * y hacer que empiece donde quiero según si son línes, puntos o sólido
     */
    // Usar el buffer activo para el color

    glColorPointer ( 3 , GL_FLOAT , 0, 0);

    glBindBuffer ( GL_ARRAY_BUFFER , 0 );

    glBindBuffer ( GL_ARRAY_BUFFER , id_vbo_n );

    glNormalPointer (GL_FLOAT, 0, 0);

    glBindBuffer ( GL_ARRAY_BUFFER , 0);

    if((textura1!= nullptr || textura2!= nullptr) && modo!=3){
        glEnable(GL_TEXTURE_2D);
        glEnableClientState ( GL_TEXTURE_COORD_ARRAY);
        glBindBuffer ( GL_ARRAY_BUFFER , id_vbo_tex);
        glTexCoordPointer(2, GL_FLOAT, 0, 0);
        glBindBuffer ( GL_ARRAY_BUFFER , 0);
        if(modoSeleccion==0)
            textura1->activar();
        else
            textura2->activar(); //textura de seleccion
    }
    //glBindBuffer ( GL_ARRAY_BUFFER , 0);
    // especifícar cual es el VBO que vamos a u
    glBindBuffer ( GL_ELEMENT_ARRAY_BUFFER , id_vbo_tri);

    glDrawElements(GL_TRIANGLES, 3*f.size(),GL_UNSIGNED_INT, 0);

    glBindBuffer ( GL_ELEMENT_ARRAY_BUFFER , 0);
    if((textura1!= nullptr || textura2!= nullptr)  && modo!=3){
        glDisable(GL_TEXTURE_2D);
        glDisableClientState ( GL_TEXTURE_COORD_ARRAY);
    }
    glDisableClientState(GL_VERTEX_ARRAY);
    //deshabilitar el uso de array de colores y de vértices
    glDisableClientState(GL_COLOR_ARRAY);

}
void Malla3D::crearVectorTexturas(std::vector <Tupla2f> tex) {

    ct=tex;

}
void Malla3D::colorear(Tupla3f color1, Tupla3f color2, Tupla3f color3) {
    c.clear();
    c1.clear();
    c2.clear();
    for (int i=0; i<v.size(); i++) {
        c.push_back(color1);
        c1.push_back(color2);
        c2.push_back(color3);
    }

}

void Malla3D::setColor(Tupla3f color1, Tupla3f color2, Tupla3f color3) {
    colorear(color1, color2, color3);
}
Tupla3f Malla3D::getColorS() {
    return colorS;
}
void Malla3D::setCentro(Tupla3f cent) {
    centro=cent;
}
Tupla3f Malla3D::getCentro() {
    return centro;
}
int Malla3D::getModo() {
    return modo;
}
void Malla3D::setModoSeleccion(int valor) {
    modoSeleccion=valor;
}
int Malla3D::getModoSeleccion() {
    return modoSeleccion;
}
void Malla3D::calcularNormales() {
    Tupla3f a, b, normalCara, pVectorial;
    nv.resize(v.size());
    for (auto it = nv.begin(); it != nv.end(); ++it){
        (*it) = {0, 0, 0};
    }
    for(int h=0; h<f.size(); h++){
        //p,q,r q-p r-p
        //calculamos los vectores con los que hacer el
        //producto vectorial de la cara

        a=v[f[h](1)]-v[f[h](0)];
        b=v[f[h](2)]-v[f[h](0)];

        //realizamos el producto vectorial
        pVectorial=a.cross(b);
        normalCara=pVectorial.normalized();

        //sumamos la normal de la cara a cada vértice
        nv[f[h](0)]=nv[f[h](0)]+normalCara;
        nv[f[h](1)]=nv[f[h](1)]+normalCara;
        nv[f[h](2)]=nv[f[h](2)]+normalCara;

    }

    for(int h=0; h<nv.size(); h++){
        //normales de los vertices
        if (nv[h].lengthSq() > 0)
            nv[h].normalized();
    }

}
GLuint Malla3D::CrearVBO(GLuint tipo_vbo, GLuint tam, GLvoid *puntero_ram) {
    GLuint id_vbo ; // resultado: identificador de VBO
    glGenBuffers ( 1 , & id_vbo ); // crear nuevo VBO, obtener identificador
    glBindBuffer ( tipo_vbo , id_vbo ); // activar el VBO usando su identificador
// esta instrucción hace la transferencia de datos desde RAM hacia GPU
    glBufferData ( tipo_vbo , tam , puntero_ram , GL_STATIC_DRAW );
    glBindBuffer ( tipo_vbo , 0 ); // desactivación del VBO (activar 0)
    return id_vbo ; // devolver el identificador resultado
}
void Malla3D::setTextura(const std::string & archivo) {
    textura1 = new Textura(archivo);
}
void Malla3D::setTextura(const std::string &archivo1, const std::string &archivo2) {
    textura1 = new Textura(archivo1);
    textura2 = new Textura(archivo2);
}
Malla3D::~Malla3D() {
    if(textura1!=NULL)
        delete textura1;
    if(textura2!=NULL)
        delete textura2;
}


