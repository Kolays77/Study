import numpy as np

V = 63
N = 200
a = ((-1)**V) * 0.1 * V
sigma = 0.01*V+1
lamb = 2 + (-1)**V*0.01*V

segment = [0,0]
segment[0] = ((-1)**V) * 0.05*V
segment[1] = segment[0] + 6

count_intervals = int(1 + np.log2(N)) #формула Стерджеса для числа интервалов
