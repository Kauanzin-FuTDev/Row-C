#include <stdio.h>
#include <malloc.h>
#include <string.h> // Para strcpy()
int count = 0;

typedef struct cell{
    int count;
    char tel[10];
    struct cell *next;
}tc;


typedef struct row{
    tc *begen;
   tc *end;
}tr;

tr *row;

void insert(char x[10], tr *r, int co){
    tc *new = (tc*) malloc(sizeof(tc));
    new->count = co;
    strcpy(new->tel,x);
    new->next = NULL;
    if(r->begen == NULL){
        r->begen = new;
        r->end = new;
    }
    else{
        r->end->next =new;
        r->end = new;
    }
}

void PrintRow(tr *r){
    tc *aux;
    if(r->begen == NULL){
        printf("\n Fila Vazia");
    }
    else{
        aux = r->begen;
        printf("\n[");
        do{
            printf("%d %s\t" , aux->count ,aux->tel);
            aux = aux->next;
        }while(aux !=NULL);
        printf("]\n");
    }
}

void Remove(tr *r){
    tc *aux;
    if(r->begen == NULL){
        printf("\n Fila vazia");
    }
    else{
        aux = r->begen;
        printf("%s removido", r->begen->tel);
        r->begen = r->begen->next;
        free(aux);
    }
}

void ClearRow(tr *r){
    tc *aux;
    if(r->begen == NULL){
        printf("\n Fila vazia");
    }
    else{
        aux = r->begen;
        do{
            r->begen = r->begen->next;
            free(aux);
            aux =  r->begen;
        }while(aux != NULL);
        printf("\nFIla esvaziada");
    }
}

void PrintSetValue(tr *r){
    char x[10];
    printf("\n=================================");
    printf("\nColoque o telefone:");
    scanf("%s", x);
    printf("\n=================================");

    count++;
    insert(x,r,count);
}
void PrintValues(tr *r){
    printf("\n=================================");
    PrintRow(r);
    printf("\n=================================");

}
void PrintRemove(tr *r){
    printf("\n=================================");
    Remove(r);
    printf("\n=================================");
}

int main(void) {
    row = (tr*) malloc(sizeof(tr));

    if(!row){
        printf("Sem memória disponível!\n");
        exit(1);
    }
    if(row != NULL)
    {
        /*a fila inicia-se vazia, portanto inicio e fim são iguais a NULL*/
        row->end = NULL;
        row->begen = NULL;
    }
    int option = 0;
    do{
        printf("\n *** Gerenciador de Chamadas ***\n\n");
        printf("1 - Inserir\n");
        printf("2 - Remover\n");
        printf("3 - Imprimir\n");
        printf("4 - Esvaziar\n");
        printf("0 - Fim");
        printf("\n Digite a opção: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                PrintSetValue(row);
                break;
            case 2:
                PrintRemove(row);
                break;
            case 3:
                PrintValues(row);
                break;
            case 4:
                ClearRow(row);
                break;
            case 0:
                break;
            default:
                printf("Opção inválida");
        }
        if (option == 0)
        {
            break;
        }

    } while (option !=0);

    return 0;
}
