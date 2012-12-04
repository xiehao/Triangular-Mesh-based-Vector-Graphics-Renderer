#ifndef T_TYPES_HH
#define T_TYPES_HH

#include <vector>

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include <CGAL/Triangulation_vertex_base_with_id_2.h>
#include <CGAL/Triangulation_vertex_base_with_info_2.h>

struct s_info
{
    s_info(void) { }
    s_info(const int _id, const float _r, const float _g, const float _b)
        : id(_id), r(_r), g(_g), b(_b) { }

    int id;
    float r;
    float g;
    float b;
};

typedef CGAL::Exact_predicates_inexact_constructions_kernel t_Kernel;
#if 0
typedef CGAL::Triangulation_vertex_base_with_id_2<t_Kernel> t_VertexBase;
#else
typedef CGAL::Triangulation_vertex_base_with_info_2<s_info, t_Kernel> t_VertexBase;
#endif
typedef CGAL::Triangulation_data_structure_2<t_VertexBase> t_DataStructure;
typedef CGAL::Delaunay_triangulation_2<t_Kernel, t_DataStructure> t_Triangulation;

typedef t_Triangulation::Finite_faces_iterator t_FaceIterator;
typedef t_Triangulation::Finite_vertices_iterator t_VertexIterator;
typedef t_Triangulation::Finite_edges_iterator t_EdgeIterator;
typedef t_Triangulation::Face_handle t_FaceHandle;
typedef t_Triangulation::Vertex_handle t_VertexHandle;
typedef t_Triangulation::Vertex_circulator t_VertexCirculator;
typedef t_Triangulation::Point t_Point;
#if 0
typedef std::vector<t_Point> t_Vertices;
#else
typedef std::pair<t_Point, s_info> t_VertexNode;
typedef std::vector<t_VertexNode> t_Vertices;
#endif
typedef std::vector<std::pair<t_Point, t_Point> > t_Matches;

#endif // T_TYPES_HH
