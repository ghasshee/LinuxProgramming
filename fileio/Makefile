
LIB = -I ../ -I ../lib 
CC = cc ${LIB} 

cp : 
	${CC} copy.c -o cp 
	${CC} seek_io.c -o seek 
	${CC} large_file.c -o large_file
	${CC} temp.c -o temp


clean : 
	rm a.out ./cp ./seek ./temp ./large_file 
