/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aula4;

import java.util.Scanner;

/**
 *
 * @author Ricardo de F. Oliveira
 */
public class Aula4 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Counter c1 = new Counter();
        Counter c2 = new Counter();
        Counter c3 = new Counter();
        Scanner sc = new Scanner(System.in);
        
        c1.contar2();
        c2.contar1();
        c3.contar2();
        
        System.out.printf("c1: %d\nc2: %d\nc3: %d\n", c1.getCount(), c2.getCount(), c3.getCount());
        
        float div = Counter.divCount();
        System.out.printf("div: %f\n", div);
        
        System.out.printf("Valor: ");
        double valor = sc.nextDouble();
        
        System.out.printf("Cubo de %.3f: %.3f\n", valor, Calculate.cube(valor));
        System.out.printf("Area do ciruclo de raio %.3f: %.3f\n", valor, Calculate.areaCirculo(valor));
        System.out.printf("Perimetro do ciruclo de raio %.3f: %.3f\n", valor, Calculate.perimetroCirculo(valor));
    }
    
}
