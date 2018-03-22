# 42_push_swap

42school algorythm project. The goal is to sort given stack of integers,
using a limited number of operations and one more additional stack.

Available operation: 
1. Swap two numbers at the top of the stack. [sa, sb, ss]
2. Rotate number from the top to the bottom of the stack. [ra, rb, rr]
3. Rotate number from the bottom to the top of the stack. [rra, rrb, rrr]
4. Push number from the one stack the another.  [pa, pb]

**Usage ./push_swap [numbers] | ./checker [numbers]**

<pre><code>push_swap prints the necessary operation to sort stack;

checker checks will be the stack sorted using this operations;</pre></code>

To visualize sorting process use **./run [n]**, 

where n - quantity of numbers, which will be generated randomly.

