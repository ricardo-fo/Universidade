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
public class Disciplina {
    private float nota1;
    private float nota2;
    private float media;
    
    public Disciplina(float n1, float n2){
        this.nota1 = n1;
        this.nota2 = n2;
    }
    
    public float getNota1(){
        return this.nota1;
    }
    
    public float getNota2(){
        return this.nota2;
    }
    
    public void setNota1(float n1, int teste){
        this.nota1 = n1;
    }
    
    public float calcularMedia(){
        this.media = (this.nota1 + this.nota2)/2;
        return this.media;
    }
}
