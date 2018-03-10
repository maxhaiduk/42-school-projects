#!/usr/bin/python

import Tkinter as tk
from visual import show_stat

def b1(tools):
	#print (tools)
	show_stat(tools)
	exit()
	

def b2():
	exit()

def query():
	file = open("/Users/mhaiduk/projects/push_swap/visual/tools", "r")
	tools = file.read().split('\n')
	tools.remove('')

	root = tk.Tk()
	root.title("push_swap mhaiduk")
	root.call('wm', 'attributes', '.', '-topmost', '1')
	
	# set root dimensions
	w = 300   
	h = 200   
	
	# get screen dimensions
	ws = root.winfo_screenwidth()
	hs = root.winfo_screenheight()
	x = (ws/2) - (w/2)
	y = (hs/2) - h
	root.geometry('%dx%d+%d+%d' % (w, h, x, y))

	var = tk.StringVar()
	label = tk.Label(root, textvariable=var, heigh=3)
	var.set("Do you want to see the statistics?")
	

	button1=tk.Button(root, text='Yes', width=25, heigh=3,
						command= lambda: b1(tools))
	

	button2=tk.Button(root, text='NO', width=25, heigh=3,
						command=b2)
	
	label.pack()
	button1.pack()
	button2.pack()

	root.mainloop()

	
if __name__ == "__main__":
	query()