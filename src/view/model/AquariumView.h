#ifndef AQUARIUMVIEW_H
#define AQUARIUMVIEW_H

#include <QGraphicsView>
#include "model/Aquarium.h"

class AquariumView : public QGraphicsView {
Q_OBJECT

public:
    AquariumView(QWidget *parent = nullptr);

    void updateView(const Aquarium &aquarium);

private:
    QGraphicsScene *m_scene;
};

#endif // AQUARIUMVIEW_H
