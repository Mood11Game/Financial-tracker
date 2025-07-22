#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H

#include <QMainWindow>
#include "masterwind.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Authorization;
}
QT_END_NAMESPACE

class Authorization : public QMainWindow
{
    Q_OBJECT

public:
    explicit Authorization(QWidget *parent = nullptr);
    ~Authorization();

private:
    Ui::Authorization *ui;
    masterWind* obj;
};
#endif
