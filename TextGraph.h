#ifndef TEXT_GRAPH_H
#define TEXT_GRAPH_H

/**
 * Class to draw graphics in text mode using ncurses
 * @author luis.arias.cruz
 * @date 15/01/2025
 */
#include <ncurses.h>

class TextGraph {
    private:
        int initiated;
        int maxx, maxy;
    public:
        TextGraph();
        ~TextGraph();
        void startTextGraph();
        void stopTextGraph();
        void drawPoint(int, int);
        void drawLine(int, int, int, int);
        void refreshG();
        int getMaxX();
        int getMaxY();
        void clearGraphs();
};

#endif