#include "masterwind.h"
#include "ui_masterwind.h"

masterWind::masterWind(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::masterWind)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose, false);
}

masterWind::~masterWind()
{
    delete ui;
}

void masterWind::on_openMasterWind()
{
    show();
    activateWindow();
}
