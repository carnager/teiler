CFLAGS := ${CFLAGS} -std=c99 -Wall -Wextra -Werror -pedantic ${CPPFLAGS}

ifeq ($(shell pkg-config --exists gtk+-3.0 && echo 1), 1) 
	CFLAGS += $(shell pkg-config --cflags gtk+-3.0)
	LDFLAGS = $(shell pkg-config --libs gtk+-3.0)
else
	CFLAGS += $(shell pkg-config --cflags gtk+-2.0)
	LDFLAGS = $(shell pkg-config --libs gtk+-2.0)
endif

PREFIX=/usr
BINDIR=${PREFIX}/bin
INSTALLDIR=${DESTDIR}${BINDIR}

SOURCE := imgclip.c
TARGET := imgclip

all: ${TARGET}

${TARGET}: ${SOURCE}
	@echo ${CC} $^ -o $@
	@${CC} $^ -o $@ ${CFLAGS} ${LDFLAGS}

install: 
	install -d ${INSTALLDIR}
	install -m 755 ${TARGET} ${INSTALLDIR}/${TARGET}

clean: 
	${RM} ${TARGET}

.PHONY: clean
