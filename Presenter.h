//
// Created by eric on 21/10/2020.
//

#ifndef LEDQT_PRESENTER_H
#define LEDQT_PRESENTER_H


#include "Fenetre.h"

class Presenter:public QObject {
Q_OBJECT;
private:
    Fenetre *fenetre;
    QSerialPort *serial;
public:
 Presenter();

    virtual ~Presenter();

    void init();
 public slots:
    void sendData();
    void sendAnalogData();


};


#endif //LEDQT_PRESENTER_H
