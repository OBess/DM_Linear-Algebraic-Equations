#include "linearalgebraicequations.h"
#include "./ui_linearalgebraicequations.h"

#include <string>

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


void LinearAlgebraicEquations::on_nextWindow_clicked()
{
    compute();
}

void LinearAlgebraicEquations::compute()
{
    seidelsSetup.reset(new UISeidelsSetup(this));
    seidelsSetup->set_dimension(ui->varsAmount->currentText().toUInt());
    seidelsSetup->show();
}
