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
public abstract class Pessoa {
    protected String nome;
    protected String endereco;
    protected double rendimento;
    
    public Pessoa(String nome, String endereco, double rendimento){
        this.nome = nome;
        this.endereco = endereco;
        this.rendimento = rendimento;
    }
    
    // Método para cáculo de imposto de uma pessoa, sendo esta ou física ou jurídica
    public abstract double calcularImposto();

    public String getNome() {
        return nome;
    }

    public String getEndereco() {
        return endereco;
    }

    public double getRendimento() {
        return rendimento;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setEndereco(String endereco) {
        this.endereco = endereco;
    }

    public void setRendimento(double rendimento) {
        this.rendimento = rendimento;
    }    
}
