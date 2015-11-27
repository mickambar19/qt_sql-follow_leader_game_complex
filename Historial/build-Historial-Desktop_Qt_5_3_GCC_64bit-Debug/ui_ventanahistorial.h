/********************************************************************************
** Form generated from reading UI file 'ventanahistorial.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENTANAHISTORIAL_H
#define UI_VENTANAHISTORIAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VentanaHistorial
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTableWidget *tablaDatosHistorial;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *btnActualizar;
    QPushButton *btnRegresar;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *VentanaHistorial)
    {
        if (VentanaHistorial->objectName().isEmpty())
            VentanaHistorial->setObjectName(QStringLiteral("VentanaHistorial"));
        VentanaHistorial->resize(602, 343);
        centralWidget = new QWidget(VentanaHistorial);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tablaDatosHistorial = new QTableWidget(centralWidget);
        tablaDatosHistorial->setObjectName(QStringLiteral("tablaDatosHistorial"));

        verticalLayout->addWidget(tablaDatosHistorial);

        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        tablaDatosHistorial->raise();

        verticalLayout->addWidget(frame);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        btnActualizar = new QPushButton(centralWidget);
        btnActualizar->setObjectName(QStringLiteral("btnActualizar"));

        horizontalLayout->addWidget(btnActualizar);

        btnRegresar = new QPushButton(centralWidget);
        btnRegresar->setObjectName(QStringLiteral("btnRegresar"));

        horizontalLayout->addWidget(btnRegresar);


        verticalLayout->addLayout(horizontalLayout);

        VentanaHistorial->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(VentanaHistorial);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 602, 25));
        VentanaHistorial->setMenuBar(menuBar);
        mainToolBar = new QToolBar(VentanaHistorial);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        VentanaHistorial->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(VentanaHistorial);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        VentanaHistorial->setStatusBar(statusBar);

        retranslateUi(VentanaHistorial);

        QMetaObject::connectSlotsByName(VentanaHistorial);
    } // setupUi

    void retranslateUi(QMainWindow *VentanaHistorial)
    {
        VentanaHistorial->setWindowTitle(QApplication::translate("VentanaHistorial", "VentanaHistorial", 0));
        pushButton->setText(QApplication::translate("VentanaHistorial", "Ordenar Oponentes", 0));
        btnActualizar->setText(QApplication::translate("VentanaHistorial", "Actualizar", 0));
        btnRegresar->setText(QApplication::translate("VentanaHistorial", "Regresar", 0));
    } // retranslateUi

};

namespace Ui {
    class VentanaHistorial: public Ui_VentanaHistorial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANAHISTORIAL_H
