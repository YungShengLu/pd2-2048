#include "QHeaderfile.h"
#include "Headerfile.h"
#include "QGame.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/img/num2048.ico"));

    srand(time(NULL));
    QGame *game = new QGame();
    game->show();
    game->drawMenu();

    return app.exec();
}
