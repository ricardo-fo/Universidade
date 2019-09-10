/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aula5exer1;

import java.util.Scanner;

/**
 *
 * @author Ricardo de F. Oliveira
 */
public class Aula5Exer1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        String nome;
        String endereco;
        double rendimento;
        String certificado;

        Pessoa pessoas[] = new Pessoa[3];
        Scanner sc = new Scanner(System.in);
        
        for(int i = 0; i < 3; i++){
            System.out.println("<1> Pessoa Física;");
            System.out.println("<2> Pessoa Jurídica;");
            System.out.print(">>> ");
            int op = sc.nextInt();
            
            System.out.print("\nNome: ");
            nome = sc.next(); 
            
            System.out.print("Endereço: ");
            endereco = sc.next(); 
            
            System.out.print("Rendimento: ");
            rendimento = sc.nextDouble();
            
            switch (op) {
                case 1:
                    System.out.print("CPF: ");
                    certificado = sc.next();
                    PessoaFisica pf = new PessoaFisica(nome, endereco, rendimento, certificado);
                    
                    pessoas[i] = pf;
                    break;
                case 2:
                    System.out.print("CNPJ: ");
                    certificado = sc.next();
                    PessoaJuridica pj = new PessoaJuridica(nome, endereco, rendimento, certificado);
                    
                    pessoas[i] = pj;
                    break;
                default:
                    System.out.println("Opção inválida!");
                    break;
            }
            System.out.println();
        }
        
        for(int i = 0; i < 3; i++){
            System.out.println("Nome: " + pessoas[i].getNome());
            System.out.println("Endereço: " + pessoas[i].getEndereco());
            System.out.printf("Rendimento: %f", pessoas[i].getRendimento());
            System.out.printf("\nImposto: %f\n\n", pessoas[i].calcularImposto());
        }
    }
    
}
