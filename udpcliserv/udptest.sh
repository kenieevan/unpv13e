#!/bin/bash
i=0
nu=${1}
port=${2}
if [ $# -ne 2 ]
then
	echo "input loop port"
	exit 1
fi

while [ $i -lt $nu ]
do
   ip net exec 172-ns ./udpcli01 100.64.0.1 $port < input 
   i=$[$i+1]
   port=$[$port+1]
done
