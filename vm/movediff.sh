#!/bin/sh
./corewar -v 30 $1 $2 -d $3 >tmp_our.dmp
../goinfre/corewar -v 30 $1 $2 -d $3 >tmp_zaz.dmp
diff tmp_our.dmp tmp_zaz.dmp
