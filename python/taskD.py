def solve(a,b,c):
  if c < 0:
    return "NO SOLUTION"
  
  if a == 0:
    if b == c*c:
      return "MANY SOLUTION"
    else:
      return "NO SOLUTION"
  
  if not (c*c - b)/a == (c*c - b)// a:
    return "NO SOLUTION"
  else:
    return (c*c - b)//a

#a = int(input())
#b = int(input())
#c = int(input())
#print(solve(a,b,c))


for a in range(-5, 5, 1):
  for b in range(-5, 5, 1):
    for c in range(-5, 5, 1):
        print(a,b,c, solve(a,b,c))
 