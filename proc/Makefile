
LIB = -I ../ -I ../lib 
CC = cc ${LIB} 

cp : 
	${CC} mem_segments.c -o mem_segments
	${CC} modify_env.c   -o modify_env 


clean : 
	rm a.out ./mem_segments ./modify_env 
