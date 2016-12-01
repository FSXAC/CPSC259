# generates a random series of webpages
# -- square matrix
# -- main diagonal is all 0s
# -- output as .txt file

import random

N = int(input("Enter number of links: "))

# write to file
file = open("web.txt", "w")
for i in range(N):
    for j in range(N):
        if i == j:
            file.write("0")
        else:
            file.write(str(random.choice(["0", "1"])))
        if (j != N - 1):
            file.write(" ")
    if (i != N - 1):
        file.write("\n")
file.close()
