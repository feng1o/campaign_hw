#!/bin/bash 
echo "one key complie "
echo
sh /home/huawei-code-craft/SDK-gcc/batch32.sh
echo 
/home/huawei-code-craft/SDK-gcc/bin/future_net  /home/huawei-code-craft/test-case/topo.csv  /home/huawei-code-craft/test-case/demand.csv  /home/huawei-code-craft/test-case/result.csv 