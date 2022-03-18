# himpunan
S = { 1, 2, 3, 4, 5, 6, 7, 8, 9}
A = { 1, 2, 3, 4, 5}
B = { 3, 4, 5, 6, 7}

print("A = ", A)
print("B = ", B)

data = A.union(B)
print("A union B = ", data)

data = A.intersection(B)
print("A irisan B = ", data)

data = S.difference(A)
print("Komplemen A = ", data)
data = S.difference(B)
print("Komplemen B = ", data)

data = A.difference(B)
print("A selisih B = ", data)
data = B.difference(A)
print("B selisih A = ", data)

data = A.symmetric_difference(B)
print("A Beda Setangkup B", data)


capres = {"Prabowo", "Anies", "Ganjar"}
cawapres = {"Ridwan Kamil", "Risma"}
print("")
print("Perkalian Kartesian capres x cawapres = {", end = ' ')
for i in capres:
    for j in cawapres:
        print("(",i,",",j,"),", end = ' ')
print("}")
print("Perkalian Kartesian cawapres x capres = {", end = ' ')
for i in cawapres:
    for j in capres:
        print("(",i,",",j,"),", end = ' ')
print("}")