#include "KeyboardAdapter.h"
#include "KeyReader.h"

void KeyboardAdapter::initKeyboard() {
    keyReader.init();
}

void KeyboardAdapter::closeKeyboard() {
    keyReader.close();
}

Key KeyboardAdapter::getKeyPressed() {
    return key;
}

bool KeyboardAdapter::checkKey(Key expectedKey) {
    return key == expectedKey;
}

void KeyboardAdapter::readKey() {
    int _key = keyReader.readKey();

    switch ((char)_key)
    {
        case 'A':
        case 'a':
            key = Key::A;
            break;
        case 'B':
        case 'b':
            key = Key::B;
            break;
        case 'C':
        case 'c':
            key = Key::C;
            break;
        case 'D':
        case 'd':
            key = Key::D;
            break;
        case 'E':
        case 'e':
            key = Key::E;
            break;
        case 'F':
        case 'f':
            key = Key::F;
            break;
        case 'G':
        case 'g':
            key = Key::G;
            break;
        case 'H':
        case 'h':
            key = Key::H;
            break;
        case 'I':
        case 'i':
            key = Key::I;
            break;
        case 'J':
        case 'j':
            key = Key::J;
            break;
        case 'K':
        case 'k':
            key = Key::K;
            break;
        case 'L':
        case 'l':
            key = Key::L;
            break;
        case 'M':
        case 'm':
            key = Key::M;
            break;
        case 'N':
        case 'n':
            key = Key::N;
            break;
        case 'O':
        case 'o':
            key = Key::O;
            break;
        case 'P':
        case 'p':
            key = Key::P;
            break;
        case 'Q':
        case 'q':
            key = Key::Q;
            break;
        case 'R':
        case 'r':
            key = Key::R;
            break;
        case 'S':
        case 's':
            key = Key::S;
            break;
        case 'T':
        case 't':
            key = Key::T;
            break;
        case 'U':
        case 'u':
            key = Key::U;
            break;
        case 'V':
        case 'v':
            key = Key::V;
            break;
        case 'W':
        case 'w':
            key = Key::W;
            break;
        case 'X':
        case 'x':
            key = Key::X;
            break;
        case 'Y':
        case 'y':
            key = Key::Y;
            break;
        case 'Z':
        case 'z':
            key = Key::Z;
            break;
        case '0':
            key = Key::_0;
            break;
        case '1':
            key = Key::_1;
            break;
        case '2':
            key = Key::_2;
            break;
        case '3':
            key = Key::_3;
            break;
        case '4':
            key = Key::_4;
            break;
        case '5':
            key = Key::_5;
            break;
        case '6':
            key = Key::_6;
            break;
        case '7':
            key = Key::_7;
            break;
        case '8':
            key = Key::_8;
            break;
        case '9':
            key = Key::_9;
            break;
        case ' ':
            key = Key::SPACE;
            break;
        case '\'':
            key = Key::SINGLE_QUOTE;
            break;
        case ';':
            key = Key::SEMI_COLON;
            break;
        case '+':
            key = Key::PLUS;
            break;
        case '-':
            key = Key::MINUS;
            break;
        
        default:
            key = Key::UNKNOWN;
    }
}