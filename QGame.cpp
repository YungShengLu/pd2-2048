#include "QHeaderfile.h"
#include "QButton.h"
#include "QBoard.h"
#include "QGame.h"

QGame::QGame(QWidget *parent) : QGraphicsView(parent) {   
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800, 950);

    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 750, 900);
    setScene(scene);
    setStyleSheet("QGame { background: rgb(187,173,160); }");
}

void QGame::drawMenu() {   
    QGraphicsTextItem *title = new QGraphicsTextItem(QString("2048"));
    QFont font1("Ubuntu", 100, QFont::Bold);
    title->setFont(font1);
    int pos_x = this->width()/2 - title->boundingRect().width()/2;
    int pos_y = 50;
    title->setPos(pos_x, pos_y);
    scene->addItem(title);

    QGraphicsTextItem *hint1 = new QGraphicsTextItem(QString("HOW TO PLAY:"));
    QFont font2("Ubuntu", 22, QFont::Bold);
    hint1->setFont(font2);
    pos_x = 150;
    pos_y = 250;
    hint1->setPos(pos_x, pos_y);
    scene->addItem(hint1);

    QGraphicsTextItem *hint2 = new QGraphicsTextItem(QString("- Use your arrow keys to move the tiles."));
    QFont font3("Ubuntu", 18, QFont::Bold);
    hint2->setFont(font3);
    pos_x = 150;
    pos_y = 300;
    hint2->setPos(pos_x, pos_y);
    scene->addItem(hint2);

    QGraphicsTextItem *hint3 = new QGraphicsTextItem(QString("- When two tiles with the same number touch,\n   they merge into one!"));
    hint3->setFont(font3);
    pos_x = 150;
    pos_y = 350;
    hint3->setPos(pos_x, pos_y);
    scene->addItem(hint3);

    QButton *play = new QButton(QString("Start !"));
    int btn1_x = this->width()/2 - play->boundingRect().width()/2;
    int btn1_y = 475;
    play->setPos(btn1_x, btn1_y);
    connect(play, SIGNAL(clicked()), this, SLOT(start()));
    scene->addItem(play);

    QButton *quit = new QButton(QString("Quit !"));
    int btn2_x = this->width()/2 - quit->boundingRect().width()/2;
    int btn2_y = 550;
    quit->setPos(btn2_x, btn2_y);
    connect(quit, SIGNAL(clicked()), this, SLOT(close()));
    scene->addItem(quit);
}

void QGame::drawOption() {
    QGraphicsTextItem *title = new QGraphicsTextItem(QString("Option"));
    QFont font1("Ubuntu", 100, QFont::Bold);
    title->setFont(font1);
    int pos_x = this->width()/2 - title->boundingRect().width()/2;
    int pos_y = 50;
    title->setPos(pos_x, pos_y);
    scene->addItem(title);

    QGraphicsTextItem *option1 = new QGraphicsTextItem(QString("Version: "));
    QFont font2("Ubuntu", 20, QFont::Bold);
    option1->setFont(font2);
    pos_x = 225;
    pos_y = 300;
    option1->setPos(pos_x, pos_y);
    scene->addItem(option1);

    combobox1 = new QComboBox();
    QFont font3("Ubuntu", 16, QFont::Bold);
    combobox1->setFont(font3);
    combobox1->setGeometry(390, 300, 200, 40);
    combobox1->setEditable(false);
    combobox1->insertItem(0, "數 字 版");
    combobox1->insertItem(1, "朝 代 版");
    scene->addWidget(combobox1);

    QGraphicsTextItem *option3 = new QGraphicsTextItem(QString("Target: "));
    option3->setFont(font2);
    pos_x = 225;
    pos_y = 500;
    option3->setPos(pos_x, pos_y);
    scene->addItem(option3);

    combobox3 = new QComboBox();
    combobox3->setFont(font3);
    combobox3->setGeometry(390, 500, 200, 40);
    combobox3->setEditable(false);
    combobox3->insertItem(0, "2048");
    combobox3->insertItem(1, "4096");
    scene->addWidget(combobox3);

    QGraphicsTextItem *option2 = new QGraphicsTextItem(QString("Dimension: "));
    option2->setFont(font2);
    pos_x = 225;
    pos_y = 400;
    option2->setPos(pos_x, pos_y);
    scene->addItem(option2);

    combobox2 = new QComboBox();
    combobox2->setFont(font3);
    combobox2->setGeometry(390, 400, 200, 40);
    combobox2->setEditable(false);
    combobox2->insertItem(0, "3");
    combobox2->insertItem(1, "4");
    combobox2->insertItem(2, "5");
    combobox2->insertItem(3, "6");
    combobox2->insertItem(4, "7");
    combobox2->insertItem(5, "8");
    scene->addWidget(combobox2);

    QButton *play = new QButton(QString("Play !"));
    int btn1_x = this->width()/2 - play->boundingRect().width()/2;
    int btn1_y = 600;
    play->setPos(btn1_x, btn1_y);
    connect(play, SIGNAL(clicked()), this, SLOT(play()));
    scene->addItem(play);

    connect(combobox1, SIGNAL(activated(int)), this, SLOT(changeVersion(int)));
    connect(combobox2, SIGNAL(activated(int)), this, SLOT(changeDimension(int)));
    connect(combobox3, SIGNAL(activated(int)), this, SLOT(changeTarget(int)));
}

void QGame::drawGameOver() {
    QGraphicsTextItem *title = new QGraphicsTextItem(QString("Game over!"));
    QFont font1("Ubuntu", 100, QFont::Bold);
    title->setFont(font1);
    title->setPos(400, 350);
    scene->addItem(title);

    score = new QScore();
    score->setGeometry(400, 400, 100, 150);
    scene->addWidget(score);

    best = new QBest();
    best->setGeometry(600, 400, 100, 150);
    scene->addWidget(best);

    QButton *again = new QButton(QString("Try again !"));
    int btn1_x = this->width()/2 - again->boundingRect().width()/2;
    int btn1_y = 475;
    again->setPos(btn1_x, btn1_y);
    connect(again, SIGNAL(clicked()), this, SLOT(restart()));
    scene->addItem(again);

    QButton *quit = new QButton(QString("Quit !"));
    int btn2_x = this->width()/2 - quit->boundingRect().width()/2;
    int btn2_y = 550;
    quit->setPos(btn2_x, btn2_y);
    connect(quit, SIGNAL(clicked()), this, SLOT(close()));
    scene->addItem(quit);
}

void QGame::start() {
    scene->clear();
    drawOption();
}

void QGame::play() {
    scene->clear();

    if (version > 1 || version < 0)
        version = 0;

    if (dimension == 0 || dimension > 8)
        dimension = 3;

    if (target > 4096 || target < 4096)
        target = 2048;

    board = new QBoard(version, dimension, target);
    scene->addWidget(board);
}

void QGame::changeVersion(int v) {
    version = v;
}

void QGame::changeDimension(int d) {
    dimension = d + 3;
}

void QGame::changeTarget(int t) {
    target = (t + 1) * 2048;
}

void QGame::restart() {
    scene->clear();
    start();
}
