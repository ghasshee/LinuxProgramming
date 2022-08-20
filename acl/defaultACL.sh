#!/bin/sh 

sudo useradd paulh
sudo groupadd teach 

setfacl -d -m u::rwx,u:paulh:rw,g::rx,g:teach:rwx,o::- sub
getfacl -d --omit-header sub


sudo userdel paulh
sudo groupdel teach 


