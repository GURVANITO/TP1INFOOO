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

#define PHOTO "lena24.bmp"  // image BMP 24 bits a traiter
#define PHOTO_DEST "lena_seuillage.bmp" //image BMP 24 bits seuillé


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

//    Image2D A;
//    Image2D X(800, 600, 255, 1, 1, 12);
//    Image2D B(f,1,1);


    char* f="mola.bmp";
    char* f2="lena24.bmp";//char* f2="El_Capitan_SunsetBW.bmp";
    Image2D C(f2,1,1);
    FILE *fp;
    FILE *fp2;
    fp2=fopen("lena24.bmp","rb");
    //fp2=fopen("lenaNueva.bmp","wb");
    unsigned char info[54];
    fread(info, sizeof(unsigned char), 54, fp2); // read the 54-byte header
    //fclose(fp);
    int width = *(int*)&info[18];
    int height = *(int*)&info[22];
    int size = 3 * width * height;
    unsigned char* image_and_en_tete_to_save = new unsigned char[size];
    for(int iD=0;iD<54;iD++)//the first 54 bytes
    {
        image_and_en_tete_to_save[iD]=info[iD];
        //cout <<image_and_en_tete_to_save[iD]<<endl;
    }

    for (int i=0; i<C.getNbx(); i++) {
        for (int j=0; j<C.getNby(); j++) {
            image_and_en_tete_to_save[54+(i*(C.getNby())+j)*3]=(unsigned char)C.getPixelValue(i,j);
            image_and_en_tete_to_save[54+1+(i*(C.getNby())+j)*3]=(unsigned char)C.getPixelValue(i,j);
            image_and_en_tete_to_save[54+2+(i*(C.getNby())+j)*3]=(unsigned char)C.getPixelValue(i,j);
        }
    }

    fclose(fp2);
    fp2=fopen("mola2.bmp","wb");
    fwrite(image_and_en_tete_to_save,sizeof(char),(54+C.getSize()*3),fp2);// fonction to read binary
    ///Closure

    fclose(fp2);

    //Seuillage
    int  a;
	int i;

	//ouverture des fichiers bmp

	fp=fopen(PHOTO,"rb");
	fp2=fopen(PHOTO_DEST,"w+b");

	// recopie de l'entete

	for(i=0;i<54;i++)
	{
		fputc(fgetc(fp),fp2);
	}

	//traitement seuillage

	while((a=fgetc(fp))!=EOF)
	{
		if(a>=0x79)
		{fputc(a,fp2);
		}
		else
		{fputc(0x00,fp2);
		}
	}

	fclose(fp);
    fclose(fp2);
    return 0;
}
