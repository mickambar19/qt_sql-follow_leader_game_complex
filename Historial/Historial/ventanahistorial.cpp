#include "ventanahistorial.h"
#include "ui_ventanahistorial.h"
#include <cstring>
#include <QTableWidgetItem>

VentanaHistorial::VentanaHistorial(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VentanaHistorial)
{
    ui->setupUi(this);
    listaHistorial.CargarDatos();
    listaHistorial.Mostrar1();
    setWindowFlags(Qt::WindowTitleHint|Qt::WindowMinimizeButtonHint);
}

VentanaHistorial::~VentanaHistorial()
{
    delete ui;
}

void VentanaHistorial::on_btnActualizar_clicked()
{
    limpiarTabla();
    pnodo actual;
    actual=listaHistorial.inicio;
    ui->tablaDatosHistorial->insertColumn(0);
    ui->tablaDatosHistorial->insertColumn(1);
    ui->tablaDatosHistorial->insertColumn(2);
    ui->tablaDatosHistorial->insertColumn(3);
    int i=0;
    QStringList titulos;
    titulos<<"Jugador"<<"Oponente"<<"Ganador"<<"Puntaje De Ganador";
    ui->tablaDatosHistorial->setHorizontalHeaderLabels(titulos);
    ui->tablaDatosHistorial->horizontalHeader()->setStretchLastSection(true);
    while(actual!=NULL)
    {
        QTableWidgetItem *item;
        ui->tablaDatosHistorial->insertRow(i);
        item = new QTableWidgetItem;
        item->setText(actual->g.NombreJugador);
        ui->tablaDatosHistorial->setItem(i,0,item);

        item = new QTableWidgetItem;
        item->setText(actual->g.NombreOponente);
        ui->tablaDatosHistorial->setItem(i,1,item);

        item = new QTableWidgetItem;
        item->setText(actual->g.NombreGanador);
        ui->tablaDatosHistorial->setItem(i,2,item);

        item = new QTableWidgetItem;
        item->setText(QString::number(actual->g.puntos));
        ui->tablaDatosHistorial->setItem(i,3,item);


        actual=actual->siguiente;
    }
}

void VentanaHistorial::limpiarTabla()
{

    for(int i = 0; i < ui->tablaDatosHistorial->rowCount();)
    {
        delete ui->tablaDatosHistorial->item(i,0);
        delete ui->tablaDatosHistorial->item(i,1);
        delete ui->tablaDatosHistorial->item(i,2);
        delete ui->tablaDatosHistorial->item(i,3);

        ui->tablaDatosHistorial->removeRow(i);
    }
    for(int i = 0; i < ui->tablaDatosHistorial->columnCount();)
    {
       ui->tablaDatosHistorial->removeColumn(i);
    }
    ui->tablaDatosHistorial->horizontalHeader()->setStretchLastSection(false);


}

void VentanaHistorial::on_btnOrdenarPorOponente_clicked()
{
    limpiarTabla();
    pnodo actual;
    //listaHistorial.Burbuja();
    Lista listaAux;
    listaAux=listaHistorial;
    listaAux.Mostrar1();
    //listaHistorial.QuickSort(listaHistorial.inicio,listaHistorial.fin);
    actual=listaAux.inicio;
    ui->tablaDatosHistorial->insertColumn(0);
    ui->tablaDatosHistorial->insertColumn(1);
    ui->tablaDatosHistorial->insertColumn(2);
    ui->tablaDatosHistorial->insertColumn(3);
    int i=0;
    QStringList titulos;
    titulos<<"Jugador"<<"Oponente"<<"Ganador"<<"Puntaje De Ganador";
    ui->tablaDatosHistorial->setHorizontalHeaderLabels(titulos);
    ui->tablaDatosHistorial->horizontalHeader()->setStretchLastSection(true);
    while(actual!=NULL)
    {
        QTableWidgetItem *item;
        ui->tablaDatosHistorial->insertRow(i);
        item = new QTableWidgetItem;
        item->setText(actual->g.NombreJugador);
        ui->tablaDatosHistorial->setItem(i,0,item);

        item = new QTableWidgetItem;
        item->setText(actual->g.NombreOponente);
        ui->tablaDatosHistorial->setItem(i,1,item);

        item = new QTableWidgetItem;
        item->setText(actual->g.NombreGanador);
        ui->tablaDatosHistorial->setItem(i,2,item);

        item = new QTableWidgetItem;
        item->setText(QString::number(actual->g.puntos));
        ui->tablaDatosHistorial->setItem(i,3,item);

        i++;
        actual=actual->siguiente;
    }
}

void VentanaHistorial::on_btnRegresar_clicked()
{
    this->close();
    system("./jueguito");
}
