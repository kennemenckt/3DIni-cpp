#ifndef sprte_h
#define sprte_h

#include "3D.h"
#include "GraphAdapter.h"

class Sprte
{
	private:
		punto3d pos;
		double v;
		double ori;
		double fre;
		double minx,miny,maxx,maxy;
	public:
		punto2d _3da2d(punto3d p1);
		punto2d _3da2D(punto3d p1);
		void dibPun3d(GraphAdapter &graphAdapter, punto3d pto, int col);
		void dibPun3dxy(punto3d pto1, int color,double esc);
		void dibPun3dxz(punto3d pto1, int color,double esc);
		void dibPun3dyz(punto3d pto1, int color,double esc);
		void zomfa3dxy(const char * nom, punto3d p, int esc);
		void zomfa3dxz(const char * nom, punto3d p, int esc);
		void zomfa3dyz(const char * nom, punto3d p, int esc);
		void linea3d(GraphAdapter &graphAdapter, punto3d p1, punto3d p2, int color);
		void linea3dOld(GraphAdapter &graphAdapter, punto3d p1, punto3d p2, int color);
		void incVision(int desp);
		void incOri(int desp);
		void incFre(int desp);
		int sprteIni(double x, double y, double z, double v, double orin, double fr, double x1,double y1,double x2,double y2);
		void movArrSprte(double desp);
		void movYSprte(double desp);
		void movLadoSprte(double desp);
		void movFrenteSprte(double desp);
		void movFrnArrSprte(double desp);
		void impDat(GraphAdapter &graphAdapter);
		punto3d posSprte();
		void ponPosSprte(punto3d pos);
		void increaseSpeed(int inc);
		void decreaseSpeed(int dec);
};
#endif