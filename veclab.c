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
    char user_input[50];
    char token[5][4];
    
    vect vectors[MAX_VECTS];
    clear(vectors, MAX_VECTS);
    int num_vects = 0;

    fprintf(stdout, "enter \"help\" for help or quit to quit\n");
    do{
        char *tok;
        fprintf(stdout, "> ");
        fgets(user_input, 50, stdin);
        int token_index = 0;
        tok = strtok(user_input, " ");
        strcpy(token[token_index], tok);
        while(tok != NULL && token_index <= 5){
            tok = strtok(NULL, " ");
            if(tok != NULL){
               token_index++;
               strcpy(token[token_index], tok); 
            }
        }
        token[token_index][strlen(token[token_index])-1] = '\0'; // remove new line char from last token

        if(token_index == 0){
            if(!strcmp(token[0], "help")){
                help();
            } else if(!strcmp(token[0], "clear")){
                clear(vectors, MAX_VECTS);
                num_vects = 0;
            } else if(!strcmp(token[0], "list")){
                list_vects(vectors, MAX_VECTS);
            } else{
                // display vector info with given name
                int index = find_vect(vectors, token[0], num_vects);
                if(strcmp(token[0], "quit") && index == -1){
                    fprintf(stdout, "command/vector not found\n");
                } else if(strcmp(token[0], "quit")){
                    vect_info(&vectors[index]);
                }
            }
        } else if(token_index == 2){
            int index1 = find_vect(vectors, token[0], num_vects);
            int index2 = find_vect(vectors, token[2], num_vects);
            vect answer = {"ans", 0, 0, 0};
            if(index1 != -1 && index2 != -1){ // no save operations
                if(!strcmp(token[1], "+")){
                    // add
                    add_vect(&answer, &vectors[index1], &vectors[index2]);
                    vect_info(&answer);
                } else if(!strcmp(token[1], "-")){
                    // sub
                    sub_vect(&answer, &vectors[index1], &vectors[index2]);
                    vect_info(&answer);
                } else if(!strcmp(token[1], ".")){
                    // dot
                    float dot = dot_vect(&vectors[index1], &vectors[index2]);
                    fprintf(stdout, " ans = %f\n", dot);
                } else if(!strcmp(token[1], "x")){
                    // cross
                    cross_vect(&answer, &vectors[index1], &vectors[index2]);
                    vect_info(&answer);
                } else{
                    fprintf(stdout, "invalid no save operand\n");
                }
            } else if((index1 != -1 || index2 != -1) && !strcmp(token[1], "*")){
                    //scalar no save
                    if(index1 != -1){
                        float scale = atof(token[2]);
                        scale_vect(&answer, &vectors[index1], scale);
                        vect_info(&answer);
                    } else if(index2 != -1){
                        float scale = atof(token[0]);
                        scale_vect(&answer, &vectors[index2], scale);
                        vect_info(&answer);
                    } else{
                        fprintf(stdout, "invalid no save scale\n");
                    }
            } else{
                fprintf(stdout, "invalid no save calc\n");
            }
        } else if(token_index == 3){
            int ans_index = find_vect(vectors, token[0], num_vects);
            vect *answer;
            if(ans_index == -1){
                if(num_vects < MAX_VECTS){
                    answer = &vectors[num_vects];
                    num_vects++;
                }
            } else{
                answer = &vectors[ans_index];
            }
            float x = atof(token[2]);
            float y = atof(token[3]);
            if(num_vects <= MAX_VECTS){ //********************************************************* */
                if(!(x == 0 && y == 0) && !strcmp(token[1], "=")){
                    // assign new z=0
                    
                    new_vect(answer, token[0], x, y, 0);
                    vect_info(answer);
                } else{
                    fprintf(stdout, "invalid assign command z=0\n");
                }
            } else{
                fprintf(stdout, "only %d vects can be saved\n", MAX_VECTS);
            }
        } else if(token_index == 4){
            int index1 = find_vect(vectors, token[2], num_vects);
            int index2 = find_vect(vectors, token[4], num_vects);
            int ans_index = find_vect(vectors, token[0], num_vects);
            vect *answer;
            if(ans_index == -1){
                if(num_vects < MAX_VECTS){
                    answer = &vectors[num_vects];
                    strcpy(vectors[num_vects].name, token[0]);
                    num_vects++;
                }
            } else{
                answer = &vectors[ans_index];
            }
            float x = atof(token[2]);
            float y = atof(token[3]);
            float z = atof(token[4]);
            if(num_vects <= MAX_VECTS){ /***************************************************************** */
                if((index1 != -1 || index2 != -1) && !strcmp(token[3], "*")){
                    //scalar save
                    if(index1 != -1){
                        float scale = atof(token[4]);
                        scale_vect(answer, &vectors[index1], scale);
                        vect_info(answer);
                    } else if(index2 != -1){
                        float scale = atof(token[2]);
                        scale_vect(answer, &vectors[index2], scale);
                        vect_info(answer);
                    } else{
                        fprintf(stdout, "invalid save scale\n");
                    }
                } else if(!(x == 0 && y == 0 && z == 0) && !strcmp(token[1], "=")){
                    // assign new
                    if(!strcmp(vectors[num_vects-1].name, token[0])){
                        new_vect(answer, token[0], x, y, z);
                        vect_info(answer);
                    } else{
                        fprintf(stdout, "only %d vects can be saved\n", MAX_VECTS);
                    }
                } else if(index1 != -1 && index2 != -1){ // save operations
                    if(!strcmp(token[3], "+")){
                        // add
                        add_vect(answer, &vectors[index1], &vectors[index2]);
                        vect_info(answer);
                    } else if(!strcmp(token[3], "-")){
                        // sub
                        sub_vect(answer, &vectors[index1], &vectors[index2]);
                        vect_info(answer);
                    } else if(!strcmp(token[3], "x")){
                        // cross
                        cross_vect(answer, &vectors[index1], &vectors[index2]);
                        vect_info(answer);
                    } else{
                        fprintf(stdout, "invalid save operand\n");
                    }
                } else{
                    fprintf(stdout, "invalid save calc\n");
                }
            } else{
                fprintf(stdout, "only %d vects can be saved\n", MAX_VECTS);
            }
        } else{
            fprintf(stdout, "Invalid input\n");
        }
        printf("%d vects\n", num_vects);
    } while(strcmp(token[0], "quit"));
    return 0;
}