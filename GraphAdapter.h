#ifndef GRAPH_ADAPTER_H
#define GRAPH_ADAPTER_H

#include "MyTextGraph.h"

/**
 * This class serves as an adapter to any Graphics library
 * If the graphics library needs to be changed only this
 * code needs to be updated
 */
class GraphAdapter {
    private:
        MyTextGraph textGraph;

    public:
        void initGraphMode();
        void closeGraphMode();
        void setColor(int color);
        void drawPoint(int x, int y);
        void drawLine(int x1, int y1, int x2, int y2);
        void drawText(int x, int y, char *text);
        void refreshScreen();
        void clearScreen();
        int getScreenWidth();
        int getScreenHeight();
};

#endif