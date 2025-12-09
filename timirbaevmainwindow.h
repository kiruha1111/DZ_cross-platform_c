#ifndef TIMIRBAEVMAINWINDOW_H
#define TIMIRBAEVMAINWINDOW_H

#include "timirbaevtable.h"
#include "timirbaevdialog.h"

#include <QMainWindow>
#include <QScrollArea>

QT_BEGIN_NAMESPACE
namespace Ui {
class TimirbaevMainWindow;
}
QT_END_NAMESPACE

class TimirbaevMainWindow : public QMainWindow {
    Q_OBJECT

public:
    TimirbaevMainWindow(QWidget *parent = nullptr);
    TimirbaevPark park;
    ~TimirbaevMainWindow();

private slots:
    void on_actionLoad_triggered();
    void on_actionSave_triggered();
    void on_actionClear_triggered();

    void on_actionEdit_triggered();

private:
    Ui::TimirbaevMainWindow *ui;
    TimirbaevTable* tableWidget = nullptr;
    std::vector<std::shared_ptr<TimirbaevCourier>>* couriers;
};

#endif // TIMIRBAEVMAINWINDOW_H
