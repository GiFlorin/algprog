/*Escreva um programa que leia um valor em minutos (int) e converta para horas e minutos 
(por exemplo, 125 minutos = 2 horas e 5 minutos), utilizando divisão inteira e o operador %.*/
#include <stdio.h>

int main() {
    int min, hora;
    printf("Minutos:");
    scanf("%i", &min);
    hora = min/60;
    min = min%60;
    printf("Resultado: %i:%i", hora, min);
}