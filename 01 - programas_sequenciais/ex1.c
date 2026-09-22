/*Ler as coordenadas de dois pontos no plano cartesiano e imprimir a distância entre estes dois
pontos. OBS: fórmula da distância entre dois pontos (x1,y1) e (x2, y2) */
#include <stdio.h>
#include <math.h>

int main() {
    int x1, x2, y1, y2;
    int dist;
    
    printf("Qual é o x1:  ");
    scanf("%d", &x1);

    printf("Qual é o y1:  ");
    scanf("%d", &y1);

    printf("Qual é o x2:  ");
    scanf("%d", &x2);

    printf("Qual é o y2:  ");
    scanf("%d", &y2);

    dist = hypot(x1 - x2, y1 - y2);
    printf("A distância entre os pontos é %d", dist);
    return 0;
};
