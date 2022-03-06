#include <stdio.h>
#include <stdlib.h>

#include <architecture.h>
#include <macho.h>

unsigned char *extractBytes(FILE *fp, long length) {
    unsigned char *bytes = (unsigned char *)malloc(length * sizeof(char));
    rewind(fp);
    for(int i = 0; i < length; i++) {
        fread(bytes+i, 1, 1, fp);
    }

    return bytes;
}

struct objectFile readFile(char *fileName) {
    FILE *fp;
    struct objectFile buffer;
    buffer.didLoad = false;

    if( (fp = fopen(fileName, "rb")) ) {
        unsigned char *bytes = NULL;

        fseek(fp, 0, SEEK_END);
        buffer.length = ftell(fp);
        printf("\t[size: %ld]\n", buffer.length);
        if(buffer.length > 0) {
            buffer.bytes = extractBytes(fp, buffer.length);
            buffer.didLoad = true;
        } else {
            printf("\n\n%s\n", "Empty file!");
            exit(1);
        }
    } else {
        printf("\t%s\n", "File not found!");
        exit(1);
    }

    return buffer;
}

int main(int argc, char **argv) {
    for(int i = 1; i < argc; i++) {
        printf("Loading %s...", argv[i]);
        struct objectFile buffer = readFile(argv[i]);
        extractFromObjectFile(buffer);
    }

    return 0;
}