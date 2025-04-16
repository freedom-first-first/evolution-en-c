#include<stdio.h>
#include "list.h"
#include<stdlib.h>
#include<string.h>

/*student initialisation fonction*/
list init_student_list(){
    return NULL;
}
/*fonction pour ajouter un element a la list*/
list push(list student_list, char *nom, int age){
    list student;
    student = (list)malloc(sizeof(*student_list));
    if(student==NULL){
        printf("erreur d'allocation de la memoire pour la list\n");
        return 0;
    }
    //student_list->suivant=student;
    student->suivant=student_list;
    student->nom =(char*)malloc(sizeof(char)*strlen(nom)+1);
    //student->nom=nom;
    strcpy(student->nom,nom);
    student->age=age;
   // student_list=student;
    return student;

}

void display(list student_list){
    int i=0;
    if(student_list!=NULL){
        printf("les identifiant de l'etudiant %d est [nom: %s  age: %d]",i,student_list->nom,student_list->age);
        return display(student_list->suivant);
    }
    
}

