#%%
from scipy.interpolate import lagrange 
import numpy as np
import matplotlib.pyplot as plt

"""
Курсовая работа
Вычислить с точностью e минимум функции f(x) = x^3 + g(x) на отрезке [a,b], 
если g(x)- интерполяционный многочлен, построенный по исходным данным.   
Исходные данные представлены в виде таблицы xs/ys

TO-DO
1) понять какие у меня данные
2) понять какой метод минимизации использовать

"""

#scipy function
def create_poly(xs, ys):
    return lagrange(xs, ys)

def create_lagrange_poly(xs, ys):
    poly = np.poly1d(0)
    for i in range(len(xs)):
        temp = np.poly1d(ys[i])
        for j in range(len(ys)):
            if i != j:
                temp *=  np.poly1d([1.0/(xs[i] - xs[j]), -xs[j]/(xs[i] - xs[j])])
        poly += temp
    
    return poly


def find_min_bisection(func, a, b, eps):
    mid = (a+b)/2
    count = 0
    print(f"Итерация 0 a={a} b={b} mid={mid}")
    while b-a > eps:
        count += 1
        if func(mid) < func(b):
            b = mid
        else:
            a = mid
        mid = (a+b)/2
        print(f"Итерация {count} a={a:5f} b={b:5f} mid={mid:5f} f(mid)= {func(mid):5f}")
    return mid


if __name__ == "__main__":
    a = 0.78
    b = 3.90
    eps = 0.001
    xs = np.array([0.78, 1.56, 2.34, 3.12, 3.90])
    ys = np.array([1.20, 1.12, 2.25, 4.28, 2.50])
    
    poly = create_lagrange_poly(xs, ys)
    final_poly = np.poly1d([1,0,0,0]) + poly
   
    print(f"Полученный полином : \n {final_poly}\n") 
    plt.plot(np.arange(-2, 5, eps), final_poly(np.arange(-2, 5, eps)))
    plt.axvline(x=a, color='r', linewidth=1)
    plt.axvline(x=b, color='r', linewidth=1)
    print("Поиск минимума (метод бисекций)")
    min_x = find_min_bisection(final_poly, a, b, eps) 
    print(f"\nМинимум в точке x = {round(min_x, 6)}") 
    print(f"Значение в минимуме f(x) = {round(final_poly(min_x), 6)}") 

# %%
