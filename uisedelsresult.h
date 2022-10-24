#ifndef UISEDELSRESULT_H
#define UISEDELSRESULT_H

#include <QMainWindow>

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

    void set_method(sfe::SeidelsMethod seidelsMethod) noexcept;

    void print(const QString& filepath);

private:
    Ui::UISedelsResult *ui;

    sfe::SeidelsMethod _seidelsMethod;
};

#endif // UISEDELSRESULT_H
