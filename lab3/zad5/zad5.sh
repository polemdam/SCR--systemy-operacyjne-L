#!/bin/bash
a=1;
CZAS_H=`date +%H`
CZAS_M=`date +%M`
trap 'print "Control-C cannot terminate this script."' INT
trap 'print "kill -quit cannot terminate this script."' QUIT
trap 'print "kill -fpe cannot terminate this script."' FPE
trap 'print "kill -ill cannot terminate this script."' ILL

while [ $a -le 100 ] ; do
   # echo "I am still alive...."
    echo $CZAS_H':'$CZAS_M
    a=$[a + 1]
    sleep 1s
done
