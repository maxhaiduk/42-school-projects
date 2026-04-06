#!/usr/bin/python

import sys
import time
from visual import *

def read_array(argv):
	arr = []
	if (len(argv) == 2):
		arr = [int(i) for i in argv[1].split(' ')]
	else:
		for i in range (1, len(argv)):
			arr.append(int(argv[i]))
	return (arr)

def read_tools():
	file = open("./visual/tools", "r")
	tools = file.read().split('\n')
	tools.remove('')
	return (tools)


def main():

	if (len(sys.argv) == 1):
		print ("Error")
		exit()
	
	arr = read_array(sys.argv)
	tools = read_tools()
	visual(arr, tools)	

if __name__ == "__main__":
	main()