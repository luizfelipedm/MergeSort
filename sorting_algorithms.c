#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define TAM1 10                                     // Define o tamanho do primeiro vetor;
#define TAM2 100                                    // Define o tamanho do segundo vetor;
#define TAM3 1000                                   // Define o tamanho do terceiro vetor;
#define TAM4 10000                                  // Define o tamanho do quarto vetor;


void getRuntime(bool t);
void submenu(int opcao, int *vet, int tam, char *nome); // Função que exibe um submenu de opções
void menu();                                        // Função que exibe um menu de opções
void verify_alg(int alg);                           // Função que verifica qual o Algoritmo de Ordenação;
void show(int *vet, int tam, int tp, char *nome,int alg, int trocas); // Função que exibe os vetores;
void fill_array(int *vet, int tam, int tp);         // Função que preenche os vetores com números em Ordem Crescente ou Decrescente ou Aleatória;
void sort_algorithms(int *vet, int tam, int i, char *nome);// Função que agrupa todas as funções de ordenação;



// Algoritmos de Ordenação Simples
void insertion_sort(int *vet, int tam, int *trocas);    // Função de Ordenação *InsertionSort*;
void selection_sort(int *vet , int tam, int *trocas);   // Função de Ordenação *SelectionSort*;
void bubble_sort(int *vet, int tam, int *trocas);       // Função de Ordenação *BubbleSort*;

// Algoritmo de Ordenação Complexo
void merge_sort(int i, int tam, int *vet, int *aux, int *trocas);    // Função de Ordenação *MergeSort*;

void array_ordered(int *vet, int tam);             // Função que Retorna um Vetor Preenchido em Ordem Crescente;
void array_reverse(int *vet, int tam);             // Função que Retorna um Vetor Preenchido em Ordem Decrescente;
void array_rand(int *vet, int tam);                // Função que Retorna um Vetor Preenchido em Ordem Aleatória;


int main()
{         
    
    
    menu();
    

    
    

    return 0;
}



void getRuntime(bool t)
{
    clock_t start_t, end_t;
    
    
    if(t == false)
    start_t = 0;
    start_t = clock();
    end_t = 0;

    if(t == true){
    end_t = 0;
    end_t = clock();
    double total_t = (double) (end_t - start_t)/1000000;

    printf("Tempo total: %f s \n", total_t );
    
    total_t = 0;
    
    }
}

void submenu(int opcao, int *vet, int tam, char *nome)
{
        
        if(opcao == 1) opcao = 10;
        if(opcao == 2) opcao = 100;
        if(opcao == 3) opcao = 1000;
        if(opcao == 4) opcao = 10000;

        puts("");
        puts("-------------------------------------SUBMENU-----------------------------------");
        puts("Algoritmos de Ordenacao: InsertionSort, SelectionSort, BubbleSort, MergeSort");
        puts("Escolha o tipo de dados para preencher o vetor:");
        printf("1 - Crescente [0..%d]\n",opcao);
        printf("2 - Decrescente [0..%d]\n",opcao);
        printf("3 - Aleatorio [0..%d]\n",opcao);
        puts("4 - Todos.");
        puts("0 - Sair");
        puts("-------------------------------------SUBMENU-----------------------------------");
        printf("Opcao: ");
        scanf("%d",&opcao);
        puts("");

        switch (opcao)
        {
        case 1:
            sort_algorithms(vet,tam, opcao,nome);
            break;
        case 2:
            sort_algorithms(vet,tam, opcao,nome);
            break;
        case 3:
            sort_algorithms(vet,tam, opcao,nome);
            break;
        case 4:
            for(int i=1; i <= 3;i++)
                sort_algorithms(vet,tam, i,nome);
            break;
        default:
            break;
        }
}

void menu()
{
    int opcao=-1; 
    int vet_1[TAM1],
        vet_2[TAM2],
        vet_3[TAM3],
        vet_4[TAM4];
    while(opcao !=0){
        
        puts("");
        puts("");
        puts("----------------------------------------MENU-----------------------------------");
        puts("Algoritmos de Ordenacao: InsertionSort, SelectionSort, BubbleSort, MergeSort");
        puts("Escolha um tamanho de Vetor:");
        puts("1 - Vetor com 10 Numeros");
        puts("2 - Vetor com 100 Numeros");
        puts("3 - Vetor com 1000 Numeros");
        puts("4 - Vetor com 10000 Numeros");
        puts("5 - Todos os tamanhos");
        puts("0 - Sair");
        puts("----------------------------------------MENU-----------------------------------");
        printf("Opcao: ");
        scanf("%d",&opcao);
        puts("");
        switch (opcao)
        {
        case 1:
            submenu(opcao,vet_1,TAM1,"Vetor 1 com 10 Numeros");
            break;
        case 2:
            submenu(opcao,vet_2,TAM2,"Vetor 2 com 100 Numeros");
            break;
        case 3:
            submenu(opcao,vet_3,TAM3,"Vetor 3 com 1000 Numeros");
            break;
        case 4:
            submenu(opcao,vet_4,TAM4,"Vetor 4 com 10000 Numeros");
            break;
        case 5:
            submenu(opcao,vet_1,TAM1,"Vetor 1 com 10 Numeros");
            submenu(opcao,vet_2,TAM2,"Vetor 2 com 100 Numeros");
            submenu(opcao,vet_3,TAM3,"Vetor 3 com 1000 Numeros");
            submenu(opcao,vet_4,TAM4,"Vetor 4 com 10000 Numeros");
            break;
        
        default:
            break;
        }


    }
}


void verify_alg(int alg)
{
    switch (alg)
    {
    case 1:
        printf("| InsertionSort | ");
        
        break;
    case 2:
        printf("| SelectionSort | ");
        
        break;
    case 3:
        printf("| BubbleSort    | ");
        
        break;
    case 4:
        printf("| MergeSort     | ");
        
        break;
    
    default:
        break;
    }
}

void show(int *vet, int tam, int tp, char nome[27], int alg, int trocas)
{
    puts("------------------------------");
    for (int i = 0; i < tam; i++)
    {
        printf(" %d", vet[i]);
    }
    puts("");
    puts("------------------------------");
    verify_alg(alg);
    switch (tp)
    {
    case 1:
        printf("%s - Ordem Crescente - Num de Trocas: %d ",nome, trocas);
        puts("");
        break;
    case 2:
        printf("%s - Ordem Decrescente - Num de Trocas: %d ",nome, trocas );
        puts("");
        break;
    case 3:
        printf("%s - Ordem Aleatoria - Num de Trocas: %d ",nome, trocas );
        puts("");
        break;
    default:
        break;
    }
    
     
}

void fill_array(int *vet, int tam, int tp)
{
    switch (tp)
    {
    case 1:
        array_ordered(vet,tam);
        break;
    case 2:
        array_reverse(vet,tam);
        break;
    case 3:
        array_rand(vet,tam);
        break;
    default:
        break;
    }
}
void sort_algorithms(int *vet, int tam, int i, char *nome)
{
    puts("");
    puts("");
    puts("########### INSERTION_SORT ############");
        int alg;
    
        int trocas = 0;
        alg = 1;
        fill_array(vet,tam,i);                      // Preenche o vetor em Ordem Crescente ou Decrescente ou Aleatória
        getRuntime(false);
        insertion_sort(vet,tam,&trocas);            // Chama a função de Ordenação *InsertionSort*;
        getRuntime(true);
        
        show(vet,tam,i,nome,alg,trocas);
        puts("");

    puts("");
    puts("END ######## INSERTION_SORT ############");
    puts("");
    puts("");
    puts("########### SELECTION_SORT ############");
    
        trocas = 0;
        alg = 2;
        fill_array(vet,tam,i);                      // Preenche o vetor em Ordem Crescente ou Decrescente ou Aleatória
        getRuntime(false);
        selection_sort(vet,tam,&trocas);            // Chama a função de Ordenação *SelectionSort*;
        getRuntime(true);     
        show(vet,tam,i,nome,alg,trocas);
        puts("");
    
    puts("");
    puts("END ######## SELECTION_SORT ############");
    puts("");
    puts("");
    puts("########### BUBBLE_SORT ###############");
    
        trocas = 0;
        alg = 3;
        fill_array(vet,tam,i);                      // Preenche o vetor em Ordem Crescente ou Decrescente ou Aleatória
        getRuntime(false);
        bubble_sort(vet,tam,&trocas);               // Chama a função de Ordenação *BubbleSort*;
        getRuntime(true);
        
        show(vet,tam,i,nome,alg,trocas);
           
    
    puts("");
    puts("END ######## BUBBLE_SORT ###############");
    puts("");
    puts("");
    puts("########### MERGE_SORT ################");
    int aux[tam];                                   // Vetor aux[] criado para utilização no *MergeSort*;
    
        trocas = 0;
        alg = 4;
        fill_array(vet,tam,i);                      // Preenche o vetor em Ordem Crescente ou Decrescente ou Aleatória
        getRuntime(false);
        merge_sort(0,tam,vet,aux,&trocas);          // Chama a função de Ordenação *MergeSort*;
        getRuntime(true);
        
        show(vet,tam,i,nome,alg,trocas);
         
    
    puts("");
    puts("END ######## MERGE_SORT ################");
}




void insertion_sort(int *vet, int tam, int *trocas)
{
    int atual,
        aux;
    for (int i=1; i < tam; i++)             // O "i" começa na posição [1] do vetor e vai até a ultima posição;
    {
        atual = i;                          // O "atual" recebe a posição [i] que está passando;

        while (vet[atual] < vet[atual-1])   // Enquanto o valor que está passando na posição "atual" for menor que a posição "atual" menos 1, ocorre a troca;
        {                                   // Ocorre a troca;
            aux = vet[atual];
            (*trocas)++;
            vet[atual] = vet[atual-1];
            (*trocas)++;
            vet[atual-1] = aux;
            (*trocas)++;
            atual--;                        // O "atual" decrementa;

            if (atual == 0)                 // Quando "atual" chegar na posição [0], primeira posição do vetor, o laço while para;
                break;
        }

    }
}

void selection_sort(int *vet , int tam, int *trocas)
{
    int menor,
        aux;
    for(int i=0; i < tam-1; i++)        // Percorre todo o vetor até [tam-1], pois a ultima posição não precisa testar;
    {
        menor = i;                      // "menor" valor recebe a posição que está passando;

        for (int j=i+1; j < tam; j++)   // Percorre o vetor da posição [i+1] até o final;
        {
            if (vet[j] < vet[menor])    // Testa se a posição que está passando é menor que o menor valor;
            {
                menor = j;              // menor recebe a posição do menor valor;
            }
        }

        if (menor != i)                 // Se a posição for diferente da que está passando, ocorre a troca;
        {
            aux = vet[i];
            vet[i] = vet[menor];
            (*trocas)++;
            vet[menor] = aux;
            (*trocas)++;
        }
    }
}

void bubble_sort(int *vet, int tam, int *trocas)
{
    int aux;
    for (int j = 1; j < tam; j++) 
    {
        for (int i = 0; i < tam - 1; i++) 
        {
            if (vet[i] > vet[i + 1]) 
            {
                aux = vet[i];
                (*trocas)++;
                vet[i] = vet[i + 1];
                (*trocas)++;
                vet[i + 1] = aux;
                (*trocas)++;
            }
        }
    }
}

void merge_sort(int i, int tam, int *vet, int *aux, int *trocas) 
{
    if (tam <= i) {
        return;                                     // A subseção está vazia ou tem um único elemento;
    }
    int mid = (i + tam) / 2;

    /*  o sub-vetor esquerdo é vet[i .. mid]
        o sub-vetor direito é vet[mid + 1 .. tam]; */

    merge_sort(i, mid, vet, aux, trocas);           // ordena o sub-vetor esquerdo recursivamente;
    merge_sort(mid + 1, tam, vet, aux, trocas);     // ordena o sub-vetor direito recursivamente;

    int ini_esq = i;                                // ini_esq aponta para o começo do sub-vetor esquerdo;
    int ini_dir = mid + 1;                          // ini_dir aponta para o começo do sub-vetor direito;
    int k;                                          // k é o contador dos loops;

                                                    // percorre de i até j para preencher cada elemento do vetor;
    for (k = i; k <= tam; k++) {
        if (ini_esq == mid + 1) {                   // o sub-vetor esquerdo alcançou seu final;
            aux[k] = vet[ini_dir];
            ini_dir++;
            (*trocas)++;
        } else if (ini_dir == tam + 1) {            // o sub-vetor direito alcançou seu final;
            aux[k] = vet[ini_esq];
            ini_esq++;
            (*trocas)++;
        } else if (vet[ini_esq] < vet[ini_dir]) {   // o indice do sub-vetor esquerdo tem o menor elemento;
            aux[k] = vet[ini_esq];
            ini_esq++;
            (*trocas)++;
        } else {                                    // o indice do sub-vetor direito tem o menor elemento;
            aux[k] = vet[ini_dir];
            ini_dir++;
            (*trocas)++;
        }
    }

    for (k = i; k <= tam; k++) {                    // Copia os elementos de aux[] para vet[];
        vet[k] = aux[k];
        (*trocas)++;
    }
}


void array_ordered(int *vet, int tam)
{
    for(int i=0; i < tam; i++)
    {
        vet[i] = i+1;                       // Preenche o Vetor em Ordem Crescente;
    }
}

void array_reverse(int *vet, int tam)
{
    for (int i=tam; i > 0; i--)
    {
        vet[tam-i] = i;                     // Preenche o Vetor em Ordem Decrescente;
    }
}

void array_rand(int *vet, int tam)
{
    srand(time(NULL));
    for (int i=0; i < tam; i++)
    {
        vet[i] = (rand() % 10);        // Preenche o vetor com valores aleatórios de 10 até 99
    }

}

    