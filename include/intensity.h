#ifndef D_Intensity_H
#define D_Intensity_H

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

Vector *intensity(Ray *ray, uint8_t recursionDepth, uint8_t randomSeed);

#endif // D_Intensity_H
