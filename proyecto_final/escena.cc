
#include "auxiliar.h"    // includes de OpenGL/glut/glew, windows, y librería std de C++
#include "escena.h"
#include "malla.h" // objetos: Cubo y otros....

//**************************************************************************
// constructor de la escena (no puede usar ordenes de OpenGL)
//**************************************************************************

Escena::Escena()
{
    /*Front_plane       = 50.0;
    Back_plane        = 2000.0;
    Observer_distance = 4*Front_plane;
    Observer_angle_x  = 0.0 ;
    Observer_angle_y  = 0.0 ;*/

    ejes.changeAxisSize( 5000 );
    //objetoVisible obj=NINGUNO;
    modoVisualizacion[0]=1;
    modoVisualizacion[1]=0;
    modoVisualizacion[2]=0;
    modoVisualizacion[3]=1;
    contLuces=0;
    camaraActiva=0;
    estadoRaton =NINGUNO;
    for(int i=0; i<8; i++){
        gradosAumentados[i]=0;
    }
    for(int i=0; i<7; i++){
        numLuz[i]=0;
    }
    numLuz[0]=1;
    numLuz[1]=1;
    gradoAumentado=-1;
    desactivarLuces=false;
    variacionAlfa=false;
    variacionBeta=false;
    sumarAngulo=false;
    restarAngulo=false;
    animarModelo=false;
    animarLuces=false;
    // crear los objetos de la escena....
    // .......completar: ...
    // .....
    std::vector<Tupla3f> perfilDiabolo;
    perfilDiabolo.resize(5);
    perfilDiabolo[0]={0,0,0};
    perfilDiabolo[1]={20,0,0};
    perfilDiabolo[2]={10,30,0};
    perfilDiabolo[3]={20,60,0};
    perfilDiabolo[4]={0,60,0};
    Tupla2f direccion={50,-30};
    colorDifuso={1,1,1,1};
    colorAmbiente={0, 0, 0, 1};
    colorEspecular={1, 1, 1, 1};
    Tupla3f posicion={-300,300,0};
    luz0=new LuzDireccional(direccion,GL_LIGHT0, colorAmbiente, colorEspecular, colorDifuso);
    luz1=new LuzPosicional(posicion, GL_LIGHT1, colorAmbiente, colorEspecular, colorDifuso);
    cubo = new Cubo(40);
    piramide = new PiramidePentagonal(60, 20);
    plyo =  new ObjPLY("plys/beethoven.ply");
    //objR = new ObjRevolucion("plys/lata-pcue.ply", 40);
    cono = new Cono(10, 30);
    cilindro = new Cilindro(10, 40);
    plyRevolucion = new ObjRevolucion("plys/peon.ply", 40);
    vectorPRevolucion = new ObjRevolucion(perfilDiabolo, 40);
    persona = new ModeloJerarquico();
    esfera = new Esfera(20);
    texturizarCubo();
    crearSuelo();
    //cuadro = new Cuadro(20);
   crearMateriales();
    inicializarTexturas();
    inicializarCamaras();
//std::cout<<"Creados materiales"<<std::endl;
}
void Escena::inicializarCamaras() {
    //tipo 1 perspectiva, tipo 0 ortogonal
    camaras.resize(3);
    Tupla3f eye = {0, 100, 150};
    Tupla3f at = {0,0,0};
    Tupla3f up = {0,1,0};
    //PERSPECTIVA
    camaras[0]=new Camara(eye, at, up, 1, 50, 2000);
    eye={100,200,0};
    at={0,0,0};
    up={0,1,0};
    //ORTOGONAL
    camaras[1]=new Camara(eye, at, up, 0, 50, 2000);
    eye={100,200,300};
    at={-90,40,40};
    up={0,1,0};
    //PERSPECTIVA
    camaras[2]=new Camara(eye, at, up, 1, 50, 2000);
}
void Escena::crearSuelo() {
    suelo = new Cubo(200);
    std::vector<Tupla2f> aux;
    aux.resize(4);
    aux[0]={0,0};
    aux[1]={0,10};
    aux[2]={10,10};
    aux[3]={10,0};

    suelo->crearVectorTexturas(aux);
}
void Escena::texturizarCubo() {
    std::vector<Tupla2f> aux;
    aux.push_back({0,0});
    aux.push_back({0,1});
    aux.push_back({1,1});
    aux.push_back({1,0});
    cubo->crearVectorTexturas(aux);
}
void Escena::inicializarTexturas() {
    cilindro->calcCordText();
    esfera->calcCordText();
    cono->calcCordText();
    cono->setTextura("plys/seleccionable.jpg", "plys/seleccionable1.jpg");
    cilindro->setTextura("plys/tronco.jpg");
    esfera->setTextura("plys/hojas.jpg");
    suelo->setTextura("plys/cesped.jpg");
    persona->setTextura("plys/esfera_tex.jpg", "plys/camiseta.jpg");
    cubo->setTextura("plys/seleccionable.jpg", "plys/seleccionable1.jpg");
}
void Escena::crearMateriales() {
    Tupla4f aux={1, 0, 0, 1},
            aux2= {0,0,1, 1}, aux3={0,1,0,1},
            aux4 = {0,0,0,1}, aux5={1,1,1,1},
            aux6={1,1,1,0}, aux7={0,0,0,0},
            aux8={0.627451, 0.3922, 0.07843, 1};
    material1=new Material(aux, aux2, aux, 100);
    material2=new Material(aux2, aux3, aux2, 100);
    material3=new Material(aux3, aux, aux3, 100);
    material4=new Material(aux4,aux7,aux3, 0);
    material5=new Material(aux6, aux5, aux3, 128);
    materialPiel=new Material({0.937255, 0.894, 0.69, 1},
                               {0.937255, 0.894, 0.69,1 }, {0.937255, 0.894, 0.69,1}, 128);
    materialBlanco = new Material(aux5, aux5, aux5, 100);
    materialMarron = new Material(aux8, aux8, aux8, 100);

}
Escena::~Escena(){
    //delete esfera;
    delete cubo;
    delete piramide;
    delete plyo;
    delete cono;
    delete cilindro;
    delete plyRevolucion;
    delete vectorPRevolucion;
    delete material1;
    delete material2;
    delete material3;
    delete material5;
    delete material4;
    delete luz0;
    delete luz1;
    delete persona;
    delete materialPiel;
    //delete suelo;
}

//**************************************************************************
// inicialización de la escena (se ejecuta cuando ya se ha creado la ventana, por
// tanto sí puede ejecutar ordenes de OpenGL)
// Principalmemnte, inicializa OpenGL y la transf. de vista y proyección
//**************************************************************************

void Escena::inicializar( int UI_window_width, int UI_window_height )
{
	glClearColor( 1.0, 1.0, 1.0, 1);// se indica cual sera el color para limpiar la ventana	(r,v,a,al)

	glEnable( GL_DEPTH_TEST );	// se habilita el z-bufer

    glEnable(GL_CULL_FACE);

    glEnable(GL_NORMALIZE); //activar la normalización para que el modulo de las normales siga siendo 1

    for(int i=0; i<camaras.size(); i++){
        camaras[i]->setBottom(-UI_window_height/10);
        camaras[i]->setTop(UI_window_height/10);
        camaras[i]->setRight(UI_window_height/10);
        camaras[i]->setLeft(-UI_window_height/10);
    }


    change_projection();
	glViewport( 0, 0, UI_window_width, UI_window_height );
}


void Escena::clickRaton(int boton, int estado, int x, int y) {
    xant=x;
    yant=y;
    if(boton == GLUT_RIGHT_BUTTON){
        if(estado==GLUT_DOWN){
            if(objetoPinchado)
                estadoRaton=MOVIMIENDO_CAMARA_EXAMINAR;
            else
                estadoRaton=MOVIENDO_CAMARA_FIRSTPERSON;
        }else if(estado==GLUT_UP){
            estadoRaton=NINGUNO;
        }
    }else if(boton == GLUT_LEFT_BUTTON){
        if(estado==GLUT_UP){
            dibujarSeleccion();
            processPick(x, y);
        }
    }

}
void Escena::ratonMovido(int x, int y) {

    if(estadoRaton==MOVIENDO_CAMARA_FIRSTPERSON){
        camaras[camaraActiva]->girar(x-xant, y-yant);
        xant=x;
        yant=y;
    }else if(estadoRaton==MOVIMIENDO_CAMARA_EXAMINAR){
        camaras[camaraActiva]->girarExaminar(x-xant, y-yant);
        xant=x;
        yant=y;
    }
}
// **************************************************************************
//
// función de dibujo de la escena: limpia ventana, fija cámara, dibuja ejes,
// y dibuja los objetos
//
// **************************************************************************

void Escena::dibujarSeleccion(){
    // deshabilitamos el degradado
    glDisable(GL_DITHER);
    glDisable(GL_LIGHTING);
    glDisable(GL_TEXTURE);


    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); // Limpiar la pantalla

    change_observer();

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glPushMatrix();
        glTranslatef(90, 0.5, 40);
        cono->setModo(3);
        cono->draw();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-50, 0, -50);
        cubo->setModo(3);
        cubo->draw();
    glPopMatrix();

    glEnable(GL_DITHER);
    if(modoVisualizacion[3]==1)
        glEnable(GL_LIGHTING);
    glEnable(GL_TEXTURE);
}
void Escena::processPick(int x, int y) {
    glDisable(GL_DITHER);
    glDisable(GL_LIGHTING);
    glDisable(GL_TEXTURE);

    GLint viewport[4];
    GLfloat pixel[3];


    glGetIntegerv(GL_VIEWPORT, viewport);
    glReadPixels(x, viewport[3]-y, 1, 1, GL_RGB, GL_FLOAT, (void *) pixel);

    Tupla3f leido = {pixel[0], pixel[1], pixel[2]};
    //cout<<leido(0)<<", "<<leido(1)<<", "<<leido(2)<<endl;
    Tupla3f aux=cubo->getColorS();
    Tupla3f aux1=cono->getColorS();
    //cout<<aux(0)<<", "<<aux(1)<<", "<<aux(2)<<endl;
    if(leido(0)==aux(0) && leido(1)==aux(1) && leido(2)==aux(2) ){
        camaras[camaraActiva]->setAt(cubo->getCentro());
        objetoPinchado=true;
        cubo->setModoSeleccion(1);
        cono->setModoSeleccion(0);
    }else if(leido(0)==aux1(0) && leido(1)==aux1(1) && leido(2)==aux1(2) ){
        camaras[camaraActiva]->setAt(cono->getCentro());
        objetoPinchado=true;
        cubo->setModoSeleccion(0);
        cono->setModoSeleccion(1);
    }else{
        objetoPinchado=false;
        cubo->setModoSeleccion(0);
        cono->setModoSeleccion(0);
    }

    change_observer();

    glEnable(GL_DITHER);
    if(modoVisualizacion[3]==1)
        glEnable(GL_LIGHTING);
    glEnable(GL_TEXTURE);
}
void Escena::modificarModeloJerarquico() {

    if(gradosAumentados[0]!=0){
        persona->modificarSalto(gradosAumentados[0]);
        gradosAumentados[0]=0;
    }else if(gradosAumentados[1]!=0){
        persona->modificarRRodilla1(gradosAumentados[1]);
        gradosAumentados[1]=0;
    }else if(gradosAumentados[2]!=0){
        persona->modificarRRodilla2(gradosAumentados[2]);
        gradosAumentados[2]=0;
    }else if(gradosAumentados[3]!=0){
        persona->modificarRPierna1(gradosAumentados[3]);
        gradosAumentados[3]=0;
    }else if(gradosAumentados[4]!=0){
        persona->modificarRPierna2(gradosAumentados[4]);
        gradosAumentados[4]=0;
    }else if(gradosAumentados[5]!=0){
        persona->modificarRBrazo1(gradosAumentados[5]);
        gradosAumentados[5]=0;
    }else if(gradosAumentados[6]!=0){
        persona->modificarRBrazo2(gradosAumentados[6]);
        gradosAumentados[6]=0;
    }else if(gradosAumentados[7]!=0){
        persona->modificarTLengua(gradosAumentados[7]);
        gradosAumentados[7]=0;
    }

}

void Escena::animar() {

   if(animarModelo) {

       persona->animar();
   }
   if (animarLuces) {
       contLuces++;
       if(contLuces==16) {
           luz0->animar();
           contLuces=0;
       }
       luz1->animar();
   }

}
void Escena::dibujar()
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); // Limpiar la pantalla
    if(modoVisualizacion[3]==1 || desactivarLuces) {
        glDisable(GL_LIGHTING);
        desactivarLuces=false;
    }
	change_observer();
    //cambiar tamaño de líneas y puntos
    glPointSize(4);
    //dibujar ejes
    ejes.draw();
    //habilitar luces aquí.
    if(modoVisualizacion[3]==1) {
        glEnable(GL_LIGHTING);
        if(numLuz[0]==1) {
            if(sumarAngulo) {
                if(variacionAlfa)
                    luz0->variarAnguloAlpha(2);
                if(variacionBeta)
                    luz0->variarAnguloBeta(2);
                sumarAngulo=false;
            }else if(restarAngulo) {
                if(variacionAlfa)
                    luz0->variarAnguloAlpha(-2);
                if(variacionBeta)
                    luz0->variarAnguloBeta(-2);
                restarAngulo=false;
            }
            luz0->activar();
        }if(numLuz[1]==1){
            luz1->activar();
        }
    }

    //glRotatef(45, 0,1,0);
    // COMPLETAR
    //   Dibujar los diferentes elementos de la escena
    // Habrá que tener en esta primera práctica una variable que indique qué objeto se ha de visualizar
    // y hacer
    materialBlanco->aplicar();
    glPushMatrix();
        glTranslatef(0,0,100);
        glRotatef(-90,1,0,0);
        glScalef(1.5,2,1);
        glScalef(1,1,0.01);
        if (modoVisualizacion[2]==1) {
            glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
            suelo->setModo(2);
            suelo->draw();
        }
        if(modoVisualizacion[1]==1) {
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            suelo->setModo(1);
            suelo->draw();
        }
        if(modoVisualizacion[0]==1) {
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            suelo->setModo(0);
            suelo->draw();
        }
    glPopMatrix();
    materialPiel->aplicar();
    glPushMatrix();

        glScalef(2,2,2);
        glTranslatef(0,14.6,0);
        if (modoVisualizacion[2]==1) {
            glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
            persona->setModo(2);
            persona->draw();
        }
        if(modoVisualizacion[1]==1) {
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            persona->setModo(1);
            persona->draw();
        }
        if(modoVisualizacion[0]==1) {
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            persona->setModo(0);
            persona->draw();
        }
    glPopMatrix();
    material1->aplicar();
    glPushMatrix();
        glTranslatef(50, 0, -50);
        if (modoVisualizacion[2]==1) {
            glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
            vectorPRevolucion->setModo(2);
            vectorPRevolucion->draw();
        }
        if(modoVisualizacion[1]==1) {
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            vectorPRevolucion->setModo(1);
            vectorPRevolucion->draw();
        }
        if(modoVisualizacion[0]==1) {
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            vectorPRevolucion->setModo(0);
            vectorPRevolucion->draw();
        }
    glPopMatrix();



    material4->aplicar();
    glPushMatrix();
        glTranslatef(-110, 13, -130);
        glScalef(10,10,10);
        if (modoVisualizacion[2]==1) {
            glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
            plyRevolucion->setModo(2);
            plyRevolucion->draw();
        }
        if(modoVisualizacion[1]==1) {
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            plyRevolucion->setModo(1);
            plyRevolucion->draw();
        }
        if(modoVisualizacion[0]==1) {
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            plyRevolucion->setModo(0);
            plyRevolucion->draw();
        }
    glPopMatrix();

    material5->aplicar();
    glPushMatrix();
        glTranslatef(-110, 13, -110);
        glScalef(10,10,10);
        if (modoVisualizacion[2]==1) {
            glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
            plyRevolucion->setModo(2);
            plyRevolucion->draw();
        }
        if(modoVisualizacion[1]==1) {
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            plyRevolucion->setModo(1);
            plyRevolucion->draw();
        }
        if(modoVisualizacion[0]==1) {
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            plyRevolucion->setModo(0);
            plyRevolucion->draw();
        }
    glPopMatrix();

    materialBlanco->aplicar();
    glPushMatrix();
        glTranslatef(-50, 0, -50);
        cubo->setCentro({-50, 20, -50});
        if (modoVisualizacion[2]==1) {
            glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
            cubo->setModo(2);
            cubo->draw();
        }
        if(modoVisualizacion[1]==1) {
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            cubo->setModo(1);
            cubo->draw();
        }
        if(modoVisualizacion[0]==1) {
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            cubo->setModo(0);
            cubo->draw();
        }
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-50, 40, -50);
        if (modoVisualizacion[2]==1) {
            glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
            piramide->setModo(2);
            piramide->draw();
        }
        if(modoVisualizacion[1]==1) {
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            piramide->setModo(1);
            piramide->draw();
        }
        if(modoVisualizacion[0]==1) {
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            piramide->setModo(0);
            piramide->draw();
        }
    glPopMatrix();


    material1->aplicar();
    glPushMatrix();
        glTranslatef(50, 66, -50);
        if (modoVisualizacion[2]==1) {
            glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
            plyo->setModo(2);
            plyo->draw();
        }
        if(modoVisualizacion[1]==1) {
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            plyo->setModo(1);
            plyo->draw();
        }
        if(modoVisualizacion[0]==1) {
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            plyo->setModo(0);
            plyo->draw();

        }
    glPopMatrix();
    materialBlanco->aplicar();
    glPushMatrix();
        glTranslatef(90, 0.5, 40);
        glRotatef(90, 0, 1, 0);
        cono->setCentro({90, 15.5, 40}); //15 mitad de la altura del cono + 0.5 de desplazamiento
        if (modoVisualizacion[2]==1) {
            glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
            cono->setModo(2);
            cono->draw();
        }
        if(modoVisualizacion[1]==1) {
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            cono->setModo(1);
            cono->draw();
        }
        if(modoVisualizacion[0]==1) {
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            cono->setModo(0);
            cono->draw();

        }

    glPopMatrix();
    materialMarron->aplicar();
    glPushMatrix();
        glTranslatef(-90, 0, 40);
        if (modoVisualizacion[2]==1) {
            glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
            cilindro->setModo(2);
            cilindro->draw();
        }
        if(modoVisualizacion[1]==1) {
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            cilindro->setModo(1);
            cilindro->draw();
        }
        if(modoVisualizacion[0]==1) {
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            cilindro->setModo(0);
            cilindro->draw();

        }

    glPopMatrix();

    material3->aplicar();
    glPushMatrix();

        glTranslatef(-90, 40, 40);
        if (modoVisualizacion[2]==1) {
            glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
            esfera->setModo(2);
            esfera->draw();
        }
        if(modoVisualizacion[1]==1) {
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            esfera->setModo(1);
            esfera->draw();
        }
        if(modoVisualizacion[0]==1) {
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            esfera->setModo(0);
            esfera->draw();
        }
    glPopMatrix();



}

//**************************************************************************
//
// función que se invoca cuando se pulsa una tecla
// Devuelve true si se ha pulsado la tecla para terminar el programa (Q),
// devuelve false en otro caso.
//
//**************************************************************************

bool Escena::teclaPulsada( unsigned char tecla, int x, int y ) {
    using namespace std;
    cout << "Tecla pulsada: '" << tecla << "'" << endl;
    bool salir = false;
    /*if(modoMenu==SELOBJETO){
        switch( toupper(tecla) )
        {
            case 'C' :
                if(obj==CUBO)
                    obj=NINGUNO;
                else
                obj=CUBO;
                break ;
            case 'P' :
                if(obj==PIRAMIDE)
                    obj=NINGUNO;
                else
                obj=PIRAMIDE;
                break ;
            case 'Q' :
                modoMenu=NADA;
                break ;
        }
    }else*/

    if (modoMenu == SELVISUALIZACION) {
        switch (toupper(tecla)) {
            case 'D' :
                if (modoVisualizacion[2] == 1)
                    modoVisualizacion[2] = 0;
                else
                    modoVisualizacion[2] = 1;
                break;
            case 'L' :
                if (modoVisualizacion[1] == 1)
                    modoVisualizacion[1] = 0;
                else
                    modoVisualizacion[1] = 1;
                break;
            case 'S' :
                if (modoVisualizacion[0] == 1)
                    modoVisualizacion[0] = 0;
                else
                    modoVisualizacion[0] = 1;
                break;
            case 'I' :
                if (modoVisualizacion[3] == 1) {
                    modoVisualizacion[3] = 0;
                    desactivarLuces = true;
                } else
                    modoVisualizacion[3] = 1;
                break;
            case 'Q' :
                modoMenu = NADA;
                break;
        }
        if (modoVisualizacion[3] == 1) {
            switch (toupper(tecla)) {
                case '0':
                    if (numLuz[tecla - 48] == 1) {
                        numLuz[tecla - 48] = 0;
                        luz0->desactivar();
                    }else {
                        numLuz[tecla - 48] = 1;
                    }
                    break;
                case '1':
                    if (numLuz[tecla - 48] == 1) {
                        numLuz[tecla - 48] = 0;
                        luz1->desactivar();
                    }else
                        numLuz[tecla - 48] = 1;
                    break;
                case 'A':

                    if (!variacionAlfa) variacionAlfa = true;
                    else {
                        variacionAlfa = false;
                    }
                    break;
                case 'B':
                    if (!variacionBeta) variacionBeta = true;
                    else {
                        variacionBeta = false;
                    }
                    break;
                case '<':
                    if (variacionAlfa || variacionBeta)
                        restarAngulo = true;
                    break;
                case '>':
                    if (variacionAlfa || variacionBeta)
                        sumarAngulo = true;
                    break;
                case 'P':
                    if(animarLuces) {
                        animarLuces = false;
                    }else {

                        animarLuces = true;
                    }
                    break;

            }
        }
    }else if(modoMenu==MODOANIMACION){
        switch (toupper(tecla)) {
            case'A':
                animarModelo=false;
                modoMenu=NADA;
            break;
            case'M':
                animarModelo=false;
                modoMenu=MODOMANUAL;
                break;
            case '+':
                persona->modificarVelocidadAnimacion(1.2);
                break;
            case '-':
                persona->modificarVelocidadAnimacion(0.8);
                break;
        }
    }else if(modoMenu==MODOMANUAL){
        switch(toupper(tecla)){
            case '0':
                gradoAumentado=0;
                break;
            case '1':
                gradoAumentado=1;
                break;
            case '2':
                gradoAumentado=2;
                break;
            case '3':
                gradoAumentado=3;
                break;
            case '4':
                gradoAumentado=4;
                break;
            case '5':
                gradoAumentado=5;
                break;
            case '6':
                gradoAumentado=6;
                break;
            case '7':
                gradoAumentado=7;
                break;
            case 'Q':
                modoMenu=NADA;
                break;
            case'+':
                gradosAumentados[gradoAumentado]=1;
                modificarModeloJerarquico();
                break;
            case'-':
                gradosAumentados[gradoAumentado]=-1;
                modificarModeloJerarquico();
                break;
        }
    }else if(modoMenu==MODOCAMARAS){
        switch(tecla){
            case '1':
                camaraActiva=0;
                break;
            case '2':
                camaraActiva=1;
                break;
            case '3':
                camaraActiva=2;
                break;
            case 'q':
                modoMenu=NADA;
        }
        change_projection();
        change_observer();
    }
    else
       switch( toupper(tecla) )
       {
          case 'Q' :
             if (modoMenu!=NADA)
                modoMenu=NADA;
             else {
                salir=true ;
             }
             break ;
          case 'M' :
             // ESTAMOS EN MODO SELECCION DE OBJETO
             cout<<"Entramos en el modo de movimiento manual del objeto jerárquico"<<endl;
             modoMenu=MODOMANUAL;
             break ;
           case 'A':
               cout<<"Entramos en el modo de la animación del objeto jerárquico"<<endl;
               modoMenu=MODOANIMACION;
               animarModelo=true;
               break;
          case 'V' :
             // ESTAMOS EN MODO SELECCION DE MODO DE VISUALIZACION
             cout<<"con la D entras en modo puntos, con la L en modo líneas y con la S en moso sólido"<<endl;
             modoMenu=SELVISUALIZACION;
             break ;
           case 'C':
               cout<<"entramos en el modo cámaras"<<endl;
               cout<<"1: cámara 1"<<endl;
               cout<<"2: cámara 2"<<endl;
               cout<<"3: cámara 3"<<endl;
             modoMenu=MODOCAMARAS;
            break;
             // COMPLETAR con los diferentes opciones de teclado

       }
   return salir;
}
//**************************************************************************

void Escena::teclaEspecial( int Tecla1, int x, int y )
{
   switch ( Tecla1 )
   {
	   case GLUT_KEY_LEFT:
         //camaras[camaraActiva]->mover(-2, 0, 0);
           camaras[camaraActiva]->girar(-2,0);
         break;
	   case GLUT_KEY_RIGHT:
           //camaras[camaraActiva]->mover(2, 0, 0);
           camaras[camaraActiva]->girar(2,0);
         break;
	   case GLUT_KEY_UP:
           //camaras[camaraActiva]->mover(0, 2, 0);
           camaras[camaraActiva]->girar(0,2);
         break;
	   case GLUT_KEY_DOWN:
           //camaras[camaraActiva]->mover(0, -2, 0);
           camaras[camaraActiva]->girar(0,-2);
         break;
	   case GLUT_KEY_PAGE_UP:
         camaras[camaraActiva]->zoom(1.2);
           change_projection();
         break;
	   case GLUT_KEY_PAGE_DOWN:
         camaras[camaraActiva]->zoom(0.8);
           change_projection();
         break;
	}


	//std::cout << Observer_distance << std::endl;
}

//**************************************************************************
// Funcion para definir la transformación de proyeccion
//
// ratio_xy : relacción de aspecto del viewport ( == ancho(X) / alto(Y) )
//
//***************************************************************************

void Escena::change_projection( )
{
   glMatrixMode( GL_PROJECTION );
   glLoadIdentity();
   /*const float wx = float(Height)*ratio_xy ;
   glFrustum( -wx, wx, -Height, Height, Front_plane, Back_plane );*/
   camaras[camaraActiva]->setProyeccion();
}
//**************************************************************************
// Funcion que se invoca cuando cambia el tamaño de la ventana
//***************************************************************************

void Escena::redimensionar( int newWidth, int newHeight )
{
    //hay que cambiar ahora la relación de aspecto
    //de la ventana, para eso hay que ver cual es
    //la diferencia entre el width y el height
    //y así asignarle valores al left, right
    //top y bottom
   const float factor = (float)newWidth/(float)newHeight;

   for(int i=0; i<camaras.size(); i++){
       camaras[i]->setLeft(camaras[i]->getBottom()*factor);
       camaras[i]->setRight(camaras[i]->getTop()*factor);
   }
   change_projection();
   glViewport( 0, 0, newWidth, newHeight);
}

//**************************************************************************
// Funcion para definir la transformación de vista (posicionar la camara)
//***************************************************************************

void Escena::change_observer()
{
   // posicion del observador
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   camaras[camaraActiva]->setObserver();
}
