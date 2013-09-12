#!/usr/bin/env python2
import gtk 
import sys

count = 0
def handle_owner_change(clipboard, event):
    global count
    print 'clipboard.owner-change(%r, %r)' % (clipboard, event)
    count += 1
    if count > 1:
       sys.exit(0)

image = gtk.gdk.pixbuf_new_from_file(sys.argv[1])
clipboard = gtk.clipboard_get()
clipboard.connect('owner-change', handle_owner_change)
clipboard.set_image(image)
clipboard.store()
gtk.main()

