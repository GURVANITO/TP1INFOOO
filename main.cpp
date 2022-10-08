//
//  main.cpp
//  TP1C++
//
//  Created by Gustavo Guerrero on 15/09/2019.
//  Copyright © 2019 Gustavo Guerrero. All rights reserved.
//

#include <iostream>
#include "point2D.h"
#include "Image2D.hpp"

using namespace std;

int main()
{
    //ROTATE IMAGE
    Image2D A(800, 600, 255, 1, 1, 12);
    A.rotation(180,"lena24.bmp");

    return 0;
}
