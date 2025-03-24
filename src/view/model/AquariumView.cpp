#include "AquariumView.h"
#include <memory>
#include "model/Plant.h"
#include "PlantView.h"
#include "model/Snail.h"
#include "SnailView.h"

AquariumView::AquariumView(QWidget *parent)
        : QGraphicsView(parent) {
    m_scene = new QGraphicsScene(this);
    setScene(m_scene);

    QPixmap bgPixmap("resources/background.jpg");
    if (bgPixmap.isNull()) {
        qDebug() << "Loading Background failed!";
    }
    m_scene->setSceneRect(0, 0, 681, 271);
    m_scene->setBackgroundBrush(bgPixmap);
}

void AquariumView::updateView(const Aquarium &aquarium) {
    m_scene->clear();

    for (const auto &organismPtr: aquarium.organisms()) {
//         Sprawdzamy typ za pomocą dynamic_pointer_cast
        if (auto plant = std::dynamic_pointer_cast<Plant>(organismPtr)) {
            auto plantView = new PlantView();
            plantView->setGrowthStage(plant->getCurrentSize());
            plantView->setPos(plant->x(), plant->y());
            plantView->setPos(30, 30);
            m_scene->addItem(plantView);
        } else if (auto snail = std::dynamic_pointer_cast<Snail>(organismPtr)) {
            auto snailView = new SnailView();
            snailView->setGrowthStage(snail->getCurrentSize());
            snailView->setPos(snail->x(), snail->y());
            m_scene->addItem(snailView);
        }
    }
}
