#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "simulation/SimulationManager.h"
#include "../view/model/AquariumView.h"
#include "serivce/AquariumService.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:

    void on_pushButton_clicked();   // Start
    void on_pushButton_2_clicked(); // Stop
    void on_pushButton_3_clicked(); // Restart

    void simulateStep();

private:
    static constexpr int SIMULATION_INTERVAL_MS = 1000;
    Ui::MainWindow *ui;
    QTimer *m_timer;
    SimulationManager m_simulatorManager;
    AquariumView *m_aquariumView;
    AquariumService *m_aquariumService;
    Aquarium m_aquarium;
};

#endif
