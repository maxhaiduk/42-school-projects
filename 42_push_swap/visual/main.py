#!/usr/bin/python

import sys
import time
import Tkinter as tk
from visual import *
from gui import *

def read_array(argv):
	arr = []
	if (len(argv) == 2):
		arr = [int(i) for i in argv[1].split(' ')]
	else:
		for i in range (1, len(argv)):
			arr.append(int(argv[i]))
	return (arr)

def read_tools():
	file = open("/Users/mhaiduk/projects/push_swap/visual/tools", "r")
	tools = file.read().split('\n')
	tools.remove('')
	return (tools)

def promt():
	root = tk.Tk()
	root.call('wm', 'attributes', '.', '-topmost', '1')
	w = 300# width for the Tk root
	h = 200 # height for the Tk root
	ws = root.winfo_screenwidth()
	hs = root.winfo_screenheight()
	x = (ws/2) - (w/2)
	y = (hs/2) - (h/2)
	root.geometry('%dx%d+%d+%d' % (w, h, x, y))

	label = Label(root, )

	root.mainloop()

def main():

	if (len(sys.argv) == 1):
		print ("Error")
		exit()
	
	arr = read_array(sys.argv)
	tools = read_tools()

	visual(arr, tools)
	
	query(tools)

	print (arr)
	print (tools)
	print (len(tools))
	

if __name__ == "__main__":
	main()