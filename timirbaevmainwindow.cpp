#include "timirbaevmainwindow.h"
#include "timirbaevpark.h"
#include "./ui_timirbaevmainwindow.h"

TimirbaevMainWindow::TimirbaevMainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::TimirbaevMainWindow) {
    ui->setupUi(this);
    tableWidget = new TimirbaevTable(nullptr, park);
    setCentralWidget(ui->scrollArea);
    ui->scrollArea->setVisible(false);
}

TimirbaevMainWindow::~TimirbaevMainWindow() {
    delete ui;
}

void TimirbaevMainWindow::on_actionLoad_triggered() {
    bool flag = park.LoadSer();
    if (flag) {
        ui->scrollArea->setWidget(tableWidget);
        ui->scrollArea->setWidgetResizable(true);
        ui->scrollArea->setVisible(true);
    }
}

void TimirbaevMainWindow::on_actionSave_triggered() {
    park.SaveSer();
}

void TimirbaevMainWindow::on_actionClear_triggered() {
    park.DeleteCouriers();
    ui->scrollArea->setVisible(false);
}

void TimirbaevMainWindow::on_actionEdit_triggered() {
    TimirbaevDialog* dialog = new TimirbaevDialog(nullptr, park);
    dialog->setModal(true);
    dialog->exec();
    if (!park.GetCouriers().empty()) {
        ui->scrollArea->setWidget(tableWidget);
        ui->scrollArea->setWidgetResizable(true);
        ui->scrollArea->setVisible(true);
    }
}

