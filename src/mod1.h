#ifndef _mod1_h
#define _mod1_h
#include<gtk/gtk.h>

typedef struct cellule{
    char *nom;
    float note;
    struct cellule *suivant;
}student,*list;

extern list eleve;

//=====================declaration du type boolean============================//
typedef enum bool{
    true,
    false
}bool;

//===================fonction d'initialisation de la liste==================//

list init();

//===================fonction pour verifier si la liste est vide==============//

bool is_empty(list train);

//=================fonction d'ajout en tete de liste=========================//

list front_add(list train,const char*nom,float note);

//=================fonction pour recuper la liste d'eleve========================//
void on_btn_suivant_clicked(GtkButton *bouton,gpointer user_data);

//==================fonction pour afficher popup======================//

/**
 * Affiche une boîte de dialogue modale
 * @param parent La fenêtre parente (peut être NULL)
 * @param message Le texte à afficher
 * @param is_error TRUE pour un message d'erreur (rouge), FALSE pour info (bleu)
 * @param buttons_type Configuration des boutons (GTK_BUTTONS_OK, GTK_BUTTONS_YES_NO, etc.)
 */
 void show_popup(GtkWindow *parent, const gchar *message, gboolean is_error, GtkButtonsType buttons_type);

#endif