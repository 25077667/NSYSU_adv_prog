#!/bin/bash

echo Packing $1.zip

file_path=$(find . -type d -name "$1")
if [ ! -d "${file_path}" ]; then
	echo sol not found\!
	exit
fi

grep -oE $1 submited.txt &>/dev/null
if [ $? = 0 ]; then
	echo submited
	exit
fi

cat ${file_path}/*.c* | xclip -selection c

mkdir $1
cp -r `find . -type d -name "$1" | tail -n 1` $1/
cp *.txt *.sh $1/

gedit $1/解法說明.txt

mv *.png $1/
if [ $? != 0 ]; then
	echo No screen shot\!
	####rm -rf $1/
	exit
fi

zip -r -9 B073040047-楊志璿-$1.zip $1/*

rm -rf $1/

echo $1 >> submited.txt
sed -i "/^$1\$/d" unsubmit.txt 
echo unsubmit.txt

echo done.
