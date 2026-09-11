#include <stdio.h>
#include <malloc.h> //alocação de memoria (memory allocation)

int main()
{
    int *ptr;
    ptr = (int *)malloc(sizeof(int)); //func malloc conversa com sist operacional pra conquistar mais memoria p programa
    //malloc retorna o endereço da memoria conquistada em ponteiro do tipo neutro (void)
          //converte pra ponteiro de inteiro (casting)
    ptr = (int *)malloc(sizeof(int)*5); //assim pega pra 5 inteiros

    for (int i = 0; i<5;i++)
    {
        ptr[i] = i;
        printf("%i\n",ptr[i]);
    }

    free(ptr); //quando n precisa mais da memoria alocada, tem q liberar ela pro sist op
}
