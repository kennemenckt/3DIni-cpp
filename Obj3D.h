#ifndef OBJ_3D
#define OBJ_3D

#include "List3D.h"
#include "ListLine.h"
#include "Sprte.h"
#include "GraphAdapter.h"

class Objeto_3D
{
	private:
		int color;
		List *Ptos;
		ListLinea *Lins;
		punto3d CG;  //<---Centro de Gravedad
	public:
		Objeto_3D();
		~Objeto_3D();
		void FijaPos(double x,double y,double z);
		void Color(int col);
		int LeeArch(char *nom);
		int GuardaArch(char *nom);
		void Dibuja(Sprte &Spr, GraphAdapter &graphAdapter);
		void cambiaCG(double x,double y,double z);
		void RotaXY(double despang);
		void RotaXZ(double despang);
		void RotaZY(double despang);
		punto3d ObjCG();
};

#endif