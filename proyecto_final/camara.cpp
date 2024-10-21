//
// Created by diego on 19/12/22.
//

#include "camara.h"
Camara::Camara(const Tupla3f &eye, const Tupla3f &at, const Tupla3f &up, const int &tipo, const float near,
               const float far) {
    this->eye   = eye;
    this->at    = at;
    this->up    = up;

    this->tipo  = tipo;
    this->near  = near;
    this->far   = far;

}
void Camara::setObserver() {
    gluLookAt(eye(0), eye(1), eye(2),
              at(0), at(1), at(2),
              up(0), up(1), up(2) );
}
void Camara::setProyeccion() {
    if (tipo == 1){
        //std::cout << near << " ";
        glFrustum( left, right, bottom, top, near, far );
    } else {
        glOrtho( left, right, bottom, top, near, far );
    }

}
void Camara::mover(float x, float y, float z) {
    //con esto conseguimos que la cámara se mueva por la escena
    at = {at(0)+x, at(1) + y, at(2) + z};
    eye = {eye(0)+x, eye(1) + y, eye(2) + z};
}

void Camara::rotarXFirstPerson(float angle) {
    Tupla3f at_centro = at - eye, new_up=up;
    float modulo = sqrt(at_centro.lengthSq()), modulo2 = sqrt(new_up.lengthSq());

    //en x no hace falta hacer operación se queda igual porque estamos rotando al rededor de este
    at_centro(1) = cos(angle)*at_centro(1) - sin(angle) * at_centro(2);
    at_centro(2) = sin(angle) * at_centro(1) + cos(angle) * at_centro(2);
    //normalizamos para hacer el vector de distancia 1 y lo múltiplicamos por el módulo para recuperar la distancia real
    at_centro = at_centro.normalized() * modulo;
    //cout<<at_centro(0)<<", "<<at_centro(1)<<", "<<at_centro(2)<<endl;
    at = at_centro + eye;
}
void Camara::rotarYFirstPerson(const float angle){
    Tupla3f at_centro = at - eye;
    float modulo = sqrt(at_centro.lengthSq());

    //en y no hace falta hacer operación se queda igual porque estamos rotando al rededor de este

    at_centro(0) = cos(angle)*at_centro(0) + sin(angle) * at_centro(2);
    at_centro(2) = -sin(angle) * at_centro(0) + cos(angle) * at_centro(2);

    at_centro = at_centro.normalized() * modulo;
    at = at_centro + eye;

}

void Camara::rotarZFirstPerson(const float angle){

    Tupla3f at_centro = at - eye;
    float modulo = sqrt(at_centro.lengthSq());

    //en z no hace falta hacer operación se queda igual porque estamos rotando al rededor de este

    at_centro(0) = cos(angle)*at_centro(0) - sin(angle) * at_centro(1);
    at_centro(1) = sin(angle) * at_centro(0) + cos(angle) * at_centro(1);

    at_centro = at_centro.normalized() * modulo;
    at = at_centro + eye;
}
void Camara::rotarXExaminar(const float angle){

    //el eye gira al rededor del at, las operaciones son muy similares que con la primera persona
    Tupla3f eye_centro = eye - at;
    float modulo = sqrt(eye_centro.lengthSq());


    eye_centro(1) = cos(angle) * eye_centro(1) - sin(angle) * eye_centro(2);
    eye_centro(2) = sin(angle) * eye_centro(1) + cos(angle) * eye_centro(2);
    eye_centro = eye_centro.normalized() * modulo;

    eye = eye_centro + at;

}



void Camara::rotarYExaminar(const float angle){


    Tupla3f eye_centro = eye - at;
    float modulo = sqrt(eye_centro.lengthSq());

    eye_centro(0) = cos(angle)*eye_centro(0) + sin(angle) * eye_centro(2);
    eye_centro(2) = -sin(angle) * eye_centro(0) + cos(angle) * eye_centro(2);

    eye_centro = eye_centro.normalized() * modulo;
    eye = eye_centro + at;


}
void Camara::rotarZExaminar(const float angle){

    Tupla3f eye_centro = eye - at;
    float modulo = sqrt(eye_centro.lengthSq());


    eye_centro(0) = cos(angle)*eye_centro(0) - sin(angle) * eye_centro(1);
    eye_centro(1) = sin(angle) * eye_centro(0) + cos(angle) * eye_centro(1);
    eye_centro = eye_centro.normalized() * modulo;

    eye = eye_centro + at;

}
void Camara::zoom(float factor) {
    //tenemos que aumentar y disminuir el volumen de visualización
    //para ello hay que multiplicar cada parte de la ventana de visualización
    //por un factor

    left*=factor;
    right*=factor;
    top*=factor;
    bottom*=factor;
}
void Camara::girarExaminar(int x, int y) {
    rotarXExaminar(y*(M_PI/180));
    rotarYExaminar(x*(M_PI/180));
}
void Camara::girar(int x, int y) {
    //if ((at - eye)(2) > 0) y = -y;

    rotarXFirstPerson(-y * (M_PI/180));
    rotarYFirstPerson(-x * (M_PI/180));
    //rotarXFirstPerson(x * (M_PI/180));
    //rotarYFirstPerson(y * (M_PI/180));
}
void Camara::setLeft(float valor) {
    left=valor;
}
void Camara::setRight(float valor) {
    right=valor;
}
float Camara::getBottom() {
    return bottom;
}
float Camara::getTop() {
    return top;
}
void Camara::setBottom(float valor) {
    bottom=valor;
}
void Camara::setTop(float valor) {
    top=valor;
}
void Camara::setAt(Tupla3f valor) {
    at=valor;
}