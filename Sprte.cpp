#include "Sprte.h"
#include "Corden.h"
#include <string.h>
#include "GraphAdapter.h"

#define INTER 40.0

punto2d Sprte::_3da2D(punto3d p1)
{
	double teta, phi;
	double x,y;
	punto3d aux;
	x=y=0;
	punto2d ps;
	ps.x=maxx/2;
	ps.y=maxy/2;
		///Calcula la distancia del visor al objeto
	aux=traslada(pos,p1);
		///Rota
	aux=rotaxz(aux,ori*-1);
	aux=rotayz(aux,fre*-1);
			//////Calcula  TETA
	if(aux.z==0&&aux.x==0)
		teta=0;
	else
		teta=atan2(aux.x,aux.z);
		//Ajuste de Angulo a -179�,180�
	if(teta<=(-270)/rad)
		teta+=360/rad;
	if(teta>=270/rad)
		teta-=360/rad;
				//////Calcula PHI
	if(aux.z==0&&aux.y==0)
		phi=0;
	else
		phi=atan2(aux.y,aux.z);
		//Ajuste de Angulo a -179�,180�
	if(phi<=(-270)/rad)
		phi+=360/rad;
	if(phi>=270/rad)
		phi-=360/rad;
				/////Determina Vision
	if(teta<(-1)*v||teta>v)
	{
		ps.x=-1;
		ps.y=-1;
		return ps;
	}
	if(phi<(-1)*v||phi>v)
	{
		ps.x=-1;
		ps.y=-1;
		return ps;
	}
		/////Calcula X y Y en terminos de TETA y PHI
	x=((maxx-minx)/2)*(teta/v);
	y=((maxy-miny)/2)*(phi/v);
		/////Traslada el origen al centro de la pantalla
	ps.x=minx+(maxx-minx)/2+x;
	ps.y=miny+(maxy-miny)/2-y;
	return ps;
}
/*punto2d Sprte::_3da2d(punto3d p1)
{
	double teta, phi;
	double x,y;
	polar pol;
	x=y=0;
	punto2d ps;
	ps.x=maxx/2;
	ps.y=maxy/2;
		///Calcula la distancia del visor al objeto
	p1.x-=pos.x;
	p1.y-=pos.y;
	p1.z-=pos.z;
		///Voltea hacia los lados
	if(p1.z==0)
		pol.teta=90/rad;
	else
		pol.teta=atan(p1.x/p1.z);
	if(p1.z<0&&p1.x<0)
		pol.teta+=180/rad;
	if(p1.z<0&&p1.x>=0)
		pol.teta+=180/rad;
	if(p1.z>=0&&p1.x<0)
		pol.teta+=360/rad;
	pol.r=sqrt(pow(p1.z,2)+pow(p1.x,2));

	pol.teta+=ori*-1;

	p1.x=pol.r*sin(pol.teta);
	p1.z=pol.r*cos(pol.teta);
		////voltea hacia arriba-abajo
	if(p1.z==0)
		pol.teta=90/rad;
	else
		pol.teta=atan(p1.y/p1.z);
	if(p1.z<0&&p1.y<0)
		pol.teta+=180/rad;
	if(p1.z<0&&p1.y>=0)
		pol.teta+=180/rad;
	if(p1.z>=0&&p1.y<0)
		pol.teta+=360/rad;
	pol.r=sqrt(pow(p1.z,2)+pow(p1.y,2));

	pol.teta+=fre*-1;

	p1.y=pol.r*sin(pol.teta);
	p1.z=pol.r*cos(pol.teta);

		//////Calcula  TETA
	if(p1.z==0&&p1.x>0)
		teta=90;
	if(p1.z==0&&p1.x<0)
		teta=-90;
	if(p1.z!=0)
		teta=atan(p1.x/p1.z);
				//Ajuste de cuadrantes
	if(p1.z<0&&p1.x<=0)
		teta-=180/rad;
	if(p1.z<0&&p1.x>0)
		teta+=180/rad;
				//Ajuste de Angulo a -179�,180�
	if(teta<=(-270)/rad)
		teta+=360/rad;
	if(teta>=270/rad)
		teta-=360/rad;
				//////Calcula PHI
	if(p1.z==0&&p1.y>0)
		phi=90;
	if(p1.z==0&&p1.y<0)
		phi=-90;
	if(p1.z!=0)
		phi=atan(p1.y/p1.z);
	if(p1.z<0&&p1.y<=0)
		phi-=180/rad;
	if(p1.z<0&&p1.y>0)
		phi+=180/rad;
	if(phi<=(-270)/rad)
		phi+=360/rad;
	if(phi>=270/rad)
		phi-=360/rad;
				/////Determina Vision
	if(teta<(-1)*v||teta>v)
	{
		ps.x=-1;
		ps.y=-1;
		return ps;
	}
	if(phi<(-1)*v||phi>v)
	{
		ps.x=-1;
		ps.y=-1;
		return ps;
	}
		/////Calcula X y Y en terminos de TETA y PHI
	x=((maxx-minx)/2)*(sin(teta)/sin(v));
	y=((maxy-miny)/2)*(sin(phi)/sin(v));
		/////Traslada el origen al centro de la pantalla
	ps.x=minx+(maxx-minx)/2+x;
	ps.y=miny+(maxy-miny)/2-y;
	return ps;
}*/
punto2d Sprte::_3da2d(punto3d p1)
{
	double teta, phi;
	double x,y;
	polar pol;
	x=y=0;
	punto2d ps;
	ps.x=maxx/2;
	ps.y=maxy/2;
		///Calcula la distancia del visor al objeto
	p1.x-=pos.x;
	p1.y-=pos.y;
	p1.z-=pos.z;
		///Voltea hacia los lados
	if(p1.x==0&&p1.z==0)
		pol.teta=0;
	else
		pol.teta=atan2(p1.x,p1.z);
	pol.r=sqrt((p1.z*p1.z)+(p1.x*p1.x));

	pol.teta+=ori*-1;

	p1.x=pol.r*sin(pol.teta);
	p1.z=pol.r*cos(pol.teta);
		////voltea hacia arriba-abajo
	if(p1.y==0&&p1.z==0)
		pol.teta=0;
	else
		pol.teta=atan2(p1.y,p1.z);
	pol.r=sqrt((p1.z*p1.z)+(p1.y*p1.y));

	pol.teta+=fre*-1;

	p1.y=pol.r*sin(pol.teta);
	p1.z=pol.r*cos(pol.teta);

		//////Calcula  TETA
	if(p1.x==0&&p1.z==0)
		teta=0;
	else
		teta=atan2(p1.x,p1.z);
		//Ajuste de Angulo a -179�,180�
	if(teta<=(-270)/rad)
		teta+=360/rad;
	if(teta>=270/rad)
		teta-=360/rad;
				//////Calcula PHI
	if(p1.y==0&&p1.z==0)
		phi=0;
	else
		phi=atan2(p1.y,p1.z);
			//Ajuste de Angulo a -179�,180�
	if(phi<=(-270)/rad)
		phi+=360/rad;
	if(phi>=270/rad)
		phi-=360/rad;
		/////Determina Vision
	if(teta<=-90/rad||teta>=90/rad)
	{
		ps.x=-1;
		ps.y=-1;
		return ps;
	}
	if(phi<=-90/rad||phi>=90/rad)
	{
		ps.x=-1;
		ps.y=-1;
		return ps;
	}
		/////Calcula X y Y en terminos de TETA y PHI
	x=((maxx-minx)/2)*(teta/v);
	y=((maxy-miny)/2)*(phi/v);
		/////Traslada el origen al centro de la pantalla
	ps.x=minx+(maxx-minx)/2+x;
	ps.y=miny+(maxy-miny)/2-y;
	return ps;
}
void Sprte::dibPun3dxy(punto3d pto1, int color,double esc)
{
	// int i;
	// punto3d pto2[4];
	// punto2d pto[4];
	// esc/=10;
	// pto2[0]=pto3dIni(pto1.x,pto1.y,pto1.z);
	// pto2[1]=pto3dIni(pto1.x,pto1.y+esc,pto1.z);
	// pto2[2]=pto3dIni(pto1.x+esc,pto1.y,pto1.z);
	// pto2[3]=pto3dIni(pto1.x+esc,pto1.y+esc,pto1.z);
	// for(i=0;i<4;i++)
	// {
	// 	pto[i]=_3da2d(pto2[i]);
	// 	if(pto[i].x==-1)
	// 		return;
	// }
	// setcolor(color);
	// line(pto[0].x,pto[0].y,pto[1].x,pto[1].y);
	// line(pto[0].x,pto[0].y,pto[2].x,pto[2].y);
	// line(pto[1].x,pto[1].y,pto[3].x,pto[3].y);
	// line(pto[2].x,pto[2].y,pto[3].x,pto[3].y);
	// if(pto[0].x!=pto[3].x&&pto[0].y!=pto[3].y)
	// {
	// 	setfillstyle(SOLID_FILL,color);
	// 	floodfill((pto[0].x+pto[3].x)/2,(pto[0].y+pto[3].y)/2,color);
	// }
}
void Sprte::dibPun3dxz(punto3d pto1, int color,double esc)
{
	// int i;
	// punto3d pto2[4];
	// punto2d pto[4];
	// esc/=10;
	// pto2[0]=pto3dIni(pto1.x,pto1.y,pto1.z);
	// pto2[1]=pto3dIni(pto1.x,pto1.y,pto1.z+esc);
	// pto2[2]=pto3dIni(pto1.x+esc,pto1.y,pto1.z);
	// pto2[3]=pto3dIni(pto1.x+esc,pto1.y,pto1.z+esc);
	// for(i=0;i<4;i++)
	// {
	// 	pto[i]=_3da2d(pto2[i]);
	// 	if(pto[i].x==-1)
	// 		return;
	// }
	// setcolor(color);
	// line(pto[0].x,pto[0].y,pto[1].x,pto[1].y);
	// line(pto[0].x,pto[0].y,pto[2].x,pto[2].y);
	// line(pto[1].x,pto[1].y,pto[3].x,pto[3].y);
	// line(pto[2].x,pto[2].y,pto[3].x,pto[3].y);
	// if(pto[0].x!=pto[3].x&&pto[0].y!=pto[3].y)
	// {
	// 	setfillstyle(SOLID_FILL,color);
	// 	floodfill((pto[0].x+pto[3].x)/2,(pto[0].y+pto[3].y)/2,color);
	// }
}
void Sprte::dibPun3dyz(punto3d pto1, int color,double esc)
{
	// int i;
	// punto3d pto2[4];
	// punto2d pto[4];
	// esc/=10;
	// pto2[0]=pto3dIni(pto1.x,pto1.y,pto1.z);
	// pto2[1]=pto3dIni(pto1.x,pto1.y,pto1.z+esc);
	// pto2[2]=pto3dIni(pto1.x,pto1.y+esc,pto1.z);
	// pto2[3]=pto3dIni(pto1.x,pto1.y+esc,pto1.z+esc);
	// for(i=0;i<4;i++)
	// {
	// 	pto[i]=_3da2d(pto2[i]);
	// 	if(pto[i].x==-1)
	// 		return;
	// }
	// setcolor(color);
	// line(pto[0].x,pto[0].y,pto[1].x,pto[1].y);
	// line(pto[0].x,pto[0].y,pto[2].x,pto[2].y);
	// line(pto[1].x,pto[1].y,pto[3].x,pto[3].y);
	// line(pto[2].x,pto[2].y,pto[3].x,pto[3].y);
	// if(pto[0].x!=pto[3].x&&pto[0].y!=pto[3].y,color)
	// {
	// 	setfillstyle(SOLID_FILL,color);
	// 	floodfill((pto[0].x+pto[3].x)/2,(pto[0].y+pto[3].y)/2,color);
	// }
}
void Sprte::zomfa3dxy(const char * nom, punto3d p, int esc)
{
	FILE *fp;
	double inc=0.1;
	punto3d p1;
	p1.x=p.x;                                //  * ������
	p1.y=p.y;                                //  | ������
	p1.z=p.z;                                //  |_____ *
	struct corden tam;
	double x, y;
	int color;
	double px, py;
	px=0;
	py=0;
	char c;
	tam.x=0;
	tam.y=0;
	if(!(fp=fopen(nom,"r")))
		return;

	fscanf(fp,"%d %d",&tam.y, &tam.x);
	p.y=(tam.y-1)*inc*esc+p.y;
	for(y=0;y<tam.y;y++)
	{
		  fscanf(fp,"%c",&c);
		  for(x=0;x<tam.x;x++)
		  {
			 fscanf(fp,"%c",&c);
			 if(c<58)
			color=c-'0';
			 else
			if(c!='X')
				color=c-55;
			 px=x*esc;
			 py=y*esc;
			 p1.x=p.x+px*inc;
			 p1.y=p.y-py*inc;
			 if(c!='X')
			dibPun3dxy(p1,color,esc);
		  }
	}
	fclose(fp);
	return;
}
void Sprte::zomfa3dxz(const char * nom, punto3d p, int esc)
{
	FILE *fp;
	double inc=0.1;
	punto3d p1;
	p1.x=p.x;
	p1.y=p.y;
	p1.z=p.z;
	struct corden tam;
	double x, y;
	int color;
	double px, py;
	px=0;
	py=0;
	char c;
	tam.x=0;
	tam.y=0;
	if(!(fp=fopen(nom,"r")))
		return;

	fscanf(fp,"%d %d",&tam.y, &tam.x);
	p.y=(tam.y-1)*inc*esc+p.y;
	for(y=0;y<tam.y;y++)
	{
		  fscanf(fp,"%c",&c);
		  for(x=0;x<tam.x;x++)
		  {
			 fscanf(fp,"%c",&c);
			 if(c<58)
			color=c-'0';
			 else
			if(c!='X')
				color=c-55;
			 px=x*esc;
			 py=y*esc;
			 p1.x=p.x+px*inc;
			 p1.z=p.z+py*inc;
			 if(c!='X')
			dibPun3dxz(p1,color,esc);
		  }
	}
	fclose(fp);
	return;
}
void Sprte::zomfa3dyz(const char * nom, punto3d p, int esc)
{
	FILE *fp;
	double inc=0.1;
	punto3d p1;
	p1.x=p.x;
	p1.y=p.y;
	p1.z=p.z;
	struct corden tam;
	double x, y;
	int color;
	double px, py;
	px=0;
	py=0;
	char c;
	tam.x=0;
	tam.y=0;
	if(!(fp=fopen(nom,"r")))
		return;

	fscanf(fp,"%d %d",&tam.y, &tam.x);
	p.y=(tam.y-1)*inc*esc+p.y;
	for(y=0;y<tam.y;y++)
	{
		  fscanf(fp,"%c",&c);
		  for(x=0;x<tam.x;x++)
		  {
			 fscanf(fp,"%c",&c);
			 if(c<58)
			color=c-'0';
			 else
			if(c!='X')
				color=c-55;
			 px=x*esc;
			 py=y*esc;
			 p1.z=p.z+px*inc;
			 p1.y=p.y-py*inc;
			 if(c!='X')
			dibPun3dyz(p1,color,esc);
		  }
	}
	fclose(fp);
	return;
}

void Sprte::linea3dOld(GraphAdapter &graphAdapter, punto3d p1, punto3d p2, int color)
{
	punto3d aux;
	punto2d res;
	punto2d acum;
	graphAdapter.setColor(color);
	res=_3da2d(p1);
	acum=_3da2d(p2);
	//////////////////Linea_Completa_Visible//////////
	if(acum.x!=-1&&acum.y!=-1&&res.x!=-1&&res.y!=-1)
	{
		graphAdapter.drawLine(acum.x,acum.y,res.x,res.y);
		return;
	}
	/////////////////Linea_Completa_Invisible/////////
	if(acum.x==-1&&acum.y==-1&&res.x==-1&&res.y==-1)
	{
		return;
	}
}

void Sprte::linea3d(GraphAdapter &graphAdapter, punto3d p1, punto3d p2, int color)
{
	punto3d aux;
	punto2d res;
	punto2d acum;
	graphAdapter.setColor(color);
	res=_3da2d(p1);
	acum=_3da2d(p2);
	//////////////////Linea_Completa_Visible//////////
	if(acum.x!=-1&&acum.y!=-1&&res.x!=-1&&res.y!=-1)
	{
		graphAdapter.drawLine(acum.x,acum.y,res.x,res.y);
		return;
	}
	/////////////////Linea_Completa_Invisible/////////
	if(acum.x==-1&&acum.y==-1&&res.x==-1&&res.y==-1)
	{
		return;
	}
	/////////////Linea_Algoritmo///////
	float fact;
	if(p2.y>p1.y)
	{
		fact=(p2.y-p1.y)/INTER;
		acum=_3da2d(p1);
		for(aux.y=p1.y;aux.y<=p2.y;aux.y+=fact)
		{
			aux.x=p2.x-((p2.x-p1.x)/(p2.y-p1.y))*(p2.y-aux.y);
			aux.z=p2.z-((p2.z-p1.z)/(p2.y-p1.y))*(p2.y-aux.y);
			res=_3da2d(aux);
			if(acum.x!=-1&&res.x!=-1)
				graphAdapter.drawLine(acum.x,acum.y,res.x,res.y);
			acum=res;
		}
		return;
	}
	if(p2.y<p1.y)
	{
		fact=(p2.y-p1.y)/INTER;
		acum=_3da2d(p1);
		for(aux.y=p1.y;aux.y>=p2.y;aux.y+=fact)
		{
			aux.x=p2.x-((p2.x-p1.x)/(p2.y-p1.y))*(p2.y-aux.y);
			aux.z=p2.z-((p2.z-p1.z)/(p2.y-p1.y))*(p2.y-aux.y);
			res=_3da2d(aux);
			if(acum.x!=-1&&res.x!=-1)
				graphAdapter.drawLine(acum.x,acum.y,res.x,res.y);
			acum=res;
		}
		return;
	}
	if(p2.x>p1.x)
	{
		fact=(p2.x-p1.x)/INTER;
		acum=_3da2d(p1);
		for(aux.x=p1.x;aux.x<=p2.x;aux.x+=fact)
		{
			aux.y=p2.y-((p2.y-p1.y)/(p2.x-p1.x))*(p2.x-aux.x);
			aux.z=p2.z-((p2.z-p1.z)/(p2.x-p1.x))*(p2.x-aux.x);
			res=_3da2d(aux);
			if(acum.x!=-1&&res.x!=-1)
				graphAdapter.drawLine(acum.x,acum.y,res.x,res.y);
			acum=res;
		}
		return;
	}
	if(p2.x<p1.x)
	{
		fact=(p2.x-p1.x)/INTER;
		acum=_3da2d(p1);
		for(aux.x=p1.x;aux.x>=p2.x;aux.x+=fact)
		{
			aux.y=p2.y-((p2.y-p1.y)/(p2.x-p1.x))*(p2.x-aux.x);
			aux.z=p2.z-((p2.z-p1.z)/(p2.x-p1.x))*(p2.x-aux.x);
			res=_3da2d(aux);
			if(acum.x!=-1&&res.x!=-1)
				graphAdapter.drawLine(acum.x,acum.y,res.x,res.y);
			acum=res;
		}
		return;
	}
	if(p2.z>p1.z)
	{
		fact=(p2.z-p1.z)/INTER;
		acum=_3da2d(p1);
		for(aux.z=p1.z;aux.z<=p2.z;aux.z+=fact)
		{
			aux.y=p2.y-((p2.y-p1.y)/(p2.z-p1.z))*(p2.z-aux.z);
			aux.x=p2.x-((p2.x-p1.x)/(p2.z-p1.z))*(p2.z-aux.z);
			res=_3da2d(aux);
			if(acum.x!=-1&&res.x!=-1)
				graphAdapter.drawLine(acum.x,acum.y,res.x,res.y);
			acum=res;
		}
		return;
	}
	if(p2.z<p1.z)
	{
		fact=(p2.z-p1.z)/INTER;
		acum=_3da2d(p1);
		for(aux.z=p1.z;aux.z>=p2.z;aux.z+=fact)
		{
			aux.y=p2.y-((p2.y-p1.y)/(p2.z-p1.z))*(p2.z-aux.z);
			aux.x=p2.x-((p2.x-p1.x)/(p2.z-p1.z))*(p2.z-aux.z);
			res=_3da2d(aux);
			if(acum.x!=-1&&res.x!=-1)
				graphAdapter.drawLine(acum.x,acum.y,res.x,res.y);
			acum=res;
		}
		return;
	}
}
void Sprte::incVision(int desp)
{
	v+=desp/rad;
	if(v<=0)
		v=1/rad;
	if(v>90/rad)
		v=90/rad;
}
void Sprte::incOri(int desp)
{
	if(fre<-90/rad||fre>90/rad)
		ori-=desp/rad;
	else
		ori+=desp/rad;
	if(ori<(-179)/rad)
		ori+=360/rad;
	else if(ori>179/rad)
		ori-=360/rad;
}
void Sprte::incFre(int desp)
{
	fre+=desp/rad;
	if(fre<(-179)/rad)
		fre+=360/rad;
	else if(fre>179/rad)
		fre-=360/rad;
}
int Sprte::sprteIni(double x, double y, double z, double vi, double orin, double fr, double x1, double y1, double x2, double y2)
{
	pos.x=x;
	pos.y=y;
	pos.z=z;
	v=vi/rad;
	ori=orin/rad;
	fre=fr/rad;
	minx=x1;
	miny=y1;
	maxx=x2;
	maxy=y2;
	return 1;
}
void Sprte::movYSprte(double desp)
{
	pos.y+=desp;
}
void Sprte::movArrSprte(double desp)
{
	pos.y+=desp*sin(fre+90/rad);
	desp*=cos(fre+90/rad);
	movFrenteSprte(desp);
}
void Sprte::movFrenteSprte(double desp)
{
	pos.x+=desp*sin(ori);
	pos.z+=desp*cos(ori);
}
void Sprte::movLadoSprte(double desp)
{
	pos.x+=desp*sin(ori+90/rad);
	pos.z+=desp*cos(ori+90/rad);
}
void Sprte::movFrnArrSprte(double desp)
{
	pos.y+=desp*sin(fre);
	desp*=cos(fre);
	movFrenteSprte(desp);
}
void Sprte::impDat(GraphAdapter &graphAdapter)
{
	char cad[80];
	sprintf(cad,"x:%3.1f y:%3.1f z:%3.1f V:%3.1f Or:%3.1f Fr:%3.1f",pos.x,pos.y,pos.z,v*rad,ori*rad,fre*rad);
	graphAdapter.setColor(1);
	graphAdapter.drawText(minx,maxy-1,cad);
}
void Sprte::drawFloor(GraphAdapter &graphAdapter) {
	int floorSize = 100;
	int floorSection = floorSize / 2;
	for (int z = pos.z - floorSection; z <= pos.z + floorSection; z++)
	{
		for (int x = pos.x - floorSection; x <= pos.x + floorSection; x++)
		{
			punto3d p3d;
			p3d.x = x;
			p3d.y = 0;
			p3d.z = z;
			this->dibPun3d(graphAdapter, p3d, 1);
		}
	}
}
void Sprte::drawFloor2(GraphAdapter &graphAdapter) {
	int floorSize = 500;
	int floorSection = floorSize / 2;
	for (int z = floorSection * -1; z <= floorSection; z+=5)
	{
		for (int x = floorSection * -1; x <= floorSection; x+=5)
		{
			punto3d p3d;
			p3d.x = x;
			p3d.y = 0;
			p3d.z = z;
			this->dibPun3d(graphAdapter, p3d, 1);
		}
	}
}
punto3d Sprte::posSprte()
{
	return pos;
}
void Sprte::dibPun3d(GraphAdapter &graphAdapter, punto3d pto, int col)
{
	punto2d pto2;
	pto2=_3da2d(pto);
	graphAdapter.setColor(col);
	graphAdapter.drawPoint(pto2.x,pto2.y);
}
void Sprte::ponPosSprte(punto3d pos)
{
	this->pos=pos;
}