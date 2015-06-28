#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>
class Button : public QPushButton
{
    Q_OBJECT
public:
    Button();

public slots:
    void clicking();

private:
    bool clicked;
};

#endif // BUTTON_H
