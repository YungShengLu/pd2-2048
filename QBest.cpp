#include "QBest.h"

QBest::QBest(QWidget *parent) : QWidget(parent) {
    mainLayout = new QVBoxLayout;
    setLayout(mainLayout);

    title = new QLabel(QString("        BEST        "));
    title->setAlignment(Qt::AlignCenter);
    QFont font1("Ubuntu", 16, QFont::Bold);
    title->setFont(font1);

    ifstream fin("best", ios::in);
    getline(fin, line);
    curr = (int)line.at(0);

    count = new QLabel(QString("%1").fromStdString(line));
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

QString QBest::getBest() {
    return count->text();
}

void QBest::setBest(QString record) {
    int curr = record.toInt();
    ofstream fout("best", ios::out);
    fout << curr;

    count->setText(record);
}
