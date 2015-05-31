#include "QScore.h"

QScore::QScore(QWidget *parent) : QWidget(parent) {
    mainLayout = new QVBoxLayout;
    setLayout(mainLayout);

    title = new QLabel(QString("      SCORE      "));
    title->setAlignment(Qt::AlignCenter);
    QFont font1("Ubuntu", 16, QFont::Bold);
    title->setFont(font1);

    count = new QLabel("0");
    count->setAlignment(Qt::AlignCenter);
    QFont font2("Ubuntu", 24, QFont::Bold);
    count->setFont(font2);

    title->setStyleSheet("QLabel { background: rgb(139,115,85); color: rgb(255,255,255); }");
    count->setStyleSheet("QLabel { background: rgb(139,115,85); color: rgb(255,255,255); }");

    setStyleSheet("QBest { border-radius: 10px; }");
    mainLayout->addWidget(title);
    mainLayout->addWidget(count);
    mainLayout->setSpacing(0);
}

QString QScore::getScore() {
    return count->text();
}

void QScore::setScore(QString record) {
    count->setText(record);
}
