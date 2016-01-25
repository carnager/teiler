ifndef PREFIX
  PREFIX=/usr/local
endif

install:
	install -Dm755 teiler $(DESTDIR)$(PREFIX)/bin/teiler
	install -Dm644 config.example $(DESTDIR)$(PREFIX)/share/doc/teiler/config.example
	install -Dm644 README.md $(DESTDIR)$(PREFIX)/share/doc/teiler/README.md
	install -Dm644 config.example $(DESTDIR)/etc/teiler/teiler.conf
	install -Dm755 teiler_helper $(DESTDIR)$(PREFIX)/bin/teiler_helper
	install -Dm644 uploader/s3 $(DESTDIR)/etc/teiler/uploader/s3
	install -Dm644 uploader/scp $(DESTDIR)/etc/teiler/uploader/scp
	install -Dm644 profiles/mp4-pulse $(DESTDIR)/etc/teiler/profiles/mp4-pulse
	install -Dm644 profiles/mp4-noaudio $(DESTDIR)/etc/teiler/profiles/mp4-noaudio
