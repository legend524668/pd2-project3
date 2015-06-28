#include "square.h"

square::square(QWidget *parent, int Row, int Col, int n) : QWidget(parent)
{
    row = Row;
    col = Col;
    re = n;
    button = new QPushButton(parent);
    button->setGeometry(100 + 52*row, 50 + 52*col, 52, 52);

    if(n == 0)
        button->setIcon(QPixmap(":/fire.png"));
    else if(n == 1)
        button->setIcon(QPixmap(":/blue.png"));
    else if(n == 2)
        button->setIcon(QPixmap(":/green.png"));
    else if(n == 3)
        button->setIcon(QPixmap(":/yellow.png"));
    else if(n == 4)
        button->setIcon(QPixmap(":/alpha.png"));
    else if(n == 5)
        button->setIcon(QPixmap(":/beta.png"));
    else if(n == 6)
        button->setIcon(QPixmap(":/bomb.png"));
    else if(n == 7)
        button->setIcon(QPixmap(":/star.png"));

    button->setIconSize(button->size());
    clicked = false;
    connect(button,SIGNAL(clicked()),this,SLOT(click()));

}

square::~square(){
    delete button;
}

void square::click(){
   emit clicking(row, col, re);
}
