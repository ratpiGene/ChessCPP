#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QPaintEvent>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QTimer>
#include <QMenu>
#include <QAction>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
    //ui(new Ui::MainWindow)
{
    //ui->setupUi(this);



    QMenuBar *mmm= new QMenuBar(this);
    menu = new QMenu("File", mmm);
    QAction * insert = new QAction("New",menu);
    QAction * closeAct = new QAction("Exit",menu);

    menu->addAction(insert);
    menu->addAction(closeAct);
    mmm->addMenu(menu);
    QHBoxLayout *p00=new QHBoxLayout(this);
    p00->addWidget(mmm);
    mmm->setFixedSize(150,700);


    connect(insert, SIGNAL(triggered()), this, SLOT(Repeat()));  // problem is here
    connect(closeAct, SIGNAL(triggered()), this, SLOT(close()));

    QMenu *menu1=new QMenu("Style", mmm);
    QAction * style1 = new QAction("Style1",menu1);
    QAction * style2 = new QAction("Style2",menu1);
    QAction * style3 = new QAction("Style3", menu1);
    menuFont.setBold(true);
    menuFont.setPixelSize(13);
    menu->setStyleSheet("background-color: white; color: white");
    menu->setFont(menuFont);
    menu1->setStyleSheet("background-color: white; color: white");
    menu1->setFont(menuFont);

    menu1->addAction(style1);
    menu1->addAction(style2);
    menu1->addAction(style3);
    mmm->addMenu(menu1);

    connect(style1, SIGNAL(triggered()), this, SLOT(changeStyle()));
    connect(style2, SIGNAL(triggered()), this, SLOT(changeStyle1()));
    connect(style3, SIGNAL(triggered()), this, SLOT(changeStyle2()));

    QMenu * menu2=new QMenu("Help", mmm);
    QAction * about1 = new QAction("About",menu2);

    menu2->setStyleSheet("background-color: white; color: white");
    menu2->setFont(menuFont);
    menu2->addAction(about1);

    mmm->addMenu(menu2);

    connect(about1, SIGNAL(triggered()), this, SLOT(openDialog()));


      serifFont.setBold(true);
      serifFont.setPixelSize(15);

    a=b="";
    u=p=-1;
     k=-1;


    for(int i=0; i<16; i++)
    { counter[i] = 0;}
    changeStyle();
    win = new QWidget;



    scoreFont.setBold(true);
    scoreFont.setPixelSize(30);

    msgBox = new QLabel(this);

    scoreValue=0;


    msgBox->setStyleSheet("background-image: url(none); color: white");
    msgBox->setText(scoreText.append(QString("%1").arg(scoreValue)));
    msgBox->setFont(scoreFont);
    msgBox->setGeometry(55,100,100,100);

}

MainWindow::~MainWindow()
{
    //delete ui;
}
void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter * paint = new QPainter(this);

   // paint->setBrush(Qt::green);
    paint->drawRects(rect, 16);

  //  paint->setOpacity(0.3);
//paint->setOpacity(0.3);
    paint->setBrush(Qt::red);
    int i1=220;
    int j1= 90;
    paint->drawPixmap(i1,j1, 100, 100 , QPixmap(str[0]));
    for(int i=1; i<4; i++){
        paint->drawPixmap(i1+=150,j1, 100, 100 , QPixmap(str[i]));
      }

   i1=220;
   j1= 200;
   paint->drawPixmap(i1,j1, 100, 100 , QPixmap(str[4]));
   for(int i=5; i<8; i++){
       paint->drawPixmap(i1+=150,j1, 100, 100 , QPixmap(str[i]));
     }

   i1=220;
   j1= 310;
   paint->drawPixmap(i1,j1, 100, 100 , QPixmap(str[8]));
   for(int i=9; i<12; i++){
       paint->drawPixmap(i1+=150,j1, 100, 100 , QPixmap(str[i]));
     }

   i1=220;
   j1= 420;
   paint->drawPixmap(i1,j1, 100, 100 , QPixmap(str[12]));
   for(int i=13; i<16; i++){
       paint->drawPixmap(i1+=150,j1, 100, 100 , QPixmap(str[i]));
     }


}

void MainWindow::mousePressEvent(QMouseEvent * coord)
{

    //update();
    if(coord->x()>220 && coord->x()<320 && coord->y()>90 && coord->y()<190 && counter[0] == 0){
        scoreValue++;
        scoreText.clear();
        msgBox->setText(scoreText.append(QString("%1").arg(scoreValue)));
    str[0]=st0;
    counter[0] = 1;
    k=0;
    //myFunction();



    for(int i = 0 ; i< 16; i++){
             if(counter[i] == 1)
               k++;
             }

    if(k==2)
         {
            for(int i=0; i<16; i++)
             {
                 if(counter[i]==1)
                 {
                     a = str[i];
                     u=i;
                     break;
                 }
             }

             for(int j=15; j>=0; j--)
             {
                 if(counter[j]==1)
                 {
                     b = str[j];
                     p=j;
                     break;
                 }
             }

             if(a==b)
             {
                 str[u]=deleteImg;
                 str[p]=deleteImg;
                 counter[u]=-1;
                 counter[p]=-1;
                 k=0;
                 int p=0;
                 for(int i=0; i<16; i++){
                 if(counter[i]==-1)
                   p++;
                }
                 if(p==16) myFunction();
             }

           }
    if(k>=3){
        for(int i=0; i<16;i++)
        {
            if(i==0) continue;
             if(counter[i]==-1) continue;
            str[i]=mushroom;
            counter[i]=0;

        }
    }
   // QTimer *timer = new QTimer(this);
     //    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
       //  timer->start(1000);
    update();


         //jnjel
    return;
 } // first if end
    if(coord->x()>220 && coord->x()<320 && coord->y()>90 && coord->y()<190 && counter[0] == 1){
        str[0]=mushroom;
        counter[0] = 0;
        update();
        return ;
       } // for the first element

    if(coord->x()>370 && coord->x()<470 && coord->y()>90 && coord->y()<190 && counter[1] == 0){
        scoreValue++;
        scoreText.clear();
        msgBox->setText(scoreText.append(QString("%1").arg(scoreValue)));

        str[1]=st1;
    counter[1] = 1;
    k=0;
    for(int i = 0 ; i< 16; i++){
             if(counter[i] == 1)
               k++;
             }

    if(k==2)
         {
            for(int i=0; i<16; i++)
             {
                 if(counter[i]==1)
                 {
                     a = str[i];
                     u=i;
                     break;
                 }
             }

             for(int j=15; j>=0; j--)
             {
                 if(counter[j]==1)
                 {
                     b = str[j];
                     p=j;
                     break;
                 }
             }

             if(a==b)
             {
                 str[u]=deleteImg;
                 str[p]=deleteImg;
                 counter[u]=-1;
                 counter[p]=-1;
                 k=0;
                 int p=0;
                 for(int i=0; i<16; i++){
                 if(counter[i]==-1)
                   p++;
                }
                 if(p==16) myFunction();
             }

           }
    if(k>=3){
        for(int i=0; i<16;i++)
        {
            if(i==1) continue;
             if(counter[i]==-1) continue;
            str[i]=mushroom;
            counter[i]=0;
        }
    }
    update();
    return;
 }
    if(coord->x()>370 && coord->x()<470 && coord->y()>90 && coord->y()<190 && counter[1] == 1){
        str[1]=mushroom;
        counter[1] = 0;
        update();
        return ;
       } // for the second

    if(coord->x()>520 && coord->x()<620 && coord->y()>90 && coord->y()<190 && counter[2] == 0){
        scoreValue++;
        scoreText.clear();
        msgBox->setText(scoreText.append(QString("%1").arg(scoreValue)));
    str[2]=st2;
    counter[2] = 1;
    k=0;
    for(int i = 0 ; i< 16; i++){
             if(counter[i] == 1)
               k++;
             }

    if(k==2)
         {
            for(int i=0; i<16; i++)
             {
                 if(counter[i]==1)
                 {
                     a = str[i];
                     u=i;
                     break;
                 }
             }

             for(int j=15; j>=0; j--)
             {
                 if(counter[j]==1)
                 {
                     b = str[j];
                     p=j;
                     break;
                 }
             }

             if(a==b)
             {
                 str[u]=deleteImg;
                 str[p]=deleteImg;
                 counter[u]=-1;
                 counter[p]=-1;
                 k=0;
                 int p=0;
                 for(int i=0; i<16; i++){
                 if(counter[i]==-1)
                   p++;
                }
                 if(p==16) myFunction();
             }

           }
    if(k>=3){
        for(int i=0; i<16;i++)
        {
            if(i==2) continue;
             if(counter[i]==-1) continue;
            str[i]=mushroom;
            counter[i]=0;
        }
    }
    update();
    return;
 }
    if(coord->x()>520 && coord->x()<620 && coord->y()>90 && coord->y()<190 && counter[2] == 1){
        str[2]=mushroom;
        counter[2] = 0;
        update();
        return ;
       } // for the third

    if(coord->x()>670 && coord->x()<770 && coord->y()>90 && coord->y()<190 && counter[3] == 0){
        scoreValue++;
        scoreText.clear();
        msgBox->setText(scoreText.append(QString("%1").arg(scoreValue)));

    str[3]=st3;
    counter[3] = 1;
    k=0;
    for(int i = 0 ; i< 16; i++){
             if(counter[i] == 1)
               k++;
             }

    if(k==2)
         {
            for(int i=0; i<16; i++)
             {
                 if(counter[i]==1)
                 {
                     a = str[i];
                     u=i;
                     break;
                 }
             }

             for(int j=15; j>=0; j--)
             {
                 if(counter[j]==1)
                 {
                     b = str[j];
                     p=j;
                     break;
                 }
             }

             if(a==b)
             {
                 str[u]=deleteImg;
                 str[p]=deleteImg;
                 counter[u]=-1;
                 counter[p]=-1;
                 k=0;
                 int p=0;
                 for(int i=0; i<16; i++){
                 if(counter[i]==-1)
                   p++;
                }
                 if(p==16) myFunction();
             }

           }
    if(k>=3){
        for(int i=0; i<16;i++)
        {
            if(i==3) continue;
             if(counter[i]==-1) continue;
            str[i]=mushroom;
            counter[i]=0;
        }
    }
    update();
    return;
 }
    if(coord->x()>670 && coord->x()<770  && coord->y()>90 && coord->y()<190 && counter[3] == 1){
        str[3]=mushroom;
        counter[3] = 0;
        update();
        return ;
       } // for the 4th
// first block end




    if(coord->x()>220 && coord->x()<320 && coord->y()>200 && coord->y()<300 && counter[4] == 0){

        scoreValue++;
        scoreText.clear();
        msgBox->setText(scoreText.append(QString("%1").arg(scoreValue)));

    str[4]=st4;
    counter[4] = 1;
    k=0;
    for(int i = 0 ; i< 16; i++){
             if(counter[i] == 1)
               k++;
             }

    if(k==2)
         {
            for(int i=0; i<16; i++)
             {
                 if(counter[i]==1)
                 {
                     a = str[i];
                     u=i;
                     break;
                 }
             }

             for(int j=15; j>=0; j--)
             {
                 if(counter[j]==1)
                 {
                     b = str[j];
                     p=j;
                     break;
                 }
             }

             if(a==b)
             {
                 str[u]=deleteImg;
                 str[p]=deleteImg;
                 counter[u]=-1;
                 counter[p]=-1;
                 k=0;
                 int p=0;
                 for(int i=0; i<16; i++){
                 if(counter[i]==-1)
                   p++;
                }
                 if(p==16) myFunction();
             }

           }
    if(k>=3){
        for(int i=0; i<16;i++)
        {
            if(i==4) continue;
             if(counter[i]==-1) continue;
            str[i]=mushroom;
            counter[i]=0;
        }
    }
    update();
    return;
 } // first if end
    if(coord->x()>220 && coord->x()<320 && coord->y()>200 && coord->y()<300  && counter[4] == 1){
        str[4]=mushroom;
        counter[4] = 0;
        update();
        return ;
       } // for the 5th element

    if(coord->x()>370 && coord->x()<470 && coord->y()>200 && coord->y()<300 && counter[5] == 0){

        scoreValue++;
        scoreText.clear();
        msgBox->setText(scoreText.append(QString("%1").arg(scoreValue)));


    str[5]=st5;
    counter[5] = 1;
    k=0;
    for(int i = 0 ; i< 16; i++){
             if(counter[i] == 1)
               k++;
             }

    if(k==2)
         {
            for(int i=0; i<16; i++)
             {
                 if(counter[i]==1)
                 {
                     a = str[i];
                     u=i;
                     break;
                 }
             }

             for(int j=15; j>=0; j--)
             {
                 if(counter[j]==1)
                 {
                     b = str[j];
                     p=j;
                     break;
                 }
             }

             if(a==b)
             {
                 str[u]=deleteImg;
                 str[p]=deleteImg;
                 counter[u]=-1;
                 counter[p]=-1;
                 k=0;
                 int p=0;
                 for(int i=0; i<16; i++){
                 if(counter[i]==-1)
                   p++;
                }
                 if(p==16) myFunction();
             }

           }
    if(k>=3){
        for(int i=0; i<16;i++)
        {
            if(i==5) continue;
             if(counter[i]==-1) continue;
            str[i]=mushroom;
            counter[i]=0;
        }
    }
    update();
    return;
 }
    if(coord->x()>370 && coord->x()<470 && coord->y()>200 && coord->y()<300 && counter[5] == 1){

        scoreValue++;
        scoreText.clear();
        msgBox->setText(scoreText.append(QString("%1").arg(scoreValue)));


        str[5]=mushroom;
        counter[5] = 0;
        update();
        return ;
       } // for the 6th

    if(coord->x()>520 && coord->x()<620 && coord->y()>200 && coord->y()<300 && counter[6] == 0){
    str[6]=st6;
    counter[6] = 1;
    k=0;
    for(int i = 0 ; i< 16; i++){
             if(counter[i] == 1)
               k++;
             }

    if(k==2)
         {
            for(int i=0; i<16; i++)
             {
                 if(counter[i]==1)
                 {
                     a = str[i];
                     u=i;
                     break;
                 }
             }

             for(int j=15; j>=0; j--)
             {
                 if(counter[j]==1)
                 {
                     b = str[j];
                     p=j;
                     break;
                 }
             }

             if(a==b)
             {
                 str[u]=deleteImg;
                 str[p]=deleteImg;
                 counter[u]=-1;
                 counter[p]=-1;
                 k=0;
                 int p=0;
                 for(int i=0; i<16; i++){
                 if(counter[i]==-1)
                   p++;
                }
                 if(p==16) myFunction();
             }

           }
    if(k>=3){
        for(int i=0; i<16;i++)
        {
            if(i==6) continue;
             if(counter[i]==-1) continue;
            str[i]=mushroom;
            counter[i]=0;
        }
    }
    update();
    return;
 }
    if(coord->x()>520 && coord->x()<620 && coord->y()>200 && coord->y()<300 && counter[6] == 1){
        str[6]=mushroom;
        counter[6] = 0;
        update();
        return ;
       } // for the 7th

    if(coord->x()>670 && coord->x()<770 &&  coord->y()>200 && coord->y()<300 && counter[7] == 0){

        scoreValue++;
        scoreText.clear();
        msgBox->setText(scoreText.append(QString("%1").arg(scoreValue)));


    str[7]=st7;
    counter[7] = 1;
    k=0;
    for(int i = 0 ; i< 16; i++){
             if(counter[i] == 1)
               k++;
             }

    if(k==2)
         {
            for(int i=0; i<16; i++)
             {
                 if(counter[i]==1)
                 {
                     a = str[i];
                     u=i;
                     break;
                 }
             }

             for(int j=15; j>=0; j--)
             {
                 if(counter[j]==1)
                 {
                     b = str[j];
                     p=j;
                     break;
                 }
             }

             if(a==b)
             {
                 str[u]=deleteImg;
                 str[p]=deleteImg;
                 counter[u]=-1;
                 counter[p]=-1;
                 k=0;
                 int p=0;
                 for(int i=0; i<16; i++){
                 if(counter[i]==-1)
                   p++;
                }
                 if(p==16) myFunction();
             }

           }
    if(k>=3){
        for(int i=0; i<16;i++)
        {
            if(i==7) continue;
             if(counter[i]==-1) continue;
            str[i]=mushroom;
            counter[i]=0;
        }
    }
    update();

    return;
 }
    if(coord->x()>670 && coord->x()<770  && coord->y()>200 && coord->y()<300 && counter[7] == 1){
        str[7]=mushroom;
        counter[7] = 0;
        update();
        return ;
       } // for the 8th

    // second block end



    if(coord->x()>220 && coord->x()<320 && coord->y()>310 && coord->y()<410 && counter[8] == 0){

        scoreValue++;
        scoreText.clear();
        msgBox->setText(scoreText.append(QString("%1").arg(scoreValue)));


    str[8]=st8;
    counter[8] = 1;
    k=0;
    for(int i = 0 ; i< 16; i++){
             if(counter[i] == 1)
               k++;
             }

    if(k==2)
         {
            for(int i=0; i<16; i++)
             {
                 if(counter[i]==1)
                 {
                     a = str[i];
                     u=i;
                     break;
                 }
             }

             for(int j=15; j>=0; j--)
             {
                 if(counter[j]==1)
                 {
                     b = str[j];
                     p=j;
                     break;
                 }
             }

             if(a==b)
             {
                 str[u]=deleteImg;
                 str[p]=deleteImg;
                 counter[u]=-1;
                 counter[p]=-1;
                 k=0;
                 int p=0;
                 for(int i=0; i<16; i++){
                 if(counter[i]==-1)
                   p++;
                }
                 if(p==16) myFunction();
             }

           }
    if(k>=3){
        for(int i=0; i<16;i++)
        {
            if(i==8) continue;
             if(counter[i]==-1) continue;
            str[i]=mushroom;
            counter[i]=0;
        }
    }
    update();
    return;
 }



    if(coord->x()>370 && coord->x()<470 &&  coord->y()>310 && coord->y()<410 && counter[9] == 0){

        scoreValue++;
        scoreText.clear();
        msgBox->setText(scoreText.append(QString("%1").arg(scoreValue)));

    str[9]=st9;
    counter[9] = 1;
    k=0;
    for(int i = 0 ; i< 16; i++){
             if(counter[i] == 1)
               k++;
             }

    if(k==2)
         {
            for(int i=0; i<16; i++)
             {
                 if(counter[i]==1)
                 {
                     a = str[i];
                     u=i;
                     break;
                 }
             }

             for(int j=15; j>=0; j--)
             {
                 if(counter[j]==1)
                 {
                     b = str[j];
                     p=j;
                     break;
                 }
             }

             if(a==b)
             {
                 str[u]=deleteImg;
                 str[p]=deleteImg;
                 counter[u]=-1;
                 counter[p]=-1;
                 k=0;
                 int p=0;
                 for(int i=0; i<16; i++){
                 if(counter[i]==-1)
                   p++;
                }
                 if(p==16) myFunction();
             }

           }
    if(k>=3){
        for(int i=0; i<16;i++)
        {
            if(i==9) continue;
             if(counter[i]==-1) continue;
            str[i]=mushroom;
            counter[i]=0;
        }
    }
    update();
    return;
 }

    if(coord->x()>370 && coord->x()<470 &&  coord->y()>310 && coord->y()<410 && counter[9] == 1){
        str[9]=mushroom;
        counter[9] = 0;
        update();
        return ;
       } // for the 10th

    if(coord->x()>520 && coord->x()<620 &&  coord->y()>310 && coord->y()<410 && counter[10] == 0){

        scoreValue++;
        scoreText.clear();
        msgBox->setText(scoreText.append(QString("%1").arg(scoreValue)));

    str[10]=st10;
    counter[10] = 1;
    k=0;
    for(int i = 0 ; i< 16; i++){
             if(counter[i] == 1)
               k++;
             }

    if(k==2)
         {
            for(int i=0; i<16; i++)
             {
                 if(counter[i]==1)
                 {
                     a = str[i];
                     u=i;
                     break;
                 }
             }

             for(int j=15; j>=0; j--)
             {
                 if(counter[j]==1)
                 {
                     b = str[j];
                     p=j;
                     break;
                 }
             }

             if(a==b)
             {
                 str[u]=deleteImg;
                 str[p]=deleteImg;
                 counter[u]=-1;
                 counter[p]=-1;
                 k=0;
                 int p=0;
                 for(int i=0; i<16; i++){
                 if(counter[i]==-1)
                   p++;
                }
                 if(p==16) myFunction();
             }

           }
    if(k>=3){
        for(int i=0; i<16;i++)
        {
            if(i==10) continue;
             if(counter[i]==-1) continue;
            str[i]=mushroom;
            counter[i]=0;
        }
    }

    update();
    return;
 }



    if(coord->x()>520 && coord->x()<620 &&  coord->y()>310 && coord->y()<410 && counter[10] == 1){


        str[10]=mushroom;
        counter[10] = 0;
        update();
        return ;
       } // for the 11th

    if(coord->x()>670 && coord->x()<770 &&  coord->y()>310 && coord->y()<410 && counter[11] == 0){

        scoreValue++;
        scoreText.clear();
        msgBox->setText(scoreText.append(QString("%1").arg(scoreValue)));

    str[11]=st11;
    counter[11] = 1;
    k=0;
    for(int i = 0 ; i< 16; i++){
             if(counter[i] == 1)
               k++;
             }

    if(k==2)
         {
            for(int i=0; i<16; i++)
             {
                 if(counter[i]==1)
                 {
                     a = str[i];
                     u=i;
                     break;
                 }
             }

             for(int j=15; j>=0; j--)
             {
                 if(counter[j]==1)
                 {
                     b = str[j];
                     p=j;
                     break;
                 }
             }

             if(a==b)
             {
                 str[u]=deleteImg;
                 str[p]=deleteImg;
                 counter[u]=-1;
                 counter[p]=-1;
                 k=0;
                 int p=0;
                 for(int i=0; i<16; i++){
                 if(counter[i]==-1)
                   p++;
                }
                 if(p==16) myFunction();
             }

           }
    if(k>=3){
        for(int i=0; i<16;i++)
        {
            if(i==11) continue;
             if(counter[i]==-1) continue;
            str[i]=mushroom;
            counter[i]=0;
        }
    }
    update();
    return;
 }

    if(coord->x()>670 && coord->x()<770  &&  coord->y()>310 && coord->y()<410 && counter[11] == 1){

        str[11]=mushroom;
        counter[11] = 0;
        update();
        return ;
       } // for the 12

    // end of 3rd block


    if(coord->x()>220 && coord->x()<320 && coord->y()>420 && coord->y()<520 && counter[12] == 0){

        scoreValue++;
        scoreText.clear();
        msgBox->setText(scoreText.append(QString("%1").arg(scoreValue)));


    str[12]=st12;
    counter[12] = 1;
    k=0;
    for(int i = 0 ; i< 16; i++){
             if(counter[i] == 1)
               k++;
             }

    if(k==2)
         {
            for(int i=0; i<16; i++)
             {
                 if(counter[i]==1)
                 {
                     a = str[i];
                     u=i;
                     break;
                 }
             }

             for(int j=15; j>=0; j--)
             {
                 if(counter[j]==1)
                 {
                     b = str[j];
                     p=j;
                     break;
                 }
             }

             if(a==b)
             {
                 str[u]=deleteImg;
                 str[p]=deleteImg;
                 counter[u]=-1;
                 counter[p]=-1;
                 k=0;
                 int p=0;
                 for(int i=0; i<16; i++){
                 if(counter[i]==-1)
                   p++;
                }
                 if(p==16) myFunction();
             }

           }
    if(k>=3){
        for(int i=0; i<16;i++)
        {
            if(i==12) continue;
             if(counter[i]==-1) continue;
            str[i]=mushroom;
            counter[i]=0;
        }
    }
    update();
    return;
 }


    if(coord->x()>220 && coord->x()<320 && coord->y()>420 && coord->y()<520  && counter[12] == 1){
        str[12]=mushroom;
        counter[12] = 0;
        update();
        return ;
       } //13th element

    if(coord->x()>370 && coord->x()<470 && coord->y()>420 && coord->y()<520 && counter[13] == 0){

        scoreValue++;
        scoreText.clear();
        msgBox->setText(scoreText.append(QString("%1").arg(scoreValue)));


    str[13]=st13;
    counter[13] = 1;
    k=0;
    for(int i = 0 ; i< 16; i++){
             if(counter[i] == 1)
               k++;
             }

    if(k==2)
         {
            for(int i=0; i<16; i++)
             {
                 if(counter[i]==1)
                 {
                     a = str[i];
                     u=i;
                     break;
                 }
             }

             for(int j=15; j>=0; j--)
             {
                 if(counter[j]==1)
                 {
                     b = str[j];
                     p=j;
                     break;
                 }
             }

             if(a==b)
             {
                 str[u]=deleteImg;
                 str[p]=deleteImg;

                 counter[u]=-1;
                 counter[p]=-1;
                 k=0;
                 int p=0;
                 for(int i=0; i<16; i++){
                 if(counter[i]==-1)
                   p++;
                }
                 if(p==16) myFunction();
             }

           }
    if(k>=3){
        for(int i=0; i<16;i++)
        {
            if(i==13) continue;
             if(counter[i]==-1) continue;
            str[i]=mushroom;
            counter[i]=0;
        }
    }
    update();
    return;
 }

    if(coord->x()>370 && coord->x()<470 && coord->y()>420 && coord->y()<520 && counter[13] == 1){
        str[13]=mushroom;
        counter[13] = 0;
        update();
        return ;
       } // for the 14th

    if(coord->x()>520 && coord->x()<620 && coord->y()>420 && coord->y()<520 && counter[14] == 0){

        scoreValue++;
        scoreText.clear();
        msgBox->setText(scoreText.append(QString("%1").arg(scoreValue)));


    str[14]=st14;
    counter[14] = 1;
    k=0;
    for(int i = 0 ; i< 16; i++){
             if(counter[i] == 1)
               k++;
             }

    if(k==2)
         {
            for(int i=0; i<16; i++)
             {
                 if(counter[i]==1)
                 {
                     a = str[i];
                     u=i;
                     break;
                 }
             }

             for(int j=15; j>=0; j--)
             {
                 if(counter[j]==1)
                 {
                     b = str[j];
                     p=j;
                     break;
                 }
             }

             if(a==b)
             {
                 str[u]=deleteImg;
                 str[p]=deleteImg;
                 counter[u]=-1;
                 counter[p]=-1;
                 k=0;
                 int p=0;
                 for(int i=0; i<16; i++){
                 if(counter[i]==-1)
                   p++;
                }
                 if(p==16) myFunction();
             }

           }
    if(k>=3){
        for(int i=0; i<16;i++)
        {
            if(i==14) continue;
             if(counter[i]==-1) continue;
            str[i]=mushroom;
            counter[i]=0;
        }
    }
    update();
    return;
 }

    if(coord->x()>520 && coord->x()<620 && coord->y()>420 && coord->y()<520 && counter[14] == 1){
        str[14]=mushroom;
        counter[14] = 0;
        update();
        return ;
       } // for the 15th

    if(coord->x()>670 && coord->x()<770 && coord->y()>420 && coord->y()<520 && counter[15] == 0){

        scoreValue++;
        scoreText.clear();
        msgBox->setText(scoreText.append(QString("%1").arg(scoreValue)));


    str[15]=st15;
    counter[15] = 1;
    k=0;
    for(int i = 0 ; i< 16; i++){
             if(counter[i] == 1)
               k++;
             }

    if(k==2)
         {
            for(int i=0; i<16; i++)
             {
                 if(counter[i]==1)
                 {
                     a = str[i];
                     u=i;
                     break;
                 }
             }

             for(int j=15; j>=0; j--)
             {
                 if(counter[j]==1)
                 {
                     b = str[j];
                     p=j;
                     break;
                 }
             }

             if(a==b)
             {
                 str[u]=deleteImg;
                 str[p]=deleteImg;
                 counter[u]=-1;
                 counter[p]=-1;
                 k=0;
                 int p=0;
                 for(int i=0; i<16; i++){
                 if(counter[i]==-1)
                   p++;
                }
                 if(p==16) myFunction();
             }

           }
    if(k>=3){
        for(int i=0; i<16;i++)
        {
            if(i==15) continue;
            if(counter[i]==-1) continue;
            str[i]=mushroom;
            counter[i]=0;
        }
    }
    update();
    return;
 }
    if(coord->x()>520 && coord->x()<620 && coord->y()>200 && coord->y()<300 && counter[15] == 1){
        str[15]=mushroom;
        counter[15] = 0;
        update();
        return ;
       } // for the 7th


}
void MainWindow::fileRecorder(QString scoreText)
{
    QFile file("C:\\Users\\Tamara\\Downloads\\mYgAME\\ScoreInfo.txt");

    QDataStream out(&file);   // we will serialize the data into the file
    QString a= scoreText;
    out << a;

//    QFile file("C:\Users\Tamara\Downloads\mYgAME\ScoreInfo.txt");
//        QTextStream out(&file);
//        out << "The magic number is: " << scoreText << "\n";
}

void MainWindow::myFunction(){

    fileRecorder();
    QHBoxLayout *h1 = new QHBoxLayout;
    QHBoxLayout *h2 = new QHBoxLayout;
    QLabel* label = new QLabel;
    QVBoxLayout *v = new QVBoxLayout;
    QPushButton *n=new QPushButton("Repeat", win);
    QPushButton *e = new QPushButton("Quit", win);
    n->setFixedSize(80,30);
    e->setFixedSize(80,30);
    win->setFixedSize(500,100);
    win->setStyleSheet("background-color: #DB7093; color: black");
    n->setStyleSheet("background-color: black; color: white");
    e->setStyleSheet("background-color: black; color: white");
    n->setFont(serifFont);
    e->setFont(serifFont);
    win->setWindowTitle("Menu");
    h1->addWidget(label);
    h2->addWidget(n);
    h2->addWidget(e);
    h2->addSpacing(10);
    v->addLayout(h1);
    v->addLayout(h2);
    v->addSpacing(80);
    win->setLayout(v);
    win->show();

    connect(e, SIGNAL(clicked()), this, SLOT(close()));
    connect(e, SIGNAL(clicked()), win, SLOT(close()));

    connect(n, SIGNAL(clicked()), win, SLOT(close()));
    connect(n, SIGNAL(clicked()), this, SLOT(Repeat())); // anel


}

void MainWindow::Repeat(){


    a=b="";
    u=p=-1;
     k=-1;


    for(int i=0; i<16; i++){
             str[i]="c:/Users/Tamara/Pictures/zatik.png";
    }
    for(int i=0; i<16; i++){
           counter[i]=0;
    }

    scoreText="";
    scoreValue=0;
    scoreText.clear();
    msgBox->setText(scoreText.append(QString("%1").arg(scoreValue)));

    update();
}

void MainWindow::changeStyle()
{
    for(int i=0; i<16; i++){
         if(counter[i]==0){
             str[i]="c:/Users/Tamara/Pictures/zatik.png";
         }}
     this->setStyleSheet("background-image: url(c:/Users/Tamara/Pictures/grass.jpg);");
    mushroom="c:/Users/Tamara/Pictures/zatik.png";
    deleteImg="c:/Users/Tamara/Pictures/mda.png";

    st0= "C:/Users/Tamara/Dropbox/TomasGame/letters/b.png";
    st1= "C:/Users/Tamara/Dropbox/TomasGame/letters/t.png";
    st2= "C:/Users/Tamara/Dropbox/TomasGame/letters/o.png";
    st3= "C:/Users/Tamara/Dropbox/TomasGame/letters/n.png";
    st4= "C:/Users/Tamara/Dropbox/TomasGame/letters/c.png";
    st5= "C:/Users/Tamara/Dropbox/TomasGame/letters/k.png";
    st6= "C:/Users/Tamara/Dropbox/TomasGame/letters/x.png";
    st7= "C:/Users/Tamara/Dropbox/TomasGame/letters/t.png";
    st8= "C:/Users/Tamara/Dropbox/TomasGame/letters/n.png";
    st9= "C:/Users/Tamara/Dropbox/TomasGame/letters/b.png";
    st10= "C:/Users/Tamara/Dropbox/TomasGame/letters/w.png";
    st11= "C:/Users/Tamara/Dropbox/TomasGame/letters/o.png";
    st12= "C:/Users/Tamara/Dropbox/TomasGame/letters/x.png";
    st13= "C:/Users/Tamara/Dropbox/TomasGame/letters/c.png";
    st14= "C:/Users/Tamara/Dropbox/TomasGame/letters/w.png";
    st15= "C:/Users/Tamara/Dropbox/TomasGame/letters/k.png";
    for(int i=0; i<16; i++){
        if(counter[i]==-1){
            str[i]=deleteImg;
        }
    }
    update();

}

void MainWindow::changeStyle1()
{
    for(int i=0; i<16; i++){
         if(counter[i]==0){
             str[i]="c:/Users/Tamara/Pictures/hot.png";
         }}
     this->setStyleSheet("background-image: url(c:/Users/Tamara/Pictures/epic.jpg);");
    mushroom="c:/Users/Tamara/Pictures/hot.png";
   deleteImg="c:/Users/Tamara/Pictures/sword.png";
   st0= "C:/Users/Tamara/Dropbox/TomasGame/letters/b.png";
   st1= "C:/Users/Tamara/Dropbox/TomasGame/letters/t.png";
   st2= "C:/Users/Tamara/Dropbox/TomasGame/letters/o.png";
   st3= "C:/Users/Tamara/Dropbox/TomasGame/letters/n.png";
   st4= "C:/Users/Tamara/Dropbox/TomasGame/letters/c.png";
   st5= "C:/Users/Tamara/Dropbox/TomasGame/letters/k.png";
   st6= "C:/Users/Tamara/Dropbox/TomasGame/letters/x.png";
   st7= "C:/Users/Tamara/Dropbox/TomasGame/letters/t.png";
   st8= "C:/Users/Tamara/Dropbox/TomasGame/letters/n.png";
   st9= "C:/Users/Tamara/Dropbox/TomasGame/letters/b.png";
   st10= "C:/Users/Tamara/Dropbox/TomasGame/letters/w.png";
   st11= "C:/Users/Tamara/Dropbox/TomasGame/letters/o.png";
   st12= "C:/Users/Tamara/Dropbox/TomasGame/letters/x.png";
   st13= "C:/Users/Tamara/Dropbox/TomasGame/letters/c.png";
   st14= "C:/Users/Tamara/Dropbox/TomasGame/letters/w.png";
   st15= "C:/Users/Tamara/Dropbox/TomasGame/letters/k.png";
   for(int i=0; i<16; i++){
       if(counter[i]==-1){
           str[i]=deleteImg;
       }
   }
    update();
}

void MainWindow::changeStyle2()
{
    for(int i=0; i<16; i++){
        if(counter[i]==0){
        str[i]="c:/Users/Tamara/Pictures/mushroom.png";
        }
    }
     this->setStyleSheet("background-image: url(c:/Users/Tamara/Pictures/axyus.jpg);");
       mushroom="c:/Users/Tamara/Pictures/mushroom.png";
    deleteImg="c:/Users/Tamara/Pictures/mda.png";
    st0= "C:/Users/Tamara/Dropbox/TomasGame/letters/b.png";
    st1= "C:/Users/Tamara/Dropbox/TomasGame/letters/t.png";
    st2= "C:/Users/Tamara/Dropbox/TomasGame/letters/o.png";
    st3= "C:/Users/Tamara/Dropbox/TomasGame/letters/n.png";
    st4= "C:/Users/Tamara/Dropbox/TomasGame/letters/c.png";
    st5= "C:/Users/Tamara/Dropbox/TomasGame/letters/k.png";
    st6= "C:/Users/Tamara/Dropbox/TomasGame/letters/x.png";
    st7= "C:/Users/Tamara/Dropbox/TomasGame/letters/t.png";
    st8= "C:/Users/Tamara/Dropbox/TomasGame/letters/n.png";
    st9= "C:/Users/Tamara/Dropbox/TomasGame/letters/b.png";
    st10= "C:/Users/Tamara/Dropbox/TomasGame/letters/w.png";
    st11= "C:/Users/Tamara/Dropbox/TomasGame/letters/o.png";
    st12= "C:/Users/Tamara/Dropbox/TomasGame/letters/x.png";
    st13= "C:/Users/Tamara/Dropbox/TomasGame/letters/c.png";
    st14= "C:/Users/Tamara/Dropbox/TomasGame/letters/w.png";
    st15= "C:/Users/Tamara/Dropbox/TomasGame/letters/k.png";
    for(int i=0; i<16; i++){
        if(counter[i]==-1){
            str[i]=deleteImg;
        }
    }
    update();

}

void MainWindow::openDialog()
{

    //QWidget * dialog = new QWidget();
   // dialog->setWindowTitle("About");


    QMessageBox * text = new QMessageBox();
    text->setFixedSize(300,250);
    //text->setParent(dialog);

   text->setFont(serifFont);
text->setText(func());
   text->exec();
    //

    //text->setGeometry(22, 20, 250, 200);



   // text->setFixedSize(300);

    //dialog->setLayout();


}


 QString MainWindow::func(){
     QString aboutText = "Եթե դու փազլ խաղերի սիրահար ես ,ապա ճիշտ ժամանակն է փորձելու քո արագ կողմնորոշվելու տաղանդը այս խաղում։ Կանոնները շատ պարզ են ․ պետք է գտնել նման նկարները և միաժամանակ բացել, այդ դեպքում նրանք կջնջվեն ։ Քո առաջադրանքն է որքան հնարավոր է արագ անել դա , և նոր լեվելների անցնել։ ";

    return aboutText;
}
