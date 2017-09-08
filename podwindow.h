#ifndef PODWINDOW_H
#define PODWINDOW_H

#include <QWidget>
#include <QToolButton>

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
};

#endif // PODWINDOW_H
