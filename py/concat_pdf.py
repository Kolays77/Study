import os
from PyPDF2 import PdfFileMerger

def main():
    x = [a for a in os.listdir() if a.endswith(".pdf")] 

    merger = PdfFileMerger()

    for pdf in x:
        merger.append(open(pdf, 'rb'))

    with open("output1.pdf", "wb") as fout:
        merger.write(fout)

main()