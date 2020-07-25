def multiply_matrix(A, B, mod):
    tmp1 = (A[0][0] * B[0][0] + A[0][1] * B[1][0]) % mod
    tmp2 = (A[0][0] * B[0][1] + A[0][1] * B[1][1]) % mod
    tmp3 = (A[1][0] * B[0][0] + A[1][1] * B[1][0]) % mod
    tmp4 = (A[1][0] * B[0][1] + A[1][1] * B[1][1]) % mod
    A[0][0] = tmp1
    A[0][1] = tmp2
    A[1][0] = tmp3
    A[1][1] = tmp4


def power(A, n, mod):
    if n == 0 or n == 1:
        return 
    B = [[1, 1], [1, 0]]
    if n % 2 == 1:
      power(A, n-1, mod)
      multiply_matrix(A, B, mod)
    else: 
      power(A, n // 2, mod)
      multiply_matrix(A, A, mod)



def fibonacci_n(n, mod):
    A = [[1, 1], [1, 0]]
    if n == 0:
        return 0
    power(A, n - 1, mod)
    return A[0][0]

def main(): 
    x = int(input())
    mod = int(input())
    print(fibonacci_n(x, mod))

if __name__ == '__main__':
    main()