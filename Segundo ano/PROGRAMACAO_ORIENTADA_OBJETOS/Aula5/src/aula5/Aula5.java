/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aula5;

import java.util.Scanner;

/**
 *
 * @author Ricardo de F. Oliveira
 */
public class Aula5 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        OperadorCaixa func1 = new OperadorCaixa("joselito", "000.000.000-00", 1200);
        OperadorCaixa func2 = new OperadorCaixa("josemar", "111.111.111-11", 2400);
        Gerente ger = new Gerente("josecleiton", "222.222.222-22", 3600, 2);
        
        // Setando as senhas
        func1.setSenha(123456);
        func2.setSenha(654321);
        ger.setSenha(010101);
        
        // Inserindo objetos em um vetor
        Funcionario funcs[] = new Funcionario[3];
        funcs[0] = func1;
        funcs[1] = func2;
        funcs[2] = ger;
        
        // Leitura das senhas
        int senha;
        Scanner sc = new Scanner(System.in);
        for(int i = 0; i < 3; i++){
            System.out.printf("Senha do funcionário %d: ", i + 1);
            senha = sc.nextInt();
            System.out.printf("Usuário".concat(funcs[i].autenticar(senha)? "": " não").concat(" autenticado\n\n"));
        }    
    }
    
    private static void calcularBonusTodos(Funcionario funcs[]){
        for(int i = 0; i < funcs.length; i++){
            funcs[i].calcularBonus();
        }
        
        /* Outra opção que gera o mesmo resultado
        for(Funcionario: funcs){
            funcs[i].calcularBonus();
        }
        */
    }
    
}
