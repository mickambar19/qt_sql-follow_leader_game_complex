#ifndef VENTANAHISTORIAL_H
#define VENTANAHISTORIAL_H

#include <QMainWindow>
#include "lista.h"
#include "avl.h"
namespace Ui {
class VentanaHistorial;
}

class VentanaHistorial : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaHistorial(QWidget *parent = 0);
    ~VentanaHistorial();

private slots:


    void on_btnActualizar_clicked();

    void limpiarTabla();

    void on_btnOrdenarPorOponente_clicked();

    void on_btnRegresar_clicked();

private:
    Ui::VentanaHistorial *ui;
    Lista listaHistorial;
    AVL<Ganador> avl;

};

#endif // VENTANAHISTORIAL_H
