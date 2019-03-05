#include "QHeaderfile.h"
#include "QHint.h"

QHint::QHint(int target, QWidget *parent) : QWidget(parent) {
    // create the main layout
    mainLayout = new QHBoxLayout();
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(mainLayout);

    // Hint
    if (target == 2048)
        hint = new QLabel("Join the numbers and get to the 2048 tile!    ");
    else
        hint = new QLabel("Join the numbers and get to the 4096 tile!    ");

    QFont font1("Ubuntu", 18, QFont::Bold);
    hint->setFont(font1);
    hint->setStyleSheet("QLabel { color: rgb(119,110,101); border-radius: 5px; }");

    mainLayout->addWidget(hint);
}
