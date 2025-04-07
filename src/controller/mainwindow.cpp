#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "simulation/input/SimulationContext.h"
#include <QTimer>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow), m_timer(new QTimer(this)),
          m_aquariumService(new AquariumService()),
          m_aquarium(0) {
    ui->setupUi(this),
            connect(m_timer, &QTimer::timeout, this, &MainWindow::simulateStep);

    auto layout = new QVBoxLayout(ui->simulationFrame);
    ui->simulationFrame->setLayout(layout);
    m_aquariumView = new AquariumView(ui->simulationFrame);
    layout->addWidget(m_aquariumView);

    ui->progressBar->setMinimum(0);
    ui->progressBar->setValue(0);

    ui->horizontalSlider_8->setEnabled(ui->checkBox->isChecked());
    connect(ui->checkBox, &QCheckBox::toggled, ui->horizontalSlider_8, &QWidget::setEnabled);
}

MainWindow::~MainWindow() {
    delete ui;
}

// START
void MainWindow::on_pushButton_clicked() {
    std::cout << "=== START SIMULATION ===" << std::endl;
    std::cout << "Liczba slimakow: " << ui->spinBox->value() << std::endl;
    std::cout << "Wiek slimakow: " << ui->spinBox_2->value() << std::endl;
    std::cout << "Zarlocznosc: " << ui->horizontalSlider->value() << std::endl;
    std::cout << "Tepo wzrostu (slimaki): " << ui->horizontalSlider_3->value() << std::endl;
    std::cout << "Liczba roslin: " << ui->spinBox_3->value() << std::endl;
    std::cout << "Objetosc roslin: " << ui->spinBox_4->value() << std::endl;
    std::cout << "Tepo wzrostu (roslin): " << ui->horizontalSlider_4->value() << std::endl;
    std::cout << "Liczba iteracji (dni): " << ui->spinBox_6->value() << std::endl;
    std::cout << "Wsp. zarlocznosci od wieku: " << ui->horizontalSlider_6->value() << std::endl;
    std::cout << "Wsp. wzrostu od objetosci: " << ui->horizontalSlider_7->value() << std::endl;
    std::cout << "Tepo symulacji: " << ui->horizontalSlider_2->value() << std::endl;
    std::cout << "Czy dodac losowosc?: " << ui->checkBox->isChecked() << std::endl;
    std::cout << "Wspolczynnik losowosci?: " << ui->horizontalSlider_8->value() << std::endl;
    std::cout << "=== END ===" << std::endl;

    SimulationContext context(
            ui->spinBox->value(),
            ui->spinBox_2->value(),
            ui->horizontalSlider->value(),
            ui->horizontalSlider_3->value(),
            ui->horizontalSlider_6->value(),
            ui->spinBox_3->value(),
            ui->spinBox_4->value(),
            ui->horizontalSlider_4->value(),
            ui->horizontalSlider_7->value(),
            ui->spinBox_6->value(),
            ui->simulationFrame->width(),
            ui->checkBox->isChecked(),
            ui->horizontalSlider_8->value()
    );

    if (!m_aquariumService)
        m_aquariumService = new AquariumService();

    m_aquarium = m_aquariumService->initAquariumBasedOnApplicationContext(context);

    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(context.iterationCount());
    ui->progressBar->setValue(0);

    m_timer->start(SIMULATION_INTERVAL_MS - ui->horizontalSlider_2->value() * 0.01 * SIMULATION_INTERVAL_MS);

    std::cout << "Simulation started\n";
}

// STOP
void MainWindow::on_pushButton_2_clicked() {
    m_timer->stop();
    std::cout << "Simulation stopped\n";
}

// RESTART
void MainWindow::on_pushButton_3_clicked() {
    m_timer->stop();

    ui->progressBar->setValue(0);

    on_pushButton_clicked();

    std::cout << "Simulation restarted\n";
}

void MainWindow::simulateStep() {
    m_simulatorManager.simulate(m_aquarium);
    ui->progressBar->setValue(m_aquarium.getCurrentIteration());
    m_aquariumView->updateView(m_aquarium);
    if (m_simulatorManager.isFinished(m_aquarium)) {
        m_timer->stop();
        std::cout << "Simulation finished\n";
    }
}
