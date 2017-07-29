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
    void setupRealtimeData(QList<QCustomPlot*> plots);

public slots:
    void realtimeDataSlot(int a,int b,int c, int d, int e, int f,int g, int h);

private:
    Ui::Form *ui;
    int count = 0;
    QList<QCustomPlot*> plots;
};

#endif // GRAPHWINDOW_H
