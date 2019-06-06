#coding: latin1

#Strings - imutáveis
print("*"*50)
print("STRINGS")
entrada = input("Digite uma mensagem: ")
print(entrada.capitalize())
print(entrada.upper())
total_caracteres = len(entrada)
print(entrada + " possui " + str(total_caracteres) + " caracteres.")

#Tuplas - imutáveis
print("*"*50)
print("TUPLAS")
mes = ("Jan", "Fev", "Mar", "Abr", "Mai", "Jun", "Jul", "Ago", "Set", "Out", "Nov", "Dez")
entrada = int(input("Digite o numero do mes: "))
print(mes[entrada]) # imprime o mês
print(mes[0:4]) # mosta de janeiro a abril
print(type(mes))
for i in mes:
    print(i)

#Listas - mutáveis
print("*"*50)
print("LISTAS")
nums = [1, 2, 3, 4]
print(nums)
num_novo = input("Entre com mais um numero: ")
nums.append(int(num_novo))
print(nums)

#Dicionários - mutáveis
print("*"*50)
print("DICIONARIOS")
dic = {1:"Jan", 2:"Fev", 3:"Mar", 4:"Abr", 5:"Mai", 6:"Jun"}
print("Total:", len(dic))
print(dic.values()) # imprime os valores
print(dic.items()) # imprime tudo
print(dic.keys()) # imprime os ids
print("Elemento 1:", dic[1])
if 7 not in dic:
    dic[7] = "Jul"
    print(dic.items())
if 7 in dic:
    del dic[7]
    print(dic.items())

#Set - mutáveis
print("*"*50)
print("SETS")
numeros = set([])
numeros.add(1)
numeros.add(2)
numeros.add(10)
print(numeros)
if 12 in numeros:
    print("12 pertence")
else:
    print("12 nao pertence")
impar = set([1, 3, 5, 7, 9])
par = set([2, 4, 6, 8, 10])
uniao = impar | par
interseccao = impar & par
rem_difs = impar - par
print("rem_difs:", rem_difs)
print(uniao)
print(interseccao)

#Pilhas - listas que usam append() e pop()
numeros = []
print("Entre com 5 numeros")
for i in range(1, 6):
    n = input("N" + str(i) + ": ")
    numeros.append(n)
print("Removendo o numero do topo da pilha")
numeros.pop()
print(numeros)
