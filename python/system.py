def mulMatr(a,b):
    n1=len(a)
    n2=len(a[0])
    m1=len(b)
    m2=len(b[0])
    if n2==m1:
        r=[[0 for _ in range(m2)] for _ in range(n1)]
        for i in range(n1):
            for j in range(m2):
                for k in range(n2):
                    r[i][j]=r[i][j]+a[i][k]*b[k][j]
        return r            
 
def transp(matr):
    n=len(matr)
    k=len(matr[0])
    r=[[0 for _ in range(n)] for _ in range(k)]
    for i in range(k):
        for j in range(n):
            r[i][j]=matr[j][i]
    return r
 
def det(matr):
    n=len(matr)
    if n==1:
        return matr[0][0]
    elif n==2:
        return matr[0][0]*matr[1][1]-matr[0][1]*matr[1][0]
    else:
        s=0
        p=1
        for j in range(n):
            s+=det(minor(matr,0,j))*matr[0][j]*p
            p=-p
        return s    
 
def minor(matr,ii,jj):
    n=len(matr)
    r=[]
    for i in range(n):
        if (i != ii):
            if jj==0:
                r=r+[matr[i][1:]]
            else:
                r=r+[matr[i][0:jj]+matr[i][jj+1:]]
    return r
 
def invMatr(matr):
    n=len(matr)
    d=det(matr)
    r=[[0 for _ in range(n)] for _ in range(n)]
    pr=1
    for i in range(n):
        pc=pr
        for j in range(n):
            r[i][j]=pc*det(minor(matr,i,j))/d
            pc=-pc
        pr=-pr    
    return r 
    
def start():
    
    n,m=tuple(map(int,input().split()))
    
    r=[]
    for i in range(n):
        r+=[list(map(float,input().split(' ')))]
        
    a=[row[0:m] for row in r]
    print(a)
    
    at=transp(a)
    print(at)
    
    b=[]
    for row in r:
        b=b+[[row[m]]]
    print(b)    
    
    aa=mulMatr(at,a)
    print(aa)
    
    ia=invMatr(aa)
    print(ia)
    
    z=mulMatr(at,b)
    print(z)
    
    res=mulMatr(ia,z)
    print(res)
    
start()