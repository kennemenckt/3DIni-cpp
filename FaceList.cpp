#include "FaceList.h"

FaceList::~FaceList() {
    freeMem(list);
    list = NULL;
}

void FaceList::createFace() {
    current = (FaceNode *)malloc(sizeof(FaceNode));
    if (list == NULL) {
        list = current;
        return;
    }
    FaceNode *pointer = list;
    for (;pointer->next != NULL; pointer = pointer->next);
    pointer->next = current;
}

void FaceList::addVertex(punto3d p3d) {
    current->vertexes.add(p3d);
}

FaceNode * FaceList::getFaceListPointer() {
    return list;
}

void FaceList::freeMem(FaceNode *node) {
    if (node == NULL)
        return;
    
    freeMem(node->next);
    
    node->vertexes.freeMem();
    free(node);
}

void FaceList::freeMem() {
    freeMem(list);
    list = NULL;
}