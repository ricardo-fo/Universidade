/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aula4exer2;
import java.util.Scanner;

/**
 *
 * @author Ricardo de F. Oliveira
 */
public class Aula4Exer2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        int op;
        try(Scanner sc = new Scanner(System.in)){
            do{
                System.out.println("\n<0> Sair");
                System.out.println("<1> Aumentar volume");
                System.out.println("<2> Diminuir volume");
                System.out.println("<3> Aumentar canal");
                System.out.println("<4> Diminuir canal");
                System.out.println("<5> Ligar");
                System.out.println("<6> Desligar");
                System.out.print(">>> ");
                op = sc.nextInt();
                
                switch(op){
                    case 1:
                        Tv.enviar(Tv.AUMENTARCANAL);
                        Tv.canal++;
                        break;
                    case 2:
                        Tv.enviar(Tv.DIMINUIRCANAL);
                        Tv.canal--;
                        break;
                    case 3:
                        Tv.enviar(Tv.AUMENTARVOLUME);
                        Tv.volume++;
                        break;
                    case 4:
                        Tv.enviar(Tv.DIMINUIRVOLUME);
                        Tv.volume--;
                        break;
                    case 5:
                        Tv.enviar(Tv.DESLIGAR);
                        Tv.desligarControle();
                        break;
                    case 6:
                        Tv.enviar(Tv.LIGAR);
                        Tv.ligarControle();
                        break;
                    case 0:
                        break;
                    default:
                        System.out.println("Opção inválida");
                }
                
            }while(op != 0);
        }
    }
    
}
