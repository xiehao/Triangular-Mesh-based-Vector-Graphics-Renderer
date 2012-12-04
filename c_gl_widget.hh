#ifndef C_GL_WIDGET_HH
#define C_GL_WIDGET_HH

#include <QGLWidget>
#include <tr1/memory>

class c_gl_widget : public QGLWidget
{
    Q_OBJECT
public:
    explicit c_gl_widget(QWidget *parent = 0);
    void updateGL(void);

signals:
protected:
    void initializeGL(void);
    void resizeGL(int _width, int _height);
    void paintGL(void);
public slots:
private:
    void draw(void);
};

#endif // C_GL_WIDGET_HH
