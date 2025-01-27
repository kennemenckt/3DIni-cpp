#include "MyTextGraph.h"
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <thread>
#include <chrono>

using namespace std;

MyTextGraph::~MyTextGraph() {
    closeScreen();
}

void MyTextGraph::clearScr() {
    system("clear");
}

void MyTextGraph::initScreen() {
    initScreen(170, 55);
}

void MyTextGraph::initScreen(int width, int height) {
    if (screen != NULL)
        closeScreen();
    
    maxx = width;
    maxy = height;
    screen = (char **)malloc(maxy * sizeof(char *));
    for (int y = 0; y < maxy; y++)
    {
        screen[y] = (char *)malloc(maxx * sizeof(char));
    }
    clearScreen();
}

void MyTextGraph::closeScreen() {
    if (screen == NULL)
        return;
    
    for (int y = 0; y < maxy; y++)
    {
        free(screen[y]);
    }
    free(screen);
    screen = NULL;
}

void MyTextGraph::refreshScreen() {
    clearScr();
    for (int y = 0; y < maxy; y++)
    {
        for (int x = 0; x < maxx; x++)
        {
            printf("%c", screen[y][x]);
        }
        printf("\n");
    }
}

void MyTextGraph::drawPoint(int x, int y) {
    if (screen == NULL)
        return;
    if (x < 0 || x >= maxx || y < 0 || y >= maxy)
        return;
    screen[y][x] = '*';
}

/**
 * Bresenham's line algorithm
 */
void MyTextGraph::drawLine(int x1, int y1, int x2, int y2) {
    if (screen == NULL)
        return;
    
    int dx = std::abs(x2 - x1);
    int dy = std::abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;

    while (true) {
        drawPoint(x1, y1);
        if (x1 == x2 && y1 == y2) break;
        int e2 = err;
        if (e2 > -dx) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dy) {
            err += dx;
            y1 += sy;
        }
    }
}

void MyTextGraph::clearScreen() {
    if (screen == NULL)
        return;
    for (int y = 0; y < maxy; y++)
    {
        for (int x = 0; x < maxx; x++)
        {
            screen[y][x] = ' ';
        }
    }
}

int MyTextGraph::getMaxX() {
    return maxx;
}

int MyTextGraph::getMaxY() {
    return maxy;
}