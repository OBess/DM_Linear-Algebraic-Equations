#ifndef LINEARALGEBRAICEQUATIONS_H
#define LINEARALGEBRAICEQUATIONS_H

#include <memory>

#include <QMainWindow>

#include "uiseidelssetup.h"

QT_BEGIN_NAMESPACE
namespace Ui { class LinearAlgebraicEquations; }
QT_END_NAMESPACE

class LinearAlgebraicEquations : public QMainWindow
{
    Q_OBJECT

public:
    LinearAlgebraicEquations(QWidget *parent = nullptr);
    ~LinearAlgebraicEquations();

private slots:
    void on_nextWindow_clicked();

private:
    void compute();

    Ui::LinearAlgebraicEquations *ui = nullptr;
    std::unique_ptr<UISeidelsSetup> seidelsSetup;
};
#endif // LINEARALGEBRAICEQUATIONS_H
