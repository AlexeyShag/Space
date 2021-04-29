#!/bin/bash


ABSOLUTE_FILENAME=`readlink -e "$0"`
path_to_folder=`dirname "$ABSOLUTE_FILENAME"`
out_folder="../include"

a=`realpath $path_to_folder`

rm -r $out_folder
mkdir $out_folder

for file in `find $path_to_folder -type f -name "*.h"`
do

	f=`realpath $file`
	echo $f
	file="${file:1}"

	f=`basename $f`


	touch "${out_folder}/${f}"
   	cp -r "/${file}" "./${out_folder}/${f}"

done


echo all include have been coping
