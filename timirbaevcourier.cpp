#include "timirbaevcourier.h"


int TimirbaevCourier::MaxId = 0;

void TimirbaevCourier::CreateCourier(Ui::TimirbaevAddDialog* ui) {
    firstname = ui->lineEdit->text().toLocal8Bit().constData();
    surname = ui->lineEdit_2->text().toLocal8Bit().constData();
    age = ui->lineEdit_3->text().toInt();
    phone = ui->lineEdit_4->text().toLocal8Bit().constData();
}

void TimirbaevCourier::ShowCourier(QPainter& painter, int& i) const {
    int cellWidth = 150; // Ширина ячейки
    int cellHeight = 30; // Высота ячейки
    QRect cellRect0(0 * cellWidth + 10, i * cellHeight + 10, cellWidth, cellHeight);
    painter.drawText(cellRect0, Qt::AlignCenter, QString::number(id));
    QRect cellRect1(1 * cellWidth + 10, i * cellHeight + 10, cellWidth, cellHeight);
    painter.drawText(cellRect1, Qt::AlignCenter, QString::fromLocal8Bit(firstname));
    QRect cellRect2(2 * cellWidth + 10, i * cellHeight + 10, cellWidth, cellHeight);
    painter.drawText(cellRect2, Qt::AlignCenter, QString::fromLocal8Bit(surname));
    QRect cellRect3(3 * cellWidth + 10, i * cellHeight + 10, cellWidth, cellHeight);
    painter.drawText(cellRect3, Qt::AlignCenter, QString::number(age));
    QRect cellRect4(4 * cellWidth + 10, i * cellHeight + 10, cellWidth, cellHeight);
    painter.drawText(cellRect4, Qt::AlignCenter, QString::fromLocal8Bit(phone));
    ++i;
}

void TimirbaevCourier::ViewCourier(Ui::TimirbaevDialog* ui) const {
    ui->lineEdit->setText(QString::fromLocal8Bit(firstname));
    ui->lineEdit_2->setText(QString::fromLocal8Bit(surname));
    ui->lineEdit_3->setText(QString::number(age));
    ui->lineEdit_4->setText(QString::fromLocal8Bit(phone));
    ui->label_6->setVisible(false);
    ui->lineEdit_5->setVisible(false);
    ui->label_7->setVisible(false);
    ui->lineEdit_6->setVisible(false);
}

void TimirbaevCourier::EditCourier(Ui::TimirbaevAddDialog* ui) const {
    ui->lineEdit->setText(QString::fromLocal8Bit(firstname));
    ui->lineEdit_2->setText(QString::fromLocal8Bit(surname));
    ui->lineEdit_3->setText(QString::number(age));
    ui->lineEdit_4->setText(QString::fromLocal8Bit(phone));
    ui->label_5->setVisible(false);
    ui->lineEdit_5->setVisible(false);
    ui->label_6->setVisible(false);
    ui->lineEdit_6->setVisible(false);
}
