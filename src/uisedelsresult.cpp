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

void UISedelsResult::set_results(const sfe::SeidelsMethod& seidelsMethod) noexcept
{
    auto text = ui->lblVarsAmount->text();
    text.remove(text.size() - 1, 1);
    ui->lblVarsAmount->setText(text + QString::number(seidelsMethod.vector().size()));

    QString funcStr;

    const auto& matrix = seidelsMethod.matrix();
    const auto& vector = seidelsMethod.vector();
    const auto size = matrix.size();

    for (size_t i = 0; i < size; ++i)
    {
        funcStr.clear();

        for (size_t j = 0; j < size; ++j)
        {
            funcStr.append(QString::number(matrix[i][j]))
                   .append("x" + QString::number(j + 1) + " + ");
        }

        funcStr.remove(funcStr.size() - 3, 4);

        funcStr.append(" = ")
               .append(QString::number(vector[i]));

        auto& lableInst = _labelsList.emplace_back(std::make_unique<QLabel>(funcStr, this));
        ui->funcsList->addWidget(lableInst.get());
    }

    try
    {
        const_cast<sfe::SeidelsMethod&>(seidelsMethod).compute();
    }
    catch (const std::exception& ex)
    {
        ui->lblResult->setText("Exception: " + QString(ex.what()));
        return;
    }

    QString result("x1 ... x");
    result.append(QString::number(size))
          .append(" : { ");

    for (const auto i : seidelsMethod.result())
        result.append(QString::number(i)).append(", ");

    result.remove(result.size() - 2, 3);
    result.append(" }");

    ui->lblResult->setText(result);
}
