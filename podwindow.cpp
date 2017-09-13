#include "podwindow.h"
#include "ui_podwindow.h"
#include <QPalette>

podwindow::podwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::podwindow)
{
    ui->setupUi(this);
//    pods.append(ui->toolButton);
//    pods.append(ui->toolButton_2);
//    pods.append(ui->toolButton_3);
//    pods.append(ui->toolButton_4);
//    pods.append(ui->toolButton_5);
//    pods.append(ui->toolButton_6);
//    pods.append(ui->toolButton_7);
//    pods.append(ui->toolButton_8);

    //    initPodsPro();

    //        myobutton = new MyoButton(0);
    ////        myobutton->setL(0,-20);
    ////        myobutton->setAngle(90);
    //        myobutton->setLevel(0);
    //        myobutton->update();
    //        ui->widget->layout()->addWidget(myobutton);

    //    for(int i=0;i<8;i++){
    //        MyoButton* myobutton = new MyoButton();
    //        ePods.append(myobutton);
    //    }

    //    for(int i=0;i<4;i++){
    //        ePods.at(i)->setAngle(podsPro[i].angle);
    //        ePods.at(i+4)->setAngle(podsPro[i+4].angle);
    //        ePods.at(i)->setL(podsPro[i].l1,podsPro[i].l2);
    //        ePods.at(i+4)->setL(podsPro[i+4].l1,podsPro[i+4].l2);
    //    }

    initPods();
    ui->grid->addWidget(ePods.at(0),0,1,Qt::AlignCenter);
    ui->grid->addWidget(ePods.at(1),0,2,Qt::AlignCenter);
    ui->grid->addWidget(ePods.at(2),1,2,Qt::AlignCenter);
    ui->grid->addWidget(ePods.at(3),2,2,Qt::AlignCenter);
    ui->grid->addWidget(ePods.at(4),2,1,Qt::AlignCenter);
    ui->grid->addWidget(ePods.at(5),2,0,Qt::AlignCenter);
    ui->grid->addWidget(ePods.at(6),1,0,Qt::AlignCenter);
    ui->grid->addWidget(ePods.at(7),0,0,Qt::AlignCenter);

//    connect(ePods.at(0),SIGNAL(clicked(bool)),this,SLOT(button0_clicked()));
    //    ui->grid->addWidget(ePods.at(2),0,0,Qt::AlignCenter);

}

podwindow::~podwindow()
{
    delete ui;
}

void podwindow::updatePods(double *podsvalue, int len)
{
    for(int i=0;i<len;i++){
        /*QToolButton *toolbutton = this->pods.at(i);
        //        toolbutton->setText(QString::number(podsvalue[i]));
        //        QPalette palette = toolbutton->palette();
        int valueR = 0;
        if(podsvalue[i]>=200){
            valueR = 0;
        }
        else if(podsvalue[i]<=5){
            valueR = 255;
        }
        else{
            valueR = -1.4*podsvalue[i]+262;
            //            valueR = 1316/podsvalue[i]-6;
            if(valueR>255){
                valueR=255;
            }
            else if(valueR<0){
                valueR = 0;
            }
        }
        QString gb = QString::number(valueR);
        toolbutton->setText(QString::number(podsvalue[i])+" : "+gb);
        toolbutton->setStyleSheet("background-color: rgb(255, "+gb+", "+gb+");");*/


        //            double value = 1.6*podsvalue[i]-1.6;
        double value = 0.0133*podsvalue[i]*podsvalue[i]-0.531*podsvalue[i]+0.518;
        if(value>255){
            value = 255;
        }
        else if(value<0){
            value = 0;
        }

        ePods.at(i)->setLevel((int)value);
        ePods.at(i)->update();


        //        palette.setColor(QPalette::Background,QColor(valueR,0,0));
        //        toolbutton->setPalette(palette);
    }

}

void podwindow::initPods()
{
    for(int i=0;i<8;i++){
        MyoButton* myobutton;
        switch(i){
        case 0:
            myobutton = new MyoButton(0);
            //            myobutton->setL(0,0);
            //            myobutton->setAngle(0);
            break;
        case 1:
            myobutton = new MyoButton(4);
            //            myobutton->setL(20,0);
            //            myobutton->setAngle(45);
            break;
        case 2:
            myobutton = new MyoButton(3);
            //            myobutton->setL(0,-80);
            //            myobutton->setAngle(90);
            break;
        case 3:
            myobutton = new MyoButton(5);
            //            myobutton->setL(-40,-80);
            //            myobutton->setAngle(135);
            break;
        case 4:
            myobutton = new MyoButton(1);
            //            myobutton->setL(0,80);
            //            myobutton->setAngle(0);
            break;
        case 5:
            myobutton = new MyoButton(4);
            //            myobutton->setL(20,0);
            //            myobutton->setAngle(45);
            break;
        case 6:
            myobutton = new MyoButton(2);
            //            myobutton->setL(0,-20);
            //            myobutton->setAngle(90);
            break;
        case 7:
            myobutton = new MyoButton(5);
            //            myobutton->setL(-40,-80);
            //            myobutton->setAngle(135);
            break;
        }


        ePods.append(myobutton);
    }
}

void podwindow::button0_clicked()
{
    ui->widget->hide();
//    QWidget* widget = new QWidget(this);
//    widget->layout()->addWidget(ePods.at(0));
//    this->layout()->addWidget(widget);
}

//void podwindow::initPodsPro()
//{
//    for(int i=0;i<4;i++){
//        int angle;
//        int l1;
//        int l2;

//        switch(i){
//        case 0:
//            angle = 0;
//            l1 = 0;
//            l2 = 0;
//            break;
//        case 1:
//            angle = 45;
//            l1 = 20;
//            l2 = 0;
//            break;
//        case 2:
//            angle = 90;
//            l1 = 0;
//            l2 = -20;
//        case 3:
//            angle = 135;
//            l1 = 0;
//            l2 = 0;
//        }

//        podsPro[i].angle = angle;
//        podsPro[i].l1=l1;
//        podsPro[i].l2=l2;
//        podsPro[i+4].angle = angle;
//        podsPro[i+4].l1=l1;
//        podsPro[i+4].l2=l2;
//    }
//}
