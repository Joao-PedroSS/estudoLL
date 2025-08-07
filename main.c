#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

#define MAX 5

#define IA 0
#define FA MAX-1

int IL, FL, ind;

void exibirArray(int ar[], int I, int F);
void Inserir_Inicio(int LL[]);
void Inserir_Final(int LL[]);
void Inserir_Meio(int LL[]);
void Remover(int LL[]);

int main() {
    setlocale(LC_ALL, "Portuguese");
    int LL[MAX], op, opp;

    //Criação da Lista Linear Sequencial
    IL = FL = IA - 1;

    printf("\nESCOLHA A OPERAÇÃO DESEJADA");
    printf("\nDigite 1 para adicionar informação na lista.");
    printf("\nDigite 2 para remover informação da lista.");
    printf("\nDigite 3 para exibir a lista.");
    printf("\nDigite 4 para sair.");
    printf("\n\nOpção: ");
    scanf("%d", &op);

    while(op != 4) {
        switch (op){
        case 1:
            printf("\n\t|OPERAÇÃO DE INSERÇÃO:");
            printf("\n\t|Digite 1 para Inserir no INÍCIO da Lista Linear");
            printf("\n\t|Digite 2 para Inserir no FINAL da Lista Linear");
            printf("\n\t|Digite 3 para Inserir no MEIO(k) da Lista Linear.");
            printf("\n\t|Opção: ");
            scanf("%d", &opp);

            if (opp == 1)
                Inserir_Inicio(LL);
            else if (opp == 2)
                Inserir_Final(LL);
            else if (opp == 3)
                Inserir_Meio(LL);

            break;

        case 2:
            Remover(LL);
            break;

        case 3:
            exibirArray(LL, IL, FL);
            break;

        case 5:
            exibirArray(LL, IA, MAX);
            break;
        }

        printf("\nESCOLHA A OPERAÇÃO DESEJADA");
        printf("\nDigite 1 para adicionar informações na lista.");
        printf("\nDigite 2 para remover informação da lista.");
        printf("\nDigite 3 para exibir a lista.");
        printf("\nDigite 4 para sair.");
        printf("\n\nOpção: ");
        scanf("%d", &op);
    }
}

void Inserir_Final(int LL[])
{
    int n, i;
    printf("\t|\n\t|Insira um número: ");
    scanf("%d", &n);

    if (IL == IA && FL == MAX) {
        printf("\t|Vetor cheio!");
    } else {
        if (IL == -1) {
            IL = FL = IA;
        }

        if (FL <= FA) {
            LL[FL] = n;
            FL++;

        } else {
            for (i = IL; i <= FL; i++){
                LL[i - 1] = LL[i];
            }

            IL--;
            LL[FL] = n;
        }
    }

    for (i = 0; i < 3; i++) {
        printf(".");
        Sleep(500);
    }
    system("cls");
}

void Inserir_Inicio(int LL[])
{
    int n, i;
    printf("\t|\n\t|Insira um número: ");
    scanf("%d", &n);

    if (IL == IA && FL == MAX) {
        printf("\t|Vetor cheio!");
    } else {
        if (IL == -1) {
            IL = FL = IA;
        }

        if (IL > IA) { //Tem espaço
            IL--;
            LL[IL] = n;

        } else {
            for (i = FL; i >= IL; i--){
                LL[i + 1] = LL[i];
            }

            FL++;
            LL[IL] = n;
        }
    }

    for (i = 0; i < 3; i++) {
        printf(".");
        Sleep(500);
    }
    system("cls");
}

void Inserir_Meio(int LL[])
{
    int n, i, ind, indexL;
    printf("\t|\n\t|Insira uma posição para o número (de 0 a %d): ", (IL == -1) ? 0 : FL - IL - 1);
    scanf("%d", &ind);

    indexL = IL + ind;

    printf("\t|Insira um número: ");
    scanf("%d", &n);

    if (IL == IA && FL == MAX) {
        printf("\t|Vetor sem espaço!");
    } else {
        if (FL == -1) {
            IL = FL = IA;
            LL[IL] = n;
            indexL = IL + ind;
        } else {
            if (FL != FA) { // tem espaço no final
                for (i = FL; i >= indexL; i--) {
                    LL[i + 1] = LL[i];
                }
                FL++;
                LL[indexL] = n;

            } else {
                for (i = IL; i <= indexL; i++) {
                    LL[i - 1] = LL[i];
                }
                IL--;
                LL[indexL] = n;
            }
        }
    }

    for (i = 0; i < 3; i++) {
        printf(".");
        Sleep(500);
    }
    system("cls");
}

void exibirArray(int ar[], int I, int F)
{
    int i;
    if (I == -1 || F == -1)
        printf("\n\tVetor não inicializado!");
    else {
        printf("\n\t|Lista = [%d", ar[IL]);

        for (i = I + 1; i < F; i++) {
            printf(",%d", ar[i]);
        }
        printf("]");
        for (i = 0; i < 3; i++) {
            printf(".");
            Sleep(1000);
        }
        system("cls");
    }

}

void Remover(int LL[])
{
    int i, ind;
    printf("\n\t|Insira a poscição que deseja remover:");
    scanf("%d", &ind);

    if (IL == -1) {
        printf("\t|LL não inicializada!");
    } else {
        ind = IL + ind;
        for (i = ind + 1; i < FL; i++) {
            LL[i - 1] = LL[i];
        }
        FL--;

        for (i = 0; i < 3; i++) {
            printf(".");
            Sleep(500);
        }
        system("cls");
    }

}
