#include <stdio.h>
#include <stdlib.h>

int diagwnios(int**,int,int);
int anw_tr(int**,int,int);
int katw_tr(int**,int,int);
int trace(int**,int,int);

int main(void){
    int r,c;
    printf("Insert rows :");
    scanf("%d",&r);
    printf("Insert columns :");
    scanf("%d",&c);

    int **ptr;
    ptr = malloc(r * sizeof(int*));
    for(int i = 0; i < r;i ++){
        ptr[i] = malloc(c * sizeof(int));
    }

    for(int i = 0; i < r;i++){
        for(int j = 0; j < c; j++){
            printf("insert value at [%d][%d] :",i,j);
            scanf("%d",&ptr[i][j]);
        }
    }

    int is_diagn = diagwnios(ptr,r,c);
    int is_anw = anw_tr(ptr,r,c);
    int is_katw = katw_tr(ptr,r,c);

    if(is_diagn == 1) printf("Matrix is diagonal\n");
    else printf("Matrix is not diagonal\n");

    if(is_anw == 1) printf("Matrix is upper triagunal\n");
    else printf("Matrix is not upper triagunal\n");

    if(is_katw == 1) printf("Matrix is lower triagunal\n");
    else printf("Matrix is not lower triagunal");

}

int diagwnios(int** ptr,int r ,int c){
    int is_true = 0;
    for(int i = 0; i < r;i++){
        for(int j = 0;j < c;j++){
            if(i != j) if(ptr[i][j] != 0) is_true = 1;
            if(i == j) if(ptr[i][j] == 0) is_true = 1;
        }
    }
    if(is_true == 0) return 1;
    else  return 0;
}

int trace(int** ptr,int r,int c) {
    int is_true = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (i == j) if (ptr[i][j] == 0) is_true = 1;
        }
    }
    if (is_true == 0) return 1;
    else return 0;
}

int anw_tr(int** ptr,int r,int c){
    int is_true = 0;
    int is_trace = trace(ptr,r,c);
    if(is_trace == 0) return 0;
    else{
        for(int i = 0;i < r;i++){
            for(int j = 0;j < c;j++){
                if(j > i) if(ptr[i][j] != 0) is_true = 1;
            }
        }
    }
    if(is_true == 0) return 1;
    if(is_true == 1) return 0;
}
int katw_tr(int** ptr,int r,int c){
    int is_true = 0;
    int is_trace = trace(ptr,r,c);
    if(is_trace == 0) return 0;
    else{
        for(int i = 0;i < r;i++){
            for(int j = 0;j < c;j++){
                if(j < i) if(ptr[i][j] != 0) is_true = 1;
            }
        }
    }
    if(is_true == 0) return 1;
    if(is_true == 1) return 0;
}

