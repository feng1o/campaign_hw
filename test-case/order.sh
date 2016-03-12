#!/bin/bash 
echo "one key complie "
echo
sh /home/huawei-code-craft/SDK-gcc/batch32.sh
echo 
/home/huawei-code-craft/SDK-gcc/bin/future_net  topo.csv  demand.csv  result.csv 
