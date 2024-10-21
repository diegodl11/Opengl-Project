//
// Created by diego on 29/11/22.
//

#include "modeloJerarquico.h"
ModeloJerarquico::ModeloJerarquico() {
    rPierna1.first=0;
    rPierna2.first=0;
    rBrazo1.first=0;
    rBrazo2.first=0;
    salto.first=0;
    rPierna1.second=0;
    rPierna2.second=0;
    rBrazo1.second=0;
    rBrazo2.second=0;
    salto.second=0;
    velocidadAnimacion=2;
    finSalto=false;
    giroRodillas=false;
    giroPiernas=false;
    primeraParte= true;
    movBrazo1=true;
    movBrazo2=false;
    movLengua=false;
    giroBrazos=false;
    finLengua=false;

    pierna1 = new Pierna();
    pierna2 = new Pierna();
    torso = new Torso(16);
    brazo1 = new Brazo();
    brazo2 = new Brazo();
    cabeza = new Cabeza();
}

void ModeloJerarquico::draw() {
    glPushMatrix();
        glTranslatef(0, salto.first, 0);
        glPushMatrix(); //cuerpo
            glPushMatrix();
                glTranslatef(0,16,0);
                cabeza->draw();
            glPopMatrix();

            glPushMatrix();
                glTranslatef(9,14,0);
                glRotatef(rBrazo2.first,1,0,0);
                glRotatef(15, 0,0,1);
                brazo2->draw();
            glPopMatrix();

            glPushMatrix();
                glTranslatef(-9,14,0);
                glRotatef(rBrazo1.first,1,0,0);
                glRotatef(-15, 0,0,1);
                brazo1->draw();
            glPopMatrix();

            glPushMatrix();
                glScalef(1,1,0.5);
                torso->draw();
            glPopMatrix();
            glPushMatrix();
                glTranslatef(-5, 0, 0);
                glRotatef(rPierna1.first, 1, 0, 0);
                pierna1->draw();
            glPopMatrix();

            glPushMatrix();
                glTranslatef(5, 0, 0);
                glRotatef(rPierna2.first, 1, 0, 0);
                pierna2->draw();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
}

void ModeloJerarquico::modificarRBrazo1(float angulo) {
    /*if(rBrazo1.first+angulo<-80)
        rBrazo1.second=1;
    if(rBrazo1.first+angulo>0)
        rBrazo1.second=2;
    if(rBrazo1.second==1){
        angulo=-angulo;
    }
    if(rBrazo1.second==2){
        angulo=0;
    }*/
    //angulo*=velocidadAnimacion;
    //if(rBrazo1.first+angulo>=-80 && rBrazo1.first+angulo<=0)
    rBrazo1.first = angulo + rBrazo1.first;

}
void ModeloJerarquico::modificarRBrazo2(float angulo) {
    /*if(rBrazo2.first+angulo<-80)
        rBrazo2.second=1;
    if(rBrazo2.first+angulo>0)
        rBrazo2.second=2;
    if(rBrazo2.second==1){
        angulo=-angulo;
    }
    if(rBrazo2.second==2){
        angulo=0;
    }*/
    //angulo*=velocidadAnimacion;
    //if(rBrazo2.first+angulo>=-80 && rBrazo2.first+angulo<=0)
    rBrazo2.first=angulo+rBrazo2.first;
}
void ModeloJerarquico::modificarRPierna1(float angulo) {
    /*if(rPierna1.first+angulo<-30)
        rPierna1.second=1;
    if(rPierna1.first+angulo>0)
        rPierna1.second=2;
    if(rPierna1.second==1){
        angulo=-angulo;
    }
    if(rPierna1.second==2){
        angulo=0;
    }*/
    //angulo*=velocidadAnimacion;
    //if(rPierna1.first+angulo>=-30 && rPierna1.first+angulo<=0)
    rPierna1.first= angulo+rPierna1.first;
}
void ModeloJerarquico::modificarRPierna2(float angulo) {

    /*if(rPierna2.first+angulo<-30)
        rPierna2.second=1;
    if(rPierna2.first+angulo>0)
        rPierna2.second=2;
    if(rPierna2.second==1){
        angulo=-angulo;
    }
    if(rPierna2.second==2){
        angulo=0;
    }*/
    //angulo*=velocidadAnimacion;
    //if(rPierna2.first+angulo>=-30 && rPierna2.first+angulo<=0)
        rPierna2.first= angulo+rPierna2.first;
}
void ModeloJerarquico::modificarRRodilla1(float angulo) {

    pierna1->modificarRRodilla(angulo/*, velocidadAnimacion*/);
}
void ModeloJerarquico::modificarRRodilla2(float angulo) {

    pierna2->modificarRRodilla(angulo/*, velocidadAnimacion*/);
}
void ModeloJerarquico::modificarTLengua(float desplazamiento) {
    cabeza->modificarTLengua(desplazamiento/*, velocidadAnimacion*/);
}
void ModeloJerarquico::modificarSalto(float desplazamiento) {
    /*if(salto.first+desplazamiento>10)
        salto.second=1;
    if(salto.first+desplazamiento<0)
        salto.second=2;
    if(salto.second==1)
        desplazamiento=-desplazamiento;
    if(salto.second==2)
        desplazamiento=0;*/
    //desplazamiento*=velocidadAnimacion;
    //if(salto.first+desplazamiento<=10.1 && salto.first+desplazamiento>=0)
        salto.first+=desplazamiento;
}
void ModeloJerarquico::modificarVelocidadAnimacion(float velocidad) {
    if(velocidadAnimacion*velocidad<=60 && velocidadAnimacion*velocidad>=0.5)
        velocidadAnimacion*=velocidad;
}
/*void ModeloJerarquico::animar() {
    if(primeraParte) {
        if (!finSalto) {
            modificarSalto(0.250);
        } else {
            modificarSalto(-0.250);
        }
        if (salto.first >= 15) {
            finSalto = true;
        } else if (salto.first <= 0) {
            primeraParte = false;
            finSalto = false;
        }
        if (!giroRodillas) {
            modificarRRodilla1(1);
            modificarRRodilla2(1);
        } else {
            modificarRRodilla1(-1);
            modificarRRodilla2(-1);
        }

        if (pierna1->getGiro() >= 60) {
            giroRodillas = true;
        } else if (pierna1->getGiro() <= 0) {
            giroRodillas = false;
        }
        if (!giroPiernas) {
            modificarRPierna1(-0.5);
            modificarRPierna2(-0.5);
        } else {
            modificarRPierna1(0.5);
            modificarRPierna2(0.5);
        }

        if (rPierna1.first <= -30) {
            giroPiernas = true;
        } else if (rPierna1.first >= 0) {
            giroPiernas = false;
        }
    }else{
        if(movBrazo1) {
            if (!giroBrazos) {
                modificarRBrazo1(-0.5);
            } else {
                modificarRBrazo1(0.5);
            }

            if (rBrazo1.first <= -80) {
                giroBrazos = true;
            } else if (rBrazo1.first >= 0) {
                movBrazo1 = false;
                movBrazo2 = true;
                giroBrazos = false;
            }
        }
        else if(movBrazo2) {
            if (!giroBrazos) {
                modificarRBrazo2(-0.5);
            } else {
                modificarRBrazo2(0.5);
            }

            if (rBrazo2.first <= -80) {
                giroBrazos = true;
            } else if (rBrazo2.first >= 0) {
                movBrazo2 = false;
                movLengua = true;
                giroBrazos = false;
            }
        }else if(movLengua){
            if (!finLengua) {
                modificarTLengua(0.01);
            } else {
                modificarTLengua(-0.01);
            }

            if (cabeza->getLengua() >= 1.5) {
                finLengua = true;
            } else if (cabeza->getLengua() <= 0) {
                movBrazo1=true;
                movBrazo2=false;
                movLengua=false;
                primeraParte=true;
                finLengua = false;
            }
        }
    }
}*/
void ModeloJerarquico::animar() {
    if (primeraParte) {
        if (!finSalto && salto.first <= 15) {
            if (salto.first + 0.25 * velocidadAnimacion <= 15)
                modificarSalto(0.250 * velocidadAnimacion);
            else
                salto.first = 15;
            //std::cout << "movsaltoarriba" << std::endl;
        } else if (salto.first >= 0) {
            if (salto.first - 0.25 * velocidadAnimacion >= 0)
                modificarSalto(-0.250 * velocidadAnimacion);
            else
                salto.first = 0;
            //std::cout << "movsaltoabajo" << std::endl;
        }
        if (salto.first >= 15) {
            finSalto = true;
        } else if (salto.first <= 0) {
            primeraParte = false;
            finSalto = false;
        }
        if (!giroRodillas) {
            if (pierna1->getGiro() <= 60)
                if (pierna1->getGiro() + velocidadAnimacion <= 60) {
                    modificarRRodilla1(velocidadAnimacion);
                } else {
                    pierna1->setGiro(60);
                }
            //std::cout << "movrodilla1arriba" << std::endl;
            if (pierna2->getGiro() <= 60)
                if (pierna2->getGiro() + velocidadAnimacion <= 60) {
                    modificarRRodilla2(velocidadAnimacion);
                } else {
                    pierna2->setGiro(60);
                }
            //std::cout << "movrodilla2arriba" << std::endl;
        } else {
            if (pierna1->getGiro() >= 0)
                if (pierna1->getGiro() - velocidadAnimacion >= 0) {
                    modificarRRodilla1(-velocidadAnimacion);
                } else {
                    pierna1->setGiro(0);
                }
            //std::cout << "movrodilla1abajo" << std::endl;
            if (pierna2->getGiro() >= 0)
                if (pierna2->getGiro() - velocidadAnimacion >= 0) {
                    modificarRRodilla2(-velocidadAnimacion);
                } else {
                    pierna2->setGiro(0);
                }
            //std::cout << "movrodilla2abajo" << std::endl;
        }

        if (pierna1->getGiro() >= 60) {
            giroRodillas = true;
        } else if (pierna1->getGiro() <= 0) {
            giroRodillas = false;
        }
        if (!giroPiernas) {
            if (rPierna1.first >= -30)
                if (rPierna1.first - 0.5 * velocidadAnimacion >= -30) {
                    modificarRPierna1(-0.5 * velocidadAnimacion);
                } else {
                    rPierna1.first = -30;
                }
            //std::cout << "movcadera1arriba" << std::endl;
            if (rPierna2.first >= -30)
                if (rPierna2.first - 0.5 * velocidadAnimacion >= -30) {
                    modificarRPierna2(-0.5 * velocidadAnimacion);
                } else {
                    rPierna2.first = -30;
                }
            //std::cout << "movcadera2arriba" << std::endl;
        } else {
            if (rPierna1.first <= 0)
                if (rPierna1.first + 0.5 * velocidadAnimacion <= 0) {
                    modificarRPierna1(0.5 * velocidadAnimacion);
                } else {
                    rPierna1.first = 0;
                }
            //std::cout << "movcadera1abajo" << std::endl;
            if (rPierna2.first <= 0)
                if (rPierna2.first + 0.5 * velocidadAnimacion <= 0) {
                    modificarRPierna2(0.5 * velocidadAnimacion);
                } else {
                    rPierna2.first = 0;
                }
            //std::cout << "movcadera2abajo" << std::endl;
        }

        if (rPierna1.first <= -30) {
            giroPiernas = true;
        } else if (rPierna1.first >= 0) {
            giroPiernas = false;
        }
    } else {
        if (movBrazo1) {
            if (!giroBrazos && rBrazo1.first >= -80) {
                if (rBrazo1.first - 0.5 * velocidadAnimacion >= -80)
                    modificarRBrazo1(-0.5 * velocidadAnimacion);
                else
                    rBrazo1.first = -80;
                //std::cout << "movbrazo1arriba" << std::endl;
            } else if (giroBrazos && rBrazo1.first <= 0) {
                if (rBrazo1.first + 0.5 * velocidadAnimacion <= 0)
                    modificarRBrazo1(0.5 * velocidadAnimacion);
                else
                    rBrazo1.first = 0;
                //std::cout << "movbrazo1abajo" << std::endl;
            }

            if (rBrazo1.first <= -80) {
                giroBrazos = true;
            } else if (rBrazo1.first >= 0) {
                movBrazo1 = false;
                movBrazo2 = true;
                giroBrazos = false;
            }

        } else if (movBrazo2) {
            if (!giroBrazos && rBrazo2.first >= -80) {
                if (rBrazo2.first - 0.5 * velocidadAnimacion >= -80)
                    modificarRBrazo2(-0.5 * velocidadAnimacion);
                else
                    rBrazo2.first = -80;
                //std::cout << "movbrazo2abajo" << std::endl;
            } else if (giroBrazos && rBrazo2.first <= 0) {
                if (rBrazo2.first + 0.5 * velocidadAnimacion <= 0)
                    modificarRBrazo2(0.5 * velocidadAnimacion);
                else
                    rBrazo2.first = 0;
                //std::cout << "movbrazo2abajo" << std::endl;
            }
            if (rBrazo2.first <= -80) {
                giroBrazos = true;
            } else if (rBrazo2.first >= 0) {
                movBrazo2 = false;
                movLengua = true;
                giroBrazos = false;
            }
        } else if (movLengua) {
            if (!finLengua && cabeza->getLengua() <= 1.5) {
                if(cabeza->getLengua()+0.01*velocidadAnimacion<=1.5)
                    modificarTLengua(0.01 * velocidadAnimacion);
                else
                    cabeza->setLengua(1.5);
                //std::cout << "MOVSACARLENGUA" << std::endl;
            } else if (cabeza->getLengua() >= 0) {
                if(cabeza->getLengua()-0.01*velocidadAnimacion>=0)
                    modificarTLengua(-0.01 * velocidadAnimacion);
                else
                    cabeza->setLengua(0);
                //std::cout << "MOVmeterlengua" << std::endl;
            }

            if (cabeza->getLengua() >= 1.5) {
                finLengua = true;
            } else if (cabeza->getLengua() <= 0) {
                movBrazo1 = true;
                movBrazo2 = false;
                movLengua = false;
                primeraParte = true;
                finLengua = false;
            }
        }
    }
}

void ModeloJerarquico::setModo(int mode) {

    torso->setModo(mode);
    brazo1->setModo(mode);
    brazo2->setModo(mode);
    pierna1->setModo(mode);
    pierna2->setModo(mode);

}
void ModeloJerarquico::setTextura(const std::string & texCabeza, const std::string & texTorso) {

    std::vector<Tupla2f> aux;

    aux.resize(10);
    aux[0]={0.8333333,0.25};
    aux[1]={0.5,0.25};
    aux[2]={0.5,0.75};
    aux[3]={0.8333333,0.75};
    aux[4]={1,0.75};
    aux[5]={1,0.25};
    aux[6]={0.3333333,0.25};
    aux[7]={0.3333333,0.75};
    aux[8]={0,0.25};
    aux[9]={0,0.75};
    aux[10]={0.8333333, 0};
    aux[11]={0.5,0};
    aux[12]={0.8333333, 1};
    aux[13]={0.5, 1};

    torso->crearVectorTexturas(aux);
    torso->setTextura(texTorso);
    cabeza->setTextura(texCabeza);

}

