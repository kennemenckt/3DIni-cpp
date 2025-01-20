#ifndef KEYBOARD_ADAPTER_H
#define KEYBOARD_ADAPTER_H

#include "KeyReader.h"

/**
 * Represent Keys
 */
enum class Key {
    A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
    _1, _2, _3, _4, _5, _6, _7, _8, _9, _0,
    SPACE, SINGLE_QUOTE, SEMI_COLON, PLUS, MINUS,
    UNKNOWN
};

/**
 * This class serves as an adapter to keyboard handlers
 * If the keuyboard handler needs to be changed only this
 * code needs to be updated
 */
class KeyboardAdapter {
    private:
        Key key;
        KeyReader keyReader;
    public:
        void initKeyboard();
        void closeKeyboard();
        Key getKeyPressed();
        void readKey();
        bool checkKey(Key key);
};

#endif