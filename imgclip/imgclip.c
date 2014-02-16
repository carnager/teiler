#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

void 
on_owner_change(GtkClipboard *cb, GdkEvent *event, gpointer data) {
    static int count;
    (void) cb, (void) event, (void) data;

    if (++count > 1) {
        gtk_main_quit();
    }
}

int 
main(int argc, char **argv) {
    GtkClipboard *cb = NULL;
    GdkPixbuf *image = NULL;
    GError *e = NULL;

    if (argc == 1 || !g_file_test(argv[1], G_FILE_TEST_EXISTS)) {
        fprintf(stderr, "usage: %s <file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    image = gdk_pixbuf_new_from_file(argv[1], &e);
    if (image == NULL) {
        fprintf(stderr, "%s\n", e->message);
        return EXIT_FAILURE;
    }

    gtk_init(&argc, &argv);

    cb = gtk_clipboard_get(GDK_NONE);
    gtk_clipboard_set_image(cb, image);
    g_signal_connect(G_OBJECT(cb), "owner-change", G_CALLBACK(on_owner_change), NULL);

    gtk_main();

    g_object_unref(image);

    return EXIT_SUCCESS;
}
