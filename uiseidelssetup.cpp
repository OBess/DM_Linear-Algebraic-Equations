#include "uiseidelssetup.h"
#include "ui_uiseidelssetup.h"

#include "SeidelsMethod.h"

#include <iostream>

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

    _lblMatrixA = std::make_unique<QLabel>("Матриця А");
    _lblMatrixA->setAlignment(Qt::AlignCenter);
    _lblMatrixA->setMaximumHeight(30);

    _lblVectorB = std::make_unique<QLabel>("Результат Б");
    _lblVectorB->setAlignment(Qt::AlignCenter);
    _lblVectorB->setMaximumHeight(30);

    ui->matrixLayout->addWidget(_lblMatrixA.get(), 0, static_cast<int>(_n / 2));
    ui->matrixLayout->addWidget(_lblVectorB.get(), 0, static_cast<int>(_n));

    for (size_t i = 0; i < _n; ++i)
    {
        for (size_t j = 0; j < _n + 1; ++j)
        {
            auto& item = _layoutWidgets.emplace_back(std::make_unique<QLineEdit>());
            item->setText("0");
            ui->matrixLayout->addWidget(item.get(), static_cast<int>(i) + 1, static_cast<int>(j));
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

    for (int i = 1; i < ui->matrixLayout->rowCount(); ++i)
    {
      for (int j = 0; j < ui->matrixLayout->columnCount(); ++j)
      {
        auto item = ui->matrixLayout->itemAtPosition(i, j);
        if (item)
        {
            auto textEdit = static_cast<QLineEdit*>(item->widget());
            SeidelMethod.add(j, i - 1, textEdit->text().toFloat());
        }
      }
    }


}

