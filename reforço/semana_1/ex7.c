/*Escreva um programa que leia um valor em segundos (int) e o converta para o formato HH:MM:SS 
(horas, minutos e segundos), imprimindo, por exemplo, "01:05:23" para uma entrada de 3923 segundos. 
Use apenas divisão inteira e módulo.*/
#include <stdio.h>

int main() {
    int seg, min, hora;
    printf("Segundos:  ");
    scanf("%i", &seg);

    min = seg/60;
    seg %= 60;
    hora = min/60;
    min %= 60;

    printf("Resultado: %02d:%02d:%02d ", hora, min, seg);
}