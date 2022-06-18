
LIB = -I ../ -I ../lib 
CC = cc ${LIB} 

cp : 
	${CC} procfs_pidmax.c -o procfs_pidmax
	${CC} t_uname.c -o t_uname


clean : 
	rm a.out ./procfs_pidmax ./t_uname
