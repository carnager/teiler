CFLAGS := ${CFLAGS} -std=c99 -Wall -Wextra -Werror -pedantic ${CPPFLAGS}
DOBUILD:=1

ifeq ($(shell pkg-config --exists gtk+-3.0 && echo 1), 1) 
	CFLAGS += $(shell pkg-config --cflags gtk+-3.0)
	LDFLAGS = $(shell pkg-config --libs gtk+-3.0)
else ifeq ($(shell pkg-config --exists gtk+-3.0 && echo 1), 1) 
	CFLAGS += $(shell pkg-config --cflags gtk+-2.0)
	LDFLAGS = $(shell pkg-config --libs gtk+-2.0)
else
	DOBUILD:=0
endif

PREFIX=/usr
BINDIR=${PREFIX}/bin
INSTALLDIR=${DESTDIR}${BINDIR}

SOURCE := imgclip.c
TARGET := imgclip

all: ${TARGET}

${TARGET}: ${SOURCE}
ifneq (${DOBUILD}, 0)
	@echo ${CC} $^ -o $@ 
	@${CC} $^ -o $@ ${CFLAGS} ${LDFLAGS} 
else 
	@echo "imgclip: neither gtk3 nor gtk2 are installed, skipping build"
endif

install: 
ifeq ($(wildcard ${TARGET}),)
	@echo "imgclip: no target created, skipping install" 
else
	install -d ${INSTALLDIR} 
	install -m 755 ${TARGET} ${INSTALLDIR}/${TARGET} 
endif


clean: 
	${RM} ${TARGET}

.PHONY: clean
