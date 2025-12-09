#include "timirbaevautocourier.h"

void TimirbaevAutoCourier::CreateCourier(Ui::TimirbaevAddDialog* ui) {
    TimirbaevCourier::CreateCourier(ui);
    car_model = ui->lineEdit_5->text().toLocal8Bit().constData();
    car_number = ui->lineEdit_6->text().toLocal8Bit().constData();
}

void TimirbaevAutoCourier::ShowCourier(QPainter& painter, int& i) const {
    int y = i;
    TimirbaevCourier::ShowCourier(painter, i);
    int cellWidth = 150; // Ширина ячейки
    int cellHeight = 30; // Высота ячейки
    QRect cellRect5(5 * cellWidth + 10, y * cellHeight + 10, cellWidth, cellHeight);
    painter.drawText(cellRect5, Qt::AlignCenter, QString::fromLocal8Bit(car_model));
    QRect cellRect6(6 * cellWidth + 10, y * cellHeight + 10, cellWidth, cellHeight);
    painter.drawText(cellRect6, Qt::AlignCenter, QString::fromLocal8Bit(car_number));
}

void TimirbaevAutoCourier::ViewCourier(Ui::TimirbaevDialog *ui) const {
    TimirbaevCourier::ViewCourier(ui);
    ui->label_6->setVisible(true);
    ui->lineEdit_5->setVisible(true);
    ui->lineEdit_5->setText(QString::fromLocal8Bit(car_model));
    ui->label_7->setVisible(true);
    ui->lineEdit_6->setVisible(true);
    ui->lineEdit_6->setText(QString::fromLocal8Bit(car_number));
}

void TimirbaevAutoCourier::EditCourier(Ui::TimirbaevAddDialog *ui) const {
    TimirbaevCourier::EditCourier(ui);
    ui->label_5->setVisible(true);
    ui->lineEdit_5->setVisible(true);
    ui->lineEdit_5->setText(QString::fromLocal8Bit(car_model));
    ui->label_6->setVisible(true);
    ui->lineEdit_6->setVisible(true);
    ui->lineEdit_6->setText(QString::fromLocal8Bit(car_number));
}
