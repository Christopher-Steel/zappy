#!/bin/bash

x=0

min=0
max=7

cmd[0]='avance'
cmd[1]='droite'
cmd[2]='gauche'
cmd[3]='voir'
cmd[4]='prend linemate'
cmd[5]='pose linemate'
cmd[6]='expulse'
cmd[7]='connect_nbr'

{
sleep 1
echo "team1"
sleep 1
while [ $x -le 1000 ]
do
    number=$[($RANDOM % ($[$max - $min] + 1)) + $min]
    echo ${cmd[$number]}
    usleep 1
    x=$(($x + 1))
done
sleep 1
} | telnet 127.0.0.1 $1
