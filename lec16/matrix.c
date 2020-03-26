#include <stdio.h>

int main()
{
    FILE *in, *out;
    int m,n;
    int i,j;

    if((in = fopen("in_matrix.txt", "r")) == NULL){
        printf("Unable to open a file\n");
        return -1;
    }
    fscanf(in, "%d %d", &m, &n);
    int matrix[m][n];

    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            fscanf(in, "%d,", &matrix[i][j]);
    
    fclose(in);

    if((out = fopen("out_matrix.txt", "w"))== NULL){
        printf("Unable to open a file\n");
        return -1;
    }
    fprintf(out, "%d %d \n", n, m);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++)
            fprintf(out, "%d ", matrix[j][i]);
        fprintf(out, "\n");
    }
    fclose(out);
}
