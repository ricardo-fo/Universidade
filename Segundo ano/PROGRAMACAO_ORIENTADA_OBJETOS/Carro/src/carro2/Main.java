/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package carro2;

import carro.Carro;
import java.util.Scanner;

/**
 * @author Ricardo Oliveira
 */
public class Main {
    public static void main(String[] args){       
        Scanner sc = new Scanner(System.in);
        float consumo, odometro = 0, litrosTanque, vm, tempo;
        
        System.out.printf("Consumo: ");
        consumo = sc.nextFloat();
        
        System.out.printf("Litros no tanque: ");
        litrosTanque = sc.nextFloat();
        System.out.println();
        
        Carro c1 = new Carro(consumo, odometro, litrosTanque);
        
        while(c1.getTanque() > 0){
            System.out.printf("Velocidade: ");
            vm = sc.nextFloat();
            System.out.printf("Tempo: ");
            tempo = sc.nextFloat();
            
            c1.setarVelocidade(vm, tempo);
            System.out.printf("\n\nTanque: %.3f litros\nOdometro: %.3f km\n\n", c1.getTanque(), c1.getOdometro());
        }
    }
}
