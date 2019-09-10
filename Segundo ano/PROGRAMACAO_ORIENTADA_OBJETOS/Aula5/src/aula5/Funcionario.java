/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aula5;

/**
 *
 * @author Ricardo de F. Oliveira
 */
public abstract class Funcionario {
    private String nome;
    private String cpf;
    private double salario;
    private int senha;
    
    public Funcionario(String nome, String cpf, double salario){
        this.nome = nome;
        this.cpf = cpf;
        this.salario = salario;
    }
    
    public void setSenha(int senha){
        this.senha = senha;
    }
    
    public boolean autenticar(int senha){
        if(this.senha == senha){
            return true;
        } else {
            return false;
        }
    }
    
    public void calcularBonus(){
        
    }
}
