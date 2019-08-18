#!/usr/local/bin/lua
--[[ calculadora.lua
* Este programa representa uma calculadora simplificada. Executa as 4
* operações básicas da aritmética, i.e. somar, subtrair, multiplicar e dividir.
*
* Grupo: Paradigma imperativo em linguagem de programação Lua.
* Disciplina: Linguagens de Programação.
* Profº.: Thiago Ferauche.
* Universidade Católica de Santos - Maio de 2019.
]]--

-- Função que soma dois valores.
-- Parâmetros: 'a' e 'b'-> números.
-- Saída: soma dos valores 'a' e 'b' (a + b).
function somar(valor_a, valor_b)
	local resultado = valor_a + valor_b
	return resultado
end

-- Função que subtrai dois valores.
-- Parâmetros: 'a' e 'b'-> números.
-- Saída: subtração do valor 'b' do valor 'a' (a - b).
function subtrair(valor_a, valor_b)
	local resultado = valor_a - valor_b
	return resultado
end

-- Função que multiplica dois valores.
-- Parâmetros: 'a' e 'b'-> números.
-- Saída: multiplicação dos valores 'a' e 'b' (a * b).
function multiplicar(valor_a, valor_b)
	local resultado = valor_a * valor_b
	return resultado
end

-- Função que divide dois valores.
-- Parâmetros: 'a' e 'b'-> números.
-- Saída: divisão do valor 'a' pelo valor 'b' (a / b).
function dividir(valor_a, valor_b)
	local resultado = valor_a / valor_b
	return resultado
end

-- Menu usando um laço de repetição.
repeat
	print("----------------------------------------------------")

	-- Leitura do primerio valor do teclado -> variável global.
	print("\nValor a: ")
	valor_a = io.read()
	if valor_a == "sair" then
		break
	end
	-- Conversão da leitura do teclado(string) para um valor numérico.
	valor_a = tonumber(valor_a)
	-- Caso o usuário informe um valor 'a' que não seja numérico.
	if valor_a == nil then
		print("\nInforme apenas valores numericos.\n")
	else
		-- Leitura do segundo valor do teclado -> variável global.
		print("\nValor b: ")
		valor_b = io.read()
		if valor_b == "sair" then
			break
		end
		-- Conversão da leitura do teclado(string) para um valor numérico.
		valor_b = tonumber(valor_b)
		-- Caso o usuário informe um valor 'b' que não seja numérico.
		if valor_b == nil then
			print("\nInforme apenas valores numericos.\n")
		else
			-- Leitura da operação a ser realizada -> variável global
			print("\nOperacao: ")
			operacao = io.read()
			if operacao == "sair" then
				break

			elseif operacao == "+" then
				-- Caso o usuário queira somar.
				print(valor_a.." + "..valor_b.." = "..somar(valor_a, valor_b))

			elseif operacao == "-" then
				-- Caso o usuário queira subtrair.
				print(valor_a.." - "..valor_b.." = "..subtrair(valor_a, valor_b))

			elseif operacao == "*" then
				-- Caso o usuário queira multiplicar.
				print(valor_a.." * "..valor_b.." = "..multiplicar(valor_a, valor_b))

			elseif (operacao == "/") and (valor_b ~= 0) then
				-- Caso o usuário queira dividir. Para isso, o valor b tem que ser
				-- diferente de 0.
				print(valor_a.." / "..valor_b.." = "..dividir(valor_a, valor_b))

			else
				print("Operacao invalida.\n")
			end
		end
	end
until (operacao == "sair")

print("Adeus.")
