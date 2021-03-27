import numpy as np
import params as prm
from docx import Document


def print_table_docx(data, file):
    rows_ = int(prm.N / 10)
    cols_ = 10
    document = Document()
    table = document.add_table(rows=rows_, cols=cols_)
    for i in range(rows_):
        cells = table.rows[i].cells
        for j in range(cols_):
            cells[j].text = str(round(data[i*cols_ + j], 5))
    document.add_page_break()
    document.save(file + ".docx")


def print_table(data, file):
    print_table_docx(data, file)
    print_table_docx(np.sort(data), file + "sort")


xs_normal = np.random.normal(prm.a, prm.sigma, prm.N)
xs_exp = np.random.exponential(1 / prm.lamb, prm.N)
xs_uni = np.random.uniform(prm.segment[0], prm.segment[1], prm.N)

with open("normal_distribution.txt", "w") as file1:
    for x in xs_normal:
        print(round(x, 5), end='\n', file=file1)

with open("exponential_distribution.txt", "w") as file2:
    for x in xs_exp:
        print(round(x, 5), end='\n', file=file2)

with open("uniform_distribution.txt", "w") as file3:
    for x in xs_uni:
        print(round(x, 5), end='\n', file=file3)

print_table(xs_normal, "normal_distribution")
print_table(xs_exp, "exponential_distribution")
print_table(xs_exp, "uniform_distribution")
