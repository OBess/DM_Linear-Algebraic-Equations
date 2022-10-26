#include "uisedelsresult.h"
#include "../ui_uisedelsresult.h"

UISedelsResult::UISedelsResult(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UISedelsResult)
{
    ui->setupUi(this);
}

UISedelsResult::~UISedelsResult()
{
    delete ui;
}

void UISedelsResult::set_method(sfe::SeidelsMethod seidelsMethod) noexcept
{
    _seidelsMethod = std::move(seidelsMethod);
    _seidelsMethod.compute();

    QString result_str{"[ "};

    for (const auto& result : _seidelsMethod.result())
    {
        result_str.append(QString::number(result)).append(", ");
    }

    result_str.append("]");

    ui->lblDebug->setText(result_str);
}

void UISedelsResult::print(const QString& filepath)
{

}
