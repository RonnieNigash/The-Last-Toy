#ifndef D_Radiance_H
#define D_Radiance_H

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "objects.h"

Vector *intensity(Ray *ray, uint8_t recursionDepth, uint8_t randomSeed);

#endif //D_Radiance_H
