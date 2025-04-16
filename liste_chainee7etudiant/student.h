//student.h file.
#ifndef _student_h
#define _student_h
//definition d'une cellule de la liste chainee
typedef struct float_list {
    float *float_array;
    struct float_list *suivant;
}*list, float_list;

//definition du type booleen

typedef enum bool{
    false,
    true
}bool;

//prototypes initialisation de la liste

void init(list user_list);

/*---------------------------------------------------Add element to our list----------------------------------------------------------------------------*/

list push(list user_list,float*user_float);


/*------------------------- state of the list -----------------------------------------------------------------------*/

bool if_empty(list user_list);

/*------------------------------------------- display----------------------------------------------------------------*/

void display(list user_list);

 
 
/*------------------------------------------- free list----------------------------------------------------------------*/
void free_list(list user_list);

#endif