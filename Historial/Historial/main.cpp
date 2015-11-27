#include "ventanahistorial.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    VentanaHistorial w;
    w.show();

    return a.exec();
}
