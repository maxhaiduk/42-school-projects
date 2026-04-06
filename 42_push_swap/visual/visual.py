#!/usr/bin/python

import matplotlib as mpl
from matplotlib import pyplot as plt
from matplotlib import animation
from push_swap import push_swap
from collections import Counter

def init():
	set_style()
	return line_a,


def set_style():
	
	# Set limits of axes
	ax.set_xlim(x_lim)
	ax2.set_xlim(x_lim)
	ax.set_ylim(y_lim)
	ax2.set_ylim(y_lim)

	#Set off all ticks and labels
	for tick in ax.xaxis.get_major_ticks():
		tick.label1On = False
		tick.tick1On = False
		tick.tick2On = False
	
	for tick in ax.yaxis.get_major_ticks():
		tick.label1On = False
		tick.tick1On = False
		tick.tick2On = False

	for tick in ax2.xaxis.get_major_ticks():
		tick.label1On = False
		tick.tick1On = False
		tick.tick2On = False

	for tick in ax2.yaxis.get_major_ticks():
		tick.label1On = False
		tick.tick1On = False
		tick.tick2On = False

def animate(tool):
	set_style()
	ps.operate(tool)
	
	line_a.set_data(range(ps.len_a), ps.a)

	line_b.set_data(range(ps.len_b), ps.b)
	return line_a, line_b

def visual(arr, tools):
	
	mpl.rcParams['toolbar'] = 'None'
	global ps
	ps = push_swap(arr)

	fig = plt.figure(figsize=(15, 10))
	fig.canvas.set_window_title('push_swap mhaiduk')
	t1 = fig.text(0.01, 0.96, 'STACK A', size='large', style='oblique')
	fig.text(0.01, 0.46, 'STACK B', size='large', style='oblique')
	
	global ax
	ax = fig.add_axes([0, 0.5, 1, 0.5])
	global ax2
	ax2 = fig.add_axes([0, 0, 1, 0.5])

	global line_a
	line_a, = ax.plot(range(ps.len_a), ps.a, color='green', marker='o', markersize=10)

	global line_b
	line_b, = ax2.plot([], [], color='blue', marker='o', markersize=10)

	global x_lim, y_lim
	x_lim = (-1, ps.len_a)
	m = max(ps.a)
	y_lim = (min(ps.a) - m * 0.05, m + m * 0.05)

	anim = animation.FuncAnimation(fig, animate, tools, init_func=init,
									blit=False, repeat=False, interval=10)
	plt.show()

if __name__ == "__main__":
	visual([3, 2, 1], ['sa', 'rra'])
	