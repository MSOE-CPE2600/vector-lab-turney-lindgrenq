/**
 * Filename: vecmath.h
 * Description: declarations for vecmath.c
 * Author: Quinn Lindgren
 * Date: 9/30/25
 */
#ifndef VECMATH_H
#define VECMATH_H
#include "vect.h"
int add_vect(vect *sum, vect *vect1, vect *vect2);
int sub_vect(vect *dif, vect *vect1, vect *vect2);
int scale_vect(vect *save, vect *vect1, float scaler);
float dot_vect(vect *vect1, vect *vect2);
int cross_vect(vect *cross, vect *vect1, vect *vect2);
int new_vect(vect *save, char name[], float x, float y, float z);
int list_vects(vect vect_list[], int num_vects);
int vect_info(vect *vect1);
int find_vect(vect vect_list[], char name[], int num_vects);
int help();
int clear(vect vect_list[], int num_vects);
#endif