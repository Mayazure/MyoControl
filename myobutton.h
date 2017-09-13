#ifndef MYOBUTTON_H
#define MYOBUTTON_H

#include "QPushButton"

class MyoButton : public QPushButton
{
public:
    MyoButton();
    void paintEvent(QPaintEvent* pEvent);
    void setColor(int r, int g, int b);
    void setLevel(int a);
    void setAngle(int angle);
    void setL(int l1, int l2);

private:
    int r = 0;
    int g = 176;
    int b = 240;
    int a = 0;
    int angle = 0;
    int l1 = 0;
    int l2 = 0;
};

#endif // MYOBUTTON_H
