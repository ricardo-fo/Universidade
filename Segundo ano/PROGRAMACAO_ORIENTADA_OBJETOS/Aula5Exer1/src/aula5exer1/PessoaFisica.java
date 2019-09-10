/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aula5exer1;

/**
 *
 * @author Ricardo de F. Oliveira
 */
public class PessoaFisica extends Pessoa {
    private String cpf;
    
    public PessoaFisica(String nome, String endereco, double rendimento, String cpf){
        super(nome, endereco, rendimento);
        this.cpf = cpf;
    }
    
    @Override
    public double calcularImposto(){
        double imposto;
        if(super.getRendimento() < 3000){
            imposto = this.rendimento * 0.11;
        } else {
            imposto = this.rendimento * 0.275;
        }
        
        return imposto;
    }

    public String getCpf() {
        return cpf;
    }
}
