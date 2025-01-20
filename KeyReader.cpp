#include "KeyReader.h"
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <signal.h>

static struct termios original_termios;

void restore_terminal_settings() {
    tcsetattr(STDIN_FILENO, TCSANOW, &original_termios);
}

void handle_signal(int sig) {
    printf("Signal received: %d\n", sig);
    restore_terminal_settings();
    exit(0);
}

void init_terminal_settings() {
    struct termios new_termios;

    // Save original terminal settings
    tcgetattr(STDIN_FILENO, &original_termios);
    atexit(restore_terminal_settings); // Restore on exit
    signal(SIGINT, handle_signal);     // Handle Ctrl+C

    // Set terminal to non-canonical mode (read character by character)
    new_termios = original_termios;
    new_termios.c_lflag &= ~(ICANON | ECHO); // Disable canonical mode and echoing
    tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);
}

void KeyReader::init() {
    init_terminal_settings();
}

void KeyReader::close() {
    restore_terminal_settings();
}

int KeyReader::readKey() {
    int c;
    read(STDIN_FILENO, &c, 1);
    return c;
}