#include <stdio.h>
void affiche_tab(int *p,int n){
    int i;
    for(i=0;i<n;i++){
        printf("[%d] ",p[i]);
    }
    printf("\n");
}
void permut(int *a ,int *b){
    int temp=*a;
    *a = *b;
    *b = temp;  
}

void select(int *p,int n){
    int i ,j;
    int min;
    for(i=0;i<n-1;i++){
        min=i;
        j=i+1;

        for(j;j<n;j++){
            if(p[j]<p[min]){
                min=j;
            }
        }
        if(min!=i){
            permut(&p[i],&p[min]);
        }
    }
}

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
    select(p,5);
    printf("the array after sort is : "); 
    affiche_tab(p,5); 
    printf("the array before sort is : ");
   int t[]={1,3,5,4,6};
    affiche_tab(t,5);
    insertion(t,5);
    printf("the array after sort is : "); 
    affiche_tab(t,5); 
}