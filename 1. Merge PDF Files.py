#pip install PyPDF2

from PyPDF2 import PdfFileMerger

pdfs = ["lab "+str(i)+".pdf" for i in range(1,9)] #list of files to merge

merger = PdfFileMerger()

for pdf in pdfs:
    merger.append(pdf)

merger.write("result.pdf") #output pdf
merger.close()
