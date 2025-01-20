#include "ListLine.h"

struct ListLinea *creaNodo(int v1,int v2)
{
	struct ListLinea *aux;
	aux=(struct ListLinea *)malloc(sizeof (struct ListLinea));
	if(!aux)
		return NULL;
	aux->pto1=v1;
	aux->pto2=v2;
	aux->sig=NULL;
	aux->ant=NULL;
	return aux;
}
struct ListLinea *elimiNodo(struct ListLinea * ini, ListLinea *borr)
{
	struct ListLinea *aux=ini;
	struct ListLinea *rs;
	if(ini==NULL)
		return ini;
	if(ini==borr)
	{
			 ini=ini->sig;
			 return ini;
	}
	while(aux->sig!=NULL)
	{
		if(aux->sig==borr)
		{
			aux->sig=borr->sig;
			borr->sig->ant=aux;
			free(borr);
			return ini;
		}
		aux=aux->sig;
	}
	return ini;
}
struct ListLinea *inList(struct ListLinea *ini, struct ListLinea *nev)
{
	struct ListLinea *aux;
	if(ini==NULL)
		 return nev;
	for(aux=ini;aux->sig!=NULL;aux=aux->sig);
	aux->sig=nev;
	nev->ant=aux;
	return ini;
}
struct ListLinea *insList(struct ListLinea *ini,int v1,int v2)
{
	ListLinea *nev;
	nev=creaNodo(v1,v2);
	if(nev)
		ini=inList(ini,nev);
	return ini;
}
void libera(ListLinea *ini)
{
	ListLinea *aux;
	if(ini==NULL)
		return;
	for(;ini->sig;ini=ini->sig);
	while(ini!=NULL)
	{
		aux=ini;
		ini=ini->ant;
		free(aux);
	}
}