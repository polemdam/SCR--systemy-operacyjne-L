#!/bin/bash
a=1;
read SLOWO
while [ $a -le 10 ]; do
    a=$[a+1]
    sleep 1s
done

echo $SLOWO
