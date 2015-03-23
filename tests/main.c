#include "../sources/printfc.h"


int main(int argc, char *argv[]) {

	// TODO: add more tests...
	printfc("[r]%s %s\n", "red!", "normal!");

  printfc("[r]%s %s [r]%s\n", "red!", "and", "RED!");

	printfc(" - [r]%s\n", "red");
	printfc(" - [g]%s\n", "green");
	printfc(" - [y]%s\n", "yellow");
	printfc(" - [b]%s\n", "blue");
	printfc(" - [m]%s\n", "magenta");
	printfc(" - [c]%s\n", "cyan");
	printfc(" - [n]%s\n", "normal");
  
  printfc(" - [122]%s\n", "nonsense");

  printfc(" - [r]%s\n"
          " - [g]%s\n"
          " - [y]%s\n"
          " - [b]%s\n"
          " - [m]%s\n"
          " - [c]%s\n"
          " - [n]%s\n", "yellow","red", "green","blue", "magenta", "cyan", "normal");

    return 0;
}
