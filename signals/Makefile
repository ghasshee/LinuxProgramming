
LIB = -I../ -I../lib -I../users_groups

SPELL = -std=c99 -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600 -g -W -pedantic -Wall -Wmissing-prototypes -Wno-sign-compare -Wimplicit-fallthrough -Wformat-truncation -Wcpp -D_DEFAULT_SOURCE -Wno-unused-parameter

LDLIBS = ${LINUX_LIBACL}

all :
	${CC} ${LIB} ${SPELL} ouch.c -o ouch
	${CC} ${LIB} ${SPELL} intquit.c -o intquit
	${CC} ${LIB} ${SPELL} t_kill.c -o kill



clean : 
	rm ouch intquit 
