//
// Created by eric on 21/10/2020.
//

#include <QtWidgets/QGridLayout>
#include "Fenetre.h"

Fenetre::Fenetre() : QFrame() {
    QGridLayout *layout=new QGridLayout();
    button=new QPushButton("Off");
    number=new QLCDNumber();
    slider=new QSlider();
    slider->setOrientation(Qt::Horizontal);
    layout->addWidget(number,4,1);
    layout->addWidget(slider,4,2);
    layout->addWidget(button,5,2);
    setLayout(layout);
}

QPushButton *Fenetre::getButton() const {
    return button;
}

Fenetre::~Fenetre() {

}

QSlider *Fenetre::getSlider() const {
    return slider;
}

QLCDNumber *Fenetre::getNumber() const {
    return number;
}




