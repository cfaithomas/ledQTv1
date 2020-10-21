#include <iostream>
#include <QtWidgets/QApplication>
#include "Presenter.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Presenter *p=new Presenter();


    return app.exec();
}
