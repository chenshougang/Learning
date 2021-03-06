// NOTE: compile with g++ filename.cpp -std=c++11

#include <iostream>
#include <cmath>
#include <cstdlib>
#define DIM 1024
#define DM1 (DIM-1)
#define _sq(x) ((x)*(x)) // square
#define _cb(x) abs((x)*(x)*(x)) // absolute value of cube
#define _cr(x) (unsigned char)(pow((x),1.0/3.0)) // cube root

unsigned char GR(int,int);
unsigned char BL(int,int);
unsigned char RD(int,int);

// unsigned char RD(int i,int j){
//   double a=0,b=0,d,n=0;
//   for(;a*a+(d=b*b)<4&&n++<8192;b=2*a*b+j/5e4+.06,a=a*a-d+i/5e4+.34);
//   return n/4;
// }
// unsigned char GR(int i,int j){
//   return 2*RD(i,j);
// }
// unsigned char BL(int i,int j){
//   return 4*RD(i,j);
// }


// unsigned char RD(int i,int j){
//     float s=3./(j+99);
//     return (int((i+DIM)*s+j*s)%2+int((DIM*2-i)*s+j*s)%2)*127;
// }
// unsigned char GR(int i,int j){
//     float s=3./(j+99);
//     return (int((i+DIM)*s+j*s)%2+int((DIM*2-i)*s+j*s)%2)*127;
// }
// unsigned char BL(int i,int j){
//     float s=3./(j+99);
//     return (int((i+DIM)*s+j*s)%2+int((DIM*2-i)*s+j*s)%2)*127;
// }

// unsigned char RD(int i,int j){
//     float s=3./(j+99);
//     float y=(j+sin((i*i+_sq(j-700)*5)/100./DIM)*35)*s;
//     return (int((i+DIM)*s+y)%2+int((DIM*2-i)*s+y)%2)*127;
// }
// unsigned char GR(int i,int j){
//     float s=3./(j+99);
//     float y=(j+sin((i*i+_sq(j-700)*5)/100./DIM)*35)*s;
//     return (int((i+DIM)*s+y)%2+int((DIM*2-i)*s+y)%2)*127;
// }
// unsigned char BL(int i,int j){
//     float s=3./(j+99);
//     float y=(j+sin((i*i+_sq(j-700)*5)/100./DIM)*35)*s;
//     return (int((i+DIM)*s+y)%2+int((DIM*2-i)*s+y)%2)*127;
// }


unsigned char RD(int i,int j){
    return(sqrt(_sq(73.-i)+_sq(609-j))+1)/(sqrt(abs(sin((sqrt(_sq(860.-i)+_sq(162-j)))/115.0)))+1)/200;
}
unsigned char GR(int i,int j){
    return(sqrt(_sq(160.-i)+_sq(60-j))+1)/(sqrt(abs(sin((sqrt(_sq(86.-i)+_sq(860-j)))/115.0)))+1)/200;
}
unsigned char BL(int i,int j){
    return(sqrt(_sq(844.-i)+_sq(200-j))+1)/(sqrt(abs(sin((sqrt(_sq(250.-i)+_sq(20-j)))/115.0)))+1)/200;
}

void pixel_write(int,int);
FILE *fp;
int main(){
fp = fopen("MathPic.ppm","wb");
fprintf(fp, "P6\n%d %d\n255\n", DIM, DIM);
for(int j=0;j<DIM;j++)
for(int i=0;i<DIM;i++)
pixel_write(i,j);
fclose(fp);
return 0;
}
void pixel_write(int i, int j){
static unsigned char color[3];
color[0] = RD(i,j)&255;
color[1] = GR(i,j)&255;
color[2] = BL(i,j)&255;
fwrite(color, 1, 3, fp);
}