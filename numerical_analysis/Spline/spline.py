import matplotlib.pyplot as plt
import numpy as np

def sign(x):
    if (x >= 0):
        return "+ "
    else:
        return "- "

class Spline:
    range_x = []
    def __init__(self, a, b, c, d, x):
       self._a = a
       self._b = b
       self._c = c
       self._d = d
       self._x = x
    
    def at(self, point):
        return self._a + \
                self._b*(point -self. _x) + \
                self._c * (point - self._x)**2 + \
                self._d * (point - self._x)**3
    

    def df(self, point):
        return self._b + \
                2*self._c*(point - self._x) + \
                3*self._d*(point - self._x)**2

    def ddf(self, point):
        return 2*self._c + 6*self._d * (point - self._x)

    def __str__(self):
        a = abs(self._a)
        b = abs(self._b)
        c = abs(self._c)
        return str(self._d) + "x^3 " + \
                sign(self._c) + str(c) + "x^2 " + \
                sign(self._b) + str(b) + "x " + \
                sign(self._a) + str(a) + "\t range = [" + \
                    str(self.range_x[0]) + " ; " + str(self.range_x[1]) + "]"


def print_coef_from_file():
    [print(line) for line in open('coef2.txt')]
 

def main():
    n = 500
    points_x, points_y = [list(map(float, line.split())) for line in open('points.txt')]
    splines = [list(map(float, line.split())) for line in open('coef.txt')]
    splines = [Spline(*spl) for spl in splines]

   
    for i in range(len(splines)):
       splines[i].range_x = [points_x[i], points_x[i+1]]
    
    spline_x = [np.array(np.linspace(spline.range_x[0], \
                                    spline.range_x[1], n)) for spline in splines]
    spline_y = []
    i = 0
    for spline, rng in zip(splines, spline_x):
        spline_y.append(np.array([spline.at(x) for x in rng]))
        plt.plot(rng, spline_y[i], color = 'c')
        i += 1
    
    plt.scatter(np.array(points_x),np.array(points_y))
    plt.show()
    print_coef_from_file()

    print('\n')

    for spline in splines:
        print(spline)
        print(spline.df(spline.range_x[0]), end='\n')
        print(spline.df(spline.range_x[1]), end='\n')
        print(end='\n')
    
    print("DDF for ", splines[0], " = ", splines[0].ddf(splines[0].range_x[0]), end='\n')
    print("DDF for ", splines[3], " = ", splines[3].ddf(splines[3].range_x[1]), end='\n')
main()