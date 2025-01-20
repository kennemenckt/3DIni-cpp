#ifndef LIST3D_H
#define LIST3D_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "3D.h"

struct List
{
	punto3d pos;
	int col1;
	struct List *sig;
	struct List *ant;
};
struct List *creaNod(punto3d ps, int col);
struct List *elimiNodo(struct List * ini, List *borr);
struct List *inList(struct List *ini, struct List *nev);
struct List *insList(struct List *ini, punto3d ps,int cl1);
List *Avanza(List *ini,int num);
void libera(List *ini);
#endif