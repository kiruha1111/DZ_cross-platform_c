#ifndef TIMIRBAEVCOURIER_H
#define TIMIRBAEVCOURIER_H

#pragma once
#include "timirbaevutilities.h"
#include "ui_timirbaevdialog.h"
#include "ui_timirbaevadddialog.h"

#include <fstream>
#include <QPainter>
#include <QMessageBox>

class TimirbaevCourier {
private:
    int id;
    std::string firstname;
    std::string surname;
    int age;
    std::string phone;

public:
    static int MaxId;

    TimirbaevCourier() {
        id = ++MaxId;
    }

    virtual void CreateCourier(Ui::TimirbaevAddDialog* ui);
    virtual void ShowCourier(QPainter& painter, int& i) const;
    virtual void ViewCourier(Ui::TimirbaevDialog* ui) const;
    virtual void EditCourier(Ui::TimirbaevAddDialog* ui) const;

    std::string GetFIO() {
        return surname;
    }

    template<class Archive>
    void serialize(Archive& ar, const unsigned int version) {
        ar & id;
        ar & firstname;
        ar & surname;
        ar & age;
        ar & phone;
    }

    ~TimirbaevCourier() {}
};

#endif // TIMIRBAEVCOURIER_H
