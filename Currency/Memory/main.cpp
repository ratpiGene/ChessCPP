#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(800, 550);
    //w.setStyleSheet("background-image: url(C:/Users/TamaraSH.OGMA/Dropbox/QtGameFinal/otherImages/axyus.jpg);");
    w.setWindowTitle("Toma's Game");
    w.setWindowIcon(QIcon("C:/Users/TamaraSH.OGMA/Dropbox/QtGameFinal/otherImages/games.png"));

    w.show();

    return a.exec();
}
