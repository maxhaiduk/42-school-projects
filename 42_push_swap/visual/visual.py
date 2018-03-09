#!/usr/bin/python

from matplotlib import pyplot as plt
from matplotlib import animation
from push_swap import push_swap

def init():
	set_style()
	x_pos = range(0, len(ps.a))
	rects = ax.bar(x_pos, ps.a, color='green')
	return rects

def define_vars():
	global x_lim
	x_lim = (0, len(ps.a))

	global y_lim
	y_lim = (min(ps.a), max(ps.a) + 5)

def set_style():
	ax.set_xlim(x_lim)
	ax2.set_xlim(x_lim)
	
	ax.set_ylim(y_lim)
	ax2.set_ylim(y_lim)

	for tick in ax.xaxis.get_major_ticks():
		tick.label1On = False
		tick.tick1On = False
		tick.tick2On = False

	for tick in ax2.xaxis.get_major_ticks():
		tick.label1On = False
		tick.tick1On = False
		tick.tick2On = False


def animate(tool):
	ax.cla()
	ax2.cla()	
	set_style()
	
	ps.operate(tool)
	x_pos = range(0, len(ps.a))
	stack_a = ax.bar(x_pos, ps.a, color='green')
	x_pos = range(0, len(ps.b))
	stack_b = ax2.bar(x_pos, ps.b)
	return stack_a, stack_b

def visual(arr, tools):
	
	global ps
	ps = push_swap(arr)

	fig = plt.figure(figsize=(15, 10))
	fig.canvas.set_window_title('push_swap mhaiduk')
	fig.text(0.11, 0.9, 'STACK A')
	fig.text(0.11, 0.45, 'STACK B')
	
	global ax
	ax = fig.add_axes([0.1, 0.525, 0.8, 0.4])
	global ax2
	ax2 = fig.add_axes([0.1, 0.075, 0.8, 0.4])
	
	define_vars()

	x_pos = range(0, len(ps.a))
	rects = ax.bar(x_pos, ps.a)

	anim = animation.FuncAnimation(fig, animate, tools, init_func=init, 
									blit=False, repeat=False, interval=100)
	plt.show()

def calc_stat(tools):
	pass

def show_stat(tools):
	fig = plt.figure()
	fig.canvas.set_window_title('push_swap mhaiduk')

	data = calc_stat(tools)

	ax = fig.add_axes()
	plt.show()

if __name__ == "__main__":
	#visual([3, 5, 4, 8, 1], ['sa', 'pb', 'pb', 'ss'])
	show_stat(['sa', 'pb', 'pb', 'ss'])