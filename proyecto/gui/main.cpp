#include <QApplication>
#include "../ui_interfazgrafica.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    MainWindow main_win;
    main_win.setupUi(&app);
    main_win.show();

    return app.exec();
}
