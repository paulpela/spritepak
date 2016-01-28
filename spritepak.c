/*
    spritepak - a compression utility for sprite/bitmap files

    Copyright (C) 2016  Pawel Pela <paulpela@gmail.com>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

*/

#include<stdlib.h>
#include<stdio.h>

int main(int argc, char *argv[]) {
    FILE *input;
    FILE *output;

    if(argc != 3) {
        printf("spritepak requires two arguments.\n");
        exit(1);
    }

    input = fopen(argv[1], "r");

    if(!input) {
        printf("Input file could not be opened. Exiting.\n");
        exit (1);
    }

    output = fopen(argv[2], "w");

    if(!output) {
        printf("Output file could not be opened. Exiting.\n");
        exit (1);
    }

    int counter = 0;
    int prevbyte = 0x00;
    int byte = fgetc(input);

    while(byte != EOF) {
        if(byte != prevbyte) {
            fputc(counter, output);
            fputc(prevbyte, output);
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
