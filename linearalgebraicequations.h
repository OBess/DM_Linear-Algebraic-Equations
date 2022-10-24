#ifndef LINEARALGEBRAICEQUATIONS_H
#define LINEARALGEBRAICEQUATIONS_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class LinearAlgebraicEquations; }
QT_END_NAMESPACE

class LinearAlgebraicEquations : public QMainWindow
{
    Q_OBJECT

public:
    LinearAlgebraicEquations(QWidget *parent = nullptr);
    ~LinearAlgebraicEquations();

private:
    Ui::LinearAlgebraicEquations *ui;
};
#endif // LINEARALGEBRAICEQUATIONS_H
