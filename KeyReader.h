#ifndef KEY_READER_H
#define KEY_READER_H

class KeyReader {
    public:
        void init();
        void close();
        int readKey();
};

#endif