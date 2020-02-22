#!/bin/bash

g++ -std=c++11 main.cpp -o a.out -g

attempts=0

while true; do
    python3 gentest.py
    correct=$(cat test.txt | ./a.out)
    wrong=$(cat test.txt | python3 hw1_nx.py)
    if [[ $correct != $wrong ]]; then
        echo $attempts
        echo EXPECTED:  $correct
        echo RECEIVED:  $wrong
        break
    fi
    ((attempts++))
done
