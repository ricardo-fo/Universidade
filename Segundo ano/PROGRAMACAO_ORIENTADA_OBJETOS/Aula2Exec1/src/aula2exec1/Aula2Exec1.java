/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aula2exec1;
import java.util.Scanner;

/**
 *
 * @author Ricardo de F. Oliveira
 */
public class Aula2Exec1 {

    /**
     * @param args the command line arguments
     */
    
    public static void main(String[] args) {
        // TODO code application logic here
        System.out.println("Bem-vindo(a)!");
        Scanner sc = new Scanner(System.in);
        
        System.out.printf("Volume máximo: ");
        float volMax = sc.nextFloat();
        
        System.out.printf("Volume mínimo: ");
        float volMin = sc.nextFloat();
        Tanque tanque = new Tanque(volMax, volMin);
        
        int op;
        while(true){
            while(tanque.getVolumeAtual() < tanque.getVolumeMax()){
                tanque.encher(0.5f);
                System.out.println(tanque.exibirInfos());
            }
            while(tanque.getVolumeAtual() > tanque.getVolumeMin()){
                tanque.esvaziar(0.5f);
                System.out.println(tanque.exibirInfos());
            }
        }
    }
    
}
