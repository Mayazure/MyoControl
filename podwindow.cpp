#include "podwindow.h"
#include "ui_podwindow.h"
#include <QPalette>

podwindow::podwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::podwindow)
{
    ui->setupUi(this);
    pods.append(ui->toolButton);
    pods.append(ui->toolButton_2);
    pods.append(ui->toolButton_3);
    pods.append(ui->toolButton_4);
    pods.append(ui->toolButton_5);
    pods.append(ui->toolButton_6);
    pods.append(ui->toolButton_7);
    pods.append(ui->toolButton_8);

    myobutton = new MyoButton();
    myobutton->setAngle(45);
    myobutton->setLevel(255);
    myobutton->setL(20,0);
    myobutton->update();
    ui->widget->layout()->addWidget(myobutton);

//    for(int i=0;i<8;i++){
//        MyoButton* myobutton = new MyoButton();
//        ePods.append(myobutton);
//    }


}

podwindow::~podwindow()
{
    delete ui;
}

void podwindow::updatePods(double *podsvalue, int len)
{
    for(int i=0;i<len;i++){
        QToolButton *toolbutton = this->pods.at(i);
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
        toolbutton->setStyleSheet("background-color: rgb(255, "+gb+", "+gb+");");

        if(i==0){
            int value = podsvalue[i];
            if(value>255){
                value = 255;
            }
            else if(value<0){
                value = 0;
            }

            myobutton->setLevel(value);
            myobutton->update();
        }

//        palette.setColor(QPalette::Background,QColor(valueR,0,0));
//        toolbutton->setPalette(palette);
    }

}
