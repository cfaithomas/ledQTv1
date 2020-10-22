#include <iostream>
#include <QtWidgets/QApplication>
#include "Presenter.h"
#include "Settings.h"

int Settings::min=0;
int Settings::max=255;
QString Settings::usbname="/dev/ttyACM0";
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Presenter *p=new Presenter();


    return app.exec();
}
