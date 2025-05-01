#ifndef student_h_
#define student_h_

typedef struct cellule_etudiant{
    char *matricule;
    char *nom;
    char *prenom;
    char *birthday;
    int level;
    struct cellule_etudiant*suivant;
}*list,cellule_eleve;

//creation du type booleen 

typedef enum bool{
    FALSE,
    TRUE
}bool;

//initialisation de la list
list init();

//===========================================fonction pour tester si une liste est vide==============================================//

bool is_empty(list student_list);

//============================== declaration de la fonction d'ajout d'un etudiant en debut de la liste===============================//

list front_add(list eleve,char *matricule,char *nom,char *prenom, char*birthday,int level);


//============================================definition de la fonction de retrait en debut=======================================//

list pop_front(list eleve);

//===============================================fonction d'affichage de la liste des etudiants=============================================//

void print_list(list eleve);

#endif
