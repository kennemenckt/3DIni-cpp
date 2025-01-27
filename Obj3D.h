#ifndef OBJ_3D
#define OBJ_3D

#include "FaceList.h"
#include "Sprte.h"
#include "GraphAdapter.h"

class Objeto_3D
{
	private:
		int color;
		FaceList faces;
		punto3d CG;  //<---Gravity Center
	public:
		Objeto_3D();
		~Objeto_3D();
		void FijaPos(double x,double y,double z);
		void setColor(int col);
		int readFileOBJ(char *nom);
		int GuardaArch(char *nom);
		void Dibuja(Sprte &Spr, GraphAdapter &graphAdapter);
		void cambiaCG(double x,double y,double z);
		void RotaXY(double despang);
		void RotaXZ(double despang);
		void RotaZY(double despang);
		punto3d ObjCG();
};

#endif