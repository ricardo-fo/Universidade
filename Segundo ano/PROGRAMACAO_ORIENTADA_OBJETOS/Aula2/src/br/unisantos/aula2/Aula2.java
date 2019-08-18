/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.unisantos.aula2;
import java.util.Scanner;

/**
 *
 * @author Ricardo Oliveira
 */
public class Aula2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        System.out.print("Leitura de um input(inteiro): ");
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        System.out.println("Seu input: " + num);
        
        System.out.println("Leitura de vários dados: ");
        Scanner scStr = new Scanner(System.in);
        while(scStr.hasNext()){
            System.out.println("Seu dado: " + scStr.next());
        }
    }
    
}
