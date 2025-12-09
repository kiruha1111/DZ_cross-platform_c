#ifndef TIMIRBAEVTABLE_H
#define TIMIRBAEVTABLE_H

#include <QWidget>
#include "timirbaevpark.h"

class TimirbaevTable : public QWidget {
    Q_OBJECT

public:
    TimirbaevTable(QWidget* parent, TimirbaevPark& park);
    void drawTable(QPainter &painter);

private:
    void paintEvent(QPaintEvent* event) override;
    TimirbaevPark* ptr_park = nullptr;
    std::vector<std::shared_ptr<TimirbaevCourier>>* ptr_couriers = nullptr;

};

#endif // TIMIRBAEVTABLE_H
