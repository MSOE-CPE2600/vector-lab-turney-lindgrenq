/**
 * Filename: veclab.c
 * Description: allows user to input vectos and do calculations
 * Author: Quinn Lindgren
 * Date: 9/30/25
 */
#include "vect.h"
#include "vecmath.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VECTS 10

int main(int argc, char* argv[]){
    char user_input[80];
    char *token1;
    char *token2;
    char *token3;
    char *token4;
    char *token5;
    
    vect vectors[MAX_VECTS];
    clear(vectors, MAX_VECTS);
    int num_vects = 0;

    do{
        token1 = NULL;
        token2 = NULL;
        token3 = NULL;
        token4 = NULL;
        token5 = NULL;
        fprintf(stdout, "> ");
        fgets(user_input, 80, stdin);
        token1 = strtok(user_input, " ");
        token2 = strtok(NULL, " ");
        token3 = strtok(NULL, " ");
        token4 = strtok(NULL, " ");
        token5 = strtok(NULL, " ");
        
        if(token2 == NULL){
            if(!strcmp(token1, "help\n")){
                help();
            } else if(!strcmp(token1, "clear\n")){
                clear(vectors, MAX_VECTS);
                num_vects = 0;
            } else if(!strcmp(token1, "list\n")){
                list_vects(vectors, MAX_VECTS);
            } else{
                if(strcmp(token1, "quit\n")){
                    fprintf(stdout, "Invalid input\n");
                }
                //print vector info or display error


            }
        } else if(!strcmp(token2, "=")){
            vect *save = &vectors[num_vects];
            int index = find_vect(vectors, token1, num_vects);
            if(index != -1){
                save = &vectors[index];
            }
            //check if doing operation or making assignment
        }
        

    } while(strcmp(token1, "quit\n"));


    return 0;
}