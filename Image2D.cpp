//
//  Image2D.cpp
//  TP1C++
//
//  Created by Gustavo Guerrero on 15/09/2019.
//  Copyright © 2019 Gustavo Guerrero. All rights reserved.
//

#include "Image2D.hpp"

using namespace std;

void enregistrer_image(string filename, Image2D image);

//CONSTRUCTION
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

//SETTER - GETTER
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

Image2D::~Image2D()
{
    (*this).libere_partie_dynamique();
}

// interpolation au plus proche voisin
bool Image2D::pixel_is_in_image(int x,int y){ 
    if(ptr[x][y]!= NULL){
        return true;
    }
    else {
        return false;
    }
}

int Image2D::interpolation_nn_x(float x){       
    int pos_x = static_cast<int>(ceil(x/dx));
    if (pixel_is_in_image(pos_x,0)){
        return pos_x;
    }
    else{
        return NULL;
    }
}
int Image2D::interpolation_nn_y(float y){       
    int pos_y = static_cast<int>(ceil(y/dy));
    if (pixel_is_in_image(0,pos_y)){
        return pos_y;
    }
    else{
        return NULL;
    }
}

//Rotation de l'image
void Image2D::rotation (float theta, char* filename){
    Image2D newImage(filename,1,1);
    long pixels = newImage.getSize();

    double radians = (theta * M_PI) / 180;
    int sinf = (int) sin(radians);
    int cosf = (int) cos(radians);

    double x0 = 0.5 * (newImage.getNbx() - 1);     // point to rotate about
    double y0 = 0.5 * (newImage.getNby() - 1);     // center of image

    // rotation
    for (int x = 0; x < newImage.getNbx(); x++) {
        for (int y = 0; y < newImage.getNby(); y++) {
            long double a = x - x0;
            long double b = y - y0;
            int xx = (int) (+a * cosf - b * sinf + x0);
            int yy = (int) (+a * sinf + b * cosf + y0);

            if(xx>=0 && newImage.getNby() && yy>=0 && yy < newImage.getNby()){ 
                newImage.setPixelValue(x,y,(yy*newImage.getNby()+xx));
            } 
        }
    }
    string new_filename = filename;
    new_filename = "rotated_" + new_filename;
    enregistrer_image(new_filename , newImage);
    cout << "Rotation = no error";
}

//FONCTION EN LOCAL - Enregistrer image
void enregistrer_image(string filename, Image2D image){
    string fileName = "new_" + filename;
    FILE *out = fopen(fileName.c_str(), "wb");

    int i;
    unsigned char tmp;
    unsigned char* image_and_en_tete_to_save = new unsigned char[image.getSize()];

    /*for (i = 0; i < image.getSize(); i += 3) {
        tmp = image_and_en_tete_to_save[i];
        image_and_en_tete_to_save[i] = image_and_en_tete_to_save[i + 2];
        image_and_en_tete_to_save[i + 2] = tmp;
    }*/
    for (int i=0; i<image.getNbx(); i++) {
        for (int j=0; j<image.getNby(); j++) {
            image_and_en_tete_to_save[54+(i*(image.getNby())+j)*3]=(unsigned char)image.getPixelValue(i,j);
            image_and_en_tete_to_save[54+1+(i*(image.getNby())+j)*3]=(unsigned char)image.getPixelValue(i,j);
            image_and_en_tete_to_save[54+2+(i*(image.getNby())+j)*3]=(unsigned char)image.getPixelValue(i,j);
        }
    }
    cout << "\nl'entête de l'image est : " << image_and_en_tete_to_save;
    fwrite(image_and_en_tete_to_save, sizeof(unsigned char), image.getSize(), out); // read the rest of the data at once
    fclose(out);
}

/*Image2D rotation(float theta)
{

}*/