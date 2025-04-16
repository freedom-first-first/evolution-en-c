#include <stdio.h>
extern void affiche_tab(int *p,int n);
extern void permut(int *a ,int *b);
void insertion(int *p,int n){
    for(int i=1;i<n;i++){
        for(int j=i;j>0;j--){
            if(p[j-1]>p[j])
            permut(&p[j-1],&p[j]);
        }
    }
}

int main(){
    int p[]={1,3,5,4,6};
    printf("the array before sort is : ");
    affiche_tab(p,5);
    insertion(p,5);
    printf("the array after sort is : "); 
    affiche_tab(p,5); 
}