#ifndef UISEDELSRESULT_H
#define UISEDELSRESULT_H

#include <memory>

#include <QMainWindow>
#include <QLabel>

#include "SeidelsMethod.h"

namespace Ui {
class UISedelsResult;
}

class UISedelsResult : public QMainWindow
{
    Q_OBJECT

public:
    explicit UISedelsResult(QWidget *parent = nullptr);
    ~UISedelsResult();

    void set_results(const sfe::SeidelsMethod& seidelsMethod) noexcept;

private:
    Ui::UISedelsResult *ui;

    std::vector<std::unique_ptr<QLabel>> _labelsList;
};

#endif // UISEDELSRESULT_H
