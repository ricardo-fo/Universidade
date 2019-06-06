#coding: latin-1
from functools import reduce

lista = [float(i) for i in list(input().split())]
fatorial = lambda n : reduce(lambda x, y : x * y, range(1, int(n) + 1))
fatoriais = list(map(lambda x : fatorial(x), lista))
print(fatoriais)
