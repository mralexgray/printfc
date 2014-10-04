#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

// ANSI escape codes.
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"


// Maps format characters to color codes.
static const char *ccmap(char c)
{
	switch(c){
	case 'r': return RED;
	case 'g': return GREEN;
	case 'y': return YELLOW;
	case 'b': return BLUE;
	case 'm': return MAGENTA;
	case 'c': return CYAN;
	default:  return RESET;
	}
}


// Counts occurences of character in string.
static int howMany(const char *s, char c)
{
	int n = 0;
	while(*s){
		if(*s == c)
			++n;
		++s;
	}
	return n;
}


// Appends character to string.
static void cappend(char *s, char c)
{
	s += strlen(s);
	s[0] = c;
	s[1] = 0;
}


// Reads printf format string, replacing color-indicating
// characters with their respective color codes.
static char *ccformat(const char *f)
{
	char *r = malloc(strlen(f) * 8);
	if(!r)
		return NULL;
	*r = 0;

	strcat(r, RESET);
	while(*f){
		if(f[0] == '[' && f[3] == '%'){
			strcat(r, ccmap(f[1])), f += 3;
			while(!isalpha(*f))
				cappend(r, *f), ++f;
			cappend(r, *f), ++f;
			strcat(r, RESET);
		} else{
			cappend(r, *f);
			++f;
		}
	}
	strcat(r, RESET);
	return r;
}


// Main printing function.
int printfc(const char *cf, ...)
{
	va_list args;
	va_start(args, cf);
	char *f = ccformat(cf);
	if(f){
		vprintf(f, args);
		free(f);
		va_end(args);
		return 0;
	}
	return 1;
}