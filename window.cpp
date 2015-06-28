#include "window.h"
#include "ui_window.h"


Window::Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);
    srand(time(NULL));
    record[0] = -1; record[1] = -1;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            candyTable[i][j] = rand()%4;
            markTable[i][j] = 0;
            clickLocation[i][j] = 0;
        }
    }
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
           squares[i][j] = new square(this, i, j, candyTable[i][j]);
           connect(squares[i][j], SIGNAL(clicking(int, int, int)), this, SLOT(act(int,int,int)));
        }
    }
    text();
    //print();
    printf("\n");
    /*for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
            bot(j, i, candyTable[i][j]);*/

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            rowchecking(i, j);
            colchecking(i, j);
        }
    }
    for(int i = 0; i < 10; i++){
       for(int j = 0; j < 10; j++){
           printf("%d ", markTable[i][j]);
       }
       printf("\n");
    }
    taking();

    text();

    reset();
    text();
}

Window::~Window()
{
    delete ui;
}

void Window::print(){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            printPic(i, j, candyTable[i][j]);
        }
    }
}

void Window::printPic(int i, int j, int n){
    block = new QLabel(this);
    block->setGeometry(100 + 52*i, 50 + 52*j, 52, 52);
    block->setVisible(true);

    if(n == 0)
        block->setPixmap(QPixmap(":/fire.png"));  
    else if(n == 1)
        block->setPixmap(QPixmap(":/blue.png"));
    else if(n == 2)
        block->setPixmap(QPixmap(":/green.png"));
    else if(n == 3)
        block->setPixmap(QPixmap(":/yellow.png"));
    else if(n == 4)
        block->setPixmap(QPixmap(":/alpha.png"));
    else if(n == 5)
        block->setPixmap(QPixmap(":/beta.png"));
    else if(n == 6)
        block->setPixmap(QPixmap(":/bomb.png"));
    else if(n == 7)
        block->setPixmap(QPixmap(":/star.png"));
}

void Window::rowchecking(int x, int y){
    int n = 1;
    for(int i = x; candyTable[i + 1][y] == candyTable[x][y] && x < 10; i++)
        n++;
    for(int i = x; candyTable[i - 1][y] == candyTable[x][y] && x >= 0; i--)
        n++;
    if(n > 2){
        markTable[x][y] = 1;
        for(int i = x; candyTable[i + 1][y] == candyTable[x][y] && x < 10; i++)
            markTable[i + 1][y] = 1;
        for(int i = x; candyTable[i - 1][y] == candyTable[x][y] && x >= 0; i--)
            markTable[i - 1][y] = 1;
    }
}

void Window::colchecking(int x, int y){
    int n = 1;
    for(int i = y; candyTable[x][i + 1] == candyTable[x][y] && i < 10; i++)
        n++;
    for(int i = y; candyTable[x][i - 1] == candyTable[x][y] && i >= 0; i--)
        n++;
    if(n > 2){
        markTable[x][y] = 1;
        for(int i = y; candyTable[x][i + 1] == candyTable[x][y] && x < 10; i++)
            markTable[x][i + 1] = 1;
        for(int i = y; candyTable[x][i - 1] == candyTable[x][y] && x >= 0; i--)
            markTable[x][i - 1] = 1;
    }
}

void Window::taking(){
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++){
            if(markTable[i][j] == 1)
                candyTable[i][j] = -1;
        }
}

void Window::reset(){
    int tmp[10];

    for(int i = 0; i < 10; i++){
        int n = 0;
        for(int j = 0; j < 10; j++)
            tmp[j] = -1;
        for(int j = 9; j >= 0; j--){
            if(candyTable[i][j] != -1){
                tmp[n] = candyTable[i][j];
                n++;
            }
        }
        for(int j = 9, n = 0; j >= 0; j--, n++){
            candyTable[i][j] = tmp[n];
            if(tmp[n] == -1)
                candyTable[i][j] = rand() % 4;
        }
    }
}

void Window::text(){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++)
            printf("%2d ", candyTable[i][j]);
        printf("\n");
    }
    printf("\n");
}

void Window::bot(int i, int j, int n){
    button[i][j] = new QPushButton(this);
    button[i][j]->setGeometry(100 + 52*i, 50 + 52*j, 52, 52);

    button[i][j]->setIconSize(button[i][j]->size());
    if(n == 0)
        button[i][j]->setIcon(QPixmap(":/fire.png"));
    else if(n == 1)
        button[i][j]->setIcon(QPixmap(":/blue.png"));
    else if(n == 2)
        button[i][j]->setIcon(QPixmap(":/green.png"));
    else if(n == 3)
        button[i][j]->setIcon(QPixmap(":/yellow.png"));
    else if(n == 4)
        button[i][j]->setIcon(QPixmap("/alpha.png"));
    else if(n == 5)
        button[i][j]->setIcon(QPixmap("/beta.png"));
    else if(n == 6)
        button[i][j]->setIcon(QPixmap("/bomb.png"));
    else if(n == 7)
        button[i][j]->setIcon(QPixmap("/star.png"));

    clicked = false;
    //if(clicked == true){
        connect(button[i][j], SIGNAL(clicked()), this, SLOT(mark()));
        printf("clicked");
    //}
    button[i][j]->show();
    if(clickLocation[9][9] == 2)
        printf("done");
}

void Window::mark(){
    //if(clicked == true)
             //text();
}

void Window::clicking(int i, int j, int n){
    //printf("%d, %d, %d \n", i, j, n);
}

void Window::refresh(){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
           squares[i][j] = new square(this, i, j, candyTable[i][j]);
           connect(squares[i][j], SIGNAL(clicking(int, int, int)), this, SLOT(act(int,int,int)));
        }
    }
}

void Window::act(int row, int col, int n){
    printf("%d, %d, %d \n", row, col, n);
    if(signal == 0){
        tag[signal] = new QLabel(this);
        tag[signal]->setGeometry(100 + 52*row, 50 + 52*col, 52, 52);
        tag[signal]->setPixmap(QPixmap(":/border.png"));
        tag[signal]->setVisible(true);
        signal++;
        record[0] = row;
        record[1] = col;
        printf("sig = %d \n", signal);
    }
    else if(signal == 1){
        int tmp = -1;
        printf("%d, %d\n", candyTable[row][col], candyTable[record[0]][record[1]]);
        tmp = candyTable[row][col];
        candyTable[row][col] = candyTable[record[0]][record[1]];
        candyTable[record[0]][record[1]] = tmp;
        printf("%d, %d\n", candyTable[row][col], candyTable[record[0]][record[1]]);
        signal--;
        refresh();printf("refresh sig = %d\n", signal);
    }
}



