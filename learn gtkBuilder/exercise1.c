#include<gtk/gtk.h>

GtkBuilder *builder;
GtkWidget *main_window;
//gtk_button *btn_test;
GError *error=NULL;

void on_btn_quit_clicked(GtkButton *button,gpointer user_data){
    gtk_main_quit();
}
void on_btn_transmut_clicked(GtkButton *button,gpointer user_data){
    GtkEntry *entry = GTK_ENTRY(user_data);
    if(entry==NULL){
        g_error("witget not found");
    }
    const gchar *text = gtk_entry_get_text(entry);
    GtkLabel *container = GTK_LABEL(gtk_builder_get_object(builder,"result"));

    gtk_label_set_text(container,text);
}

int main(int argc,char**argv){
    gtk_init(&argc,&argv);
//initialisation du builder
    builder =gtk_builder_new();
    // chargement du .glade 
    gtk_builder_add_from_file(builder,"exercise1.glade",&error);
    if(error) {
        g_print("erreur de chargement de glade %s\n",error->message);
        g_error_free(error);
    }
    //recuperation de la fenetre par son id
    main_window=GTK_WIDGET(gtk_builder_get_object(builder,"main_window"));
    //recuperation de l'entry
    GtkEntry *entry =GTK_ENTRY(gtk_builder_get_object(builder,"text"));
    //connexion automatique des signaux
    gtk_builder_connect_signals(builder,entry);
   // GtkButton *button=GTK_WIDGET(gtk_builder_get_object(builder,btn_quit));
    //connexion des signals
    

    gtk_widget_show_all(main_window);
    gtk_main();
    g_object_unref(builder);
}