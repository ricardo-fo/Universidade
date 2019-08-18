/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aula1exec2;

/**
 *
 * @author Ricardo Oliveira
 */
public class Aula1Exec2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        if(args.length != 2){
            System.out.printf("\nErro: insira apenas dois valores numéricos!\n", args);
        } else {
            float valor1 = Float.parseFloat(args[0]);
            float valor2 = Float.parseFloat(args[1]);
            float maior, menor;

            if(valor1 > valor2){
                maior = valor1;
                menor = valor2;
            } else {
                maior = valor2;
                menor = valor1;
            }
            System.out.printf("\nMaior: %f | Menor: %f\n", maior, menor);
            System.out.printf("%f - %f = %f\n", maior, menor, (maior - menor));
        }
    }
}
