#!/bin/sh

let "i=1"

while [ 1 ]
do
./corewar -d $i ../goinfre/champions/examples/bigzork.cor ../goinfre/champions/examples/zork.cor ../goinfre/champions/examples/helltrain.cor
read -p "test"
((i++))
done
