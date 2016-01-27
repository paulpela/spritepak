# spritepak
A simple compression algorithm for binary files

## How it works

It takes a binary file and reads it byte by byte. The output are words (16
bits), composed like this:

0xYYZZ

Where:

- `YY` is the count (how many times the next 8 bits are repeated in input
  file)
- `ZZ` the input byte

This works pretty well for bitmap files where there are often long strings of
the same byte (in case of 256 color or 8bit indexed modes).
