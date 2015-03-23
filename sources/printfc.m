#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "printfc.h"

// ANSI escape codes.
#define RED            "\x1b[31m"
#define GREEN           "\x1b[32m"
#define YELLOW          "\x1b[33m"
#define BLUE            "\x1b[34m"
#define MAGENTA         "\x1b[35m"
#define CYAN            "\x1b[36m"
#define NORMAL          "\x1b[0m"
#define OTHER(X)        "\x1b[38;5;"#X"m"

// Maps format characters to color codes.

static const char *ccmap(char c) { return

    c == 'r' ? RED     : c == 'g' ? GREEN : c == 'y' ? YELLOW : c == 'b' ? BLUE :
    c == 'm' ? MAGENTA : c == 'c' ?  CYAN : c == 'n' ? NORMAL : OTHER(c);

// ({ printfc("[r]%s[-]%c\n", " - ERROR: invalid color specifier: ", c); exit(1); NORMAL; });
}

// Counts occurences of character in string.

__unused static int howMany(const char *s, char c) { int n = 0; while(*s){ if(*s == c) ++n; ++s; } return n; }

// Appends character to string.

static void cappend(char *s, char c) { s += strlen(s); s[0] = c; s[1] = 0; }

// Reads printf fmt str, replacing color-indicating chars with respective color codes.

static char *ccformat(const char *f) {

	char *r; if(!(r = malloc(strlen(f) * 8))) return NULL; *r = 0;

	strcat(r, NORMAL);

	while(*f){

		if(f[0] == '[' && f[2] == ']'  && f[3] == '%'){

			strcat(r, ccmap(f[1])), f += 3;
			while(!isalpha(*f)) cappend(r, *f), ++f;
			cappend(r, *f), ++f;
			strcat(r, NORMAL);

    } else{ cappend(r, *f); ++f; }
	}
	strcat(r, NORMAL);
	return r;
}

// Main printing function.
int printfc(const char *cf, ...) { va_list args; va_start(args, cf); char *f;

  if(!(f = ccformat(cf))) return 1; vprintf(f, args); free(f); return va_end(args), 0;
}
