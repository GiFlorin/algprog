/*Uma estação meteorológica registra a temperatura e a condição do tempo ao longo da manhã,
realizando uma medição a cada 3 horas, iniciando às 0h e terminando às 12h.

Para cada horário, devem ser informados a temperatura registrada e um código correspondente à condição do
tempo: 1 – Ensolarado, 2 – Nublado, 3 – Chuvoso.
Faça um programa utilizando obrigatoriamente for e switch-case:
a) calcule a média das temperaturas registradas;
b) informe a maior temperatura registrada;
c) informe o horário em que ocorreu a maior temperatura;
d) conte quantas mediçõ es indicaram cada uma das três condições meteorológicas*/

#include <stdio.h>

int main(void) {
    int h0t, h3t, h6t, h9t, h12t; // temperaturas
    int ensolarado = 0, nublado = 0, chuvoso = 0; // condicoes
    int maior_temp = 0, maior_temp_h = 0; // comparacoes
    float media_temp = 0, soma = 0;

    for (int h = 0; h<=12; h +=3 ) {
        int cond, temp;
        // recebe as temperaturas e guarda em variaveis
        printf("\nDigite a temperatura da hora %d:  ", h);
        scanf("%d", &temp);

        // guardar a temperatura na variavel certa
        switch (h) {
            case 0: h0t = temp; break;
            case 3: h3t = temp; break;
            case 6: h6t = temp; break;
            case 9: h9t = temp; break;
            case 12: h12t = temp; break;
        }
        soma += (float)temp;
        if (temp > maior_temp) {
            maior_temp = temp;
            maior_temp_h = h;
        }


        // recebe as condicoes e guarda nos contadores
        printf("Condicao do tempo(1 - Ensolarado, 2 - Nublado, 3 - Chuvoso):  ");
        scanf("%d", &cond);
        switch (cond) {
            case 1: ensolarado++; break;
            case 2: nublado++; break;
            case 3: chuvoso++; break;
            default: printf("Valor invalido\n"); break;
        }
    }
    media_temp = soma / 5.0; // divide a media

    // output
    printf("\n--DADOS--\n");
    printf("Media das temperaturas: %.2f \n", media_temp);
    printf("Maior temp registrada:  %d \n", maior_temp);
    printf("Horario da maior temp:  %dh \n", maior_temp_h);
    printf("Num ensolarado:         %d \n", ensolarado);
    printf("Num nublado:            %d \n", nublado);
    printf("Num chuvoso:            %d", chuvoso);

    return 0;
}

