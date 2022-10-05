//
//  main.cpp
//  TP1C++
//
//  Created by Gustavo Guerrero on 15/09/2019.
//  Copyright © 2019 Gustavo Guerrero. All rights reserved.
//

#include <iostream>
#include "point2D.h"
#include "point3D.h"
#include "Image2D.hpp"

using namespace std;

int main()
{
//PRIMERA PARTE

//    point2D A(1,1);
//    point2D B;
//
//    A.print();
//    B.print();
//    cout<<B.CalculeNorme()<<endl;
//
//    cout<<"B=A  : "<<endl;
//    B=A;
//    B.print();
//
//    cout<<"C=B  : "<<endl;
//    point2D C=B;
//
//
//    cout<<"C : "<<endl;
//    C.print();
//    C.set_x(4);
//    cout<<"C x =4: "<<endl;
//
//    C.print();
//
//    cout<<"B : "<<endl;
//    B.print();
//
//    cout<<"A+=B  : "<<endl;
//    A+=B;
//    A.print();
//
//
//    if (A==B)
//        cout<<"A=B"<<endl;
//    else cout<<"A!=B"<<endl;
//    B.set_x(4);
//    if (C==B)
//        cout<<"C=B"<<endl;
//    else cout<<"C!=B"<<endl;
//
//    cout << "Hello world!" << endl;



//    SEGUNDA PARTE
    ///////////////////////////////////////:
//
//    /** test de points 2D **/
//
//    point2D A(1,1.5);
//    point2D B;
//    //   B.print();
//
//    /** test de points 3D */
//    point3D C;
//    point3D D(1,1,2);
//
//    C.print();
//    D.print();
//
//    /** test surcharge opérateur += **/
//    //    D+=D;
//
//    /** test opérateur << **/
//    cout <<"Point D"<<D;
//
//
//    /** test création objets dynamique */
//
//    point3D *pE=new point3D(0,1,2);
//    pE->print();
//    cout << *pE;
//
//
//    cout << "Hello    world!" << endl;



    //TERCERA PARTE
    cout<<"Arrancamos"<<endl;
    //Image2D A;
    //Image2D X(800, 600, 255, 1, 1, 12);

    //Image2D B(f,1,1);
//    char* f2="lena24.bmp";//char* f2="El_Capitan_SunsetBW.bmp";
//    Image2D C(f2,1,1);
//    ;
//    //FILE *fp;
//    FILE *fp2;
//    fp2=fopen("lena24.bmp","rb");
//    //fp2=fopen("lenaNueva.bmp","wb");
//    unsigned char info[54];
//    fread(info, sizeof(unsigned char), 54, fp2); // read the 54-byte header
//    //fclose(fp);
//    int width = *(int*)&info[18];
//    int height = *(int*)&info[22];
//    int size = 3 * width * height;
//    unsigned char* image_and_en_tete_to_save = new unsigned char[size];
//
//    for(int iD=0;iD<54;iD++)//the first 54 bytes
//    {
//
//        image_and_en_tete_to_save[iD]=info[iD];
//        //cout <<iD<<image_and_en_tete_to_save[iD]<<endl;
//        cout <<image_and_en_tete_to_save[iD]<<endl;
//    }
//
//    for (int i=0; i<C.getNbx(); i++) {
//        for (int j=0; j<C.getNby(); j++) {
//            image_and_en_tete_to_save[54+(i*(C.getNby())+j)*3]=(unsigned char)C.getPixelValue(i,j);
//            image_and_en_tete_to_save[54+1+(i*(C.getNby())+j)*3]=(unsigned char)C.getPixelValue(i,j);
//            image_and_en_tete_to_save[54+2+(i*(C.getNby())+j)*3]=(unsigned char)C.getPixelValue(i,j);
//        }
//    }
//
//   // fwrite(&tab, sizeof ptr[0][0],n,fp2);
//    fclose(fp2);
//    fp2=fopen("test.bmp","wb");
//    fwrite(image_and_en_tete_to_save,sizeof(char),(54+C.getSize()*3),fp2);// fonction to read binary
//    ///Closure
//
//    fclose(fp2);



    ////////////////////////////////////////////////
    ///////////////////////////////////////////
    /////////////////////////////////////////:::
    //fonction seuillage

//char* f1="mola.bmp";
//Image2D D(f1,1,1);
//FILE *fp1;
//fp1=fopen("mola.bmp","rb");
//
//
//    unsigned char info1[54];
//    fread(info1, sizeof(unsigned char), 54, fp1); // read the 54-byte header
//    //fclose(fp);
//    int width1 = *(int*)&info1[18];
//    int height1 = *(int*)&info1[22];
//    int size1 = 3 * width1 * height1;
//    unsigned char* image_and_en_tete_to_save1 = new unsigned char[size1];
//
//
//
//    for(int iD1=0;iD1<54;iD1++)//the first 54 bytes
//    {
//
//        image_and_en_tete_to_save1[iD1]=info1[iD1];
//        //cout <<iD<<image_and_en_tete_to_save[iD]<<endl;
//        //cout <<image_and_en_tete_to_save1[iD1]<<endl;
//    }
//
//    for (int i=0; i<D.getNbx(); i++) {
//        for (int j=0; j<D.getNby(); j++) {
//
//            if (D.getPixelValue(i,j) >150)
//        {
//            image_and_en_tete_to_save1[54+(i*(D.getNby())+j)*3]=(unsigned char)D.getPixelValue(i,j);
//            image_and_en_tete_to_save1[54+1+(i*(D.getNby())+j)*3]=(unsigned char)D.getPixelValue(i,j);
//            image_and_en_tete_to_save1[54+2+(i*(D.getNby())+j)*3]=(unsigned char)D.getPixelValue(i,j);
//        }
//            else {
//                D.setPixelValue(i,j,0);
//            }
//    }
//    }
//
//   // fwrite(&tab, sizeof ptr[0][0],n,fp2);
//    fclose(fp1);
//    fp1=fopen("test_mola.bmp","wb");
//    fwrite(image_and_en_tete_to_save1,sizeof(char),(54+D.getSize()*3),fp1);// fonction to read binary
//    ///Closure
//
//    fclose(fp1);


//méthode
//jusqu'à la ligne 266 c'est la question sur le masque
//char* f1="lena24.bmp";
//Image2D D(f1,1,1);
//FILE *fp1;
//fp1=fopen("lena24.bmp","rb");
//
//    unsigned char info1[54];
//    fread(info1, sizeof(unsigned char), 54, fp1); // read the 54-byte header
//    fclose(fp1);
//    int width1 = *(int*)&info1[18];
//    int height1 = *(int*)&info1[22];
//    int size1 = 3 * width1 * height1;
//    unsigned char* image_and_en_tete_to_save1 = new unsigned char[size1];
//
//char* f3="mask.bmp";
//Image2D E(f3,1,1);
//FILE *fp3;
//fp3=fopen("mask.bmp","rb");
//
//    unsigned char info3[54];
//    fread(info3, sizeof(unsigned char), 54, fp3); // read the 54-byte header
//    fclose(fp3);
//    int width3 = *(int*)&info3[18];
//    int height3 = *(int*)&info3[22];
//    int size3 = 3 * width3 * height3;
//    unsigned char* image_and_en_tete_to_save3 = new unsigned char[size3];
//
//
//
//
//
//    for(int iD1=0;iD1<54;iD1++)//the first 54 bytes
//    {
//
//        image_and_en_tete_to_save1[iD1]=info1[iD1];
//        //cout <<iD<<image_and_en_tete_to_save[iD]<<endl;
//        //cout <<image_and_en_tete_to_save1[iD1]<<endl;
//    }
//
//
//
//     for(int iD3=0;iD3<54;iD3++)//the first 54 bytes
//    {
//
//        image_and_en_tete_to_save3[iD3]=info3[iD3];
//        //cout <<iD<<image_and_en_tete_to_save[iD]<<endl;
//        //cout <<image_and_en_tete_to_save1[iD1]<<endl;
//    }
//
//    for (int i=0; i<D.getNbx(); i++) {
//        for (int j=0; j<D.getNby(); j++) {
//
//            if (D.getPixelValue(i,j) <= E.getPixelValue(i,j))
//        {
//            image_and_en_tete_to_save1[54+(i*(D.getNby())+j)*3]=(unsigned char)D.getPixelValue(i,j);
//            image_and_en_tete_to_save1[54+1+(i*(D.getNby())+j)*3]=(unsigned char)D.getPixelValue(i,j);
//            image_and_en_tete_to_save1[54+2+(i*(D.getNby())+j)*3]=(unsigned char)D.getPixelValue(i,j);
//        }
//            else {
//                D.setPixelValue(i,j,0);
//            }
//    }
//    }
//
//   // fwrite(&tab, sizeof ptr[0][0],n,fp2);
//    fclose(fp1);
//    fp1=fopen("test_du_masque_avec_mola.bmp","wb");
//    fwrite(image_and_en_tete_to_save1,sizeof(char),(54+D.getSize()*3),fp1);// fonction to read binary
//    ///Closure
//
//    fclose(fp1);



/////////////////A PARTIR DE MAINTENANT ON TEST la translation////////////////////////////////////

char* f2="lena24.bmp";
Image2D E(f2,1,1);
E.enregistreImage(f2);




char* f1="lena24.bmp";
Image2D D(f1,1,1);
FILE *fp1;
fp1=fopen("lena24.bmp","rb");

    unsigned char info1[54];
    fread(info1, sizeof(unsigned char), 54, fp1); // read the 54-byte header
    fclose(fp1);
    int width1 = *(int*)&info1[18];
    int height1 = *(int*)&info1[22];
    int size1 = 3 * width1 * height1;
    unsigned char* image_and_en_tete_to_save1 = new unsigned char[size1];

 for(int iD1=0;iD1<54;iD1++)//the first 54 bytes
    {

        image_and_en_tete_to_save1[iD1]=info1[iD1];
        //cout <<iD<<image_and_en_tete_to_save[iD]<<endl;
        //cout <<image_and_en_tete_to_save1[iD1]<<endl;
    }

    for (int i=0; i<D.getNbx(); i++) {
        for (int j=0; j<D.getNby(); j++) {

            image_and_en_tete_to_save1[54+(i*(D.getNby())+j)*3]=(unsigned char)D.getPixelValue(i,j);
            image_and_en_tete_to_save1[54+1+(i*(D.getNby())+j)*3]=(unsigned char)D.getPixelValue(i,j);
            image_and_en_tete_to_save1[54+2+(i*(D.getNby())+j)*3]=(unsigned char)D.getPixelValue(i,j);

            int a=D.getPixelValue(i,j);
            D.setPixelValue(511-j,511-i,a);

            //D.setPixelValue(t,z,a);

        }
    }

cout<<"sorti de la boucle"<<endl;

   // fwrite(&tab, sizeof ptr[0][0],n,fp2);
    fclose(fp1);
    fp1=fopen("test_translation_lena.bmp","wb");
    fwrite(image_and_en_tete_to_save1,sizeof(char),(54+D.getSize()*3),fp1);// fonction to read binary
    ///Closure

    fclose(fp1);



    return 0;
}
