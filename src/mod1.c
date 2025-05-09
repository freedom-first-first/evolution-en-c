#include<stdio.h>
#include"mod1.h"
#include<gtk/gtk.h>
#include<errno.h>

list eleve=NULL;

//===================fonction d'initialisation de la liste==================//
list init(){
    return NULL;
}
//===================fonction pour verifier si la liste est vide==============//
bool is_empty(list train){
    return (train==NULL)?true:false;
}

//=================fonction d'ajout en tete de liste=========================//

list front_add(list train,const char*nom,float note){
    list new =(list)malloc(sizeof(student));
    if(new==NULL){
        printf("erreur d'allocation memoire pour l'ajout de l'etudiant");
        return train;
    }
    new->nom = malloc(strlen(nom)+1);
    strcpy(new->nom,nom);
    new->note=note;
    new->suivant=train;
    return new;
}
//=================Fonction pour récupérer la liste d'élèves==================//

void on_btn_suivant_clicked(GtkButton *bouton, gpointer user_data) {
    GtkBuilder *builder = GTK_BUILDER(user_data);
    if (!GTK_IS_BUILDER(user_data)) {
        g_printerr("ERREUR: user_data n'est pas un GtkBuilder !\n");
        return;
    }
    
    // 1. Récupération des entrées
    GtkEntry *entry_nom = GTK_ENTRY(gtk_builder_get_object(builder, "nom"));
    GtkEntry *entry_note = GTK_ENTRY(gtk_builder_get_object(builder, "note"));
    
    const gchar *nom = gtk_entry_get_text(entry_nom);
    const gchar *char_note = gtk_entry_get_text(entry_note);

    // 2. Validation et conversion de la note
    errno = 0;
    char *end;
    float note = strtof(char_note, &end);
    
    if(errno != 0 || *end != '\0' || end == char_note) {
        // Gestion d'erreur améliorée
        gtk_widget_set_tooltip_text(GTK_WIDGET(entry_note), "Note invalide. Exemple: 15.5");
        gtk_entry_set_text(entry_note, "");
        gtk_widget_grab_focus(GTK_WIDGET(entry_note));
        
        // Message dans la console
        g_printerr("Erreur: Conversion de la note impossible ('%s')\n", char_note);
        return;
    }

    // 3. Ajout de l'élève
    eleve = front_add(eleve, nom, note);
    
    // 4. Réinitialisation des champs
    gtk_entry_set_text(entry_nom, "");
    gtk_entry_set_text(entry_note, "");
    gtk_widget_grab_focus(GTK_WIDGET(entry_nom));  // Retour au champ nom

    // Optionnel: Afficher un message de succès
    g_print("Élève ajouté: %s (%.2f)\n", nom, note);
}

//==================fonction pour afficher popup======================//

/**
 * Affiche une boîte de dialogue modale
 * @param parent La fenêtre parente (peut être NULL)
 * @param message Le texte à afficher
 * @param is_error TRUE pour un message d'erreur (rouge), FALSE pour info (bleu)
 * @param buttons_type Configuration des boutons (GTK_BUTTONS_OK, GTK_BUTTONS_YES_NO, etc.)
 */
 void show_popup(GtkWindow *parent, const gchar *message, gboolean is_error, GtkButtonsType buttons_type) {
    // Crée la boîte de dialogue
    GtkWidget *dialog = gtk_message_dialog_new(parent,
                                            GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT,
                                            is_error ? GTK_MESSAGE_ERROR : GTK_MESSAGE_INFO,
                                            buttons_type,
                                            "%s", message);
    
    // Personnalisation supplémentaire
    gtk_window_set_title(GTK_WINDOW(dialog), is_error ? "Erreur" : "Succès");
    
    // Affiche la boîte de dialogue et attend la réponse
    gtk_dialog_run(GTK_DIALOG(dialog));
    
    // Détruit la boîte de dialogue après utilisation
    gtk_widget_destroy(GTK_WIDGET(dialog));
}
