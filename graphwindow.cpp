#include "graphwindow.h"
#include "ui_graphwindow.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}

void Form::setupRealtimeDataDeom(QCustomPlot *customPlot)
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

}

void Form::realtimeDataSlot()
{

}
