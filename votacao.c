#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct Eleitor{
    char nome[100];
    char titulo[20];
    char voto[50];
} Eleitor;

typedef struct Node{
    Eleitor dados;
    struct Node *esq, *dir; 
} Node;

Node* criarNo(Eleitor e){
    Node* novo = (Node*)malloc(sizeof(Node));
    novo->dados = e;
    novo->esq = novo->dir = NULL;
    return novo;
}

Node* add(Node* raiz, Eleitor e){
    if (raiz == NULL) return criarNo(e);
    int cmp = strcmp(e.titulo, raiz->dados.titulo);
    if (cmp < 0)
        raiz->esq = add(raiz->esq, e);
    else if (cmp > 0)
        raiz->dir = add(raiz->dir, e);
    return raiz;
}

Node* buscar(Node* raiz, char* titulo){
    if (raiz == NULL ) return NULL;
    int cmp = strcmp(titulo, raiz->dados.titulo);
    if (cmp == 0) return raiz;
    else if (cmp < 0) return buscar(raiz->esq, titulo);
    else return buscar(raiz->dir, titulo);
}

Node* min(Node* raiz){
    while (raiz && raiz->esq) raiz = raiz->esq;
    return raiz;
}

Node* apaga(Node* raiz, char* titulo){
    if (!raiz) return NULL;
    int cmp = strcmp(titulo, raiz->dados.titulo);
    if (cmp < 0) raiz->esq = apaga(raiz->esq, titulo);
    else if (cmp > 0) raiz->dir = apaga(raiz->dir, titulo);
    else{
        if (!raiz->esq){
            Node* temp = raiz->dir;
            free(raiz);
            return temp;
        } else if (!raiz->dir){
            Node* temp = raiz->esq;
            free(raiz);
            return temp;
        }
        Node* temp = min(raiz->dir);
        raiz->dados = temp->dados;
        raiz->dir = apaga(raiz->dir, temp->dados.titulo);
    }
    return raiz;
}

void inOrder(Node* raiz){
    if (!raiz) return;
    inOrder(raiz->esq);
    printf("Nome: %s |  Titulo: %s | Voto: %s\n", raiz->dados.nome, raiz->dados.titulo, raiz->dados.voto);
    inOrder(raiz->dir);
}

void save(Node* raiz, FILE* f){
    if (!raiz) return;
    save(raiz->esq, f);
    fprintf(f, "%s;%s;%s\n", raiz->dados.nome, raiz->dados.titulo, raiz->dados.voto);
    save(raiz->dir, f);
}

void saveArq(Node* raiz){
    FILE* f = fopen("database.txt", "w");
    if (!f) return;
    save(raiz, f);
    fclose(f);
}

Node* loadArq(){
    FILE* f = fopen("database.txt", "r");
    if (!f) return NULL;
    Node* raiz = NULL;
    Eleitor e;

    while (fscanf(f, "%99[^;];%19[^;];%49[^\n]\n", e.nome, e.titulo, e.voto) == 3) {
        raiz = add(raiz, e);
    }

    fclose(f);
    return raiz;
}

int main(){ 
    setlocale(LC_ALL, "pt_BR.UTF-8");
    Node* raiz = loadArq();
    int opcao;
    char titulo[20];
    Eleitor e;

    do{
        printf("\nSistema de Votação\n");
        printf("1- Cadastrar eleitor\n");
        printf("2- Buscar eleitor\n");
        printf("3- Atualizar voto\n");
        printf("4- Remover eleitor\n");
        printf("5- Listar eleitores\n");
        printf("0- Sair\nOpção: ");
        scanf("%d", &opcao);
        getchar();

        switch(opcao){
            case 1:
                printf("Nome: "); fgets(e.nome, 100, stdin); strtok(e.nome, "\n");
                printf("Titulo: "); fgets(e.titulo, 20, stdin); strtok(e.titulo, "\n");
                printf("Voto: "); fgets(e.voto, 50, stdin); strtok(e.voto, "\n");
                raiz = add(raiz, e);
                saveArq(raiz);
                break;
            case 2:
                printf("Digite o titulo: "); fgets(titulo, 20, stdin); strtok(titulo, "\n");
                Node* acha = buscar(raiz, titulo);
                if (acha)
                    printf("Nome: %s | Titulo: %s | Voto: %s\n", acha->dados.nome, acha->dados.titulo, acha->dados.voto);
                else
                    printf("Eleitor não encontrado. \n");
                break;
            case 3:
                printf("Título de eleitor a atualizar: "); fgets(titulo, 20, stdin); strtok(titulo, "\n");
                Node* alvo = buscar(raiz, titulo);
                if (alvo){
                    printf("Novo voto: "); fgets(alvo->dados.voto, 50, stdin); strtok(alvo->dados.voto, "\n");
                    saveArq(raiz);
                } else {
                    printf("Eleitor nao encontrado. \n");
                }
                break;
            case 4:
                printf("Título de eletor para apagar: "); fgets(titulo, 20, stdin); strtok(titulo, "\n");
                raiz = apaga(raiz, titulo);
                saveArq(raiz);
                break;
            case 5:
                inOrder(raiz);
                break;
            case 0:
                saveArq(raiz);
                break;
            default:
                printf("Opcao invalida. \n");
        }   
    } while (opcao != 0);
    return 0;
}