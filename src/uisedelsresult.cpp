#include "uisedelsresult.h"
#include "../views/ui_uisedelsresult.h"

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

    try
    {
        _seidelsMethod.compute();
    }
    catch (const std::exception& ex)
    {
        qPrintable(ex.what());
        return;
    }

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
