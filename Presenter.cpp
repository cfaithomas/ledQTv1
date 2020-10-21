//
// Created by eric on 21/10/2020.
//

#include <cstring>
#include "Presenter.h"

Presenter::Presenter():QObject() {
fenetre=new Fenetre();
serial=new QSerialPort();
fenetre->show();
QObject::connect(fenetre->getButton(),&QPushButton::clicked,this,&Presenter::sendData);
QObject::connect(fenetre->getSlider(),&QSlider::valueChanged,this,&Presenter::sendAnalogData);
init();
}

void Presenter::init() {
    serial->setPortName("/dev/ttyACM0"); //definition du port sur lequel est branché l'arduino
    serial->setBaudRate(QSerialPort::Baud9600); //définition de la vitesse de transmission
    serial->setDataBits(QSerialPort::Data8); //codage sur 8bits
    serial->setParity(QSerialPort::NoParity); //pas de parité
    serial->setStopBits(QSerialPort::OneStop); //un bit de stop
    serial->setFlowControl(QSerialPort::NoFlowControl); //pas de controle de flux
    serial->open(QIODevice::ReadWrite);
    if(serial->isOpen())
    {
        qDebug("Le port USB est ouvert");
    } else
        qDebug("Echec de l'ouverture du port");
}

void Presenter::sendData() {


if(fenetre->getButton()->text()=="Off")
{

    if(serial->isOpen()&&serial->isWritable())
        serial->write("ON\n");
    else
        qDebug("Erreur Ecriture");
    fenetre->getButton()->setText("On");
}
else
{
    if(serial->isOpen()&&serial->isWritable())
        serial->write("OFF\n");
    else
        qDebug("Erreur Ecriture");
    fenetre->getButton()->setText("Off");
}

}

Presenter::~Presenter() {
serial->close();
}

void Presenter::sendAnalogData() {
    char *value[255];
fenetre->getNumber()->display(fenetre->getSlider()->value());
sprintf(*value,"%d",fenetre->getSlider()->value());


    std::strcat(*value,"A");
    if(serial->isOpen()&&serial->isWritable())
        serial->write((const char *)value);
    else
        qDebug("Erreur Ecriture");
}




