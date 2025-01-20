#ifndef LIST_LINEA
#define LIST_LINEA
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListLinea
{
	int pto1,pto2;
	struct ListLinea *sig;
	struct ListLinea *ant;
};
struct ListLinea *creaNodo(int v1,int v2);
struct ListLinea *elimiNodo(struct ListLinea * ini, ListLinea *borr);
struct ListLinea *inList(struct ListLinea *ini, struct ListLinea *nev);
struct ListLinea *insList(struct ListLinea *ini,int v1,int v2);
void libera(ListLinea *ini);
#endif