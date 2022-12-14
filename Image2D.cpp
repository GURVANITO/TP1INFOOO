//
//  Image2D.cpp
//  TP1C++
//
//  Created by Gustavo Guerrero on 15/09/2019.
//  Copyright © 2019 Gustavo Guerrero. All rights reserved.
//

#include "Image2D.hpp"

using namespace std;

Image2D::Image2D(){

    int width = 128;
    int height = 128;
    int size=width*height;
    int image_blanche[size][size]; // allocate 3 bytes per pixel

    for (int i=0; i<width; i++) {
        for (int j=0; j<width; j++) {
                (*this).ptr[i][j]=0;
        }
    }
}


Image2D::Image2D(int nx, int ny, int ngl, double milx, double mily, int p0){



    int width = nx;
    int height = ny;
    int size = 3 * width * height;
    (*this).nbx=width;
    (*this).nby=height;
    (*this).size=width*height;
    (*this).dx=milx;
    (*this).dy=mily;
    unsigned char* image = new unsigned char[size]; // allocate 3 bytes per pixel
    unsigned char* imageBLU=new unsigned char[width*height];//definition of the RED
    unsigned char* imageGRE=new unsigned char[width*height];//definition of the GREEN
    unsigned char* imageRED=new unsigned char[width*height];//definition of the BLUE

    for(int id=0;id<(width*height);id++)
    {
        imageBLU[id]=image[3*id];
        imageGRE[id]=image[3*id+1];
        imageRED[id]=image[3*id+2];

    }
    (*this).alloue_partie_dynamique(width,height);
    for (int i=0; i<(*this).nbx; i++) {
        for (int j=0; j<(*this).nby; j++) {
            double mean=0;
            mean=((double)imageRED[i*((*this).nby)+j]+(double)imageBLU[i*((*this).nby)+j]+(double)imageGRE[i*((*this).nby)+j])/3.0;
                (*this).ptr[i][j]=(int)mean;
        }
    }

    delete [] image;
    image=NULL;
    delete [] imageBLU;
    imageBLU=NULL;
    delete [] imageRED;
    imageRED=NULL;
    delete [] imageGRE;
    imageGRE=NULL;

}




Image2D::Image2D(char* path,double milx, double mily){
    FILE* f = fopen(path, "rb");
    unsigned char info[54];
    fread(info, sizeof(unsigned char), 54, f); // read the 54-byte header
    // extract image height and width from header
    int width = *(int*)&info[18];
    int height = *(int*)&info[22];
    int size = 3 * width * height;
    (*this).nbx=width;
    (*this).nby=height;
    (*this).size=width*height;
    (*this).dx=milx;
    (*this).dy=mily;
    unsigned char* image = new unsigned char[size]; // allocate 3 bytes per pixel
    unsigned char* imageBLU=new unsigned char[width*height];//definition of the RED
    unsigned char* imageGRE=new unsigned char[width*height];//definition of the GREEN
    unsigned char* imageRED=new unsigned char[width*height];//definition of the BLUE

    fread(image,sizeof(unsigned char),size,f);//We fill the FULL image
    fclose(f);

    for(int id=0;id<(width*height);id++)
    {
        imageBLU[id]=image[3*id];
        imageGRE[id]=image[3*id+1];
        imageRED[id]=image[3*id+2];

    }
    (*this).alloue_partie_dynamique(width,height);
    for (int i=0; i<(*this).nbx; i++) {
        for (int j=0; j<(*this).nby; j++) {
            double mean=0;
            mean=((double)imageRED[i*((*this).nby)+j]+(double)imageBLU[i*((*this).nby)+j]+(double)imageGRE[i*((*this).nby)+j])/3.0;
                (*this).ptr[i][j]=(int)mean;
        }
    }

    delete [] image;
    image=NULL;
    delete [] imageBLU;
    imageBLU=NULL;
    delete [] imageRED;
    imageRED=NULL;
    delete [] imageGRE;
    imageGRE=NULL;


}

int Image2D::getNbx(){
    return nbx;
}
void Image2D::setNbx(int a){

nbx=a;

}
int Image2D::getNby(){
    return nby;
}
void Image2D::setNby(int a){

nby=a;

}
int Image2D::getNgl(){
    return number_grey_level;
}
void Image2D::setNgl(int a){

number_grey_level=a;

}
long int Image2D::getSize(){
    return size;
}
double Image2D::getDx(){
    return dx;
}
void Image2D::setDx(double a){
 dx=a;
}
double Image2D::getDy(){
    return dy;
}
void Image2D::setDy(double a){
dy=a;
}

int Image2D::getPixelValue(int i,int j){

return ptr[i][j];

}

void Image2D::setPixelValue(int i,int j, int a){
ptr[i][j]=a;
}



//
//void Image2D::MASKOFF(char* path1,char* path2){
//     FILE* f1 = fopen(path1, "rb");
//     FILE* f2 = fopen(path2, "rb");
//
// for (int i=0; i<(*this).getNbx(); i++) {
//        for (int j=0; j<(*this).getNby(); j++) {
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
//
//}




// allocation dynamique de mémoire via new..
void Image2D::alloue_partie_dynamique(int dimx, int dimy){
    if ( dimx<=0 || dimy<=0 )
    {
        std::cout<<"Dimension de l'allocation anormales...\n";
        std::cout<<"dimx : " << dimx << ", dimy :" << dimy << endl ;
        exit ( 1 );
    }

    ptr = new int* [dimx]; //!< ptr[i] pointe sur la ligne i.
    for (int i=0; i<dimx ; i++){
        ptr[i] = new int[dimy]; //!< ptr[i][j] sur l'element i,j
        if ( ptr==NULL || ptr[i]==NULL )
        {
            std::cout<<"Probleme allocation memoire...exiting\n";
            exit ( 1 );
        }
    }

}

void Image2D::libere_partie_dynamique(){
    if ( ptr!=NULL)
    {
        for(int i=0; i< ((*this).nbx) ; i++){
            if ( ptr[i]!=NULL ){
                delete [] ptr[i];
            }
        }
        delete [] ptr;
        ptr=NULL;
    }
}

void Image2D::init(int valeur_init){
    if ((*this).ptr!=NULL)
    {
        for (int i=0; i<(*this).nbx; i++) {
            for (int j=0; j<(*this).nby; j++) {
                (*this).ptr[i][j]=valeur_init;
            }
        }
    }else{
        (*this).alloue_partie_dynamique((*this).nbx,(*this).nby);
        for (int i=0; i<(*this).nbx; i++) {
            for (int j=0; j<(*this).nby; j++) {
                (*this).ptr[i][j]=valeur_init;
            }
        }

    }


}


void Image2D::enregistreImage(char* path){

FILE* f = fopen(path, "rb");



unsigned char info3[54];
//    fread(info3, sizeof(unsigned char), 54, fp3);
 for(int iD3=0;iD3<54;iD3++)//the first 54 bytes
    {
        unsigned char* image_and_en_tete_to_save3 = new unsigned char[size];
        image_and_en_tete_to_save3[iD3]=info3[iD3];
        //cout <<iD<<image_and_en_tete_to_save[iD]<<endl;
        //cout <<image_and_en_tete_to_save1[iD1]<<endl;
    }
//    unsigned char info[54];
//    fread(info, sizeof(unsigned char), 54, f); // read the 54-byte header
//    // extract image height and width from header
//    int width = *(int*)&info[18];
//    int height = *(int*)&info[22];
//    int size = 3 * width * height;
//    (*this).nbx=width;
//    (*this).nby=height;
//    (*this).size=width*height;
//    unsigned char* image = new unsigned char[size]; // allocate 3 bytes per pixel
//    unsigned char* imageBLU=new unsigned char[width*height];//definition of the RED
//    unsigned char* imageGRE=new unsigned char[width*height];//definition of the GREEN
//    unsigned char* imageRED=new unsigned char[width*height];//definition of the BLUE
//
//    fread(image,sizeof(unsigned char),size,f);//We fill the FULL image
//    fclose(f);
//
//    for(int id=0;id<(width*height);id++)
//    {
//        imageBLU[id]=image[3*id];
//        imageGRE[id]=image[3*id+1];
//        imageRED[id]=image[3*id+2];
//
//    }
//    (*this).alloue_partie_dynamique(width,height);
//    for (int i=0; i<(*this).nbx; i++) {
//        for (int j=0; j<(*this).nby; j++) {
//            double mean=0;
//            mean=((double)imageRED[i*((*this).nby)+j]+(double)imageBLU[i*((*this).nby)+j]+(double)imageGRE[i*((*this).nby)+j])/3.0;
//                (*this).ptr[i][j]=(int)mean;
//        }
//    }

   // fwrite(&tab, sizeof ptr[0][0],n,fp2);
    fclose(f);
    f=fopen("testtttttttttttt.bmp","wb");
    for (int i=0; i<(*this).nbx; i++) {
        for (int j=0; j<(*this).nby; j++) {
    fwrite(ptr[i][j],sizeof(ptr[i][j]),1,f);// fonction to read binary
    ///Closure
        }
    }
    fclose(f);
}








Image2D::~Image2D()
{
    (*this).libere_partie_dynamique();
}
