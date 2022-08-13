#!/bin/sh 

make 

echo 'All operating systems provide services for programs they run' > apue
chmod g+s apue
cat apue 

./t_stat apue
