#include "controller/mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon("resources/snail.png"));
    MainWindow w;
    w.setWindowTitle("Slimaks");
    w.show();
    return QApplication::exec();
}
