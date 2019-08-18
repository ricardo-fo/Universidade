#coding: latin-1

lista = [int(i) for i in list(input().split())]
par = list(filter(lambda x : x % 2 == 0, lista))
print("Pares: ", par)
