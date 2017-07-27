#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H

#include <QWidget>
#include "qcustomplot.h"

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();
    void setupRealtimeData(QCustomPlot *customPlot,
                           QCustomPlot *customPlot1,
                           QCustomPlot *customPlot2,
                           QCustomPlot *customPlot3,
                           QCustomPlot *customPlot4,
                           QCustomPlot *customPlot5,
                           QCustomPlot *customPlot6,
                           QCustomPlot *customPlot7);

public slots:
    void realtimeDataSlot(int a,int b,int c, int d, int e, int f,int g, int h);

private:
    Ui::Form *ui;
    int count = 0;
};

#endif // GRAPHWINDOW_H
