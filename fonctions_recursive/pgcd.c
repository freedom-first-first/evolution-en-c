#include <stdio.h>
#include <conio.h>

 /*
 on a l'algorithme suivant 
(1):pgcd(a,b)= a si b = 0; et (2):pgcd(a,b)=pgcd(b,a%b) sinon
 implementez une fonction recurcive en c qui resout ce  probleme. 
 je propose ma solution.
  
 tout d'abord c'est quoi une fonction recurcive c'est une fonction qui s'appelle elle meme .
                 =======================================
                 =commment ecrit une fonction recursive=
                 =======================================
  un fonction recursive est constituee de deux principale partie la comprehension de ces deux 
  partie facilite grandement l'ecrit des fonctions recurcives car l'ecriture se resume a la def-
  inition de deux contions on donc
  **la close de base 
  **la condition de sortie.
     
  Dans notre cas 
 */

 int pgcd(int a,int b){
    int PGCD;
    if(b==0/*condition de sortie*/){
        PGCD=a;
        return PGCD;
    }else{
        /*int temp;
        temp=a;
        a=b;
        b=temp%b;*/
        return pgcd(b,a%b);
    }
 }
 int main(){
    int a,b;
    printf("entrer un nombre: ");
    scanf("%d",&a);
    printf("\n");
    printf("entrer le deuxieme nombre inferieur au premier: ");
    scanf("%d",&b);
    printf("\n");

    printf("pgcd(%d,%d)=%d",a,b,pgcd(a,b));
    getch();


 }