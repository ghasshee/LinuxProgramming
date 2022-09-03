
LIB = -I../ -I../lib -I../users_groups

SPELL = -std=c99 -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600 -g -W -pedantic -Wall -Wmissing-prototypes -Wno-sign-compare -Wimplicit-fallthrough -Wformat-truncation -Wcpp -D_DEFAULT_SOURCE -Wno-unused-parameter

LDLIBS = ${LINUX_LIBACL}


all :
	${CC} ${LIB} ${SPELL} t_unlink.c -o t_unlink 
	${CC} ${LIB} ${SPELL} list_files.c -o ls
	${CC} ${LIB} ${SPELL} tree_dir.c -o tree



clean : 
	rm a.out ./acl_view
