#pragma once

#include <QGraphicsPixmapItem>
#include <QPixmap>

class SnailView : public QGraphicsPixmapItem {
public:
    explicit SnailView(QGraphicsItem *parent = nullptr);

    void setGrowthStage(int stage);

private:
    QPixmap m_snailPixmap;
    int m_currentStage;
};
