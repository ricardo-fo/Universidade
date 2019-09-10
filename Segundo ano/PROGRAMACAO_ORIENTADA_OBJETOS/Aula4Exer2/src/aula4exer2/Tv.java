/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aula4exer2;

/**
 *
 * @author Ricardo de F. Oliveira
 */
public class Tv {
    public static int canal = 1;
    public static int volume = 50;
    public static String bateria = "standby";
    
    public static final byte AUMENTARVOLUME = 0;
    public static final byte DIMINUIRVOLUME = 1;
    public static final byte AUMENTARCANAL = 2;
    public static final byte DIMINUIRCANAL = 3;
    public static final byte LIGAR = 4;
    public static final byte DESLIGAR = 5;
    
    public static void ligarControle(){
        bateria = "normal";
    }
    
    public static void desligarControle(){
        bateria = "standby";
    }
    
    public static void enviar(int codigo){
        System.out.println("Código: " + codigo);
    }
}
