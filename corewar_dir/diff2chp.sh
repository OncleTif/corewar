#!/bin/sh

let "i=$3"

while [ 1 ]
do
	echo "cycle" $i
./corewar -d $i $1 $2 >tmp_our.dmp
../goinfre/corewar -d $i $1 $2 >tmp_zaz.dmp
diff tmp_our.dmp tmp_zaz.dmp
if [ $? != 0 ]
then
	echo "difference au cycle " $i
	exit
fi
#read -p ""
((i=i+$4))
done
