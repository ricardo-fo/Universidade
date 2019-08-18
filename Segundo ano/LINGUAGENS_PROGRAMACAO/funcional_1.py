#coding: latin-1

from functools import reduce

soma_intervalo = lambda a,b:reduce(lambda x,y:x+y, range(a,b+1))

n1 = int(input("Entre com n1..: "))
n2 = int(input("Entre com n2..: "))

param=sorted([n1,n2])
resultado=soma_intervalo(param[0],param[1])

print(resultado)

