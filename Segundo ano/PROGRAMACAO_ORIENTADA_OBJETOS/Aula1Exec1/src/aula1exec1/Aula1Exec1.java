/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aula1exec1;

/**
 *
 * @author Ricardo Oliveira
 */
public class Aula1Exec1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        if(args.length != 3){
            System.out.println("Erro: Quantidade de parâmetros incorreta! Envie apenas 3 parâmetros.");
        } else {
            System.out.printf("Saudações, %s. Sua idade é %s. Você estuda em %s.\n", args[0], args[1], args[2]);    
        }
    }
    
}
