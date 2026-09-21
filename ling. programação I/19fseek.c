#include <stdio.h>

int main()
{
    char nome[] = "rafa ela";
    FILE *fp;
    fp = fopen("nome.txt","w");
    fwrite(nome, sizeof(char), sizeof(nome), fp);
    fclose(fp);

    fp = fopen("nome.txt", "r");
    char letra;
    //fseek(file, offset, origin) -> arquivo, qtd de bytes p pular, posicao inicial
    fseek(fp, 5 * sizeof(char), SEEK_SET); //fseek posiciona o ponteiro do arq a uma dist relativa (ao inicio / fim do arquivo, ou posicao atual do arq)
              //pra ler o "e" de rafa ela
    fread(&letra, sizeof(char),1,fp);
    printf("%c\n",letra);
}
