#include "c_gl_widget.hh"

#include <glu.h>

#include "c_data.hh"

c_gl_widget::c_gl_widget(QWidget *parent)
    : QGLWidget(parent)
{
    QSizePolicy::Policy policy = QSizePolicy::Expanding;
    setSizePolicy(policy, policy);
    setFormat(QGLFormat(QGL::DoubleBuffer | QGL::DepthBuffer));
}

void c_gl_widget::updateGL(void)
{
    paintGL();
    return;
}

void c_gl_widget::initializeGL(void)
{
    glClearDepth(1.f);

    glShadeModel(GL_SMOOTH);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    glEnable(GL_DEPTH_TEST);

    return;
}

void c_gl_widget::resizeGL(int _width, int _height)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0, _width, 0, _height);
    glViewport(0, 0, _width, _height);

    return;
}

void c_gl_widget::paintGL(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    draw();

    return;
}

void c_gl_widget::draw(void)
{
    qglClearColor(Qt::black);

    const t_Triangulation *t = c_data::get_instance()->m_p_triangulation;

    t_FaceIterator f_iter_begin = t->finite_faces_begin();
    t_FaceIterator f_iter_end = t->finite_faces_end();
    t_FaceIterator f_iter = f_iter_begin;
    for (; f_iter != f_iter_end; ++f_iter)
    {
        t_VertexHandle v0(f_iter->vertex(0));
        t_VertexHandle v1(f_iter->vertex(1));
        t_VertexHandle v2(f_iter->vertex(2));

        t_Point p0(v0->point());
        t_Point p1(v1->point());
        t_Point p2(v2->point());

        glBegin(GL_TRIANGLES);

        glColor3f(v0->info().r, v0->info().g, v0->info().b);
        glVertex2i(p0.x() + .5f, p0.y() + .5f);
        glColor3f(v1->info().r, v1->info().g, v1->info().b);
        glVertex2i(p1.x() + .5f, p1.y() + .5f);
        glColor3f(v2->info().r, v2->info().g, v2->info().b);
        glVertex2i(p2.x() + .5f, p2.y() + .5f);

        glEnd();
    }

    return;
}
