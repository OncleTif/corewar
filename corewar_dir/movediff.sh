#!/bin/sh
./corewar -v -1 $1 $2 -d $3 >tmp_our.dmp
./goinfre/corewar -v -1 $1 $2 -d $3 >tmp_zaz.dmp
diff tmp_our.dmp tmp_zaz.dmp
