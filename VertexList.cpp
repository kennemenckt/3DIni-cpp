#include "VertexList.h"

VertexList::~VertexList() {
    freeMem(list);
    list = NULL;
}

void VertexList::add(punto3d vertex) {
    VertexNode *vertexNode = (VertexNode *)malloc(sizeof(VertexNode));
    vertexNode->vertex = vertex;
    if (list == NULL)
    {
        list = vertexNode;
        return;
    }
    
    VertexNode *pointer = list;
    for (; pointer->next != NULL ; pointer = pointer->next);

    pointer->next = vertexNode;
}

punto3d VertexList::get(int position) {
    VertexNode *pointer = list;
    for (int idx = 1; idx < position && pointer != NULL; idx++, pointer = pointer->next);
    return pointer->vertex;    
}

VertexNode * VertexList::getVertexListPointer() {
    return list;
}

void VertexList::freeMem(VertexNode *node) {
    if (node == NULL)
        return;
    
    freeMem(node->next);
    
    free(node);
}

void VertexList::freeMem() {
    freeMem(list);
    list = NULL;
}