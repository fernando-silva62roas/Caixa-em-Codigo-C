#include <stdio.h>

int main() {
    int usuario, senha, saldo, saque;
    int n100, n50, n20, n10, n5;

    printf("Usuario (1 = Ana, 2 = Bruno, 3 = Luis): ");
    scanf("%d", &usuario);
    printf("Senha: ");
    scanf("%d", &senha);

    /* Confere o login e define o saldo de cada usuario */
    if (usuario == 1 && senha == 1234) {
        saldo = 1000;
        printf("\nBem-vindo(a), Ana!\n");
    } else if (usuario == 2 && senha == 4321) {
        saldo = 500;
        printf("\nBem-vindo(a), Bruno!\n");
    } else if (usuario == 3 && senha == 1111) {
        saldo = 2500;
        printf("\nBem-vindo(a), Luis!\n");
    } else {
        printf("Usuario ou senha incorretos!\n");
        return 0;
    }

    printf("Saldo: R$ %d\n", saldo);
    printf("Quanto deseja sacar? R$ ");
    scanf("%d", &saque);

    if (saque <= 0 || saque % 5 != 0) {
        printf("O valor precisa ser maior que 0 e divisivel por 5!\n");
    } else if (saque > saldo) {
        printf("Saldo insuficiente!\n");
    } else {
        saldo = saldo - saque;

        /* Calcula a quantidade de cada nota */
        n100 = saque / 100;
        saque = saque % 100;
        n50 = saque / 50;
        saque = saque % 50;
        n20 = saque / 20;
        saque = saque % 20;
        n10 = saque / 10;
        saque = saque % 10;
        n5 = saque / 5;

        printf("\nNotas entregues:\n");
        if (n100 > 0) printf("%d nota(s) de R$ 100\n", n100);
        if (n50 > 0) printf("%d nota(s) de R$ 50\n", n50);
        if (n20 > 0) printf("%d nota(s) de R$ 20\n", n20);
        if (n10 > 0) printf("%d nota(s) de R$ 10\n", n10);
        if (n5 > 0) printf("%d nota(s) de R$ 5\n", n5);

        printf("\nNovo saldo: R$ %d\n", saldo);
    }

    return 0;
}