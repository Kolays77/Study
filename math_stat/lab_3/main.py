import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import cont_distributions as cd

"""
Лабораторная 3 по математической статистике
To-do
1) ну там пиздец много'\\

"""

if __name__ == "__main__":
    N = 200
    with open("D1.txt") as file1:
        data1 = np.loadtxt(file1)   
    with open("D2.txt") as file2:
        data2 = np.loadtxt(file2)
        
    print(data1, end='\n\n')
    print(data2.shape)
    emp1 = cd.Empirical(data1)   
    emp1.show()
    emp1.plot_edf()
    emp2 = cd.Empirical(data2)
    emp2.show()