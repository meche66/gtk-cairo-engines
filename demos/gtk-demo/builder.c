/* Builder
 *
 * Demonstrates an interface loaded from a XML description.
 */

#include <gtk/gtk.h>
#include "demo-common.h"

void
quit_activate (GtkAction *action)
{
}

void
about_activate (GtkAction *action)
{
  GtkWidget *about_dlg;

  about_dlg = gtk_about_dialog_new ();
  gtk_about_dialog_set_name (GTK_ABOUT_DIALOG (about_dlg), "GtkBuilder demo");
  gtk_dialog_run (GTK_DIALOG (about_dlg));
  gtk_widget_destroy (about_dlg);
}

GtkWidget *
do_builder (GtkWidget *do_widget)
{
  static GtkWidget *window = NULL;
  GtkBuilder *builder;
  GError *err = NULL;
  gchar *filename;
  
  if (!window)
    {
      builder = gtk_builder_new ();
      filename = demo_find_file ("demo.ui", NULL);
      gtk_builder_add_from_file (builder, filename, &err);
      g_free (filename);
      if (err)
	{
	  g_error ("ERROR: %s\n", err->message);
	  return NULL;
	}
      gtk_builder_connect_signals (builder, NULL);
      window = GTK_WIDGET (gtk_builder_get_object (builder, "window1"));
    }

  if (!GTK_WIDGET_VISIBLE (window))
    {
      gtk_widget_show_all (window);
    }
  else
    {	 
      gtk_widget_destroy (window);
      window = NULL;
    }


  return window;
}