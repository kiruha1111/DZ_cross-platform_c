#ifndef TIMIRBAEVADDDIALOG_H
#define TIMIRBAEVADDDIALOG_H

#include <QDialog>
#include "timirbaevpark.h"

namespace Ui {
class TimirbaevAddDialog;
}

class TimirbaevAddDialog : public QDialog
{
    Q_OBJECT

public:
    TimirbaevAddDialog(QWidget* parent, TimirbaevPark* park, bool mode);
    TimirbaevAddDialog(QWidget* parent, TimirbaevPark* park, bool mode, std::shared_ptr<TimirbaevCourier> courier);
    ~TimirbaevAddDialog();

private slots:
    void on_pushButton_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

private:
    Ui::TimirbaevAddDialog *ui;
    TimirbaevPark* ptr_park = nullptr;
    std::shared_ptr<TimirbaevCourier> ptr_courier = nullptr;
    bool mode;
};

#endif // TIMIRBAEVADDDIALOG_H
