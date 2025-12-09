#include "timirbaevdialog.h"
#include "ui_timirbaevdialog.h"
#include <QDebug>

TimirbaevDialog::TimirbaevDialog(QWidget *parent, TimirbaevPark& park)
    : QDialog(parent)
    , ui(new Ui::TimirbaevDialog)
{
    ui->setupUi(this);
    ptr_park = &park;
    ptr_couriers = &(*ptr_park).GetCouriers();
    for (auto& courier : (*ptr_couriers))
        ui->comboBox->addItem(QString::fromLocal8Bit(courier->GetFIO()));
}

TimirbaevDialog::~TimirbaevDialog()
{
    delete ui;
}

void TimirbaevDialog::on_pushAddButton_clicked()
{
    TimirbaevAddDialog* addDialog = new TimirbaevAddDialog(nullptr, ptr_park, true);
    addDialog->setModal(true);
    if (addDialog->exec() != QDialog::Rejected) {
        //qDebug() << "Заход в условие";
         if (!ptr_couriers->empty()) {
            ui->comboBox->addItem(QString::fromLocal8Bit((*ptr_couriers)[(*ptr_couriers).size() - 1]->GetFIO()));
            ui->comboBox->setCurrentText(QString::fromLocal8Bit((*ptr_couriers)[(*ptr_couriers).size() - 1]->GetFIO()));
        }
    }
}


void TimirbaevDialog::on_pushEditButton_clicked()
{
    if (!(*ptr_couriers).empty()) {
        TimirbaevAddDialog* addDialog = new TimirbaevAddDialog(nullptr, ptr_park, false, (*ptr_couriers)[ui->comboBox->currentIndex()]);
        addDialog->setModal(true);
        addDialog->exec();
        (*ptr_couriers)[ui->comboBox->currentIndex()]->ViewCourier(ui);
        ui->comboBox->setItemText(ui->comboBox->currentIndex(), QString::fromLocal8Bit((*ptr_couriers)[ui->comboBox->currentIndex()]->GetFIO()));
    }
    else QMessageBox::information(nullptr, "Информация", "Нет курьеров!");
}


void TimirbaevDialog::on_pushDeleteButton_clicked()
{
    if (!ptr_couriers->empty()) {
        int index = ui->comboBox->currentIndex();
        ptr_couriers->erase(ptr_couriers->begin() + index);
        ui->comboBox->removeItem(index);
        if (ui->comboBox->currentText().isEmpty()) {
            ui->lineEdit->clear();
            ui->lineEdit_2->clear();
            ui->lineEdit_3->clear();
            ui->lineEdit_4->clear();
            ui->lineEdit_5->clear();
            ui->lineEdit_6->clear();
        }
    } else QMessageBox::information(nullptr, "Информация", "Нет курьеров!");
}


void TimirbaevDialog::on_pushCloseButton_clicked()
{
    close();
}


void TimirbaevDialog::on_comboBox_currentIndexChanged(int index)
{
    if (!ptr_couriers->empty())
        (*ptr_couriers)[index]->ViewCourier(ui);
}

