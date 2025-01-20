#include "List3D.h"

struct List *creaNod(punto3d num, int cl1)
{
	struct List *aux;
	aux=(struct List *)malloc(sizeof (struct List));
	if(!aux)
		return NULL;
	aux->pos.x=num.x;
	aux->pos.y=num.y;
	aux->pos.z=num.z;
	aux->col1=cl1;
	aux->sig=NULL;
	aux->ant=NULL;
	return aux;
}
struct List *elimiNodo(struct List * ini, List *borr)
{
	struct List *aux=ini;
	struct List *rs;
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
struct List *inList(struct List *ini, struct List *nev)
{
	struct List *aux;
	if(ini==NULL)
		 return nev;
	for(aux=ini;aux->sig!=NULL;aux=aux->sig);
	aux->sig=nev;
	nev->ant=aux;
	return ini;
}
struct List *insList(struct List *ini, punto3d ps,int cl1)
{
	List *nev;
	nev=creaNod(ps,cl1);
	if(nev)
		ini=inList(ini,nev);
	return ini;
}
List *Avanza(List *ini,int num)
{
	int i=1;
	List *rec;
	for(rec=ini;rec!=NULL&&i<num;rec=rec->sig,i++);
	return rec;
}
void libera(List *ini)
{
	List *aux;
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