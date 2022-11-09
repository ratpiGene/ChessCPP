#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMouseEvent>
#include <QMainWindow>
#include <QWidget>
#include <QMessageBox>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void myFunction();
    QString func();
    void templateFunction(int z, QString stn);
public slots:
    void Repeat();
    void changeStyle();
    void changeStyle1();
    void changeStyle2();
    void openDialog();
    void newGame();
    void fileRecorder();
private:
   // Ui::MainWindow *ui;
    QRect rect[16];
    QString str[16];
    QString mushroom;
    QString deleteImg;

    int counter[16]; // -1 disabled , 0 closed , 1 open
    int k;
    QString a, b;
    int u,p;


    QString st0;
    QString st1;
    QString st2;
    QString st3;
    QString st4;
    QString st5;
    QString st6;
    QString st7;
    QString st8;
    QString st9;
    QString st10;
    QString st11;
    QString st12;
    QString st13;
    QString st14;
    QString st15;


    QWidget *win;


    QFont serifFont;

    QFont menuFont;

    QFont scoreFont;

    QMenu *menu;

   // QPushButton * but ;
    QLabel* msgBox;
    QString scoreText;
    int scoreValue;



};

#endif // MAINWINDOW_H
