ifndef PREFIX
  PREFIX=/usr/local
endif

install:
	install -Dm755 teiler $(DESTDIR)$(PREFIX)/bin/teiler
	install -Dm644 config.example $(DESTDIR)$(PREFIX)/share/doc/teiler/config.example
	install -Dm644 README.md $(DESTDIR)$(PREFIX)/share/doc/teiler/README.md
	install -Dm644 config.example $(DESTDIR)/etc/teiler.conf
	install -Dm755 teiler_helper $(DESTDIR)$(PREFIX)/bin/teiler_helper
	install -Dm755 uploader/s3 $(DESTDIR)$(PREFIX)/share/doc/teiler/uploader/s3
	install -Dm755 uploader/scp $(DESTDIR)$(PREFIX)/share/doc/teiler/uploader/scp
