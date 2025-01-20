#ifndef D3_H
#define D3_H

#include <math.h>
#include <stdio.h>

#define rad 57.29577951

struct punto3d
{
	double x,y,z;
};
struct punto2d
{
	double x,y;
};
struct polar
{
	double r,teta;
};
polar rectAPol(double x, double y);
void polArect(double *x,double *y, polar pol);
punto3d pto3dIni(double x, double y, double z);
punto3d rotaxz(punto3d p1,double desp);
punto3d rotayz(punto3d p1,double desp);
punto3d rotaxy(punto3d p1,double desp);
punto3d traslada(punto3d ori, punto3d pto);
void movx(punto3d *mov, double desp);
void movy(punto3d *mov, double desp);
void movz(punto3d *mov, double desp);

#endif