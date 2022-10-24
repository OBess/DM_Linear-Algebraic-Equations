#include "uiseidelssetup.h"
#include "ui_uiseidelssetup.h"

UISeidelsSetup::UISeidelsSetup(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UISeidelsSetup)
{
    ui->setupUi(this);
}

UISeidelsSetup::~UISeidelsSetup()
{
    delete ui;
}

void UISeidelsSetup::set_dimension(size_t n)
{
    _n = n;
    auto text = ui->lblVarsAmount->text();
    text.remove(text.size() - 1, 1);
    ui->lblVarsAmount->setText(text + QString::number(n));
}
