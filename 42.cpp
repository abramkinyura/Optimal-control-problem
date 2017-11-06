#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int MethodRK(double a1,double a2,double *b1,double *b2);


int main(void)
{
int r;
int N;
double delta=0.01;
printf("Input r\n");
r=scanf("%d",&r);
double beta1=1.0;
double beta2=2.0;
MethodRK(beta1,beta2,
return 0;
}

int MethodRK(double beta1,double beta2,double *beta1new,double *b2new)
{
int i;
double h,k1x1, k1x2, k1p1, k1p2, k2x1, k2x2, k2p1, k2p2, k3x1, k3x2, k3p1, k3p2, k4x1, k4x2, k4p1, k4p2;
double x1=0;
double x2=beta1;
double p1=beta2;
double p2=0;
h=2/(N-1);



for(i=0; i<N; i++){
//Считаем k1x1,k1x2,k1p1,k1p2
k1x1=x2;

if (p2>0)
k1x2=16;
else
k1x2=0;

k1p1=0;

k1p2=-p1-pow((i+h*N),r)*x2/((1+x2*x2)*(1+x2*x2));
//Считаем k2x1,k2x2,k2p1,k2p2
k2x1=x2+(h/2.0)*k1x2;

if(p2>0)
k2x2=16+(h/2.0)*k1p2;
else 
k2x2=(h/2.0)*k1p2;

k2p1=-(h/2.0)*k1x1;
k2p2=-p1-pow((i+h*N),r)*x2/((1+x2*x2)*(1+x2*x2))-(h/2.0)*k1p1;
//Считаем k3x1,k3x2,k3p1,k3p2
k3x1=x2+(h/2.0)*k2x2;

if(p2>0)
k3x2=16+(h/2.0)*k2p2;
else
k3x2=(h/2.0)*k2p2;

k3p1=-(h/2.0)*k2x1;
k3p2=-p1-pow((i+h*N),r)*x2/((1+x2*x2)*(1+x2*x2))-(h/2.0)*k2p1;

//Считаем k4x1,k4x2,k4p1,k4p2;
k4x1=x2+h*k3x2;

if(p2>0)
k4x2=16+h*k3p2;
else 
k4x2=h*k3p2;

k4p1=-h*k3x1;
k4p2=-p1-pow((i+h*N),r)*x2/((1+x2*x2)*(1+x2*x2))-h*k3p1;
x1=x1+(h/6.0)*(k1x1+2*k2x1+2*k3x1+k4x1);
x2=x2+(h/6.0)*(k1x2+2*k2x2+2*k3x2+k4x2);
p1=p1+(h/6.0)*(k1p1+2*k2p1+2*k3p1+k4p1);
p2=p2+(h/6.0)*(k1p2+2*k2p2+2*k3p2+k4p2);
}
*b1=x2;
*b2=p1;

}
