/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aula4exer1;

/**
 *
 * @author Ricardo de F. Oliveira
 */
public class Pi {
    //char, byte, short, long, int, float, double, boolean
    public static char converterChar(){
        return String.valueOf(Math.PI).charAt(0);
    }
    
    public static byte converterByte(){
        return Double.valueOf(Math.PI).byteValue();
    }
    
    public static short converterShort(){
        return Double.valueOf(Math.PI).shortValue();
    }
    
    public static long converterLong(){
        return Double.valueOf(Math.PI).longValue();
    }
    
    public static int converterInt(){
        return Double.valueOf(Math.PI).intValue();
    }
    
    public static float converterFloat(){
        return Double.valueOf(Math.PI).floatValue();
    }
    
    public static double converterDouble(){
        return Math.PI;
    }
    
    public static boolean converterBoolean(){
        return Boolean.parseBoolean(String.valueOf(Math.PI));
    }
    
}
