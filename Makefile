all: compile

compile:
	gcc spritepak.c -o spritepak

test: compile
	./spritepak input.test output.test
	hexdump output.test
