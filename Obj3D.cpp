#include "Obj3D.h"
#include <ctype.h>
#include "GraphAdapter.h"

#define RAD 57.29577951

Objeto_3D::Objeto_3D()
{
	color=4;
	Ptos=NULL;
	Lins=NULL;
	CG.x=0;
	CG.y=0;
	CG.z=0;
}
Objeto_3D::~Objeto_3D()
{
	libera(Ptos);
	libera(Lins);
}
void Objeto_3D::FijaPos(double x,double y,double z)
{
	punto3d np;
	List *rec;
	CG.x+=x;
	CG.y+=y;
	CG.z+=z;
	for(rec=Ptos;rec!=NULL;rec=rec->sig)
	{
		rec->pos.x+=x;
		rec->pos.y+=y;
		rec->pos.z+=z;
	}
}
void Objeto_3D::Color(int col)
{
	color=col;
}
int Objeto_3D::LeeArch(char *nom)
{
	List *ini;
	FILE *fp;
	char com;
	punto3d p;
	List *ap1,*ap2;
	float x,y,z;
	int v1,v2,cgl=0;
	fp=fopen(nom,"r");
	if(!fp)
		return 0;
	while(!feof(fp))
	{
		fscanf(fp,"%c",&com);
		if(toupper(com)=='C')
		{
			cgl=1;
			do
			{
				fscanf(fp,"%c",&com);
				if(feof(fp))
					return 0;
			}
			while(com!='(');
			fscanf(fp,"%f",&x);
			do
			{
				fscanf(fp,"%c",&com);
				if(feof(fp))
					return 0;
			}
			while(com!=',');
			fscanf(fp,"%f",&y);
			do
			{
				fscanf(fp,"%c",&com);
				if(feof(fp))
					return 0;
			}
			while(com!=',');
			fscanf(fp,"%f",&z);
			do
			{
				fscanf(fp,"%c",&com);
				if(feof(fp))
					return 0;
			}
			while(com!=')');
			CG.x=x;
			CG.y=y;
			CG.z=z;
		}
		if(toupper(com)=='P')
		{
			do
			{
				fscanf(fp,"%c",&com);
				if(feof(fp))
					return 0;
			}
			while(com!='(');
			fscanf(fp,"%f",&x);
			do
			{
				fscanf(fp,"%c",&com);
				if(feof(fp))
					return 0;
			}
			while(com!=',');
			fscanf(fp,"%f",&y);
			do
			{
				fscanf(fp,"%c",&com);
				if(feof(fp))
					return 0;
			}
			while(com!=',');
			fscanf(fp,"%f",&z);
			do
			{
				fscanf(fp,"%c",&com);
				if(feof(fp))
					return 0;
			}
			while(com!=')');
			p.x=x;
			p.y=y;
			p.z=z;
			Ptos=insList(Ptos,p,color);
		}
		else if(toupper(com)=='L')
		{
			do
			{
				fscanf(fp,"%c",&com);
				if(feof(fp))
					return 0;
			}
			while(com!='(');
			fscanf(fp,"%d",&v1);
			do
			{
				fscanf(fp,"%c",&com);
				if(feof(fp))
					return 0;
			}
			while(com!=',');
			fscanf(fp,"%d",&v2);
			do
			{
				fscanf(fp,"%c",&com);
				if(feof(fp))
					return 0;
			}
			while(com!=')');
			Lins=insList(Lins,v1,v2);
		}
	}
	if(!cgl)
	{
		List *ptos=Ptos;
		int totpto=0;
		for(;ptos!=NULL;ptos=ptos->sig,totpto++)
		{
			CG.x+=ptos->pos.x;
			CG.y+=ptos->pos.y;
			CG.z+=ptos->pos.z;
		}
		CG.x/=totpto;
		CG.y/=totpto;
		CG.z/=totpto;
	}
	fclose(fp);
	return 1;
}
int Objeto_3D::GuardaArch(char *nom)
{
	FILE *fp;
	fp=fopen(nom,"w");
	if(!fp)
		return 0;
	List *ptos=Ptos;
	ListLinea *lins=Lins;
	int totpto=1;
	for(;ptos!=NULL;ptos=ptos->sig,totpto++)
	{
		fprintf(fp,"P%d(%f,%f,%f)\n",totpto,ptos->pos.x,ptos->pos.y,ptos->pos.z);
	}
	for(;lins!=NULL;lins=lins->sig)
	{
		fprintf(fp,"L(%d,%d)\n",lins->pto1,lins->pto2);
	}
	fclose(fp);
	return 1;
}
void Objeto_3D::Dibuja(Sprte &Spr, GraphAdapter &graphAdapter)
{
	punto2d p;
	List *pto1=Ptos;
	List *pto2;
	ListLinea *reclin=Lins;
	int ptos=0;
	for(;pto1!=NULL;pto1=pto1->sig,ptos++)
	{
		Spr.dibPun3d(graphAdapter, pto1->pos,color);
	}
	Spr.dibPun3d(graphAdapter, Ptos->pos, 1);
	for(;reclin!=NULL;reclin=reclin->sig)
	{
		pto1=Avanza(Ptos,reclin->pto1);
		pto2=Avanza(Ptos,reclin->pto2);
		Spr.linea3d(graphAdapter, pto1->pos,pto2->pos,color);
	}
}
void Objeto_3D::cambiaCG(double x,double y,double z)
{
	CG.x=x;
	CG.y=y;
	CG.z=z;
}
void Objeto_3D::RotaXY(double despang)
{
	List *pto1=Ptos;
	double r;
	double ang;
	double dx,dy;
	for(;pto1!=NULL;pto1=pto1->sig)
	{
		dx=pto1->pos.x-CG.x;
		dy=pto1->pos.y-CG.y;
		r=sqrt(dx*dx+dy*dy);
		if(dy==0&&dx==0)
			ang=0;
		else
			ang=atan2(dy,dx);
		ang+=despang/RAD;
		dx=r*cos(ang);
		dy=r*sin(ang);
		pto1->pos.x=CG.x+dx;
		pto1->pos.y=CG.y+dy;
	}
}
void Objeto_3D::RotaXZ(double despang)
{
	List *pto1=Ptos;
	double r;
	double ang;
	double dx,dz;
	for(;pto1!=NULL;pto1=pto1->sig)
	{
		dx=pto1->pos.x-CG.x;
		dz=pto1->pos.z-CG.z;
		r=sqrt(dx*dx+dz*dz);
		if(dz==0&&dx==0)
			ang=0;
		else
			ang=atan2(dz,dx);
		ang+=despang/RAD;
		dx=r*cos(ang);
		dz=r*sin(ang);
		pto1->pos.x=CG.x+dx;
		pto1->pos.z=CG.z+dz;
	}
}
void Objeto_3D::RotaZY(double despang)
{
	List *pto1=Ptos;
	double r;
	double ang;
	double dz,dy;
	for(;pto1!=NULL;pto1=pto1->sig)
	{
		dz=pto1->pos.z-CG.z;
		dy=pto1->pos.y-CG.y;
		r=sqrt(dz*dz+dy*dy);
		if(dy==0&&dz==0)
			ang=0;
		else
			ang=atan2(dy,dz);
		ang+=despang/RAD;
		dz=r*cos(ang);
		dy=r*sin(ang);
		pto1->pos.z=CG.z+dz;
		pto1->pos.y=CG.y+dy;
	}
}
punto3d Objeto_3D::ObjCG()
{
	return CG;
}