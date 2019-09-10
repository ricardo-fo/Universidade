/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aula2exec1;

/**
 * Classe para o controle de um tanque, sendo limitada, sendo o limite superior o
 * atributo volumeMax e limite inferior, volumeMin; O valor atual do tanque definido
 * como o atributo volumeAtual, o atributo bomba controla o estado atual do tanque, se
 * está enchendo ou esvaziando
 * @author Ricardo de F. Oliveira
 */
public class Tanque {
    private float volumeMax;
    private float volumeMin;
    private float volumeAtual;
    private boolean bomba;
    
    public Tanque(float volMax, float volMin){
        this.volumeMax = volMax;
        this.volumeMin = volMin;
        this.volumeAtual = volMin;
        this.bomba = true;
    }
    
    /* Descrição: este método controla o quanto o tanque pode ser enchido
     * Parâmetros: litros: float -> quanto será colocado no tanque 
    */
    public void encher(float litros){
        float novoVolumeAtual = this.volumeAtual + litros;

        this.volumeAtual = novoVolumeAtual;
        if(novoVolumeAtual == this.volumeMax){
            this.bomba = false;
        }
    }
    
    /* Descrição: este método controla o quanto o tanque pode ser esvaziado
     * Parâmetros: litros: float -> quanto será retirado no tanque 
    */
    public void esvaziar(float litros){
        float novoVolumeAtual = this.volumeAtual - litros;
        if(novoVolumeAtual == this.volumeMin){
            this.bomba = true;
        }
        this.volumeAtual = novoVolumeAtual;
    }
    
    /* Descrição: este método retorna, em forma de string, os valores contidos
     * na bomba e no volume atual, respectivamente
    */
    public String exibirInfos(){
        // Variável auxiliar de exibição da mensagem para a bomba
        String strBomba;
        if(this.bomba){
            strBomba = "ligada";
        } else {
            strBomba = "desligada";
        }
        return "\nBomba: " + strBomba + "\nVolume atual: " + String.valueOf(this.volumeAtual) + "\n";
    }
    
    public void setVolumeMax(float capacidade){
        this.volumeMax = capacidade;
    }
    
    public void setVolumeMin(float min){
        this.volumeMin = min;
    }
    
    public void setVolumeAtual(float volAtual){
        this.volumeAtual = volAtual;
    }
    
    public float getVolumeMax(){
        return this.volumeMax;
    }
    
    public float getVolumeMin(){
        return this.volumeMin;
    }
    
    public float getVolumeAtual(){
        return this.volumeAtual;
    }
}
