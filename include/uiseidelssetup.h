#ifndef UISEIDELSSETUP_H
#define UISEIDELSSETUP_H

#include <QMainWindow>
#include <QLineEdit>
#include <QLabel>

#include <memory>
#include <list>

#include "uisedelsresult.h"

namespace Ui {
class UISeidelsSetup;
}

class UISeidelsSetup : public QMainWindow
{
    Q_OBJECT

public:
    explicit UISeidelsSetup(QWidget *parent = nullptr);
    ~UISeidelsSetup();

    void set_dimension(size_t n);

private slots:
    void on_cancelBtn_released();

    void on_computeBtn_released();

private:
    void build_window();

    Ui::UISeidelsSetup *ui;

    std::list<std::unique_ptr<QLineEdit>> _layoutWidgets;

    std::unique_ptr<QLabel> _lblMatrixA;

    std::unique_ptr<QLabel> _lblVectorB;

    size_t _n = 0;

    std::unique_ptr<UISedelsResult> seidelsResult;
};

#endif // UISEIDELSSETUP_H
