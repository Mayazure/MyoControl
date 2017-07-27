#include "graphwindow.h"
#include "ui_graphwindow.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    setupRealtimeData(ui->customePlot,ui->customePlot1,ui->customePlot2);
}

Form::~Form()
{
    delete ui;
}

void Form::setupRealtimeData(QCustomPlot *customPlot, QCustomPlot *customPlot1, QCustomPlot *customPlot2)
{
    /*
    customPlot->setNotAntialiasedElements(QCP::aeAll);
    QFont font;
    font.setStyleStrategy(QFont::NoAntialias);
    customPlot->xAxis->setTickLabelFont(font);
    customPlot->yAxis->setTickLabelFont(font);
    customPlot->legend->setFont(font);
    */

    customPlot->addGraph();
    customPlot->graph(0)->setPen(QPen(Qt::blue));
    customPlot->graph(0)->setName("Line0");
    customPlot1->addGraph();
    customPlot1->graph(0)->setPen(QPen(Qt::blue));
    customPlot1->graph(0)->setName("Line1");
    customPlot2->addGraph();
    customPlot2->graph(0)->setPen(QPen(Qt::blue));
    customPlot2->graph(0)->setName("Line2");
//    customPlot->addGraph();
//    customPlot->graph(3)->setPen(QPen(Qt::blue));
//    customPlot->graph(3)->setName("Line3");
//    customPlot->addGraph();
//    customPlot->graph(4)->setPen(QPen(Qt::blue));
//    customPlot->graph(4)->setName("Line4");
//    customPlot->addGraph();
//    customPlot->graph(5)->setPen(QPen(Qt::blue));
//    customPlot->graph(5)->setName("Line5");
//    customPlot->addGraph();
//    customPlot->graph(6)->setPen(QPen(Qt::blue));
//    customPlot->graph(6)->setName("Line6");
//    customPlot->addGraph();
//    customPlot->graph(7)->setPen(QPen(Qt::blue));
//    customPlot->graph(7)->setName("Line7");

    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%h:%m:%s");
    customPlot->xAxis->setTicker(timeTicker);
    customPlot->axisRect()->setupFullAxesBox();
    customPlot->yAxis->setRange(-120, 120);

    customPlot1->xAxis->setTicker(timeTicker);
    customPlot1->axisRect()->setupFullAxesBox();
    customPlot1->yAxis->setRange(-120, 120);

    customPlot2->xAxis->setTicker(timeTicker);
    customPlot2->axisRect()->setupFullAxesBox();
    customPlot2->yAxis->setRange(-120, 120);

    connect(customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->xAxis2, SLOT(setRange(QCPRange)));
    connect(customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->yAxis2, SLOT(setRange(QCPRange)));

    connect(customPlot1->xAxis, SIGNAL(rangeChanged(QCPRange)), customPlot1->xAxis2, SLOT(setRange(QCPRange)));
    connect(customPlot1->yAxis, SIGNAL(rangeChanged(QCPRange)), customPlot1->yAxis2, SLOT(setRange(QCPRange)));

    connect(customPlot2->xAxis, SIGNAL(rangeChanged(QCPRange)), customPlot2->xAxis2, SLOT(setRange(QCPRange)));
    connect(customPlot2->yAxis, SIGNAL(rangeChanged(QCPRange)), customPlot2->yAxis2, SLOT(setRange(QCPRange)));

}

void Form::realtimeDataSlot(int a,int b,int c, int d, int e, int f,int g, int h)
{
//    qDebug()<<emg[0];
    static QTime time(QTime::currentTime());
    double key = time.elapsed()/1000.0;
    static double lastPointKey=0;
    if(key-lastPointKey>0.002){
        ui->customePlot->graph(0)->addData(key,a);
        ui->customePlot1->graph(0)->addData(key,b);
        ui->customePlot2->graph(0)->addData(key,c);
//        ui->customePlot->graph(2)->addData(key,emg[2]);
//        ui->customePlot->graph(3)->addData(key,emg[3]);
//        ui->customePlot->graph(4)->addData(key,emg[4]);
//        ui->customePlot->graph(5)->addData(key,emg[5]);
//        ui->customePlot->graph(6)->addData(key,emg[6]);
//        ui->customePlot->graph(7)->addData(key,emg[7]);
        lastPointKey = key;
    }

    ui->customePlot->xAxis->setRange(key,2,Qt::AlignRight);
    ui->customePlot1->xAxis->setRange(key,2,Qt::AlignRight);
    ui->customePlot2->xAxis->setRange(key,2,Qt::AlignRight);
    if(count == 4){
        ui->customePlot->replot();
        ui->customePlot1->replot();
        ui->customePlot2->replot();
        count = 0;
    }
    else{
        count ++;
    }
}
