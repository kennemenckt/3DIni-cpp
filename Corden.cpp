#include "Corden.h"

void ini(struct corden *cor, int p1, int p2)
{
	cor->x=p1;
	cor->y=p2;
}
void borra(struct corden *cor)
{
	cor->x=0;
	cor->y=0;
}
void iniz(struct xyz *cor, int p1, int p2, int p3)
{
	cor->x=p1;
	cor->y=p2;
	cor->z=p3;
}
void borraz(struct xyz *cor)
{
	cor->x=0;
	cor->y=0;
	cor->z=0;
}