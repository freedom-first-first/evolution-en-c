#include<stdio.h>
#include<stdlib.h>
/*
on vas ecrire une fonction qui calcule la somme de 3 variable passee a la fonction main
*/
 
int main(int argc,char *argv[]){
   if(argc!=4){
     printf("le nombre d'argument ne correspond pas");
     return EXIT_FAILURE;
  }
  int somme=0;
  for(int i=1;i<=4;i++){
    somme=somme + (int)argv[i];
  }
  printf("la somme de %d + %d + %d = %d",argv[1],argv[1],argv[1],somme);
}
 