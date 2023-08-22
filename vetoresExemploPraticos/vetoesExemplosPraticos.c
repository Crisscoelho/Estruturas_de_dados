#include <stdio.h>
#include <stdlib.h>

void somar_vetor_com_escalar(int v[], int n, int escalar){
    for (int i = 0; i < n; i++)
    {
        v[i]+= escalar;
    }
}

void print_vetor(int *v, int n){
    for (int i = 0; i < n; i++)
    {
        v[i]++;
        printf("&v[%d] = %p, v[%d] = %d\n", i, &v[i], i, v[i]);
    }

    puts("");

    
}
    

int main() {
    // alocacao de um vetor estático (memória Stack)
    puts("### VETOR ESTATICO");
    int vs[5] = {0, 10, 20, 30, 40};

    print_vetor(vs,5);
    somar_vetor_com_escalar(vs, 5, 9);
    print_vetor(vs,5);

    puts("### VETOR DINAMICO COM CALLOC");
     int *vh = (int *) calloc(5, sizeof(int));
        for (int i = 0; i <5; i++)
    {
        vh[i] = i * 100;
        printf("&vh[%d] = %p, vh[%d] = %d\n", i, &vh[i], i, vh[i]);
    }

    print_vetor(vh,5);
    somar_vetor_com_escalar(vh, 5, 9);
    print_vetor(vh,5);

    //desalocando o vetor dinamico
    free(vh);
    vh = NULL;
     

    return 0;
}