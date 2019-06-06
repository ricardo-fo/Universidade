#coding: latin-1

lista1 = set(map(int, list(input("L1: ").split())))
lista2 = set(map(int, list(input("L2: ").split())))
lista3 = set(map(int, list(input("L3: ").split())))

ordem = sorted(set(lista1 | lista2 | lista3))
print(ordem)
