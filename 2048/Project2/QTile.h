#ifndef QTILE_H
#define QTILE_H

#include "QHeaderfile.h"
#include "Headerfile.h"

class Tile;

class QTile : public QLabel {
    Q_OBJECT

public:
    QTile(const QString &text);
    QTile(Tile *tile);

    void drawTile(int version, int dimension);

private:
    Tile *tile;
    qreal scale;

protected:

signals:

public slots:

};

#endif // QTILE_H
