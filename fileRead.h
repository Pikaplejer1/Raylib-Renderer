#pragma once

#include "mathD.h"

int getObjectFileFromName(char* filename, obj** object);

void freeObj(obj *o);
