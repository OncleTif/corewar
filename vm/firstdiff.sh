#!/bin/sh
./corewar -v 14 $1 $2 >tmp_our.dmp
../goinfre/corewar -v 14 $1 $2 >tmp_zaz.dmp
diff tmp_our.dmp tmp_zaz.dmp
