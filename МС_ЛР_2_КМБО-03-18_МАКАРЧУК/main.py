import numpy as np
import math
import pandas as pd
import matplotlib.pyplot as plt
V = 63
N = 200
a = ((-1)**V) * 0.1 * V
sigma = 0.01*V+1
lamb = 2 + (-1)**V*0.01*V

segment = [0,0]
segment[0] = ((-1)**V) * 0.05*V
segment[1] = segment[0] + 6


class ContDistrub:
    def __init__(self):
        self.type = None
        self.mean = None
        self.dispertion = None
        self.std = None
        self.mode = None
        self.median = None
        self.skewness = None #коэф асиметрии 
        self.kurtosis = None #коэф эксцесса
       
    def show(self):
        print("theoretical characteristics of", self.type,  end='\n')
        print("mean", self.mean, end='\n')
        print("disp", self.dispersion, end='\n')
        print("std", self.std, end='\n')
        print("moda: ", self.mode, end='\n')
        print("median: ", self.median, end='\n')
        print("skewness  :", self.skewness, end='\n' )
        print("kurtosis: ", self.kurtosis, end='\n\n')



class UniformContDistrub(ContDistrub):
    def __init__(self,a,b):
        self.type = "Uniform"
        self.mean = (a+b)/2 
        self.dispersion = (b-a)**2 / 12
        self.std = (b-a)/2/np.sqrt(3)
        self.mode = self.mean
        self.median = self.mean
        self.skewness = 0
        self.kurtosis = -6/5


class NormalContDistrub(ContDistrub):
    def __init__(self, a,sigma):
        self.type = "Normal"
        self.mean = a
        self.dispersion = sigma**2
        self.std = sigma
        self.mode = a
        self.median = a
        self.skewness = 0
        self.kurtosis = 0


class ExponentialContDistrub(ContDistrub):
    def __init__(self, lamb):
        self.type = "Exponential"
        self.mean = 1/lamb
        self.dispersion = 1/lamb/lamb
        self.std = self.mean
        self.mode = 0
        self.median = np.log(2)/lamb
        self.skewness = 2
        self.kurtosis = 6

def read_values_from_file(file):
    arr = np.loadtxt(file, dtype=float)
    return arr

if __name__ == "__main__":

    theor_uniform_cont_distrub = UniformContDistrub(segment[0],segment[1])
    theor_normal_cont_distrub = NormalContDistrub(a, sigma)
    theor_exp_cont_distrub = ExponentialContDistrub(lamb)

    unform_distrub = read_values_from_file("uniform_distribution.txt")
    normal_distrub = read_values_from_file("normal_distribution.txt")
    exp_distrub = read_values_from_file("exponential_distribution.txt")
    
    #theor_uniform_cont_distrub.show()
    #theor_normal_cont_distrub.show()
    #theor_exp_cont_distrub.show()

    count, bins, ignored = plt.hist(normal_distrub, 30, density=True)
    plt.plot(bins, 1/(sigma * np.sqrt(2 * np.pi)) *
               np.exp( - (bins - a)**2 / (2 * sigma**2) ),
         linewidth=2, color='r')    
    print(count, " ", bins, "  ", ignored)