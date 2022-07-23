#/bin/sh

mkdir top
mkdir src1
touch src1/aaa
mount -bind src1 top
mkdir top/sub
mkdir src2
touch src2/bbb
mount --bind src2 top/sub
find top
## top
## top/aaa
## top/sub
## top/sub/bbb

mkdir dir1
mount --bind top dir1
find dir1
## dir1
## dir1/aaa
## dir1/sub
##              ## here dir1/sub/bbb does not exist!

mkdir dir2
mount --rbind top dir2
find dir2
## dir2
## dir2/aaa
## dir2/sub
## dir2/sub/bbb

