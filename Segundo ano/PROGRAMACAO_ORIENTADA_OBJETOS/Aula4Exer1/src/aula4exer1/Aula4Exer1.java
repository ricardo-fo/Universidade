/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aula4exer1;
import java.util.Scanner;

/**
 *
 * @author Ricardo de F. Oliveira
 */
public class Aula4Exer1 {
    public static void main(String[] args){
        //char, byte, short, long, float, double, boolean
        int op;
        try(Scanner sc = new Scanner(System.in)) {
            do {
                System.out.println("<0> Sair");
                System.out.println("<1> Char");
                System.out.println("<2> Byte");
                System.out.println("<3> Short");
                System.out.println("<4> Long");
                System.out.println("<5> Int");
                System.out.println("<6> Float");
                System.out.println("<7> Double");
                System.out.print("<8> Boolean\n>>> ");
                op = sc.nextInt();
                
                switch(op){
                    case 0:
                        break;
                    case 1:
                        System.out.print(Pi.converterChar());
                        System.out.println();
                        break;
                    case 2:
                        System.out.print(Pi.converterByte());
                        System.out.println();
                        break;
                    case 3:
                        System.out.print(Pi.converterShort());
                        System.out.println();
                        break;
                    case 4:
                        System.out.print( Pi.converterLong());
                        System.out.println();
                        break;
                    case 5:
                        System.out.print(Pi.converterInt());
                        System.out.println();
                        break;
                    case 6:
                        System.out.print(Pi.converterFloat());
                        System.out.println();
                        break;
                    case 7:
                        System.out.print(Pi.converterDouble());
                        System.out.println();
                        break;
                    case 8:
                        System.out.print(Pi.converterBoolean());
                        System.out.println();
                        break;
                    default:
                        System.out.println("Opção inválida!");
                }
                
            }while(op != 0);
        }
    }
}
