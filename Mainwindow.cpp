#include "Mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    QPixmap *pixmap = new QPixmap(":/img/num2048.png");
    QIcon *icon = new QIcon(*pixmap);
    setWindowIcon(*icon);
    setIconSize(QSize(pixmap->width(), pixmap->height()));

    game = new QGame();

    setCentralWidget(game);
    setWindowTitle("2048");
}

MainWindow::~MainWindow() {

}
