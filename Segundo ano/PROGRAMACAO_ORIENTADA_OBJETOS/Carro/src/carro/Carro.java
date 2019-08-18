/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package carro;
/** 
 * @author Ricardo Oliveira
 */
public class Carro {
    public float tanque = 0;
    public float odometro = 0;
    public float consumoMedio = 0;

    // Método construtor
    public Carro(float consumo, float odometro, float tanque){
        this.consumoMedio = consumo;
        this.odometro = odometro;
        this.tanque = tanque;
    }
    
    // Método para controle de velocidade
    public void setarVelocidade(float vm, float tempo){
        float distancia = vm * tempo;
        float litros = distancia / getConsumoMedio();
        setOdometro(getOdometro() + distancia);
        setTanque(getTanque() - litros);
    }

    public void setTanque(float tanque) {
        this.tanque = tanque;
    }

    public void setOdometro(float odometro) {
        this.odometro = odometro;
    }
    
    public float getTanque() {
        return tanque;
    }

    public float getOdometro() {
        return odometro;
    }

    public float getConsumoMedio() {
        return consumoMedio;
    }
}