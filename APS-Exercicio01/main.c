#include <stdio.h>
#include <stdlib.h>
// Criando a enumeração:
enum boolean {
    true = 1, false = 0
};
// Permitindo a sua declaração como um tipo qualquer:
typedef  enum boolean  bool;

int *arrayId;
char (*arrayFn)[50];
char (*arrayLn)[50];
char (*arrayBd)[50];
char (*arrayPn)[50];
int cad = 0; // numero de pessoas cadastradas
int array = 50; //numero de pessoas que podem ser cadastradas sem alterar o array
void add(char info[]) {
    char *token;
    int cadastro = cad; //variavel intermediaria que faz os cadastros, ela é utilizada para caso algum delete seja feito, o código aproveite esse espaço de memória novamente
    int i = 0, e = 0;
    char intermediario[25];
    if(cad >= array-1) {
        array+=10;
        arrayId = (int *) realloc (arrayId, array * sizeof(int));
        arrayFn=(char (*)[25])realloc(arrayFn, sizeof(*arrayFn)*array);
        arrayLn=(char (*)[25])realloc(arrayLn, sizeof(*arrayLn)*array);
        arrayBd=(char (*)[25])realloc(arrayBd, sizeof(*arrayBd)*array);
        arrayPn=(char (*)[25])realloc(arrayPn, sizeof(*arrayPn)*array);
    }
    token = strtok(info, " ");

    for(i = 0; i<cad; i++) {
        if(arrayId[i] ==  -2) {
            cadastro = i;
        }
    }

    for(i = 0; i<cad; i++) {
        if(arrayId[i] ==  atoi(token)) {
            cadastro = -3;
        }
    }

    if(cadastro!= -3) {

        i = 0;
        while( token != NULL ) {
            strcpy(intermediario, token);
            switch(i) {
            case 0:
                arrayId[cadastro] = atoi(intermediario);
                break;
            case 1:
                for(e = 0; e<=strlen(intermediario); e++) {
                    if(e==strlen(intermediario)) {
                        arrayFn[cadastro][e] = ' ';
                    } else {
                        arrayFn[cadastro][e] = intermediario[e];
                    }
                }
                break;
            case 2:
                for(e = 0; e<=strlen(intermediario)+1; e++) {
                    if(e==strlen(intermediario)) {
                        arrayLn[cadastro][e] = ' ';
                    } else {
                        arrayLn[cadastro][e] = intermediario[e];
                    }
                }
                break;
            case 3:
                for(e = 0; e<=strlen(intermediario)+1; e++) {
                    if(e==strlen(intermediario)) {
                        arrayBd[cadastro][e] = ' ';
                    } else {
                        arrayBd[cadastro][e] = intermediario[e];
                    }
                }
                break;
            case 4:
                for(e = 0; e<=strlen(intermediario)+1; e++) {
                    if(e==strlen(intermediario)) {
                        arrayPn[cadastro][e] = ' ';
                    } else {
                        arrayPn[cadastro][e] = intermediario[e];
                    }
                }
                break;
            default:
                printf("Dado a mais inserido e ignorado %s    %i\n", intermediario, i);
                break;
            }
            i++;
            token = strtok(NULL, " ");
        }
        cad++;
    } else {
        printf("ID %d ja cadastrado\n", atoi(token));
    }

}

void info(int id) {
    int i = 0;
    int e = -1;

    for(i = 0; i<cad; i++) {
        if(arrayId[i] ==  id) {
            e = i;
        }
    }
    if(e != -1) {
        i = 0;
        printf("%d ", arrayId[e]);
        while(arrayFn[e][i] != ' ') {
            printf("%c",arrayFn[e][i]);
            i++;
        }
        printf(" ");
        i = 0;
        while(arrayLn[e][i] != ' ') {
            printf("%c",arrayLn[e][i]);
            i++;
        }
        printf(" ");
        i = 0;
        while(arrayBd[e][i] != ' ') {
            printf("%c",arrayBd[e][i]);
            i++;
        }
        printf(" ");
        i = 0;
        while(arrayPn[e][i] != ' ') {
            printf("%c",arrayPn[e][i]);
            i++;
        }
        printf("\n");
    } else {
        printf("ID %d nao existente\n", id);
    }
}

void del(int id) {
    int i = 0;
    int e = -1;
    char intermediario[4];

    for(i = 0; i<cad; i++) {
        if(arrayId[i] ==  id) {
            e = i;
        }
    }

    if(e != -1) {
        arrayId[e] = -2;
        while(arrayFn[e][i] != ' ') {
            arrayFn[e][i] = ' ';
            i++;
        }
        i = 0;
        while(arrayLn[e][i] != ' ') {
            arrayLn[e][i] = ' ';
            i++;
        }
        i = 0;
        while(arrayBd[e][i] != ' ') {
            arrayBd[e][i] = ' ';
            i++;
        }
        i = 0;
        while(arrayPn[e][i] != ' ') {
            arrayPn[e][i] = ' ';
            i++;
        }
        printf("\n");
        cad--;
    } else {
        printf("ID %d nao existente\n", id);
    }
}

void query(char info[]) {
    int i = 0, e = 0, o = 0, contA = 0, contB = 0;
    int arrayBuscaA[array], arrayBuscaB[array], arrayBuscaC[array], arrayBuscaD[array], arrayBuscaE[array], arrayBuscaF[array], arrayBuscaG[array];
    char *token, *token2;
    char intermediario[200], intermediario2[200];
    bool verA = false, verB = false, verC = false, verD = false;

    for(i = 0; i<array; i++) {
        arrayBuscaA[i] = -4;
    }

    for(i = 0; i<array; i++) {
        arrayBuscaB[i] = -4;
    }

    for(i = 0; i<array; i++) {
        arrayBuscaC[i] = -4;
    }

    for(i = 0; i<array; i++) {
        arrayBuscaD[i] = -4;
    }

    for(i = 0; i<array; i++) {
        arrayBuscaE[i] = -4;
    }

    for(i = 0; i<array; i++) {
        arrayBuscaF[i] = -4;
    }

    for(i = 0; i<array; i++) {
        arrayBuscaG[i] = -4;
    }
    token  = strtok(info, ":");

    while( token != NULL ) {
        o = 0;
        e = 0;
        if(strcmp(token, "fn") == 0) {
            verA = true;
            token  = strtok(NULL, "\0");
            strcpy(intermediario2, token);
            token  = strtok(token, " ");
            for(i = 0; i<cad; i++) {
                while(arrayFn[i][e] != ' ') {
                    intermediario[e] = arrayFn[i][e];
                    e++;
                }
                intermediario[e] = ' ';
                token2 = strtok(intermediario, " ");
                if(strcmp(intermediario, token) == 0) {
                    arrayBuscaA[o] = arrayId[i];
                    o++;
                }
                e = 0;
            }
            strcpy(token, intermediario2);
        }
        o = 0;
        e = 0;
        if(strcmp(token, "ln") == 0) {
            verB = true;
            token  = strtok(NULL, "\0");
            strcpy(intermediario2, token);
            token  = strtok(token, " ");
            for(i = 0; i<cad; i++) {
                while(arrayLn[i][e] != ' ') {
                    intermediario[e] = arrayLn[i][e];
                    e++;
                }
                intermediario[e] = ' ';
                token2 = strtok(intermediario, " ");
                if(strcmp(intermediario, token) == 0) {
                    arrayBuscaB[o] = arrayId[i];
                    o++;
                }
                e = 0;
            }
            strcpy(token, intermediario2);
        }
        o = 0;
        e = 0;
        if(strcmp(token, "bd") == 0) {
            verC = true;
            token  = strtok(NULL, "\0");
            strcpy(intermediario2, token);
            token  = strtok(token, " ");
            for(i = 0; i<cad; i++) {
                while(arrayBd[i][e] != ' ') {
                    intermediario[e] = arrayBd[i][e];
                    e++;
                }
                intermediario[e] = ' ';
                token2 = strtok(intermediario, " ");
                if(strcmp(intermediario, token) == 0) {
                    arrayBuscaC[o] = arrayId[i];
                    o++;
                }
                e = 0;
            }
            strcpy(token, intermediario2);
        }
        o = 0;
        e = 0;
        if(strcmp(token, "pn") == 0) {
            verD = true;
            token  = strtok(NULL, "\0");
            strcpy(intermediario2, token);
            token  = strtok(token, " ");
            for(i = 0; i<cad; i++) {
                while(arrayPn[i][e] != ' ') {
                    intermediario[e] = arrayPn[i][e];
                    e++;
                }
                intermediario[e] = ' ';
                token2 = strtok(intermediario, " ");
                if(strcmp(intermediario, token) == 0) {
                    arrayBuscaD[o] = arrayId[i];
                    o++;
                }
                e = 0;
            }
            strcpy(token, intermediario2);
        }

        token  = strtok(token, " ");
        token  = strtok(NULL, "\0");
        token  = strtok(token, ":");

    }

    o = 0;
    contA = 0;
    contB = 0;
    if((arrayBuscaA[0] != -4) && (arrayBuscaB[0] != -4)) {

        for(i = 0; arrayBuscaA[i] != -4; i++) {
            contA++;
        }

        for(i = 0; arrayBuscaB[i] != -4; i++) {
            contB++;
        }

        for(i = 0; i<contA; i++) {
            for(e = 0; e<contB; e++) {
                if(arrayBuscaA[i] == arrayBuscaB[e]) {
                    arrayBuscaE[o] = arrayBuscaA[i];
                    o++;
                }
            }
        }
    } else if(arrayBuscaA[0] != -4 && (verB == false)) {
        for(i = 0; arrayBuscaA[i] != -4; i++) {
            contA++;
        }
        for(i = 0; i < contA; i++) {
            arrayBuscaE[i] = arrayBuscaA[i];
        }
    } else if(arrayBuscaB[0] != -4 && (verA == false)) {
        for(i = 0; arrayBuscaB[i] != -4; i++) {
            contB++;
        }
        for(i = 0; i < contB; i++) {
            arrayBuscaE[i] = arrayBuscaB[i];
        }
    }

    o = 0;
    contA = 0;
    contB = 0;
    if((arrayBuscaC[0] != -4) && (arrayBuscaD[0] != -4)) {

        for(i = 0; arrayBuscaC[i] != -4; i++) {
            contA++;
        }

        for(i = 0; arrayBuscaD[i] != -4; i++) {
            contB++;
        }

        for(i = 0; i<contA; i++) {
            for(e = 0; e<contB; e++) {
                if(arrayBuscaC[i] == arrayBuscaD[e]) {
                    arrayBuscaF[o] = arrayBuscaC[i];
                    o++;
                }
            }
        }
    } else if(arrayBuscaC[0] != -4 && (verD == false)) {
        for(i = 0; arrayBuscaC[i] != -4; i++) {
            contA++;
        }
        for(i = 0; i < contA; i++) {
            arrayBuscaF[i] = arrayBuscaC[i];
        }
    } else if(arrayBuscaD[0] != -4 && (verC == false)) {
        for(i = 0; arrayBuscaD[i] != -4; i++) {
            contB++;
        }
        for(i = 0; i < contB; i++) {
            arrayBuscaF[i] = arrayBuscaD[i];
        }
    }

    o = 0;
    contA = 0;
    contB = 0;
    if((arrayBuscaE[0] != -4) && (arrayBuscaF[0] != -4)) {
        for(i = 0; arrayBuscaE[i] != -4; i++) {
            contA++;
        }

        for(i = 0; arrayBuscaF[i] != -4; i++) {
            contB++;
        }

        for(i = 0; i<contA; i++) {
            for(e = 0; e<contB; e++) {
                if(arrayBuscaE[i] == arrayBuscaF[e]) {
                    arrayBuscaG[o] = arrayBuscaE[i];
                    o++;
                }
            }
        }
    } else if(arrayBuscaE[0] != -4) {
        for(i = 0; arrayBuscaE[i] != -4; i++) {
            contA++;
        }
        for(i = 0; i < contA; i++) {
            arrayBuscaG[i] = arrayBuscaE[i];
        }
    } else if(arrayBuscaF[0] != -4) {
        for(i = 0; arrayBuscaF[i] != -4; i++) {
            contB++;
        }
        for(i = 0; i < contB; i++) {
            arrayBuscaG[i] = arrayBuscaF[i];
        }
    }

    if(arrayBuscaG[0] == -4) {
        printf("\n");
    } else {
        contA = 0;
        for(i = 0; arrayBuscaG[i] != -4; i++) {
            contA++;
        }
        if(contA > 1) {
            for(i = 0; i<contA; i++) {
                for(e = i+1; e<contA; e++) {
                    if(arrayBuscaG[i]>arrayBuscaG[e]) {
                        o = arrayBuscaG[i];
                        arrayBuscaG[i] = arrayBuscaG[e];
                        arrayBuscaG[e] = o;
                    }
                }
            }

            for(i = 0; i<contA; i++) {
                printf("%d ", arrayBuscaG[i]);
            }
            printf("\n");
        } else {
            printf("%d\n", arrayBuscaG[0]);
        }
    }

}

int main()
{
    int i = 0, tokenInt;
    int id;
    char *token;
    arrayId = (int *) calloc (array, sizeof(int));
    arrayFn=(char (*)[25])malloc(sizeof(*arrayFn)*array);
    arrayLn=(char (*)[25])malloc(sizeof(*arrayLn)*array);
    arrayBd=(char (*)[25])malloc(sizeof(*arrayBd)*array);
    arrayPn=(char (*)[25])malloc(sizeof(*arrayPn)*array);
    char intermediario[200] = {"s"};

    while(strcmp(intermediario, "000") != 0) {
        fflush(stdin);
        strcpy(intermediario, "");
        gets(intermediario);

        token  = strtok(intermediario, " ");
        if(strcmp(token, "add") == 0 ) {
            token  = strtok(NULL, "\0");
            add(token);
        } else if(strcmp(token, "info") == 0) {
            token  = strtok(NULL, "\0");
            tokenInt = atoi(token);
            info(tokenInt);
        } else if(strcmp(token, "del") == 0) {
            token  = strtok(NULL, "\0");
            tokenInt = atoi(token);
            del(tokenInt);
        } else if(strcmp(token, "query") == 0 ) {
            token  = strtok(NULL, "\0");
            query(token);
        }
    }

    free(arrayId);
    free(arrayFn);
    free(arrayLn);
    free(arrayBd);
    free(arrayPn);

    return 0;
}
