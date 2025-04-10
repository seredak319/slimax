#ifndef AQUARIUMVIEW_H
#define AQUARIUMVIEW_H

#include <QGraphicsView>
#include "model/Aquarium.h"
#include "PlantView.h"
#include "SnailView.h"

class AquariumView : public QGraphicsView {
Q_OBJECT

public:
    AquariumView(QWidget *parent = nullptr);

    void updateView(const Aquarium &aquarium, const bool isAnimated);

private:
    QGraphicsScene *m_scene;
    std::vector<PlantView *> m_plantViews;
    std::vector<SnailView *> m_snailViews;

    void animateSnailMovement(SnailView *snailView, const QPointF &startPos, const QPointF &endPos);

    void moveWithoutAnimation(SnailView *snailView, const QPointF &targetPos);

    static const int BASE_ANIMATION_DELAY;
    static const int BASE_ANIMATION_STEPS_NUMBER;
};

#endif
