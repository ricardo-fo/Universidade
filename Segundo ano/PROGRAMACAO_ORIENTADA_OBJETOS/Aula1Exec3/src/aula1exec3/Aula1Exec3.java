/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aula1exec3;

/**
 *
 * @author Ricardo Oliveira
 */
public class Aula1Exec3 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        if(args.length != 1){
            System.out.println("\nErro: Insira apenas um único valor!\n");
        } else {
            try {
                int valor = Integer.parseInt(args[0]);
                if(valor < 0){
                    System.out.println("\nErro: Insira apenas valores positivos!\n");
                } else {
                    int aux = 1;
                    for(int i = valor; i > 1; i--){
                        aux *= i;
                    }
                    System.out.printf("\n%d! = %d\n", valor, aux);
                }
            } catch(NumberFormatException err) {
                System.out.println("\nErro: Insira apenas valores inteiros!\n");
            }
        }
    }
    
}
