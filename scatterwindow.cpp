#include "scatterwindow.h"
#include "ui_scatterwindow.h"

ScatterWindow::ScatterWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScatterWindow)
{
    ui->setupUi(this);
}

ScatterWindow::~ScatterWindow()
{
    delete ui;
}
