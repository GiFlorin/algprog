/*Escreva um programa que leia uma string str1 do teclado. O programa deve então gerar uma outra
string str2 cujo conteúdo seja o mesmo da string original mas na ordem reversa.
 Finalmente, o programa deve
decidir se as strings são palı́ndromas, ou seja, iguais na ordem direta e reversa. Considere que caracteres em
maiúsculo e minúsculo são iguais.*/

#include <stdio.h>
#include <string.h>
#define TAM 10

int main(void) {
    char str1[TAM+1] = {'\0'};
    char str2[TAM + 1] = {'\0'};
    int palindromo = 0;

    // entrada de dados
    printf("Digite a str1[%d]:  ", TAM);
    fgets(str1, TAM+1, stdin);

    str1[strlen(str1)-1]= '\0';
    printf("%s", str1);
    // inverter string
    int i;
    for(i = 0; i < strlen(str1); i++) {
        str2[i] = str1[strlen(str1) -1 - i];
        printf(" %c ", str2[i]);
    }
    str2[i] = '\0';


    // igualar as duas
    for (int i = 0; i < strlen(str1); i++) {
        str1[i] = tolower(str1[i]);
        str2[i] = tolower(str2[i]);
    }

    palindromo = strcmp(str1, str2);

    printf("\n-- RESULTADOS -- \n");

    if(!palindromo) {
        printf("\nÉ um palindromo!!\n");
    } else printf("\nNao e um palindromo!!\n");

    // resultados

    printf("STR1: %s\n", str1);
    printf("STR2: %s\n", str2);
    return 0;

}
