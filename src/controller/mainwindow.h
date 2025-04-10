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

/**
 * @class MainWindow
 * @brief Główne okno aplikacji.
 *
 * Klasa MainWindow zarządza interfejsem użytkownika, inicjalizuje symulację
 * akwarium oraz obsługuje zdarzenia związane z rozpoczęciem, zatrzymaniem i
 * restartem symulacji.
 */
class MainWindow : public QMainWindow {
Q_OBJECT

public:
    /**
     * @brief Konstruktor okna głównego.
     * @param parent Wskaźnik na rodzica (opcjonalny).
     */
    MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Destruktor.
     */
    ~MainWindow();

private slots:
    /**
     * @brief Obsługuje zdarzenie przycisku "Start".
     */
    void on_pushButton_clicked();

    /**
     * @brief Obsługuje zdarzenie przycisku "Stop".
     */
    void on_pushButton_2_clicked();

    /**
     * @brief Obsługuje zdarzenie przycisku "Restart".
     */
    void on_pushButton_3_clicked();

    /**
     * @brief Wykonuje pojedynczy krok symulacji.
     */
    void simulateStep();

private:
    static constexpr int SIMULATION_INTERVAL_MS = 1000; ///< Interwał symulacji w ms.
    Ui::MainWindow *ui;                  ///< Interfejs użytkownika.
    QTimer *m_timer;                     ///< Timer symulacji.
    SimulationManager m_simulatorManager;///< Menadżer symulacji.
    AquariumView *m_aquariumView;        ///< Widok akwarium.
    AquariumService *m_aquariumService;  ///< Usługa do inicjalizacji akwarium.
    Aquarium m_aquarium;                 ///< Model akwarium.
};

#endif
