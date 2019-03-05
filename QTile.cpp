#include "QHeaderfile.h"
#include "Headerfile.h"
#include "QTile.h"
#include "Tile.h"

QTile::QTile(Tile *tile) {
    setAlignment(Qt::AlignCenter);
    this->tile = tile;
}

void QTile::drawTile(int version, int dimension) {
    if (tile == NULL) {
        setText("");
        setStyleSheet("QTile { background: rgb(204,192,179); border-radius: 10px; }");
    }
    else {
        if (version)
            setText(QString::fromStdString(tile->getWord(tile->getNumber())));
        else
            setText(QString::number(tile->getNumber()));

        switch (dimension) {
        case 3: {
            QFont font1("Ubuntu", 60);
            setFont(font1);
            break;
        }
        case 4: {
            QFont font2("Ubuntu", 55);
            setFont(font2);
            break;
        }
        case 5: {
            QFont font3("Ubuntu", 45);
            setFont(font3);
            break;
        }
        case 6: {
            QFont font4("Ubuntu", 40);
            setFont(font4);
            break;
        }
        case 7: {
            QFont font5("Ubuntu", 30);
            setFont(font5);
            break;
        }
        case 8: {
            QFont font6("Ubuntu", 25);
            setFont(font6);
            break;
        }
        }

        switch (tile->getNumber()) {
        case 2:
            setStyleSheet("QTile { background: rgb(238,228,218); color: rgb(119,110,101); border-radius: 10px; }");
            break;
        case 4:
            setStyleSheet("QTile { background: rgb(237,224,200); color: rgb(119,110,101); border-radius: 10px; }");
            break;
        case 8:
            setStyleSheet("QTile { background: rgb(242,177,121); color: rgb(255,255,255); border-radius: 10px; }");
            break;
        case 16:
            setStyleSheet("QTile { background: rgb(245,150,100); color: rgb(255,255,255); border-radius: 10px; }");
            break;
        case 32:
            setStyleSheet("QTile { background: rgb(245,125,95); color: rgb(255,255,255); border-radius: 10px; }");
            break;
        case 64:
            setStyleSheet("QTile { background: rgb(245,95,60); color: rgb(255,255,255); border-radius: 10px; }");
            break;
        case 128:
            setStyleSheet("QTile { background: rgb(237,207,114); color: rgb(255,255,255); border-radius: 10px; }");
            break;
        case 256:
            setStyleSheet("QTile { background: rgb(237,99,97); color: rgb(255,255,255); border-radius: 10px; }");
            break;
        case 512:
            setStyleSheet("QTile { background: rgb(237,97,130); color: rgb(255,255,255); border-radius: 10px; }");
            break;
        case 1024:
            setStyleSheet("QTile { background: rgb(204,97,237); color: rgb(255,255,255); border-radius: 10px; }");
            break;
        case 2048:
            setStyleSheet("QTile { background: rgb(134,97,237); color: rgb(255,255,255); border-radius: 10px; }");
            break;
        case 4096:
            setStyleSheet("QTile { background: rgb(99,97,237); color: rgb(255,255,255); border-radius: 10px; }");
            break;
        default:
            setStyleSheet("QTile { background: rgb(238,228,218); color: rgb(119,110,101); border-radius: 10px; }");
            break;
        }
    }
}
