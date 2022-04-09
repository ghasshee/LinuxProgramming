



cp : 
	cc copy.c -o cp 
	cc seek_io.c -o seek 
	cc large_file.c -o large_file
	cc temp.c -o temp


clean : 
	rm a.out cp 
