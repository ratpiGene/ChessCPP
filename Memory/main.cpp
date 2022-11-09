#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(800, 550);
    //w.setStyleSheet("background-image: url(c:/Users/Tamara/Pictures/axyus.jpg);");
    w.setWindowTitle("Memory Game");
    w.setWindowIcon(QIcon("C:/Users/Tamara/Dropbox/TomasGame/otherImages/games.png"));

    w.show();

    return a.exec();
}
