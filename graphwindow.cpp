#include "graphwindow.h"
#include "ui_graphwindow.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    QDateTime time(QDateTime::currentDateTime());
    QString timeString = time.toString("yyyy-MM-dd");
    QString title = "Myo Control Graph - "+timeString;
    setWindowTitle(title);

    plots.clear();
    plots.append(ui->customePlot);
    plots.append(ui->customePlot1);
    plots.append(ui->customePlot2);
    plots.append(ui->customePlot3);
    plots.append(ui->customePlot4);
    plots.append(ui->customePlot5);
    plots.append(ui->customePlot6);
    plots.append(ui->customePlot7);

    setupRealtimeData(plots);
}

Form::~Form()
{
    delete ui;
}

void Form::setupRealtimeData(QList<QCustomPlot*> plots)
{
    /*
    customPlot->setNotAntialiasedElements(QCP::aeAll);
    QFont font;
    font.setStyleStrategy(QFont::NoAntialias);
    customPlot->xAxis->setTickLabelFont(font);
    customPlot->yAxis->setTickLabelFont(font);
    customPlot->legend->setFont(font);
    */

    QSharedPointer<QCPAxisTickerDateTime> timeTicker(new QCPAxisTickerDateTime);
    timeTicker->setDateTimeFormat("hh:mm:ss:zzzz");

    for(int i=0;i<8;i++){
        plots.at(i)->addGraph();
        plots.at(i)->graph(0)->setPen(QPen(Qt::blue));
        plots.at(i)->graph(0)->setName("Line"+i);

        plots.at(i)->xAxis->setTicker(timeTicker);
        plots.at(i)->axisRect()->setupFullAxesBox();
        plots.at(i)->yAxis->setRange(-130, 130);

        connect(plots.at(i)->xAxis, SIGNAL(rangeChanged(QCPRange)), plots.at(i)->xAxis2, SLOT(setRange(QCPRange)));
        connect(plots.at(i)->yAxis, SIGNAL(rangeChanged(QCPRange)), plots.at(i)->yAxis2, SLOT(setRange(QCPRange)));
    }

}

void Form::realtimeDataSlot(int a,int b,int c, int d, int e, int f,int g, int h)
{
    //    qDebug()<<emg[0];

    int emg[8]={a,b,c,d,e,f,g,h};

//    static QTime time(QTime::currentTime());
//    double key = time.elapsed()/1000.0;
    double key = QDateTime::currentDateTime().toTime_t();
    static double lastPointKey=0;
    if(key-lastPointKey>0.0){
        for(int i=0;i<8;i++){
            plots.at(i)->graph(0)->addData(key,emg[i]);
            plots.at(i)->xAxis->setRange(key,2,Qt::AlignRight);
        }
        lastPointKey = key;
    }

    if(count == 4){
        for(int i=0;i<8;i++){
            plots.at(0)->replot();
        }
        count = 0;
    }
    else{
        count ++;
    }
}
