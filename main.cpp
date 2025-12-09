#include "timirbaevmainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TimirbaevMainWindow w;
    w.show();
    return a.exec();
}
