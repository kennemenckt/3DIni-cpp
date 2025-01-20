#if !defined _CORDEN_H
#define _CORDEN_H

#include <stdio.h>
struct corden
{
	int x;
	int y;
};
struct xyz
{
	int x;
	int y;
	int z;
};
void ini(struct corden *cor, int p1, int p2);
void borra(struct corden *cor);
void iniz(struct xyz *cor, int p1, int p2, int p3);
void borraz(struct xyz *cor);
#endif