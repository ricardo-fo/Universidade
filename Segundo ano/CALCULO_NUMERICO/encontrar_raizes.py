#!/usr/bin/env python
"""
* Nome: Ricardo de Freitas Oliveira
* Curso: Ciência da Computação
* Disciplina: Cáculo Numérico I
* Professor: Júlio César
* Universidade Católica de Santos - Abril de 2019

* Exercícios - Encontrar as raízes com precisão de 0.0000001 :
* 1) x * e^x = 2 							(Método da Secante)
*	Resp.: x ~ 0.852605403832 no intervalo [0, 2]

* 2) sqrt(x) - 5 * e^(-x) 					(Método da bisseção)
*	Resp.: x ~ 1.430445135 no intervalo [0, 2]

* 3) x^5 + 3*x^4 - 9*x^3 - x^2 + 20*x - 12 	(Método de Newton-Raphson)
*	Resp.: x ~ 0.7673597489 no intervalo [0, 1]
"""

##############################################################################
# ------------------------------ Exercício 1 --------------------------------- 

import math

def funcaoSecante(x):
	resultado = x * math.exp(x) - 2
	return resultado

def paradaSecante(xn, erro):
	if(funcaoSecante(xn + erro)*funcaoSecante(xn - erro) < 0):
		return True
	else:
		return False

def secante(inf, sup, erro):
	if(inf > sup):
		# correção de possível erro com os limites do intervalo
		aux = inf
		inf = sup
		sup = aux

	a = inf
	fa = funcaoSecante(a)
	b = sup
	fb = funcaoSecante(b)
	xn = (a*fb - b*fa)/(fb-fa)
	fxn = funcaoSecante(xn)
	n = 0

	while(not paradaSecante(xn, erro)):
		a = xn
		fa = fxn
		xn = (a*fb - b*fa)/(fb-fa)
		fxn = funcaoSecante(xn)
		n = n + 1

	return {"raiz":xn, "iteracoes":n, "limite inferior":0, "limite superior":2}


##############################################################################
# ------------------------------ Exercício 2 ---------------------------------
def funcaoBissecao(x):
    x2 = -1 * x
    resultado = math.sqrt(x) - 5 * math.exp(x2)
    return resultado

def paradaBissecao(a, b, erro):
    if((abs(b - a)/2) < erro):
        return False
    else:
        return True

def bisseccao(inf, sup , erro):
	if(inf > sup):
		# correção de possível erro com os limites do intervalo
		aux = inf
		inf = sup
		sup = aux

	# definição das variáveis 
	a = inf
	fa = funcaoBissecao(a)
	b = sup
	fb = funcaoBissecao(b)
	n = 1
	xn = (a + b)/2
	fxn = funcaoBissecao(xn)

	# iterações para encontrar a raiz
	while(paradaBissecao(a, b, erro)):
		xn = (a + b)/2
		fxn = funcaoBissecao(xn)
		"""
		# CASO DESEJE VER O PROCESSO: REMOVA AS ASPAS DESTE COMENTÁRIO
		print("\na: {}\nfa(a): {}\nb: {}\nf(b): {}\nxn: {}\nf(xn): {}\niteracao: {}\n".format(a, fa, b, fb, xn, fxn, n))
		"""
		if(fxn < 0):
			# f(xn) negativo
			a = xn
			fa = funcaoBissecao(a)
		elif(fxn > 0):
			# f(xn) positivo
			b = xn
			fb = funcaoBissecao(b)          
		else:
			# f(xn) igual 0. Logo, encontrada a raiz exata
			print("\nf(xn) = 0")
			return {"raiz":xn, "iteracoes":n, "limite inferior":0, "limite superior":2}
		n = n + 1

	return {"raiz":xn, "iteracoes":n, "limite inferior":0, "limite superior":2}

##############################################################################
# ------------------------------ Exercício 3 ---------------------------------
def funcaoNewton(x):
    resultado = x**5 + 3*(x**4) - 9*(x**3) - x**2 + 20*x - 12
    return resultado

def primeiraDerivada(x):
    resultado = 5*(x**4) + 12*(x**3) - 27*(x**2) - 2*x + 20
    return resultado

def segundaDerivada(x):
    resultado = 20*(x**3) + 36*(x**2) - 54*x - 2
    return resultado

def paradaNewton(a, b, erro):
    return (abs(b - a) < erro)


def convergencia(fa, fb, fx1, fx, fx2):
    # fa = f(a)
    # fb = f(b)
    # fx1 = f'(x)
    # fx = f(x0)
    # fx2 = f''(x0)
    if(fa * fb > 0):
        return False
    elif(fx1 == 0):
        return False
    elif(fx * fx2 < 0):
        return False
    else:
        return True

def newtonRaphson(inf, sup, erro):
    if(inf > sup):
        # correção de possível erro com os limites do intervalo
        aux = inf
        inf = sup
        sup = aux
    # definição das variáveis
    a = inf
    fa = funcaoNewton(a)
    b = sup
    fb = funcaoNewton(b)
    z = sup
    xn = sup
    n = 0
    condicao = True

    while(condicao):
        xn = xn - (funcaoNewton(xn) / primeiraDerivada(xn))
        condicao = paradaNewton(z, xn, erro) and (convergencia(fa, fb, primeiraDerivada(xn), xn, segundaDerivada(xn)))
        z = xn
        n = n + 1
        """
	    # CASO DESEJE VER O PROCESSO: REMOVA AS ASPAS DESTE COMENTÁRIO
		print("\na: {}\nb: {}\nxn: {}\niteracao: {}\n".format(a, b, xn, n))
	    """
    xn = xn - (funcaoNewton(xn) / primeiraDerivada(xn))
    xnn = xn
    n = n + 1

    """
    # CASO DESEJE VER O PROCESSO: REMOVA AS ASPAS DESTE COMENTÁRIO
	print("\na: {}\nb: {}\nxn: {}\niteracao: {}\n".format(a, b, xn, n))
    """
    return {"raiz":xn, "iteracoes":n, "limite superior":0, "limite inferior":1}

##############################################################################
# ------------------------------- Resposta  ---------------------------------- 
print("""
* Nome: Ricardo de Freitas Oliveira
* Curso: Ciencia da Computacao
* Disciplina: Caculo Numerico I
* Professor: Julio Cesar
* Universidade Catolica de Santos - Abril de 2019
""")
print("------------------------------ Exercicio 1 ---------------------------------")
print("Metodo: Secante")
resultado = secante(0, 2, 0.0000001)
for info in resultado:
    print("{}: {}".format(info, resultado[info]))
print("----------------------------------------------------------------------------") 

print("")

print("------------------------------ Exercicio 2 ---------------------------------")
print("Metodo: Bissecao")
resultado = bisseccao(0, 2, 0.0000001)
for info in resultado:
    print("{}: {}".format(info, resultado[info]))
print("----------------------------------------------------------------------------")

print("")

print("------------------------------ Exercicio 3 ---------------------------------")
print("Metodo: Newton-Raphson")
resultado = newtonRaphson(0, 1, 0.0000001)
for info in resultado:
    print("{}: {}".format(info, resultado[info]))
print("----------------------------------------------------------------------------")
