#ifndef __SET_MATERIAL_H__
#define __SET_MATERIAL_H__

#define MAT_GOLD 0
#define MAT_SILVER 1     
#define MAT_SILVER_POLISHED 2
#define MAT_BRONZE 3
#define MAT_CHROME 4
#define MAT_BRASS 5
#define MAT_TIN 6
#define MAT_COPPER 7
#define MAT_PLASTIC_BLACK 8
#define MAT_RED_MATTE 9
#define MAT_GREEN_MATTE 10
#define MAT_BLUE_MATTE 11
#define MAT_WHITE_MATTE 12
#define MAT_BLACK_MATTE 13

#include "color.h"
#include "material.h"


Material setMaterial( int materialID );

#endif//__SET_MATERIAL_H__
