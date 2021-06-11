#%%
import numpy as np
import matplotlib.pyplot as plt
"""
Курсовая работа
Вычислить с точностью e минимум функции f(x) = x^3 + g(x) на отрезке [a,b], 
если g(x)- интерполяционный многочлен, построенный по исходным данным.   
Исходные данные представлены в виде таблицы xs/ys
"""
def create_lagrange_poly(xs, ys):
    poly = np.poly1d(0)
    for i in range(len(xs)):
        temp = np.poly1d(ys[i])
        for j in range(len(ys)):
            if i != j:
                temp *=  np.poly1d([1.0/(xs[i] - xs[j]), -xs[j]/(xs[i] - xs[j])])
        poly += temp
    return poly

def find_min(f, a, b, eps):
    #	Реализации метода золотого сечения для нахождения минимума функции
    #	Функция с точностью eps находит значение аргумента, при котором функция f(x) достигает своего минимума на отрезке [a, b]
    phi = (np.sqrt(5) + 1)/2
    x1 = b - (b-a)/phi
    x2 = a + (b-a)/phi
    y1 = f(x1)
    y2 = f(x2)
    iter = 1
    
    while(round(np.abs(b-a), 4) >= eps):
        print(f"Итерация {iter}  x1={round(x1, 4)}  x2={round(x2, 4)} y1={round(y1, 4)}  y2={round(y2, 4)}  a={round(a,4)}  b={round(b,4)}")
        if (y1 < y2):
            b = x2
            x2 = x1
            x1 = b - (b-a) / phi
            y2 = y1
            y1 = f(x1)
        else:
            a = x1
            x1 = x2
            x2 = a + (b-a) / phi
            y1 = y2
            y2 = f(x2)
        iter+=1
    print("Количество итераций : ", iter)
    return (a+b)/2
        

if __name__ == "__main__":
    a = 0.78
    b = 3.90
    eps = 0.0001
    x_plot = 0
    y_plot = 4.5
    
    xs = np.array([0.78, 1.56, 2.34, 3.12, 3.90])
    ys = np.array([1.20, 1.12, 2.25, 4.28, 2.50])
    plt.scatter(xs, ys)
    poly = create_lagrange_poly(xs, ys)
    print(f"Полином методом Лагранжа: \n {poly}\n") 
    
    plt.plot(np.arange(x_plot, y_plot, eps), poly(np.arange(x_plot, y_plot, eps)))
    plt.axvline(x=a, color='r', linewidth=1)
    plt.axvline(x=b, color='r', linewidth=1)
    plt.show()
    
    final_poly = np.poly1d([1,0,0,0]) + poly
    print(f"Финальный полином : \n {final_poly}\n") 
    plt.plot(np.arange(x_plot, y_plot, eps), final_poly(np.arange(x_plot, y_plot, eps)))
    plt.axvline(x=a, color='r', linewidth=1)
    plt.axvline(x=b, color='r', linewidth=1)
    

    min_x = find_min(final_poly, a, b, eps) 
    print(f"\nМинимум в точке x = {round(min_x, 4)}") 
    print(f"Значение в минимуме f(x) = {round(final_poly(min_x), 4)}") 

# %%
