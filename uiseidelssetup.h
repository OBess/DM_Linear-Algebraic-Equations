#ifndef UISEIDELSSETUP_H
#define UISEIDELSSETUP_H

#include <QMainWindow>

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

private:
    Ui::UISeidelsSetup *ui;

    size_t _n = 0;
};

#endif // UISEIDELSSETUP_H
