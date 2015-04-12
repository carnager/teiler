ifndef PREFIX
  PREFIX=/usr/local
endif

install:
	install -Dm755 teiler $(DESTDIR)$(PREFIX)/bin/teiler
	install -Dm644 config.example $(DESTDIR)$(PREFIX)/share/doc/teiler/config.example
	install -Dm644 README.md $(DESTDIR)$(PREFIX)/share/doc/teiler/README.md
	install -Dm644 config.example $(DESTDIR)/etc/teiler.conf
