#include <gtk/gtk.h>
enum
  {
    FIRST_COLUMN,
    SECOND_COLUMN,
    N_COLUMNS
  }

  void quit ( GtkWidget *window, gpointer data)
  {
    gtk_main_quit();
  }
int main (int argc, char *argv[])
{
  GtkWidget *window; 
  GtkListStore *store;
  GtkWidget *view;
  GtkTreeIter iter;
  GtkCellRenderer *renderer;
  int i;
  gtk_init(&argc, &argv);
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "List");
  gtk_window_set_default_size ( GTK_WINDOW(window), 
				300, 200);
  g_signal_connect ( G_OBJECT (window), "destroy", 
		     G_CALLBACK (quit), NULL);
  store = gtk_list_store_new (N_COLUMNS, 
			      G_TYPE_STRING, G_TYPE_INT);
  for (i = 0; i < 5; i++) {
    gtk_list_store_append (store, &iter);
    gtk_list_store_set (store, &iter, 
			FIRST_COLUMN, "This Row's NUM ",
			SECOND_COLUMN, i, -1);
  }
  view = gtk_tree_view_new_with_model 
    (GTK_TREE_MODEL (store));
  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes 
    (GTK_TREE_VIEW(view), 0, "TITLE", renderer, "title", 
     FIRST_COLUMN, NULL);
  gtk_tree_view_insert_column_with_attributes(
					      GTK_TREE_VIEW(view), 1, "INDEX", renderer, "text", SECOND_COLUMN, NULL);
  gtk_container_add(GTK_CONTAINER(window), view);
  gtk_widget_show_all(window);
  gtk_main ();
  return 0;
}
