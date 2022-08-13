#!/bin/sh

# if not installed setfattr on linux 
# first install attr by 
# sudo apt install attr ## on UBUNTU

touch tfile 
getfattr -d tfile

setfattr -n user.x -v "The past is not dead." tfile
setfattr -n user.y -v "In fact, it's not even past." tfile
getfattr -n user.x tfile

getfattr -m 'T.*' tfile

getfattr -d tfile 


setfattr -n user.x tfile
getfattr -d tfile 

setfattr -n user.y tfile
getfattr -d tfile 
