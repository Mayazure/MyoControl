#include "graphwindow.h"
#include "ui_graphwindow.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    setupRealtimeData(ui->customePlot,
                      ui->customePlot1,
                      ui->customePlot2,
                      ui->customePlot3,
                      ui->customePlot4,
                      ui->customePlot5,
                      ui->customePlot6,
                      ui->customePlot7);
}

Form::~Form()
{
    delete ui;
}

void Form::setupRealtimeData(QCustomPlot *customPlot,
                             QCustomPlot *customPlot1,
                             QCustomPlot *customPlot2,
                             QCustomPlot *customPlot3,
                             QCustomPlot *customPlot4,
                             QCustomPlot *customPlot5,
                             QCustomPlot *customPlot6,
                             QCustomPlot *customPlot7)
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

    customPlot3->addGraph();
    customPlot3->graph(0)->setPen(QPen(Qt::blue));
    customPlot3->graph(0)->setName("Line3");

    customPlot4->addGraph();
    customPlot4->graph(0)->setPen(QPen(Qt::blue));
    customPlot4->graph(0)->setName("Line4");

    customPlot5->addGraph();
    customPlot5->graph(0)->setPen(QPen(Qt::blue));
    customPlot5->graph(0)->setName("Line5");

    customPlot6->addGraph();
    customPlot6->graph(0)->setPen(QPen(Qt::blue));
    customPlot6->graph(0)->setName("Line6");

    customPlot7->addGraph();
    customPlot7->graph(0)->setPen(QPen(Qt::blue));
    customPlot7->graph(0)->setName("Line7");

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

    customPlot3->xAxis->setTicker(timeTicker);
    customPlot3->axisRect()->setupFullAxesBox();
    customPlot3->yAxis->setRange(-120, 120);

    customPlot4->xAxis->setTicker(timeTicker);
    customPlot4->axisRect()->setupFullAxesBox();
    customPlot4->yAxis->setRange(-120, 120);

    customPlot5->xAxis->setTicker(timeTicker);
    customPlot5->axisRect()->setupFullAxesBox();
    customPlot5->yAxis->setRange(-120, 120);

    customPlot6->xAxis->setTicker(timeTicker);
    customPlot6->axisRect()->setupFullAxesBox();
    customPlot6->yAxis->setRange(-120, 120);

    customPlot7->xAxis->setTicker(timeTicker);
    customPlot7->axisRect()->setupFullAxesBox();
    customPlot7->yAxis->setRange(-120, 120);

    connect(customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->xAxis2, SLOT(setRange(QCPRange)));
    connect(customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->yAxis2, SLOT(setRange(QCPRange)));

    connect(customPlot1->xAxis, SIGNAL(rangeChanged(QCPRange)), customPlot1->xAxis2, SLOT(setRange(QCPRange)));
    connect(customPlot1->yAxis, SIGNAL(rangeChanged(QCPRange)), customPlot1->yAxis2, SLOT(setRange(QCPRange)));

    connect(customPlot2->xAxis, SIGNAL(rangeChanged(QCPRange)), customPlot2->xAxis2, SLOT(setRange(QCPRange)));
    connect(customPlot2->yAxis, SIGNAL(rangeChanged(QCPRange)), customPlot2->yAxis2, SLOT(setRange(QCPRange)));

    connect(customPlot3->xAxis, SIGNAL(rangeChanged(QCPRange)), customPlot3->xAxis2, SLOT(setRange(QCPRange)));
    connect(customPlot3->yAxis, SIGNAL(rangeChanged(QCPRange)), customPlot3->yAxis2, SLOT(setRange(QCPRange)));

    connect(customPlot4->xAxis, SIGNAL(rangeChanged(QCPRange)), customPlot4->xAxis2, SLOT(setRange(QCPRange)));
    connect(customPlot4->yAxis, SIGNAL(rangeChanged(QCPRange)), customPlot4->yAxis2, SLOT(setRange(QCPRange)));

    connect(customPlot5->xAxis, SIGNAL(rangeChanged(QCPRange)), customPlot5->xAxis2, SLOT(setRange(QCPRange)));
    connect(customPlot5->yAxis, SIGNAL(rangeChanged(QCPRange)), customPlot5->yAxis2, SLOT(setRange(QCPRange)));

    connect(customPlot6->xAxis, SIGNAL(rangeChanged(QCPRange)), customPlot6->xAxis2, SLOT(setRange(QCPRange)));
    connect(customPlot6->yAxis, SIGNAL(rangeChanged(QCPRange)), customPlot6->yAxis2, SLOT(setRange(QCPRange)));

    connect(customPlot7->xAxis, SIGNAL(rangeChanged(QCPRange)), customPlot7->xAxis2, SLOT(setRange(QCPRange)));
    connect(customPlot7->yAxis, SIGNAL(rangeChanged(QCPRange)), customPlot7->yAxis2, SLOT(setRange(QCPRange)));

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
        ui->customePlot3->graph(0)->addData(key,d);
        ui->customePlot4->graph(0)->addData(key,e);
        ui->customePlot5->graph(0)->addData(key,f);
        ui->customePlot6->graph(0)->addData(key,g);
        ui->customePlot7->graph(0)->addData(key,h);

        lastPointKey = key;
    }

    ui->customePlot->xAxis->setRange(key,2,Qt::AlignRight);
    ui->customePlot1->xAxis->setRange(key,2,Qt::AlignRight);
    ui->customePlot2->xAxis->setRange(key,2,Qt::AlignRight);
    ui->customePlot3->xAxis->setRange(key,2,Qt::AlignRight);
    ui->customePlot4->xAxis->setRange(key,2,Qt::AlignRight);
    ui->customePlot5->xAxis->setRange(key,2,Qt::AlignRight);
    ui->customePlot6->xAxis->setRange(key,2,Qt::AlignRight);
    ui->customePlot7->xAxis->setRange(key,2,Qt::AlignRight);

    if(count == 4){
        ui->customePlot->replot();
        ui->customePlot1->replot();
        ui->customePlot2->replot();
        ui->customePlot3->replot();
        ui->customePlot4->replot();
        ui->customePlot5->replot();
        ui->customePlot6->replot();
        ui->customePlot7->replot();
        count = 0;
    }
    else{
        count ++;
    }
}
