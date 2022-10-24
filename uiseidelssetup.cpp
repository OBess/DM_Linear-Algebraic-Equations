#include "uiseidelssetup.h"
#include "ui_uiseidelssetup.h"

#include "SeidelsMethod.h"

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
    build_window();
}

void UISeidelsSetup::build_window()
{
    auto text = ui->lblVarsAmount->text();
    text.remove(text.size() - 1, 1);
    ui->lblVarsAmount->setText(text + QString::number(_n));

    for (size_t i = 0; i < _n + 1; ++i)
    {
        for (size_t j = 0; j < _n + 1; ++j)
        {
//            auto item = _layoutItems.emplace_back(new QLineEdit);
//            ui->matrixLayout->addItem(item.get(), static_cast<int>(i), static_cast<int>(j));
        }
    }
}

void UISeidelsSetup::on_cancelBtn_released()
{
    this->close();
}


void UISeidelsSetup::on_computeBtn_released()
{
    auto accuracy = ui->accuracyEdit->text().toFloat();
    auto SeidelMethod = sfe::SeidelsMethod(_n, accuracy);
}

