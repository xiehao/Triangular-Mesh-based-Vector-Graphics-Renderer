#include "c_data.hh"

#include <iostream>
#include <fstream>
#include <sstream>

c_data *c_data::m_p_instance = NULL;

bool c_data::load(const std::string &_file_name)
{
    std::ifstream file(_file_name.c_str());

    if (!file)
    {
        std::cerr << "Loading vector graphics failed!!" << std::endl;
        return false;
    }

    std::string line;
    std::getline(file, line);
    std::istringstream stream(line);
    stream >> m_width >> m_height;

    for (; std::getline(file, line);)
    {
        int x, y;
        float r, g, b;
        std::istringstream stream(line);
        stream >> x >> y >> b >> g >> r;
        m_x.push_back(x);
        m_y.push_back(y);
        m_r.push_back(r);
        m_g.push_back(g);
        m_b.push_back(b);
    }

    file.close();

    const size_t n_vertices = m_x.size();
    return n_vertices;
}

bool c_data::save(const std::string &_file_name)
{
    std::ofstream file(_file_name.c_str());

    file.clear();

    const char s = '\t';
    size_t n_vertices = m_x.size();
    for (size_t i = 0; i < n_vertices; ++i)
    {
        file << m_x[i] << s << m_y[i] << s << m_r[i] << s << m_g[i] << s
             << m_b[i] << std::endl;
    }

    file.close();

    return true;
}
