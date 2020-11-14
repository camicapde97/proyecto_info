
#ifndef INTERFAZGRAFICA_H
#define INTERFAZGRAFICA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>
#include "utils.h"

char * table_columns [] =
{
    "numero de serie",
    "modelo",
    "estado",
    "encriptada",
    "garantia",
    "usuario",
    "docusing cheack list ",
    "docusing entrega",
    "docusing devolucion",
    "fecha entrega",
    "fecha devolucion",
    "fecha envio docusing"
};

class MainWindow
{
public:
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QPushButton *pushButton_buscarOk;
    QLineEdit *lineEdit_buscar;
    QLabel *label_buscar;
    QPushButton *pushButton_borrar;
    QMenuBar *menubar;
    QMenu *menuArchivo;
    QStatusBar *statusbar;
    QMainWindow *main_win;

    void setupUi(QApplication *app)
    {
        main_win = new QMainWindow(app->activeWindow());
        main_win->setObjectName("MainWindow");
        main_win->setWindowTitle("MainWindow");
        main_win->resize(800, 600);

        statusbar = new QStatusBar(main_win);
        statusbar->setObjectName("statusbar");
        main_win->setStatusBar(statusbar);
        
        menubar = new QMenuBar(main_win);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 910, 21));
        main_win->setMenuBar(menubar);

        menuArchivo = new QMenu(menubar);
        menuArchivo->setObjectName("menuArchivo");
        menuArchivo->setTitle("Archivo");
        menubar->addAction(menuArchivo->menuAction());

        centralwidget = new QWidget(main_win);
        centralwidget->setObjectName("centralwidget");
        main_win->setCentralWidget(centralwidget);

        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(0, 30, 781, 371));
        tableWidget->setColumnCount(ARRAY_SIZE(table_columns));
        for (int i=0; i<ARRAY_SIZE(table_columns); i++)
        {
            QTableWidgetItem *item = new QTableWidgetItem ();
            item->setText(table_columns[i]);
            tableWidget->setHorizontalHeaderItem (i, item);
        }

        label_buscar = new QLabel(centralwidget);
        label_buscar->setObjectName("label_buscar");
        label_buscar->setGeometry(QRect(10, 10, 46, 13));
        label_buscar->setText("Buscar:");

        lineEdit_buscar = new QLineEdit(centralwidget);
        lineEdit_buscar->setObjectName("lineEdit_buscar");
        lineEdit_buscar->setGeometry(QRect(70, 10, 113, 20));

        pushButton_buscarOk = new QPushButton(centralwidget);
        pushButton_buscarOk->setObjectName("pushButton_buscarOk");
        pushButton_buscarOk->setGeometry(QRect(190, 10, 71, 16));
        pushButton_buscarOk->setText("OK");

        pushButton_borrar = new QPushButton(centralwidget);
        pushButton_borrar->setObjectName("pushButton_borrar");
        pushButton_borrar->setGeometry(QRect(460, 0, 75, 23));
        pushButton_borrar->setText("Borrar");
    }

    void show ()
    {
        main_win->show();
    }
};

#endif // INTERFAZGRAFICA_H
