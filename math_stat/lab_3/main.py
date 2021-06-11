#%%
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from cont_distributions import Empirical, Normal

"""
Лабораторная 3 по математической статистике
To-do
"""


if __name__ == "__main__":
    N = 200
    with open("D1.txt") as file:
        data = np.loadtxt(file)    
    emp = Empirical(data)   
    emp.show()
    lst = emp.get_list_props()
    
    print(lst)