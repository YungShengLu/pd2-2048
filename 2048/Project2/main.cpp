#include "QHeaderfile.h"
#include "Headerfile.h"
#include "QGame.h"
#include "Mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/images/num2048.ico"));

    srand(time(NULL));
    QGame *game = new QGame();
    game->show();
    game->drawMenu();

    return a.exec();
}
