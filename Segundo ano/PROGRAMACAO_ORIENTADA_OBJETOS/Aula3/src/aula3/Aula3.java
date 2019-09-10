/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aula3;

/**
 *
 * @author Ricardo de F. Oliveria
 */
public class Aula3 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Disciplina poo = new Disciplina(5.0f, 7.5f);
        System.out.println("Nota 1: " + poo.getNota1());
        System.out.println("Nota 2: " + poo.getNota2());
        System.out.println("Média: " + poo.calcularMedia());
    }
    
}
