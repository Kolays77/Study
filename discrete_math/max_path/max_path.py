f = open("test1.in", 'r')
n = int(f.readline())
start = 0
finish = 1
w = []
for line in f:
    w.append([int(j) for j in line.split()])

INF = 10 ** 10
dist = [INF] * n
used = [False] * n
max_dist = INF
min_vertex = start

while max_dist > 0:
    i = min_vertex
    used[i] = True

    for j in range(n):
        if w[i][j] > 0:
            if dist[j] == INF:
                 dist[j] = min(w[i][j], dist[i])
            else:
                dist[j] = max(dist[j], min(w[i][j], dist[i]))

    max_dist = 0
    for j in range(n):
        if not used[j] and dist[j] > max_dist and dist[j] != INF:
            max_dist = dist[j]
            min_vertex = j

print(dist[finish])
