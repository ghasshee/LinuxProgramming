
LIB = -I ../ -I ../lib 
CC = cc ${LIB} -D_XOPEN_SOURCE=600 -g -W -pedantic -Wall -Wformat-truncation -Wcpp -D_DEFAULT_SOURCE 

all :
	${CC} t_stat.c -o t_stat


clean : 
	rm a.out ./t_stat
