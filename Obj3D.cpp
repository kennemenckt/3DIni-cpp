#include "Obj3D.h"
#include <ctype.h>
#include "GraphAdapter.h"

#define RAD 57.29577951

Objeto_3D::Objeto_3D()
{
	color=4;
	CG.x=0;
	CG.y=0;
	CG.z=0;
}
Objeto_3D::~Objeto_3D()
{
	faces.freeMem();
}
void Objeto_3D::FijaPos(double x,double y,double z)
{
	FaceNode *face = faces.getFaceListPointer();
	VertexNode *vertex;
	CG.x+=x;
	CG.y+=y;
	CG.z+=z;
	for (; face != NULL; face = face->next)
	{
		vertex = face->vertexes.getVertexListPointer();
		for (; vertex != NULL; vertex = vertex->next)
		{
			vertex->vertex.x += x;
			vertex->vertex.y += y;
			vertex->vertex.z += z;
		}
	}	
}
void Objeto_3D::setColor(int col)
{
	color=col;
}
int Objeto_3D::readFileOBJ(char *nom)
{
	VertexList vertexList;
	FILE *fp;
	char com;
	punto3d p;
	float x,y,z;
	int vertexIndex,cgl=0;
	fp=fopen(nom,"r");
	if(!fp)
		return 0;
	while(!feof(fp))
	{
		fscanf(fp,"%c",&com);
		// Skip comments and unknown lines
		if(toupper(com)!='C' && toupper(com)!='V' && toupper(com)!='F') {
			do
			{
				fscanf(fp,"%c",&com);
				if(feof(fp))
					return 1;
			}
			while(com!='\n');
		}
		// Read gravity center if present
		if(toupper(com)=='C')
		{
			cgl=1;
			do
			{
				fscanf(fp,"%c",&com);
				if(feof(fp))
					return 0;
			}
			while(com!=' ');
			fscanf(fp,"%f",&x);
			do
			{
				fscanf(fp,"%c",&com);
				if(feof(fp))
					return 0;
			}
			while(com!=' ');
			fscanf(fp,"%f",&y);
			do
			{
				fscanf(fp,"%c",&com);
				if(feof(fp))
					return 0;
			}
			while(com!=' ');
			fscanf(fp,"%f",&z);
			CG.x=x;
			CG.y=y;
			CG.z=z;
		}
		// Read vertex
		if(toupper(com)=='V')
		{
			do
			{
				fscanf(fp,"%c",&com);
				if(feof(fp))
					return 0;
			}
			while(com!=' ');
			fscanf(fp,"%f",&x);
			do
			{
				fscanf(fp,"%c",&com);
				if(feof(fp))
					return 0;
			}
			while(com!=' ');
			fscanf(fp,"%f",&y);
			do
			{
				fscanf(fp,"%c",&com);
				if(feof(fp))
					return 0;
			}
			while(com!=' ');
			fscanf(fp,"%f",&z);
			p.x=x;
			p.y=y;
			p.z=z;
			vertexList.add(p);
		}
		// Read face
		if(toupper(com)=='F')
		{
			faces.createFace();
			do {
				do
				{
					fscanf(fp,"%c",&com);
					if(feof(fp))
						return 1;
				}
				while(com!=' ' && com!='\n');
				if (com != '\n')
				{
					fscanf(fp,"%d",&vertexIndex);
					faces.addVertex(vertexList.get(vertexIndex));
				}
			}
			while(com != '\n');
		}
	}
	// Calculate gravity center if not present
	if(!cgl)
	{
		VertexNode *vertexNode = vertexList.getVertexListPointer();
		int totpto=0;
		for(;vertexNode!=NULL;vertexNode=vertexNode->next,totpto++)
		{
			CG.x+=vertexNode->vertex.x;
			CG.y+=vertexNode->vertex.y;
			CG.z+=vertexNode->vertex.z;
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
	// FILE *fp;
	// fp=fopen(nom,"w");
	// if(!fp)
	// 	return 0;
	// List *ptos=Ptos;
	// ListLinea *lins=Lins;
	// int totpto=1;
	// for(;ptos!=NULL;ptos=ptos->sig,totpto++)
	// {
	// 	fprintf(fp,"P%d(%f,%f,%f)\n",totpto,ptos->pos.x,ptos->pos.y,ptos->pos.z);
	// }
	// for(;lins!=NULL;lins=lins->sig)
	// {
	// 	fprintf(fp,"L(%d,%d)\n",lins->pto1,lins->pto2);
	// }
	// fclose(fp);
	return 1;
}
void Objeto_3D::Dibuja(Sprte &Spr, GraphAdapter &graphAdapter)
{
	punto2d p;

	FaceNode *faceNode = faces.getFaceListPointer();
	VertexNode *vertexNode;
	VertexNode *firstVertexNode;
	for (; faceNode != NULL; faceNode = faceNode->next)
	{
		vertexNode = faceNode->vertexes.getVertexListPointer();
		firstVertexNode = vertexNode;
		for (; vertexNode != NULL && vertexNode->next != NULL; vertexNode = vertexNode->next)
		{
			Spr.linea3d(graphAdapter, vertexNode->vertex,vertexNode->next->vertex,color);
		}
		Spr.linea3d(graphAdapter, vertexNode->vertex,firstVertexNode->vertex,color);
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
	// List *pto1=Ptos;
	// double r;
	// double ang;
	// double dx,dy;
	// for(;pto1!=NULL;pto1=pto1->sig)
	// {
	// 	dx=pto1->pos.x-CG.x;
	// 	dy=pto1->pos.y-CG.y;
	// 	r=sqrt(dx*dx+dy*dy);
	// 	if(dy==0&&dx==0)
	// 		ang=0;
	// 	else
	// 		ang=atan2(dy,dx);
	// 	ang+=despang/RAD;
	// 	dx=r*cos(ang);
	// 	dy=r*sin(ang);
	// 	pto1->pos.x=CG.x+dx;
	// 	pto1->pos.y=CG.y+dy;
	// }
}
void Objeto_3D::RotaXZ(double despang)
{
	// List *pto1=Ptos;
	// double r;
	// double ang;
	// double dx,dz;
	// for(;pto1!=NULL;pto1=pto1->sig)
	// {
	// 	dx=pto1->pos.x-CG.x;
	// 	dz=pto1->pos.z-CG.z;
	// 	r=sqrt(dx*dx+dz*dz);
	// 	if(dz==0&&dx==0)
	// 		ang=0;
	// 	else
	// 		ang=atan2(dz,dx);
	// 	ang+=despang/RAD;
	// 	dx=r*cos(ang);
	// 	dz=r*sin(ang);
	// 	pto1->pos.x=CG.x+dx;
	// 	pto1->pos.z=CG.z+dz;
	// }
}
void Objeto_3D::RotaZY(double despang)
{
	// List *pto1=Ptos;
	// double r;
	// double ang;
	// double dz,dy;
	// for(;pto1!=NULL;pto1=pto1->sig)
	// {
	// 	dz=pto1->pos.z-CG.z;
	// 	dy=pto1->pos.y-CG.y;
	// 	r=sqrt(dz*dz+dy*dy);
	// 	if(dy==0&&dz==0)
	// 		ang=0;
	// 	else
	// 		ang=atan2(dy,dz);
	// 	ang+=despang/RAD;
	// 	dz=r*cos(ang);
	// 	dy=r*sin(ang);
	// 	pto1->pos.z=CG.z+dz;
	// 	pto1->pos.y=CG.y+dy;
	// }
}
punto3d Objeto_3D::ObjCG()
{
	return CG;
}