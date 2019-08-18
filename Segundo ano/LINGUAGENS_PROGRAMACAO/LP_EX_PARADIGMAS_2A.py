#coding: latin-1

print("Digite um sequencia de valores separados por espacos: ")
lista = [int(i) for i in list(input().split())]
par = list(filter(lambda x : x % 2 == 0, lista))
impar = list(filter(lambda x : x % 2, lista))

print("Pares:", par)
print("Impares:", impar)
