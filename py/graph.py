
import plotly.graph_objects as go
file1 = open("C:/Users/nimak/Git/Study/py/2019_1.txt")
file2 = open("C:/Users/nimak/Git/Study/py/2019_2.txt")
score = 0
list1 = [0 for i in range(101)]
list2 = [0 for i in range(101)]

for line in file1:
    if line !='\n':
        list1[int(line)] += 1

for line in file2:
    if line !='\n':
        list2[int(line)] += 1

count_1 : int = 0
count_2 : int = 0
sum_1 : int = 0
sum_2 : int = 0
for i in range(101):
    count_1 += list_1[i]
    count_2 += list_2[i]
    
    sum_1 += list1[i] * i 
    sum_2 += list2[i] * i
print(sum_1 / count_1)
print(sum_2 / count_2)


fig = go.Figure(
    data=[go.Bar(y=list1, name = "first"), go.Bar(y = list2, name = "second")],
    layout_title_text="2019"
)
fig.show()
file1.close()
file2.close()