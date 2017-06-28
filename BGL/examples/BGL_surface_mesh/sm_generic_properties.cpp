
#include <CGAL/Simple_cartesian.h>
#include <CGAL/Surface_mesh.h>

typedef CGAL::Simple_cartesian<double> K;
typedef K::Point_3 Point_3;
typedef CGAL::Surface_mesh<Point_3> Mesh;

int main()
{
  Mesh m;
  CGAL::make_triangle(Point_3(0,0,0),Point_3(1,0,0),Point_3(1,1,0),m);

  typedef boost::property_map<Mesh, boost::vertex_property_t<int> >::type VIM;
  VIM vim = add(boost::vertex_property_t<int>("index"), m);
  put(vim, *(vertices(m).first), 7812);
  std::cout << get(vim, *(vertices(m).first)) << std::endl;
  remove(vim,m);

  return 0;
}

