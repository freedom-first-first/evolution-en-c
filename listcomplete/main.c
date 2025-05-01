#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"student.h"

int main(){
    cellule_eleve *eleve;
    eleve = init();
    char matricule[]="24f2920";
    char nom[]="kamga";
    char prenom[]="edgar";
    char birthday[]="01/07/2006";
    int level = 1;
    eleve = front_add(eleve,matricule,nom,prenom,birthday,level);
    print_list(eleve);
}