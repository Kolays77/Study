import numpy as np

V = 63
N = 200
a = ((-1)**V) * 0.1 * V
sigma = 0.01*V+1
lamb = 2 + (-1)**V*0.01*V

segment = [0,0]
segment[0] = (-1)**V * 0.05*V
segment[1] = segment[0] + 6

with open("normal_distribution.txt", "w") as file1:
    xs = np.random.normal(a, sigma, N)
    for x in xs: 
        print(x, end='\n', file=file1)
    
with open("exponential_distribution.txt", "w") as file2:
    xs = np.random.exponential(1/lamb, N)
    for x in xs: 
        print(x, end='\n',file=file2)
    

with open("uniformal_distribution.txt", "w") as file3:
    xs = np.random.uniform(segment[0], segment[1], N)
    for x in xs: 
        print(x, end='\n', file=file3)
    
