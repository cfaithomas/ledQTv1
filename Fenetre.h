//
// Created by eric on 21/10/2020.
//

#ifndef LEDQT_FENETRE_H
#define LEDQT_FENETRE_H


#include <QtWidgets/QFrame>
#include <QtWidgets/QPushButton>
#include <QtSerialPort/QSerialPort>
#include <QtWidgets/QSlider>
#include <QtWidgets/QLCDNumber>

class Fenetre : public QFrame{
private:
    QPushButton *button;
    QSlider *slider;
    QLCDNumber *number;
public:
    Fenetre();

    virtual ~Fenetre();

    QPushButton *getButton() const;

    QSlider *getSlider() const;

    QLCDNumber *getNumber() const;
};


#endif //LEDQT_FENETRE_H
