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
public class Gerente extends Funcionario {
    private int numFuncionarios;
    
    public Gerente(String nome, String cpf, double salario, int funcionarios){
        super(nome, cpf, salario);
        this.numFuncionarios = funcionarios;
    }
    
    public void cancelarOperacao(){
        System.out.println("Operação cancelada.");
    }
    
    // Indicador que há sobrescrição de método
    @Override
    public void calcularBonus(){
        
    }
}
