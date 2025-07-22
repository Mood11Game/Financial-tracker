#include "authorization.h"

#include <QApplication>
#include "dbmanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Authorization w;

    {
        DBManager obj("", "", "", "user_table");
    }

    w.show();
    return a.exec();
}
