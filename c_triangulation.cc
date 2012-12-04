#include "c_triangulation.hh"

#include "c_data.hh"

c_triangulation::c_triangulation()
{
}

bool c_triangulation::construct(void)
{
    c_data *p_data = c_data::get_instance();
    t_Triangulation *t = p_data->m_p_triangulation;
    const std::vector<int> &x = p_data->m_x;
    const std::vector<int> &y = p_data->m_y;
    const std::vector<float> &r = p_data->m_r;
    const std::vector<float> &g = p_data->m_g;
    const std::vector<float> &b = p_data->m_b;

    const size_t n_vertices = x.size();
    for (size_t i = 0; i < n_vertices; ++i)
    {
        t_VertexHandle v = t->push_back(t_Point(x[i], y[i]));
        v->info() = s_info(i, r[i], g[i], b[i]);
    }

    size_t n_faces = t->number_of_faces();
    return n_faces;
}
