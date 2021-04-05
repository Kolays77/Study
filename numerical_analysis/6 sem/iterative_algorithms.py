import numpy as np
import copy


def seidel_iteration_method(A, b, eps, is_debug=False):
    n = len(A)
    xs = np.zeros(n)
    is_converge = False
    count = 0
    while not is_converge:
        xs_new = np.copy(xs)
        for i in range(n):
            s1 = sum(A[i][j] * xs_new[j] for j in range(i))
            s2 = sum(A[i][j] * xs[j] for j in range(i + 1, n))
            xs_new[i] = (b[i] - s1 - s2) / A[i][i]

        #residual = np.sqrt(sum((xs_new - xs)**2))  # невязка
        residual = max(np.abs(xs-xs_new))  # невязка
        is_converge = residual <= eps
        xs = xs_new
        if is_debug:
            print(f"Итерация{count} : x = {xs} невязка = {round(residual, 6)}")
        count += 1
    return xs


def simple_iteration_method(A, b, eps, is_debug=False):
    n = b.shape[0]
    betas = np.array([b[i] / A[i][i] for i in range(n)])
    alphas = np.zeros((n, n))
    for i in range(n):
        for j in range(n):
            if i != j:
                alphas[i][j] = -A[i][j] / A[i][i]
    xs = betas.copy()
    count = 0
    is_converge = False
    while not is_converge:
        xs_new = betas + np.dot(alphas, xs)
        #residual = np.sqrt(sum((xs_new - xs)**2))  # невязка
        residual = max(np.abs(xs-xs_new))
        #np.allclose(x, x_new, eps)
        if is_debug:
            print(f"Итерация {count} : x = {np.transpose(xs)[0]}; невязка = {round(float(residual), 6)}")
        is_converge = residual <= eps
        xs = xs_new
        count += 1
    return xs



