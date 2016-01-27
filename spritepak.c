#include<stdio.h>

int main(int argc, char *argv[]) {
    FILE *input;
    FILE *output;

    input = fopen(argv[1], "r");
    output = fopen(argv[2], "w");

    int counter = 1;
    int prevbyte = 0x00;
    int byte = fgetc(input);

    while(byte != EOF) {
        if(byte != prevbyte) {
            fputc(counter, output);
            counter = 1;
        } else {
            counter++;
        }

        prevbyte = byte;
        byte = fgetc(input);
    }

    fclose(input);
    fclose(output);
    exit(0);
}
