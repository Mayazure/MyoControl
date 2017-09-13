#ifndef SCATTERWINDOW_H
#define SCATTERWINDOW_H

#include <QWidget>
#include <QtDataVisualization/q3dscatter.h>
//#include <QtDataVisualization/qabstract3dseries.h>

namespace Ui {
class ScatterWindow;
}

class ScatterWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ScatterWindow(QWidget *parent = 0);
    ~ScatterWindow();

private:
    Ui::ScatterWindow *ui;
    Q3DScatter *graph;
};

#endif // SCATTERWINDOW_H
