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
public class Counter {
    private static int count = 0;
    /* Atributo static deixa de ser acessível por apenas um objeto e passa a ser
     *      manipulável por todos os objetos, compartilhadamente.*/
    
    public Counter(){
        this.count++;
    }
    
    public int getCount(){
        return this.count;
    }
    
    public void contar1(){
        this.count++;
    }    
    
    public void contar2(){
        this.count += 2;
    }
    
    public static float divCount(){
        return count / 2;
        /* Não possui 'this' devido ao atributo ser compartilhado por diferentes
         * objetos da mesma classe.*/
    }
}
