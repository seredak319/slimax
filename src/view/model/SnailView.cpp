#include "SnailView.h"
#include <QPainter>

SnailView::SnailView(QGraphicsItem *parent)
        : QGraphicsPixmapItem(parent), m_currentStage(0) {
    // Wczytujemy jeden plik grafiki (np. snail.png) z zasobów .qrc
    m_snailPixmap = QPixmap(":/img/snail/snail.png");

    // Ustawiamy początkowy etap wzrostu
    setGrowthStage(m_currentStage);
}

void SnailView::setGrowthStage(int stage) {
    // Zabezpieczenie przed wyjściem poza zakres
    if (stage < 0) stage = 0;
    if (stage > 11) stage = 11;

    m_currentStage = stage;

    // Przykładowo skala rośnie od 50% (gdy stage=0) do 150% (gdy stage=11)
    double scaleMin = 0.5;
    double scaleMax = 1.5;
    double factor = scaleMin + (scaleMax - scaleMin) * (static_cast<double>(stage) / 11.0);

    // Tworzymy przeskalowany pixmap
    QPixmap scaled = m_snailPixmap.scaled(
            m_snailPixmap.width() * factor,
            m_snailPixmap.height() * factor,
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation
    );

    // Ustawiamy w QGraphicsPixmapItem
    setPixmap(scaled);
}
