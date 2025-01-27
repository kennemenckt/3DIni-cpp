#ifndef FACE_LIST_H
#define FACE_LIST_H

#include "VertexList.h"

struct FaceNode {
    VertexList vertexes;
    FaceNode *next;
};

class FaceList
{
    private:
        FaceNode * list;
        FaceNode * current;
    public:
        ~FaceList();
        void createFace();
        void addVertex(punto3d p3d);
        FaceNode *getFaceListPointer();
        void freeMem(FaceNode *);
        void freeMem();
};

#endif
