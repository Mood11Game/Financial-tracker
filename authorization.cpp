#include "authorization.h"
#include "ui_authorization.h"

Authorization::Authorization(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::Authorization),
    obj(new masterWind(this))
{
    ui->setupUi(this);

    connect(ui->buttonLogin, &QPushButton::clicked, this, [this]() {
        obj->show();
        obj->activateWindow();
    });
}

Authorization::~Authorization()
{
    delete ui;
}
