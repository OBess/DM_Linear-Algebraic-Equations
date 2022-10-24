#include "linearalgebraicequations.h"
#include "./ui_linearalgebraicequations.h"

LinearAlgebraicEquations::LinearAlgebraicEquations(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LinearAlgebraicEquations)
{
    ui->setupUi(this);
}

LinearAlgebraicEquations::~LinearAlgebraicEquations()
{
    delete ui;
}

