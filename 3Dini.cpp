#include "Sprte.h"
#include "Obj3D.h"
#include "GraphAdapter.h"
#include "KeyboardAdapter.h"

void linea(Sprte *spr, int sprs,char *cad, int ve, GraphAdapter &graphAdapter);
void Datos(Sprte *spr,int numspr, GraphAdapter &graphAdapter);
void Objeto(Sprte *spr, int numspr, Objeto_3D &obj, GraphAdapter &graphAdapter);

int main(int numpars, char **params)
{
	int movementSpeed = 1;
	int angleSpeed = 2;
	char cad[80];
	cad[0]='\0';
	int numsprs=1;
	if(numpars==1)
	{
		printf("Usage:");
		printf("\n\n3dini ARCHOBJ.3DO [ PERSPECTIVES ]");
		printf("\n\n[] = Optional");
		printf("\n\nPERSPECTIVES:");
		printf("\n\tNot specified......Front");
		printf("\n\t2..................Front and back");
		exit(0);
	}
	else
	{
		if(numpars==3)
		{
			if(params[2][0]=='2')
				numsprs=2;
		}
	}
	printf("\nNavigation keys:");
	printf("\n\t\tR.......Forward");
	printf("\n\t\tF.......Backward");
	printf("\n\t\tW.......Turn Up");
	printf("\n\t\tS.......Turn Down");
	printf("\n\t\tA.......Turn Left");
	printf("\n\t\tD.......Turn Right");
	printf("\n\t\tP.......Slide Upward");
	printf("\n\t\t[;].....Slide Downward");
	printf("\n\t\t['].....Slide Right");
	printf("\n\t\tL.......Slide Left");
	// printf("\n\tObjeto:");
	// printf("\n\t\t[W]...Rotar hacia arriba   (y+)");
	// printf("\n\t\t[S]...Rotar hacia abajo    (y-)");
	// printf("\n\t\t[A]...Rotar a la izquierda (x-)");
	// printf("\n\t\t[D]...Rotar a la derecha   (x+)");
	// printf("\n\t\t[Q]...Rotar a la izquierda (z-)");
	// printf("\n\t\t[E]...Rotar a la derecha   (z+)");
	printf("\n\tAdditional options:");
	// printf("\n\t\tENTER.........Agregar punto 3D");
	// printf("\n\t\t[C]...........Moverse al centroide del objeto");
	printf("\n\t\t[+].....Increase Central Vision Angle");
	printf("\n\t\t[-].....Decrease Central Vision Angle");
	printf("\nPress any key when ready and press Q to quit\n");

	KeyboardAdapter keyboardAdapter;
	keyboardAdapter.initKeyboard();

	keyboardAdapter.readKey();

	Objeto_3D Obj;
	if(!Obj.readFileOBJ	(params[1]))
	{
		printf("\n\nCould not read 3D object file: %s",params[1]);
		exit(1);
	}

	Obj.FijaPos(0,0,5);
	int ve=1;

	GraphAdapter graphAdapter;

	graphAdapter.initGraphMode();

	int maxx = graphAdapter.getScreenWidth();
	int maxy = graphAdapter.getScreenHeight();
	
	Sprte *spr;
	if(numsprs==2)
	{
		spr=new Sprte[2];
		if(!spr)
		{
			graphAdapter.closeGraphMode();
			printf("\nOut of memory error");
			printf("\n_SPRTE_2");
			exit(1);
		}
		if(!spr[0].sprteIni(0,1.79,0,30,0,0,0,0,maxx/2,maxy))
		{
			graphAdapter.closeGraphMode();
			printf("\nOut of memory error:");
			printf("\nThere is not enough memory for the 3D views");
			exit(1);
		}
		if(!spr[1].sprteIni(0,1.79,0,30,180,0,maxx / 2 + 1, 0, maxx, maxy))
		{
			graphAdapter.closeGraphMode();
			printf("\nOut of memory error:");
			printf("\nThere is not enough memory for the 3D views");
			exit(1);
		}
	}
	else
	{
		spr=new Sprte;
		if(!spr)
		{
			graphAdapter.closeGraphMode();
			printf("\nOut of memory error");
			printf("\n_SPRTE_1");
			exit(1);
		}
		numsprs=1;
		if(!spr[0].sprteIni(0,1.79,0,30,0,0,0,0,maxx,maxy))
		{
			graphAdapter.closeGraphMode();
			printf("\nOut of memory error:");
			printf("\nThere is not enough memory for the 3D views");
			exit(1);
		}
	}
	

	// linea(spr,numsprs,cad,ve,ini, graphAdapter);
	Objeto(spr,numsprs,Obj, graphAdapter);
	Datos(spr,numsprs, graphAdapter);

	graphAdapter.refreshScreen();
	graphAdapter.clearScreen();

	do
	{
		keyboardAdapter.readKey();
		
		// Move Forward
		if(keyboardAdapter.checkKey(Key::R))
		{
			//if(spr.pos.z<pto[7].z-10)
			spr->movFrnArrSprte(movementSpeed);
			if(numsprs==2)
				spr[1].movFrnArrSprte(movementSpeed * -1);
		}

		// // Show / Hide
		// if(keyboardAdapter.checkKey(Key::E))
		// {
		// 	ve=!ve;
		// }
		
		// Move Backward
		if(keyboardAdapter.checkKey(Key::F))
		{
			//if(spr.pos.z>pto[0].z+10)
			spr->movFrnArrSprte(movementSpeed * -1);
			if(numsprs==2)
				spr[1].movFrnArrSprte(movementSpeed);
		}

		// Turn Left
		if(keyboardAdapter.checkKey(Key::A))
		{
			spr->incOri(angleSpeed * -1);
			if(numsprs==2)
				spr[1].incOri(angleSpeed * -1);
		}

		// Turn Right
		if(keyboardAdapter.checkKey(Key::D))
		{
			spr->incOri(angleSpeed);
			if(numsprs==2)
				spr[1].incOri(angleSpeed);
		}

		// Turn Down
		if(keyboardAdapter.checkKey(Key::S))
		{
			spr->incFre(angleSpeed*-1);
			if(numsprs==2)
				spr[1].incFre(angleSpeed);
		}

		// Turn Up
		if(keyboardAdapter.checkKey(Key::W))
		{
			spr->incFre(angleSpeed);
			if(numsprs==2)
				spr[1].incFre(angleSpeed * -1);
		}

		// Slide Left
		if(keyboardAdapter.checkKey(Key::L))
		{
			spr->movLadoSprte(movementSpeed * -1);
			if(numsprs==2)
				spr[1].movLadoSprte(movementSpeed);
		}

		// Slide Right
		if(keyboardAdapter.checkKey(Key::SINGLE_QUOTE))
		{
			spr->movLadoSprte(movementSpeed);
			if(numsprs==2)
				spr[1].movLadoSprte(movementSpeed * -1);
		}

		// Slide Downwards
		if(keyboardAdapter.checkKey(Key::SEMI_COLON))
		{
			spr->movArrSprte(movementSpeed * -1);
			if(numsprs==2)
				spr[1].movArrSprte(movementSpeed * -1);
		}

		// Slide Upwards
		if(keyboardAdapter.checkKey(Key::P))
		{
			spr->movArrSprte(movementSpeed);
			if(numsprs==2)
				spr[1].movArrSprte(movementSpeed);
		}

		// Increase Vision Focus Angle
		if(keyboardAdapter.checkKey(Key::PLUS))
		{
			spr->incVision(5);
			if(numsprs==2)
				spr[1].incVision(5);
		}

		// Decrease Vision Focus Angle
		if(keyboardAdapter.checkKey(Key::MINUS))
		{
			spr->incVision(-5);
			if(numsprs==2)
				spr[1].incVision(-5);
		}

		// if(Key(kENTER))
		// {
		// 	ini=insList(ini,spr->posSprte(),YELLOW);
		// }
		// if(Key(kQ))
		// {
		// 	if(Key(kMENMAY))
		// 		Obj.RotaXZ(-5);
		// 	else
		// 		Obj.RotaXZ(-1);
		// }
		// if(Key(kE))
		// {
		// 	if(Key(kMENMAY))
		// 		Obj.RotaXZ(5);
		// 	else
		// 		Obj.RotaXZ(1);
		// }
		// if(Key(kW))
		// {
		// 	if(Key(kMENMAY))
		// 		Obj.RotaZY(-5);
		// 	else
		// 		Obj.RotaZY(-1);
		// }
		// if(Key(kS))
		// {
		// 	if(Key(kMENMAY))
		// 		Obj.RotaZY(5);
		// 	else
		// 		Obj.RotaZY(1);
		// }
		// if(Key(kA))
		// {
		// 	if(Key(kMENMAY))
		// 		Obj.RotaXY(5);
		// 	else
		// 		Obj.RotaXY(1);
		// }
		// if(Key(kD))
		// {
		// 	if(Key(kMENMAY))
		// 		Obj.RotaXY(-5);
		// 	else
		// 		Obj.RotaXY(-1);
		// }
		// if(Key(kC))
		// {
		// 	spr->ponPosSprte(Obj.ObjCG());
		// }

		// linea(spr,numsprs,cad,ve,ini, graphAdapter);
		Objeto(spr,numsprs,Obj, graphAdapter);
		Datos(spr,numsprs, graphAdapter);

		/////////////REDIBUJA////////////////
		graphAdapter.refreshScreen();
		graphAdapter.clearScreen();
	}
	while(!keyboardAdapter.checkKey(Key::Q));
	
	graphAdapter.closeGraphMode();
	
	keyboardAdapter.closeKeyboard();
	
	if(numsprs==2)
		delete[] spr;
	else
		delete spr;
	
	return 0;
}
void linea(Sprte *spr, int sprs,char *cad, int ve, GraphAdapter &graphAdapter)
{
	// punto3d p;
	// List *rec=ini;
	// p.x=50;
	// p.y=0;
	// p.z=20;
	// if(ve)
	// {
	// 	if(sprs==2)
	// 	{
	// 		spr[0].zomfa3dxy(cad, p, 1);
	// 		spr[1].zomfa3dxy(cad, p, 1);
	// 	}
	// 	else
	// 		spr->zomfa3dxy(cad, p, 1);
	// }
	// for(rec=ini;rec!=NULL;rec=rec->sig)
	// {
	// 	if(sprs==2)
	// 	{
	// 		spr[0].dibPun3d(graphAdapter, rec->pos,rec->col1);
	// 		spr[1].dibPun3d(graphAdapter, rec->pos,rec->col1);
	// 	}
	// 	else
	// 		spr->dibPun3d(graphAdapter, rec->pos,rec->col1);
	// }
}
void Datos(Sprte *spr, int numspr, GraphAdapter &graphAdapter)
{
	if(numspr==2)
	{
//		setcolor(CYAN);
		spr[0].impDat(graphAdapter);
		spr[0].drawFloor2(graphAdapter);
		spr[1].impDat(graphAdapter);
		spr[0].drawFloor2(graphAdapter);
	}
	else
	{
//		setcolor(CYAN);
		spr->impDat(graphAdapter);
		spr->drawFloor2(graphAdapter);
	}
}
void Objeto(Sprte *spr, int numspr, Objeto_3D &obj, GraphAdapter &graphAdapter)
{
	if(numspr==2)
	{
		obj.Dibuja(spr[0], graphAdapter);
		obj.Dibuja(spr[1], graphAdapter);
	}
	else
		obj.Dibuja(*spr, graphAdapter);
}
