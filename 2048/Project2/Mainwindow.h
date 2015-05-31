#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "QHeaderfile.h"
#include "QGame.h"

class QBoard;

namespace Ui {
    class MainWindow;
}
class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QGame *game;
};

#endif // MAINWINDOW_H
