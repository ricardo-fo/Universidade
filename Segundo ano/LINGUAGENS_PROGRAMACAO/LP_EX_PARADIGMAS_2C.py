#coding: latin-1

lista = [i.upper() for i in list(input().split())]
print("Caixa alta:", lista)
print("Maior length:", max(lista, key = len))
