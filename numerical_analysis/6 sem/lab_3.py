import numpy as np
import scipy.linalg
import iterative_algorithms as it_alg

""" Лабораторная работа №3 по численным методам
1. Метод простых итераций : метод simple_iteration_method
2. Метод Зейделя : метод seidel_iteration_method

"""

if __name__ == '__main__':
    eps = 0.001
    A = np.array([[15, 3, -5, -5],
                  [7, -15, -
                   6, 1],
                  [-4, 7, -19, -6],
                  [3, 0, -5, 8]])

    b = np.array([[36], [-112], [19], [-23]])
    x_true = scipy.linalg.solve(A, b)
    print("Метод простых итераций\n")
    x_simple = it_alg.simple_iteration_method(A, b, eps, is_debug=True)
    print("\n\nМетод Зейделя\n")
    x_seidel = it_alg.seidel_iteration_method(A, b, eps, is_debug=True)

    print(f"\nМетод простых итераций: {np.transpose(x_simple)[0]}") # formatting for printing vector-column
    print(f"Метод Зейделя: {x_seidel}")
    print(f"Точный ответ: {np.transpose(x_true)[0]}")
