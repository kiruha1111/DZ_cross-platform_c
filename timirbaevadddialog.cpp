#include "timirbaevadddialog.h"
#include "ui_timirbaevadddialog.h"
#include <QDebug>

TimirbaevAddDialog::TimirbaevAddDialog(QWidget* parent, TimirbaevPark* park, bool mode)
    : QDialog(parent)
    , ui(new Ui::TimirbaevAddDialog)
{
    ui->setupUi(this);
    ptr_park = park;
    this->mode = mode;
    ui->radioButton->setVisible(mode);
    ui->radioButton_2->setVisible(mode);
    ui->label_5->setVisible(false);
    ui->lineEdit_5->setVisible(false);
    ui->label_6->setVisible(false);
    ui->lineEdit_6->setVisible(false);
}

TimirbaevAddDialog::TimirbaevAddDialog(QWidget* parent, TimirbaevPark* park, bool mode, std::shared_ptr<TimirbaevCourier> courier)
    : QDialog(parent)
    , ui(new Ui::TimirbaevAddDialog)
{
    ui->setupUi(this);
    ptr_park = park;
    this->mode = mode;
    ptr_courier = courier;
    ui->radioButton->setVisible(mode);
    ui->radioButton_2->setVisible(mode);
    ptr_courier->EditCourier(ui);
}

TimirbaevAddDialog::~TimirbaevAddDialog()
{
    delete ui;
}

void TimirbaevAddDialog::on_pushButton_clicked()
{
    if (mode == true) {
        if (ui->radioButton->isChecked()) {
            if (!ui->lineEdit->text().isEmpty() && !ui->lineEdit_2->text().isEmpty() &&
                ui->lineEdit_3->text().toInt() >= 18 && ui->lineEdit_3->text().toInt() <= 60 &&
                IntCheck(ui->lineEdit_4->text().toLocal8Bit().constData()) && ui->lineEdit_4->text().length() == 10 &&
                !ui->lineEdit_5->text().isEmpty() && !ui->lineEdit_6->text().isEmpty()) {
                ptr_park->AddAutoCourier(ui);
                close();
            }
            else QMessageBox::warning(nullptr, "Ошибка", "Неккоректный ввод данных!");
        }
        else {
            if (!ui->lineEdit->text().isEmpty() && !ui->lineEdit_2->text().isEmpty() &&
                ui->lineEdit_3->text().toInt() >= 18 && ui->lineEdit_3->text().toInt() <= 60 &&
                IntCheck(ui->lineEdit_4->text().toLocal8Bit().constData()) && ui->lineEdit_4->text().length() == 10) {
                ptr_park->AddCourier(ui);
                close();
            }
            else QMessageBox::warning(nullptr, "Ошибка", "Неккоректный ввод данных!");
        }
    }
    else {
        if (!ui->lineEdit_5->isVisible()) {
            qDebug() << "Редактирование курьера";
            if (!ui->lineEdit->text().isEmpty() && !ui->lineEdit_2->text().isEmpty() &&
                ui->lineEdit_3->text().toInt() >= 18 && ui->lineEdit_3->text().toInt() <= 60 &&
                IntCheck(ui->lineEdit_4->text().toLocal8Bit().constData()) && ui->lineEdit_4->text().length() == 10) {
                ptr_courier->CreateCourier(ui);
                close();
            }
            else QMessageBox::warning(nullptr, "Ошибка", "Неккоректный ввод данных!");
        }
        else {
            qDebug() << "Редактирование автокурьера";
            if (!ui->lineEdit->text().isEmpty() && !ui->lineEdit_2->text().isEmpty() &&
                ui->lineEdit_3->text().toInt() >= 18 && ui->lineEdit_3->text().toInt() <= 60 &&
                IntCheck(ui->lineEdit_4->text().toLocal8Bit().constData()) && ui->lineEdit_4->text().length() == 10 &&
                !ui->lineEdit_5->text().isEmpty() && !ui->lineEdit_6->text().isEmpty()) {
                ptr_courier->CreateCourier(ui);
                close();
            }
            else QMessageBox::warning(nullptr, "Ошибка", "Неккоректный ввод данных!");
        }
    }
}

void TimirbaevAddDialog::on_radioButton_clicked()
{
    ui->label_5->setVisible(true);
    ui->lineEdit_5->setVisible(true);
    ui->label_6->setVisible(true);
    ui->lineEdit_6->setVisible(true);
}


void TimirbaevAddDialog::on_radioButton_2_clicked()
{
    ui->label_5->setVisible(false);
    ui->lineEdit_5->setVisible(false);
    ui->label_6->setVisible(false);
    ui->lineEdit_6->setVisible(false);
}

