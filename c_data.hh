#ifndef S_DATA_HH
#define S_DATA_HH

#include <string>
#include <vector>

#include "t_types.hh"

class c_data
{
public:
    ~c_data(void)
    {
        delete m_p_triangulation;
        delete m_p_instance;
    }

    static c_data *get_instance(void)
    {
        if (!m_p_instance)
        {
            m_p_instance = new c_data();
        }
        return m_p_instance;
    }

    bool load(const std::string &_file_name);
    bool save(const std::string &_file_name);

    int m_width;
    int m_height;

    std::vector<int> m_x;
    std::vector<int> m_y;
    std::vector<float> m_r;
    std::vector<float> m_g;
    std::vector<float> m_b;

    t_Triangulation *m_p_triangulation;

private:
    c_data(void)
    {
        m_p_triangulation = new t_Triangulation;
    }
    c_data(const c_data &) { }

    static c_data *m_p_instance;
};

#endif // S_DATA_HH
