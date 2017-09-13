#include "podwindow.h"
#include "ui_podwindow.h"
#include <QPalette>

podwindow::podwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::podwindow)
{
    ui->setupUi(this);

    initPods();
    ui->gridLayout->addWidget(ePods.at(0),0,1,Qt::AlignCenter);
    ui->gridLayout->addWidget(ePods.at(1),0,2,Qt::AlignCenter);
    ui->gridLayout->addWidget(ePods.at(2),1,2,Qt::AlignCenter);
    ui->gridLayout->addWidget(ePods.at(3),2,2,Qt::AlignCenter);
    ui->gridLayout->addWidget(ePods.at(4),2,1,Qt::AlignCenter);
    ui->gridLayout->addWidget(ePods.at(5),2,0,Qt::AlignCenter);
    ui->gridLayout->addWidget(ePods.at(6),1,0,Qt::AlignCenter);
    ui->gridLayout->addWidget(ePods.at(7),0,0,Qt::AlignCenter);

    //    connect(ePods.at(0),SIGNAL(clicked(bool)),this,SLOT(button0_clicked()));
}

podwindow::~podwindow()
{
    delete ui;
}

void podwindow::updatePods(double *podsvalue, int len)
{
    for(int i=0;i<len;i++){
        double value = 0.0133*podsvalue[i]*podsvalue[i]-0.531*podsvalue[i]+0.518;
        if(value>255){
            value = 255;
        }
        else if(value<0){
            value = 0;
        }

        ePods.at(i)->setLevel((int)value);
        ePods.at(i)->update();
    }
}

void podwindow::initPods()
{
    for(int i=0;i<8;i++){
        int type = 0;
        switch(i){
        case 0:
            type = 0;
            break;
        case 1:
            type = 4;
            break;
        case 2:
            type = 3;
            break;
        case 3:
            type = 5;
            break;
        case 4:
            type = 1;
            break;
        case 5:
            type = 4;
            break;
        case 6:
            type = 2;
            break;
        case 7:
            type = 5;
            break;
        }

        MyoButton* myobutton = new MyoButton(type);
        ePods.append(myobutton);
    }
}

void podwindow::button0_clicked()
{
//    ui->widget->hide();
}
