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
    void setupRealtimeDataDeom(QCustomPlot *customPlot);

private slots:
    void realtimeDataSlot();

private:
    Ui::Form *ui;
};

#endif // GRAPHWINDOW_H
