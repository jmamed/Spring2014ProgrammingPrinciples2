#include <stdio.h>
#pragma warning(disable:4996)


int value;
int element(int *a, int *b);

int main()
{
    FILE *fp, *fp2;
    int t;
    int a1, a2;
    int r;
    int n = 1;
    int i, j;
    int table[5][5];
    int table2[5][5];

    fp = fopen("input.txt", "r");
    fp2 = fopen("output.txt", "w");
    fscanf(fp, "%d", &t);

    while (n <= t)
    {
        fscanf(fp, "%d", &a1);
        for (i = 0; i < 4; i++){
            for (j = 0; j < 4; j++)
                fscanf(fp, "%d", &table[i][j]);
        }

        fscanf(fp, "%d", &a2);
        for (i = 0; i < 4; i++)
        {
            for (j = 0; j < 4; j++)
                fscanf(fp, "%d", &table2[i][j]);
        }

        r = element(table[a1 - 1], table2[a2 - 1]);

        if (r == 1)
            fprintf(fp2, "Case #%d: %d\n", n, value);
        else if (r == 0)
            fprintf(fp2, "Case #%d: Volunteer cheated!\n", n);
        else
            fprintf(fp2, "Case #%d: Bad magician!\n", n);
        n++;
    }
    return 0;
}


int element(int *a, int *b)
{
    int i;
    int j;
    int r = 0;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        if (a[i] == b[j])
        {
            value = a[i];
            r++;
        }
    }
    return r;
}