import numpy as np
import matplotlib.pyplot as plt


def sign(x):
    if (x >= 0):
        return "+ "
    else:
        return "- "

def flt2str(x):
    return "{0:0.5f}".format(x)

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
            self._b*(point - self. _x) + \
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
        brace = "(x " + sign(-self._x) + str(abs(self._x)) + ")"
        return flt2str(self._d) + brace + "^3 " + \
            sign(self._c) + flt2str(c) + brace + "^2 " + \
            sign(self._b) + flt2str(b) + brace + \
            sign(self._a) + flt2str(a) + "\t range = [" + \
            str(self.range_x[0]) + " ; " + str(self.range_x[1]) + "]"


def build_spline(xs, ys):
    n = len(xs) - 1
    a = ys[:]
    b = [0.0 for i in range(n)]
    d = [0.0 for i in range(n)]

    h = []

    for i in range(0, n):
        h.append(xs[i+1]-xs[i])

    alpha = [0.0]

    for i in range(1, n):
        alpha.append(3*(a[i+1]-a[i])/h[i] - 3*(a[i]-a[i-1])/h[i-1])

    c = [0 for i in range(n + 1)]
    l = c[:]
    mu = c[:]
    z = c[:]

    l[0] = 1.0
    mu[0] = 0.0
    z[0] = 0.0

    for i in range(1, n):
        l[i] = 2 * (xs[i+1]-xs[i-1])-h[i-1]*mu[i-1]
        mu[i] = h[i]/l[i]
        z[i] = (alpha[i]-h[i-1]*z[i-1])/l[i]

    l[n] = 1.0
    z[n] = 0.0
    c[n] = 0.0

    j = n - 1
    while j >= 0:
        c[j] = z[j] - mu[j] * c[j+1]
        b[j] = (a[j+1]-a[j])/h[j]-h[j]*(c[j+1]+2*c[j])/3
        d[j] = (c[j+1]-c[j])/3/h[j]
        j -= 1

    output_set = []
    for i in range(0, n):
        s = Spline(a[i], b[i], c[i], d[i], xs[i])
        s.range_x = [xs[i], xs[i+1]]
        output_set.append(s)

    return output_set


def main():
    xs = [0.1, 0.5, 0.9, 1.3, 1.7]
    ys = [-2.3026, -0.69315, -0.10536, 0.26236, 0.53063]

    print("XS: ", xs)
    print("YS: ", ys)
    print('\n')

    splines = build_spline(xs, ys)
    print("Polynoms : ", end='\n')

    n = 500
    spline_x = [np.array(np.linspace(spl.range_x[0],
                                     spl.range_x[1], n)) for spl in splines]
    spline_y = []
    i = 0
    for spline, rng in zip(splines, spline_x):
        spline_y.append(np.array([spline.at(x) for x in rng]))
        plt.plot(rng, spline_y[i], color='c')
        i += 1

    plt.scatter(np.array(xs), np.array(ys))
    plt.show()

    print('\n')

    for spline in splines:
        print(spline)
        print("df at ", spline.range_x[0], " ",
              flt2str(spline.df(spline.range_x[0])), end='\n')
        print("df at ", spline.range_x[1], " ",
              flt2str(spline.df(spline.range_x[1])), end='\n')
        print(end='\n')
        print(end='\n')

    ddf_0 = splines[0].ddf(splines[0].range_x[0]) #first poly
    ddf_n = splines[-1].ddf(splines[-1].range_x[1]) #last poly

    print("DDF for first spline = ", flt2str(ddf_0), end='\n')
    print("DDF for last  spline = ", flt2str(ddf_n), end='\n')


if __name__ == '__main__':
    main()
