#include <stdio.h>
#include <stdarg.h>
/*
prototype des fonctions variadic: type_fonction nom_fonction(argument_fixe,...);
va_list : contient tous les argument de l'utilisateurs
va_start(nom_list,argument);:permet d'initialiser la liste d'argument.
va_arg(nom_list,type);
va_end(nom_list);
*/

void somme_variadic(int count,...){
    va_list list;//va_list cree une liste d'argument nommer list
    va_start(list,count);//va_start(nom_list,nombre_argument) initialise list apres count c'est a dire faire pointer nom_list sur le premier argument.
    int somme=0;
    printf("{");
    for(int i=1;i<=count;i++){
        somme=somme+va_arg(list,int);// va_arg(nom_list,type_argument_recuperer); permet de recuperer les argument les uns apres les autres en deplacessant progressivement le pointer nom_list 
        printf("'%p / %d' ",list ,*list);
    }
    printf("}");

    printf("la somme de ses chiffres est de %d",somme);
    va_end(list);//netoyer la liste libere la memoires.

}

int main(){

    printf("entrer le nombre de nombre entier de la liste a somme : ");

    somme_variadic(5,1,3,5,5,6);
}