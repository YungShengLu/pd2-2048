#include "QHeaderfile.h"
#include "Headerfile.h"
#include "QHead.h"

QHead::QHead(int version, int target, QWidget *parent) : QWidget(parent) {
    // create the main layout
    mainLayout = new QHBoxLayout();
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(mainLayout);

    // Gametitle
    if (target == 2048) {
        if (version == 0)
            head = "數字版 2048";
        else
            head = "朝代版 2048";
    }
    else {
        if (version == 0)
            head = "數字版 4096";
        else
            head = "朝代版 4096";
    }

    gameTitle = new QLabel(QString::fromStdString(head));
    QFont font("Ubuntu", 50, QFont::Bold);
    gameTitle->setFont(font);
    gameTitle->setStyleSheet("QLabel { color: rgb(48,48,48); }");
    mainLayout->addWidget(gameTitle);
}
