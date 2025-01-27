#ifndef MY_TEXT_GRAPH
#define MY_TEXT_GRAPH

/**
 * Class to draw graphics in text mode using char matrix
 * @author luis.arias.cruz
 * @date 18/01/2025
 */
class MyTextGraph {
    private:
        char **screen;
        int maxx;
        int maxy;
        void clearScr();
    public:
        ~MyTextGraph();
        void initScreen();
        void initScreen(int width, int height);
        void closeScreen();
        void refreshScreen();
        void drawPoint(int x, int y);
        void drawLine(int x1, int y1, int x2, int y2);
        void clearScreen();
        int getMaxX();
        int getMaxY();
        void drawText(int x, int y, char *text);
        void drawChar(int x, int y, char c);
};

#endif