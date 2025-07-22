#ifndef MASTERWIND_H
#define MASTERWIND_H

#include <QMainWindow>

namespace Ui {
class masterWind;
}

class masterWind : public QMainWindow
{
    Q_OBJECT

public:
    explicit masterWind(QWidget *parent = nullptr);
    ~masterWind();

public slots:
    void on_openMasterWind();

private:
    Ui::masterWind *ui;
};

#endif // MASTERWIND_H
