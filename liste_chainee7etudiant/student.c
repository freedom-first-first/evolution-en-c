//student.c file
#include "student.h"
#include<stdio.h>
#include<stdlib.h>
// list initialisation

void init(list user_list){
    user_list = NULL;
}

/*---------------------------------------------------Add element to our list----------------------------------------------------------------------------*/

list push(list user_list,float*user_float){
    list new;
    new = (list)malloc(sizeof(float_list));
    if(new==NULL){
        printf("errlloc");
        return NULL;
    }
    new->float_array = malloc(sizeof(float)*7);
    if(new->float_array==NULL){
        printf("errlloc");
        return NULL;
    }
    new->float_array = user_float;
    new->suivant = user_list;
    user_list = (list)malloc(sizeof(float_list));
    if(user_list==NULL){
        printf("errlloc");
        return NULL;
    }
   // user_list = new;
    return new;
}

/*------------------------- state of the list -----------------------------------------------------------------------*/

bool if_empty(list user_list){
    if(user_list == NULL) return false;
    else return true;
}

/*------------------------------------------- display----------------------------------------------------------------*/

void display(list user_list) {
    if (!if_empty(user_list)) {
        printf("The list is empty.\n");
        return;
    }
    while (user_list != NULL) {
        for (int i = 0; i < 7; i++) {
            printf("float[%d]: %.2f\n", i + 1, user_list->float_array[i]);
        }
        user_list = user_list->suivant;
    }
}
/*------------------------------------------- free list----------------------------------------------------------------*/
void free_list(list user_list) {
    list temp;
    while (user_list != NULL) {
        temp = user_list;
        user_list = user_list->suivant;
        free(temp->float_array); // Free the float array
        free(temp); // Free the node itself
    }
}