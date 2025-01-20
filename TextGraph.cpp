/**
 * Class to draw graphics in text mode using ncurses
 * @author luis.arias.cruz
 * @date 15/01/2025
 */
#include <ncurses.h>
#include "TextGraph.h"

/**
 * Constructor
 */
TextGraph::TextGraph() {
    initiated = 0;
}

/**
 * Destructor
 */
TextGraph::~TextGraph() {
    stopTextGraph();
}

void TextGraph::startTextGraph() {
    if (initiated)
        return;
    initiated = 1;
    initscr();
    noecho();
    getmaxyx(stdscr, maxy, maxx);
    move(0,0);
}

void TextGraph::stopTextGraph() {
    if (!initiated)
        return;
    initiated = 0;
    endwin();
}

void TextGraph::drawPoint(int x, int y) {
    if (!initiated)
        return;
    if (x < 0 || x > maxx || y < 0 || y > maxy)
        return;
    
    mvprintw(y, x, "*");
    move(0,0);
}

void TextGraph::drawLine(int x1, int y1, int x2, int y2) {
    if (!initiated)
        return;
    
    // condition to avoid integer divided by zero in vertical lines
    if (x2 == x1)
    {
        // begin and end of coordinates are the same, single point is drawn
        if (y2 == y1)
        {
            drawPoint(x1, y1);
            return;
        }
        // normal directon
        if (y2 > y1)
        {
            for (int yy = y1; yy <= y2; yy++)
            {
                drawPoint(x1, yy);
            }
            return;
        }
        // draw the line in the opposite direction
        for (int yy = y2; yy <= y1; yy++)
        {
            drawPoint(x1, yy);
        }
        return;
    }

    // condition to avoid infinite loops in horizontal lines
    if (y2 == y1)
    {
        // normal directon
        if (x2 > x1)
        {
            for (int xx = x1; xx <= x2; xx++)
            {
                drawPoint(xx, y1);
            }
            return;
        }
        // draw the line in the opposite direction
        for (int xx = x2; xx <= x1; xx++)
        {
            drawPoint(xx, y1);
        }
        return;
    }
    
    float m = (float)(y2 - y1) / (float)(x2 - x1);
    float xx = x1;
    float yy = y1;
    int limitx = x2;

    // check if the line should be drawn in the opposite direction
    if (x1 > x2)
    {
        xx = x2;
        limitx = x1;
    }  

    while (xx <= limitx || yy <= y2)
    {
        drawPoint(xx, yy);
        xx++;
        yy = m * (xx-(float)x1) + (float)y1;
    }

}
void TextGraph::refreshG() {
    refresh();
    move(0,0);
}

int TextGraph::getMaxX() {
    return maxx;
}

int TextGraph::getMaxY() {
    return maxy;
}

void TextGraph::clearGraphs() {
    erase();
    move(0,0);
}