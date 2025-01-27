#ifndef VERTEX_LIST_H
#define VERTEX_LIST_H

#include "3D.h"

struct VertexNode {
    punto3d vertex;
    VertexNode *next;
};

class VertexList {
    private:
        VertexNode *list;
    public:
        ~VertexList();
        void add(punto3d vertex);
        punto3d get(int position);
        VertexNode *getVertexListPointer();
        void freeMem(VertexNode *node);
        void freeMem();
};

#endif