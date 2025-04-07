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

    QPixmap bgPixmap("resources/background3.jpg");
    if (bgPixmap.isNull()) {
        qDebug() << "Loading Background failed!";
    }
    m_scene->setSceneRect(0, 0, 650, 250);
    m_scene->setBackgroundBrush(bgPixmap);
}

void AquariumView::updateView(const Aquarium &aquarium) {
    m_scene->clear();
    int aquariumHeight = m_scene->sceneRect().height();

    for (const auto &organismPtr: aquarium.organisms()) {
        int x, y;
        if (auto plant = std::dynamic_pointer_cast<Plant>(organismPtr)) {
            auto plantView = new PlantView();
            plantView->setGrowthStage(plant->getCurrentSize());
            y = aquariumHeight - plantView->pixmap().height();
            plantView->setPos(plant->x(), y);
            m_scene->addItem(plantView);
        } else if (auto snail = std::dynamic_pointer_cast<Snail>(organismPtr)) {
            auto snailView = new SnailView();
            snailView->setGrowthStage(snail->getCurrentSize());

            x = snail->x();
            y = aquariumHeight - snailView->pixmap().height();

            snailView->setPos(x, y);
            m_scene->addItem(snailView);
        }
    }
}
