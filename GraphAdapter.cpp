#include "GraphAdapter.h"
#include "MyTextGraph.h"

/**
 * Initialize graphic mode
 */
void GraphAdapter::initGraphMode() {
    textGraph.initScreen();
}

/**
 * Close graphic mode
 */
void GraphAdapter::closeGraphMode() {
    textGraph.closeScreen();
}

/**
 * Clear the screen
 */
void GraphAdapter::clearScreen() {
    textGraph.clearScreen();
}

/**
 * Refresh/flush screen
 */
void GraphAdapter::refreshScreen() {
    textGraph.refreshScreen();
}

/**
 * Get screen width
 */
int GraphAdapter::getScreenWidth() {
    return textGraph.getMaxX();
}

/**
 * Get screen height
 */
int GraphAdapter::getScreenHeight() {
    return textGraph.getMaxY();
}

/**
 * Set color to draw
 */
void GraphAdapter::setColor(int color) {
    // Colors not currently supported using TextGraph
}

/**
 * Draw a point in the screen
 */
void GraphAdapter::drawPoint(int x, int y) {
    textGraph.drawPoint(x, y);
}

/**
 * Draw a line in the screen
 */
void GraphAdapter::drawLine(int x1, int y1, int x2, int y2) {
    textGraph.drawLine(x1, y1, x2, y2);
}

void GraphAdapter::drawText(int x, int y, char *text) {
    textGraph.drawText(x, y, text);
}
