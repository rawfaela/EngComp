#include <stdio.h>

int main()
{
    int matriz[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    for (int i = 0; i < 3; i++) //linha
    {
        for (int j = 0; j < 3; j++) //coluna
        {
            if (matriz[i][j] % 2 == 0)
            {
                printf("%i ",matriz[i][j]);
            }
            else 
            {
                printf("- ");
            }
        }
        printf("\n");
    }
}
