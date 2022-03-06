#ifndef MACHO_H
#define MACHO_H

#include <stdbool.h>

struct objectFile {
    long length;
    unsigned char *bytes;
    bool didLoad;
};

void extractFromObjectFile(struct objectFile fb);
void parseHeader(struct objectFile fb);

#endif
