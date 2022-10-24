#ifndef UISEIDELSSETUP_H
#define UISEIDELSSETUP_H

#include <QMainWindow>
#include <QLayoutItem>

#include <memory>
#include <list>

namespace Ui {
class UISeidelsSetup;
}

class UISeidelsSetup : public QMainWindow
{
    Q_OBJECT

public:
    explicit UISeidelsSetup(QWidget *parent = nullptr);
    ~UISeidelsSetup();

    void set_dimension(size_t n);

private slots:
    void on_cancelBtn_released();

    void on_computeBtn_released();

private:
    void build_window();

    Ui::UISeidelsSetup *ui;

    std::list<std::unique_ptr<QLayoutItem>> _layoutItems;

    size_t _n = 0;
};

#endif // UISEIDELSSETUP_H
