#pragma once

#include <QGraphicsPixmapItem>
#include <QVector>
#include <QPixmap>

class PlantView : public QGraphicsPixmapItem
{
public:
    explicit PlantView(QGraphicsItem* parent = nullptr);

    void setGrowthStage(int stage);

private:
    QVector<QPixmap> m_pixmaps;
};
