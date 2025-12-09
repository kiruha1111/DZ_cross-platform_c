#ifndef TIMIRBAEVDIALOG_H
#define TIMIRBAEVDIALOG_H

#include <QDialog>
#include "timirbaevpark.h"
#include "timirbaevadddialog.h"

namespace Ui {
class TimirbaevDialog;
}

class TimirbaevDialog : public QDialog
{
    Q_OBJECT

public:
    TimirbaevDialog(QWidget *parent, TimirbaevPark& park);
    ~TimirbaevDialog();

private slots:
    void on_pushAddButton_clicked();

    void on_pushEditButton_clicked();

    void on_pushDeleteButton_clicked();

    void on_pushCloseButton_clicked();

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::TimirbaevDialog *ui;
    TimirbaevPark* ptr_park = nullptr;
    std::vector<std::shared_ptr<TimirbaevCourier>>* ptr_couriers = nullptr;
};

#endif // TIMIRBAEVDIALOG_H
