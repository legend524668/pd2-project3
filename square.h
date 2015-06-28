#ifndef SQUARE_H
#define SQUARE_H

#include <QObject>
#include <QWidget>
#include <QPushButton>

class square : public QWidget
{
    Q_OBJECT
public:
    explicit square(QWidget *parent, int row, int col, int n);
    ~square();

signals:
    void clicking(int row, int col, int n);

public slots:
    void click();

private:
    QPushButton *button;
    int row, col, re;
    bool clicked;
};

#endif // SQUARE_H
