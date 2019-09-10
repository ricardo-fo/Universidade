/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aula4;

/**
 *
 * @author Ricardo de F. Oliveira
 */
public class Calculate {
    public static final double PI = 3.14159;
    
    public static double cube(double valor){
        return valor*valor*valor; 
    }
    
    public static double areaCirculo(double raio){
        return PI*raio*raio;
    }
    
    public static double perimetroCirculo(double raio){
        return 2*PI*raio;
    }
}
