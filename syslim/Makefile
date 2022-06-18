
LIB = -I ../ -I ../lib 
CC = cc ${LIB} 

cp : 
	${CC} t_sysconf.c -o t_sysconf 
	${CC} t_fpathconf.c -o t_fpathconf 


clean : 
	rm a.out ./t_sysconf ./t_fpathconf
