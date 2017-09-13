#ifndef PODWINDOW_H
#define PODWINDOW_H

#include <QWidget>
#include <QToolButton>
#include "myobutton.h"

namespace Ui {
class podwindow;
}

class podwindow : public QWidget
{
    Q_OBJECT

public:
    explicit podwindow(QWidget *parent = 0);
    ~podwindow();

    void updatePods(double* pods, int len);

private:
    Ui::podwindow *ui;
    QList<QToolButton*> pods;
    MyoButton* myobutton;
    QList<MyoButton*> ePods;
};

#endif // PODWINDOW_H
