#include "AquariumView.h"
#include <memory>
#include <QCoreApplication>
#include <QThread>
#include "model/Plant.h"
#include "PlantView.h"
#include "model/Snail.h"
#include "SnailView.h"

AquariumView::AquariumView(QWidget *parent)
        : QGraphicsView(parent) {
    m_scene = new QGraphicsScene(this);
    setScene(m_scene);

    QPixmap bgPixmap("resources/background3.jpg");
    if (bgPixmap.isNull()) {
        qDebug() << "Loading Background failed!";
    }
    m_scene->setSceneRect(0, 0, 650, 250);
    m_scene->setBackgroundBrush(bgPixmap);
}

void AquariumView::updateView(const Aquarium &aquarium, const bool isAnimated) {
    int aquariumHeight = m_scene->sceneRect().height();

    int plantIndex = 0;
    int snailIndex = 0;

    for (const auto &organismPtr: aquarium.organisms()) {
        if (auto plant = std::dynamic_pointer_cast<Plant>(organismPtr)) {
            if (plantIndex >= m_plantViews.size()) {
                PlantView *plantView = new PlantView();
                m_scene->addItem(plantView);
                m_plantViews.push_back(plantView);
            }
            PlantView *plantView = m_plantViews[plantIndex];
            plantView->setGrowthStage(plant->getCurrentSize());
            int y = aquariumHeight - plantView->pixmap().height();
            plantView->setPos(plant->x(), y);
            plantIndex++;
        } else if (auto snail = std::dynamic_pointer_cast<Snail>(organismPtr)) {
            if (snailIndex >= m_snailViews.size()) {
                SnailView *snailView = new SnailView();
                m_scene->addItem(snailView);
                m_snailViews.push_back(snailView);
            }
            SnailView *snailView = m_snailViews[snailIndex];
            snailView->setGrowthStage(snail->getCurrentSize());
            int y = aquariumHeight - snailView->pixmap().height();
            int newX = snail->x();

            QPointF currentPos = snailView->pos();
            QPointF targetPos(newX, y);

            if (isAnimated) {
                animateSnailMovement(snailView, currentPos, targetPos);
            } else {
                moveWithoutAnimation(snailView, targetPos);
            }
            snailIndex++;
        }
    }

    while (m_plantViews.size() > static_cast<size_t>(plantIndex)) {
        PlantView *plantView = m_plantViews.back();
        m_scene->removeItem(plantView);
        m_plantViews.pop_back();
    }
    while (m_snailViews.size() > static_cast<size_t>(snailIndex)) {
        SnailView *snailView = m_snailViews.back();
        m_scene->removeItem(snailView);
        m_snailViews.pop_back();
    }
}

void AquariumView::animateSnailMovement(SnailView *snailView, const QPointF &startPos, const QPointF &endPos) {
    const int steps = 10;

    if (endPos.x() < startPos.x()) {
        QTransform transform;
        transform.scale(-1, 1);
        snailView->setTransform(transform);
    } else {
        snailView->setTransform(QTransform());
    }

    qreal dx = (endPos.x() - startPos.x()) / steps;
    qreal dy = (endPos.y() - startPos.y()) / steps;

    for (int i = 1; i <= steps; ++i) {
        QPointF newPos(startPos.x() + i * dx, startPos.y() + i * dy);
        snailView->setPos(newPos);
        m_scene->update();
        QCoreApplication::processEvents();
        QThread::msleep(50);
    }
}

void AquariumView::moveWithoutAnimation(SnailView *snailView, const QPointF &targetPos) {
    snailView->setPos(targetPos);
    m_scene->update();
}
