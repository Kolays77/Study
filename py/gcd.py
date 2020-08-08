def NOD(m, n):
    if n == 0:
        return m
    else:
        return NOD(n, m%n)