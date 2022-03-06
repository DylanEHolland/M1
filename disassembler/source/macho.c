#include <macho.h>
#include <stdio.h>
#include <stdlib.h>

void extractFromObjectFile(struct objectFile fb) {
    parseHeader(fb);
}

void parseHeader(struct objectFile fb) {
    unsigned char magicTest[4] = {
        (unsigned char)0xfffffffe, 
        (unsigned char)0xffffffed, 
        (unsigned char)0xfffffffa, 
        (unsigned char)0xffffffcf
    };

    int n = 0;
    for(int i = 3; i >= 0; i--) {
        unsigned char byte = fb.bytes[i];
        if(byte == magicTest[n]) {
            printf("\tmagic: %x\n", byte);
        } else {
            printf("Not a Mach-O file!\n");
            exit(1);
        }

        n++;
    }
}