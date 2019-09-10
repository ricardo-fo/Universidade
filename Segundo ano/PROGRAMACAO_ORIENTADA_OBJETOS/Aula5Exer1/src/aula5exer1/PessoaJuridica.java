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
public class PessoaJuridica extends Pessoa {
    private String cnpj;
    
    public PessoaJuridica(String nome, String endereco, double rendimento, String cnpj){
        super(nome, endereco, rendimento);
        this.cnpj = cnpj;
    }
    
    @Override
    public double calcularImposto(){
        return this.rendimento * 0.18;
    }

    public String getCnpj() {
        return cnpj;
    }
}
