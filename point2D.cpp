//
//  point2D.cpp
//  TP1C++
//
//  Created by Gustavo Guerrero on 15/09/2019.
//  Copyright © 2019 Gustavo Guerrero. All rights reserved.
//


#include "point2D.h"

using namespace std;

point2D::point2D(){
x=0;
y=0;
}
point2D::point2D(double a, double b){
x=a;
y=b;
}
double point2D::CalculeNorme(){

    double norme;
    norme = sqrt(x*x+y*y);
    return norme;
}
void point2D::print(){
    //cout

    cout << "la valeur de x est :"<< x <<endl;
    cout << "la valeur de y est :"<< y <<endl;

}

double point2D::get_x(){
    return x;
}
double point2D::get_y(){
    return y;
}
void point2D::set_x(double a){
 x = a;
}
void point2D::set_y(double b){
 y = b;
}



point2D & point2D::operator= ( const point2D & p2)
{
 if (this != &p2) { // <- precaution: On vérifie que l'on travaille donc avec deux objets distincts.
 (*this).x = p2.x;
 (*this).y = p2.y;

 }

return *this;

}


point2D & point2D::operator+=(const point2D &p2)
{

        (*this).x+=p2.x;
        (*this).y+=p2.y;


    return *this;
}


bool point2D::operator==(const point2D &p2)
{
    if((*this).x == p2.x && (*this).y == p2.y){
        return true;
    }else{
        return false;
    }
}


point2D::~point2D()
{

}


