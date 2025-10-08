/**
 * Filename: vecmath.c
 * Description: performs various vector math operations
 * Author: Quinn Lindgren
 * Date: 9/30/25
 */
#include "vect.h"
#include <stdio.h>
#include <string.h>

int add_vect(vect *sum, vect *vect1, vect *vect2){
    sum->x = (vect1->x) + (vect2->x);
    sum->y = (vect1->y) + (vect2->y);
    sum->z = (vect1->z) + (vect2->z);
    return 0;
}

int sub_vect(vect *dif, vect *vect1, vect *vect2){
    dif->x = (vect1->x) - (vect2->x);
    dif->y = (vect1->y) - (vect2->y);
    dif->z = (vect1->z) - (vect2->z);
    return 0;
}

int scale_vect(vect *save, vect *vect1, float scaler){
    save->x = (vect1->x) * scaler;
    save->y = (vect1->y) * scaler;
    save->z = (vect1->z) * scaler;
    return 0;
}

float dot_vect(vect *vect1, vect *vect2){
    return ((vect1->x) * (vect2->x)) + ((vect1->y) * (vect2->y)) + ((vect1->z) * (vect2->z));
}

int cross_vect(vect *cross, vect *vect1, vect *vect2){
    cross->x = ((vect1->y) * (vect2->z)) - ((vect1->z) * (vect2->y));
    cross->y = ((vect1->z) * (vect2->x)) - ((vect1->x) * (vect2->z));
    cross->z = ((vect1->x) * (vect2->y)) - ((vect1->y) * (vect2->x));
    return 0;
}

int new_vect(vect *save, char name[], float x, float y, float z){
    strcpy(save->name, name);
    save->x = x;
    save->y = y;
    save->z = z;
    return 0;
}

int list_vects(vect vect_list[], int num_vects){
    for(int i = 0; i < num_vects; i++){
        fprintf(stdout, "%4s = <%f, %f, %f>\n", vect_list[i].name, vect_list[i].x, vect_list[i].y, vect_list[i].z);
    }
    return 0;
}

int vect_info(vect *vect1){
    fprintf(stdout, "%4s = <%f, %f, %f>\n", vect1->name, vect1->x, vect1->y, vect1->z);
    return 0;
}

int find_vect(vect vect_list[], char name[], int num_vects){
    for(int i = 0; i < num_vects; i++){
        if(!strcmp(vect_list[i].name, name)){
            return i;
        }
    }
    return -1;
}

int help(){
    fprintf(stdout, " operations supported:\n   add: +\n   subtract: -\n   scaler: *\n   dot product: .\n   cross product: x\n");
    fprintf(stdout," commands:\n   quit: quits program\n   list: lists all vectors\n   clear: clears all saved vectors\n   vector name: prints vector info\n");
    fprintf(stdout, " declare new vetor:\n   name = x y: sets vector with z=0 and given x and y\n   name = x y z: sets vector with given x y and z\n");
    return 0;
}

int clear(vect vect_list[], int num_vects){
    for(int i = 0; i < num_vects; i++){
        strcpy(vect_list[i].name, "0");
        vect_list[i].x = 0.0;
        vect_list[i].y = 0.0;
        vect_list[i].z = 0.0;
    }
    return 0;
}