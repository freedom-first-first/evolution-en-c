#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include<errno.h>
#include"mod1.h"

GtkWidget *main_window;
GtkWidget *entries_window;

//=========================callback pour le bouton entrees=========================//

void on_button_show_entries_clicked(GtkButton *entrees, gpointer user_data){
    //recuperer la position de la fenetre principale

    int x,y;
    gtk_window_get_position(GTK_WINDOW(main_window),&x,&y);
    /*positionner la entries_window au meme endroit*/

    gtk_window_move(GTK_WINDOW(entries_window),x,y);

    /*affiche la entries_window*/
    gtk_widget_show_all(entries_window);

    //gtk_widget_show(entries_window);
   gtk_widget_hide(main_window);

}

// Déclaration externe du builder si nécessaire

int recupere(const char *id, GtkBuilder *builder) {
    // 1. Récupération du widget
    GtkWidget *widget = GTK_WIDGET(gtk_builder_get_object(builder, id));
    if (!widget || !GTK_IS_ENTRY(widget)) {
        g_warning("Entry with id '%s' not found", id);
        return 0;
    }

    GtkEntry *entry = GTK_ENTRY(widget);

    // 2. Récupération du texte (pas besoin de malloc)
    const gchar *text = gtk_entry_get_text(entry);
    
    // 3. Vérification du texte vide
    if (text == NULL || *text == '\0') {
        gtk_widget_set_tooltip_text(GTK_WIDGET(entry), "Veuillez saisir un nombre");
        return 0;
    }

    // 4. Conversion en entier
    char *end;
    long val = strtol(text, &end, 10);
    
    // 5. Vérification de la conversion complète
    if (*end != '\0') {
        gtk_widget_set_tooltip_text(GTK_WIDGET(entry), "Caractères invalides détectés");
        return 0;
    }

    // 6. Vérification des limites pour int
    if (val < INT_MIN || val > INT_MAX) {
        gtk_widget_set_tooltip_text(GTK_WIDGET(entry), "Nombre trop grand");
        return 0;
    }

    return (int)val;
}



void on_stat_btn_clicked(GtkButton *button,gpointer user_data){
    GtkBuilder *builder = GTK_BUILDER(user_data);
    int nbr_inscrits = recupere("nbr_inscrits",user_data);
    int nbr_presents = recupere("nbr_presents",user_data);
    int nbr_cours_prevues = recupere("nbr_cours_prevues",user_data);
    int nbr_cours_faits = recupere("nbr_cours_faits",user_data);
    int heures_prevues = recupere("heures_prevues",user_data);
    int heures_faites = recupere("heures_faites",user_data);
    // Pour un message de succès avec juste OK
show_popup(GTK_WINDOW(main_window), "Opération réussie !", FALSE, GTK_BUTTONS_OK);
    
}

int main(int argc,char *argv[]){

    GtkBuilder *builder;

    //initialisation de GTK
    gtk_init(&argc, &argv);

    //creation du builder;

    builder = gtk_builder_new();
     
    //chargement du fichier glade

    //gtk_builder_add_from_file(builder,"gtk1.glade",NULL);
    GError *error = NULL;
if (!gtk_builder_add_from_file(builder, "gtk1.glade", &error)) {
    g_printerr("Erreur de chargement du fichier Glade : %s\n", error->message);
    g_clear_error(&error);
    return 1;
}

    
    //recuperation des fenetres 

    main_window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));
    entries_window = GTK_WIDGET(gtk_builder_get_object(builder,"entries_window"));
    gtk_widget_hide(entries_window);
    gtk_widget_show_all(main_window);
    
    // connexion des signaux

    gtk_builder_connect_signals(builder,builder);
    g_print("Signaux connectés avec succès\n");


   

    /*boucle principale*/
    gtk_main();
     //liberation de la memoire
     g_object_unref(builder);

    return 0;
}