#include <gtk/gtk.h>

void quit ( GtkWidget *window, gpointer data)
{
  gtk_main_quit();
}
int main (int argc, char *argv[])
{
  GtkWidget *window;
  GtkWidget *dialog;
  GtkWidget *label, *message;
  gint result;
  gtk_init(&argc, &argv);
  window = gtk_window_new 
    (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW(window), "Dialog Box");
  gtk_window_set_position (GTK_WINDOW(window), 
			   GTK_WIN_POS_CENTER);
  gtk_window_set_default_size (GTK_WINDOW 
			       (window), 200, 80);
  gtk_signal_connect ( G_OBJECT (window), 
		       "destroy", G_CALLBACK (quit), NULL);
  dialog = gtk_dialog_new_with_buttons ("Emergency!", 
					GTK_WINDOW (window), 
					GTK_DIALOG_DESTROY_WITH_PARENT, 
					GTK_STOCK_YES, GTK_RESPONSE_YES, 
					GTK_STOCK_NO, GTK_RESPONSE_NO, NULL); 
  label = gtk_label_new ("Do You Want Sleep?");

  gtk_box_pack_start (GTK_BOX (GTK_DIALOG 
			       (dialog)->vbox), label, TRUE, TRUE, 5); 
  gtk_widget_show_all (dialog); 
  result = gtk_dialog_run (GTK_DIALOG (dialog)); 
  switch (result) { 
  case GTK_RESPONSE_YES: 
    message = gtk_label_new ("Yes, Please Plase..."); 
    break; 
  case GTK_RESPONSE_NO: 
    message = gtk_label_new ("Nope."); 
    break; 
  default: 
    message = gtk_label_new ("You Can't Sleep, Try Again."); 
  } 
  gtk_widget_destroy (dialog); 
  gtk_container_add (GTK_CONTAINER(window), 
		     message);
  gtk_widget_show_all(window);
  gtk_main ();
  return 0;
}
