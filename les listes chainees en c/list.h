#ifndef _list_h_
#define _list_h_

/*structure de representation d'un etudiant*/
typedef struct student_list{
    struct student_list *suivant;
    char *nom;
    int age;
} *list, student_list;
/*fonction d'initialisation de la list*/
list init_student_list();
/*fonction d'ajout d'un element dans la list*/
list push(list student_list, char *nom, int age);
//fonction pour afficher les elements de la list
void display(list student_list);


#endif 