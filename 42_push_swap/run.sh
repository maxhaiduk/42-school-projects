#!/bin/sh

if [ $# -ne 1 ]; then
	echo "Usage: ./run [size of array]"
	exit 1
fi

ARG=$(./ran_nums/ran_nums.py $1)

echo $ARG

./push_swap $ARG | tee visual/tools | ./checker -v -s $ARG && \
echo 'The initial array:\n'; echo $ARG'\n' && \
./visual/main.py $ARG
