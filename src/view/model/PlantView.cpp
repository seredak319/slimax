#include "PlantView.h"
#include <QPainter>

PlantView::PlantView(QGraphicsItem *parent)
        : QGraphicsPixmapItem(parent) {
    m_pixmaps.reserve(12);
    m_pixmaps.push_back(QPixmap(":/img/plant/wild_plant_grow_1.png"));
    m_pixmaps.push_back(QPixmap(":/img/plant/wild_plant_grow_2.png"));
    m_pixmaps.push_back(QPixmap(":/img/plant/wild_plant_grow_3.png"));
    m_pixmaps.push_back(QPixmap(":/img/plant/wild_plant_grow_4.png"));
    m_pixmaps.push_back(QPixmap(":/img/plant/wild_plant_grow_5.png"));
    m_pixmaps.push_back(QPixmap(":/img/plant/wild_plant_grow_6.png"));
    m_pixmaps.push_back(QPixmap(":/img/plant/wild_plant_grow_7.png"));
    m_pixmaps.push_back(QPixmap(":/img/plant/wild_plant_grow_8.png"));
    m_pixmaps.push_back(QPixmap(":/img/plant/wild_plant_grow_9.png"));
    m_pixmaps.push_back(QPixmap(":/img/plant/wild_plant_grow_10.png"));
    m_pixmaps.push_back(QPixmap(":/img/plant/wild_plant_grow_11.png"));
    m_pixmaps.push_back(QPixmap(":/img/plant/wild_plant_grow_12.png"));
    setPixmap(m_pixmaps[0]);
}

void PlantView::setGrowthStage(int stage) {
    if (stage < 0) stage = 0;
    if (stage >= m_pixmaps.size()) stage = m_pixmaps.size() - 1;
    setPixmap(m_pixmaps[stage]);
}
