#%%

import numpy as np
import matplotlib.pyplot as plt
import math

"""
Лабораторная работа №4
Решить уравнение f(x)=0, где f(x) = 4^(x)-5x-2 на [0, 5] 
1. методом половинного деления :  bisection_method
2. простой итерации :
3. метод Ньютона : newton_method
4. метод секущей : secant_method
"""


def bisection_method(left, right, func, eps, is_log=False):  
    count = 0
    if np.abs(func(left)) < eps:
        return left
    if np.abs(func(right)) < eps:
        return right
    if np.sign(func(left)) == np.sign(func(right)):
        raise Exception("Error:two values with NOT opposite signs")
    mid = (left + right)/2
    value_mid = func(mid)
    while right-left > eps:
        count += 1
        if  np.sign(func(mid)) == np.sign(func(right)):
            right = mid
        else:
            left = mid
        mid = (right + left)/2
        value_mid = func(mid)
        if is_log:
            print(f"Итерация номер {count} невязка {round(right-left, 6)} f(x)={round(value_mid, 6)}")
    if is_log:
      print(f"Итерация номер {count} невязка {round(right-left, 6)} f(x)={round(value_mid, 6)}")
      print('\n')
    return mid


def simple_iteration_method(x0_, phi, eps, is_log=True):
    x0 = x0_
    x1 = phi(x0)
    count = 0
    print(f"Начальное приближение x = {x0}")
    while True:
        count += 1
        x1 = phi(x0)
        if is_log:
            print(f"Итерация номер {count} невязка {round(np.abs(x1 - x0), 6)} x={round(x1, 6)}")
        if np.abs(x1 - x0) < eps:
            break
        x0 = x1
    if is_log:
        print('\n')
    return x1


def newton_method(x, func, func_der, eps, is_log=True):
    x0 = x
    count = 0
    print(f"Начальное приближение x = {x0}")
    while True:
        count += 1
        x1  = x0 - func(x0) / func_der(x0)
        if np.abs(x1 - x0) < eps:
            break
        if is_log:
            print(f"Итерация номер {count} невязка {round(np.abs(x1 - x0), 6)} x={round(x1, 6)}")
        x0 = x1
    if is_log:
        print('\n')
    return x1


def secant_method(x0_, x1_, func, eps, is_log=True):
    x0 = x0_
    x1 = x1_
    count = 0
    print(f"Начальное приближение x0 = {x0}, x1 = {x1}")
    while True:
        count += 1
        x2 = x1 - func(x1) * (x1 - x0)/(func(x1) - func(x0))
        if is_log:
            print(f"Итерация номер {count} невязка {np.abs(x2 - x1)} x = {x2}")
        if np.abs(x2 - x1) < eps:
            break
        x0, x1 = x1, x2
    if is_log:
        print('\n')
    return x2


def plot(left, right, func, d=0.0001):
    xs = np.arange(left, right, d)   
    ys = func(xs)
    plt.subplots(figsize=(12, 8))
    plt.yscale("symlog")
    
    plt.axhline(y=0, color='k', linewidth=1)
    plt.axvline(x=0, color='k', linewidth=1)
    plt.plot(xs, ys)


if __name__ == '__main__':
    left = 0
    right = 20
    eps = 0.0001

    func = lambda x: np.float_power(4, x)-5*x-2
    func_der = lambda x: np.float_power(4, x)*np.log(4) - 5
    phi = lambda x: np.log(5*x+2)/np.log(4)

    print(f"Метод половинного деления")
    x_bisection = bisection_method(left, right, func, eps, True)
    print(f"Метод простых итераций")
    x_simple = simple_iteration_method(left, phi, eps, True)  
    print(f"Метод Ньютона")
    x_newtom = newton_method(1.1, func, func_der, 0.000000001, True)
    print(f"Метод секущей")
    x_secant = secant_method(0.5, 1.8, func, eps, True)
    
    print(f"Метод половинного деления x = {x_bisection}")
    print(f"Метод простых итераций x = {x_simple}")
    print(f"Метод Ньютона x = {x_newtom}")
    print(f"Метод секущей x = {x_secant}")
    plot(left, right, func, eps)
    