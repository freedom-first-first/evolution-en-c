#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"student.h"

//definition de la fonction d'initialisation de la liste d'etudiant
list init(){
    return NULL;
}

//fonction de verification si la liste est vide

bool is_empty(list student_list){
    bool booleen;
    return booleen=(student_list==NULL)?TRUE:FALSE;
}



/*================================================================================================*/

//definition de la fonction d'ajout d'un etudiant dans la liste

list front_add(list eleve,char *matricule,char *nom,char *prenom, char*birthday,int level){
    list new_student = (list)malloc(sizeof(cellule_eleve));
    if(new_student==NULL) return new_student;
    new_student->matricule = malloc(strlen(matricule)+1);
    strcpy(new_student->matricule,matricule);
    new_student->nom = malloc(strlen(nom)+1);
    strcpy(new_student->nom,nom);
    new_student->prenom = malloc(strlen(prenom)+1);
    strcpy(new_student->prenom,prenom); 
    new_student->birthday = malloc(strlen(birthday)+1);
    strcpy(new_student->birthday,birthday);
     new_student->suivant=eleve;
     return new_student;
}

//definition de la fonction de retrait en debut

list pop_front(list eleve){
    if(is_empty(eleve)) return eleve;
    list temp=eleve;
    eleve=eleve->suivant;
    free(temp->matricule);
    free(temp->nom);
    free(temp->prenom);
    free(temp->birthday);
    free(temp);
    return eleve;
}


//===============================================fonction d'affichage de la liste des etudiants=============================================//

void print_list(list eleve){
    while(eleve->suivant!=NULL){
        if(is_empty(eleve)) printf("nothing to print");
        printf("votre matricule est : %s\n",eleve->matricule);
        printf("votre nom est : %s\n",eleve->nom);
        printf("votre prenom est : %s\n",eleve->prenom);
        printf("votre birthsay est : %s\n",eleve->birthday);
        printf("votre niveau est : %d\n",eleve->level);

        eleve=eleve->suivant;
    }
}


