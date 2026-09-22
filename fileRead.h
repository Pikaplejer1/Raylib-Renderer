#pragma once

#include "mathD.h"

int getObjectFileFromName(char* filename, obj** object);

void freeObj(obj *o);

/**
 * A function that takes in a line of character, and returns a number of correctly paresed formats, and saves them to 
 * a,b,c respectivly
 * @return returns a number of correctly scanned patterns
 * @param a* first variable to scan to 
 * @param b* second variable to scan to 
 * @param c* third variable to scan to 
 */
int parseFaceLine(const char *line, int *a, int *b, int *c);
