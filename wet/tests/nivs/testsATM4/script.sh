#! /bin/bash

for (( i=1; i<5; i++ ))
do 
    gcc -no-pie test${i}.c -o run${i}.out 
    ./prf hello_world run${i}.out >> output${i}.txt
    #rm run${i}.out
done
