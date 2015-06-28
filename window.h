#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include "time.h"
#include <square.h>

namespace Ui {
class Window;
}

class Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = 0);
    void print();
    void printPic(int i, int j, int n);
    void rowchecking(int x, int y);
    void colchecking(int x, int y);
    void taking();
    void reset();

    void text();
    void bot(int i, int j, int n);
    void refresh();

    void click(int i, int j);
    ~Window();

private:
    Ui::Window *ui;

    int candyTable[10][10];
    int markTable[10][10];
    int clickLocation[10][10];
    int score = 0;
    int signal = 0;
    int record[2];
    int tmp = -1;
    bool clicked;
    square *squares[10][10];
    QLabel *block;
    QLabel *tag[2];
    QPushButton *button[10][10];

private slots:
    void mark();
    void act(int row, int col, int n);
    void clicking(int i, int j, int n);
};

#endif // WINDOW_H
