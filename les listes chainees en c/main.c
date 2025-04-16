#include<stdio.h>
#include "list.h"
#include<stdlib.h>
int main(){

    list class1;
    //class1 = (list)malloc(sizeof(*list));
    class1=init_student_list();
   char *nom ="kamga";
    printf("size of class1 is %d",sizeof(class1));
    class1 = push(class1,nom,18);
    display(class1);
}