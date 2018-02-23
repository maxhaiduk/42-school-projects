#!/usr/bin/python

import sys
import random

if (len(sys.argv) != 2):
	print("Usage: ./ran_num [number]")
        exit()

nums = range(0, int(sys.argv[1]))
random.shuffle(nums)
str_list = [str(i) for i in nums]
str = ' '.join(str_list)
print str
