#include "../sources/printfc.h"


int main(int argc, char *argv[]) {
	// TODO: add more tests...
	printfc("[r]%s %s\n", "red!", "normal!");
	printfc(" - [r]%s\n", "red");
	printfc(" - [g]%s\n", "green");
	printfc(" - [y]%s\n", "yellow");
	printfc(" - [b]%s\n", "blue");
	printfc(" - [m]%s\n", "magenta");
	printfc(" - [c]%s\n", "cyan");
	printfc(" - [n]%s\n", "normal");
    return 0;
}
