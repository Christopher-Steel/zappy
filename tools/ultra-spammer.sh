x=0

while [ $x -le 100 ]
do
    ./spammer.py $1 $2 $3 >& /dev/null&
    x=$(($x + 1))
done
