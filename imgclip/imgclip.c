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

void 
on_timeout_expired(gpointer data) {
    (void) data;

    gtk_main_quit();
}

int main(int argc, char **argv) {
    int ret = EXIT_FAILURE;
    GtkClipboard *cb = NULL;
    GdkPixbuf *image = NULL;
    GError *e = NULL;
    GOptionContext *opt_ctx = NULL;
    char *help = NULL;
    static int timeout;
    static const GOptionEntry entries[] = {
        { "timeout", 't', 0, G_OPTION_ARG_INT, &timeout, "Timeout", "secs" }, 
        { NULL, 0, 0, 0, NULL, NULL, NULL }
    };

    opt_ctx = g_option_context_new("<file>");

    g_option_context_add_main_entries(opt_ctx, entries, NULL);
    if (!g_option_context_parse(opt_ctx, &argc, &argv, &e)) {
        fprintf(stderr, "%s\n", e->message);
        goto error_out;
    }

    if (argc == 1 || !g_file_test(argv[1], G_FILE_TEST_EXISTS)) {
        help = g_option_context_get_help(opt_ctx, TRUE, NULL);
        fprintf(stderr, "%s", help);
        g_free(help);
        goto error_out;
    }

    image = gdk_pixbuf_new_from_file(argv[1], &e);
    if (image == NULL) {
        fprintf(stderr, "%s\n", e->message);
        goto error_out;
    }

    gtk_init(&argc, &argv);

    cb = gtk_clipboard_get(GDK_NONE);
    gtk_clipboard_set_image(cb, image);
    g_signal_connect(G_OBJECT(cb), "owner-change", G_CALLBACK(on_owner_change), NULL);

    if (timeout > 0) {
        g_timeout_add_seconds(timeout, (GSourceFunc)on_timeout_expired, NULL);
    }

    gtk_main();

    g_object_unref(image);

    ret = EXIT_SUCCESS;

error_out: 
    g_option_context_free(opt_ctx);

    return ret;
}
