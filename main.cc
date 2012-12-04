#include "c_main_window.hh"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    c_main_window w;
    w.show();
    
    return a.exec();
}
