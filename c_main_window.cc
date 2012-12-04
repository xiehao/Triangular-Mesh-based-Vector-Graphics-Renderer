#include "c_main_window.hh"
#include "ui_c_main_window.h"

#include <QDebug>
#include <QFileDialog>
#include <QTime>

#include "c_data.hh"
#include "c_gl_widget.hh"
#include "c_triangulation.hh"

c_main_window::c_main_window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::c_main_window),
    m_work_space(QObject::trUtf8("../../")),
    m_triangulation(new c_triangulation)
{
    ui->setupUi(this);
}

c_main_window::~c_main_window()
{
    delete ui;
}

void c_main_window::on_actionOpen_triggered()
{
    QString file_name =
            QFileDialog::getOpenFileName(this,
                                         QObject::trUtf8("Open vector graphics"),
                                         m_work_space,
                                         QObject::trUtf8("all(*.*)"));

    QTime time;
    c_data *p_data = c_data::get_instance();
    qDebug() << "Loading vector graphics...";
    time.start();
    if (p_data->load(file_name.toStdString()))
    {
        qDebug() << "Loading vector graphics done!! Using "
                 << time.elapsed() / 1000.f << " second(s)";

        /*!< construct Delaunay triangulation based on loaded data */
        qDebug() << "Constructing Delaunay triangulation...";
        time.start();
        m_triangulation->construct();
        qDebug() << "Constructing Delaunay triangulation done!! Using "
                 <<  time.elapsed() / 1000.f << " second(s)";

        /*!< update OpenGL */
        ui->gl_widget->resize(QSize(p_data->m_width, p_data->m_height));
        ui->gl_widget->updateGL();
        ui->gl_widget->update();
    }
}
