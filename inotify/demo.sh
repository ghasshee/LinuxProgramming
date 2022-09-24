#!/bin/sh 


./demo_inotify dir1 dir2 & 


echo "Hello World" > aaa

mv aaa dir1/ 

mv dir1/aaa dir2/bbb

killall demo_inotify


