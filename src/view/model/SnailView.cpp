#include "SnailView.h"
#include <QPainter>

SnailView::SnailView(QGraphicsItem *parent)
        : QGraphicsPixmapItem(parent), m_currentStage(0) {
    m_snailPixmap = QPixmap("resources/snail.png");
    setGrowthStage(m_currentStage);
}

void SnailView::setGrowthStage(int stage) {
    if (stage < 0) stage = 0;
    if (stage > 11) stage = 11;

    m_currentStage = stage;

    double scaleMin = 0.05;
    double scaleMax = 0.15;
    double factor = scaleMin + (scaleMax - scaleMin) * (static_cast<double>(stage) / 11.0);

    QPixmap scaled = m_snailPixmap.scaled(
            m_snailPixmap.width() * factor,
            m_snailPixmap.height() * factor,
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation
    );

    setPixmap(scaled);
}
