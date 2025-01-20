#include "3D.h"

polar rectAPol(double x, double y)
{
	polar aux;
	if(y==0&&x==0)
		aux.teta=0;
	else
		aux.teta=atan2(y,x);
	aux.r=sqrt(x*x+y*y);
	return aux;
}
void polArect(double *x,double *y, polar pol)
{
	*x=pol.r*sin(pol.teta);
	*y=pol.r*cos(pol.teta);
}
punto3d pto3dIni(double x, double y, double z)
{
	punto3d pto;
	pto.x=x;
	pto.y=y;
	pto.z=z;
	return pto;
}
punto3d rotaxz(punto3d p1,double desp)
{
	polar pol;
	pol=rectAPol(p1.z,p1.x);
	pol.teta+=desp;
	polArect(&p1.x,&p1.z,pol);
	return p1;
}
punto3d rotayz(punto3d p1,double desp)
{
	polar pol;
	pol=rectAPol(p1.z,p1.y);
	pol.teta+=desp;
	polArect(&p1.y,&p1.z,pol);
	return p1;
}
punto3d rotaxy(punto3d p1,double desp)
{
	polar pol;
	pol=rectAPol(p1.x,p1.y);
	pol.teta+=desp;
	polArect(&p1.x,&p1.y,pol);
	return p1;
}
punto3d traslada(punto3d ori, punto3d pto)
{
	pto.x-=ori.x;
	pto.y-=ori.y;
	pto.z-=ori.z;
	return pto;
}
void movx(punto3d *mov, double desp)
{
	mov->x+=desp;
}
void movy(punto3d *mov, double desp)
{
	mov->y+=desp;
}
void movz(punto3d *mov, double desp)
{
	mov->z+=desp;
}
