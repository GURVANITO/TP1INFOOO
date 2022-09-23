#include "point3D.h"

point3D::point3D():point2D(),z(0.0)
{
   x=0;
   y=0;
   z=0;//ctor
}

point3D::point3D(double a, double b, double c):point2D(a,b),z(c)
{
    x=a;
    y=b;
    z=c;//ctor
}

void point3D::print()
{
    cout << "la valeur de x est :"<< x <<endl;
    cout << "la valeur de y est :"<< y <<endl;
    cout << "la valeur de Z est :"<< z <<endl;
}

double point3D::get_z(){
    return z;
}
void point3D::set_z(double c){
    z = c;
}




point3D & point3D::operator= ( const point3D & p2)
{
 if (this != &p2) { // <- precaution: On vérifie que l'on travaille donc avec deux objets distincts.
 (*this).x = p2.x;
 (*this).y = p2.y;
 (*this).z = p2.z;

 }

return *this;

}


point3D & point3D::operator+=(const point3D &p2)
{

        (*this).x+=p2.x;
        (*this).y+=p2.y;
        (*this).z+=p2.z;


    return *this;
}


bool point3D::operator==(const point3D &p2)
{
    if((*this).x == p2.x && (*this).y == p2.y && (*this).z == p2.z ){
        return true;
    }else{
        return false;
    }
}




point3D::~point3D()
{
    //dtor
}
