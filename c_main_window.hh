#ifndef C_MAIN_WINDOW_HH
#define C_MAIN_WINDOW_HH

#include <QMainWindow>

#include <tr1/memory>

namespace Ui {
class c_main_window;
}

class c_triangulation;

class c_main_window : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit c_main_window(QWidget *parent = 0);
    ~c_main_window();
    
private slots:
    void on_actionOpen_triggered();

private:
    Ui::c_main_window *ui;

    QString m_work_space;
    std::tr1::shared_ptr<c_triangulation> m_triangulation;
};

#endif // C_MAIN_WINDOW_HH
