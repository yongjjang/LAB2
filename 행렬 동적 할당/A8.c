#include <stdio.h>
#include <stdlib.h>

void main(){
  int col, row;


  printf("두 행렬의 행과 열의 크기 입력\n");
  scanf("%d %d", &row, &col);
  printf("\n행렬의 크기 : [%d][%d]\n\n",row, col);

  int **matrix1, **matrix2, **result;
  int x, y;
  
  result = (int **)malloc(row * sizeof(int *));
  matrix1 = (int **)malloc(row * sizeof(int *));
  matrix2 = (int **)malloc(row * sizeof(int *));
  
  for (x = 0; x < row; x++){
    matrix1[x] = (int *)malloc(col * sizeof(int));
    matrix2[x] = malloc(col * sizeof(int *));
    result[x] = malloc(col * sizeof(int *));
  }

  srand(0);
 
  printf("첫 번째 행렬\n");
  for ( x = 0; x < row; x++){
    for ( y = 0; y < col; y++){
      matrix1[x][y] = rand() % 10; //0부터 10까지의 난수를 행렬에 삽입
      printf("%d ",matrix1[x][y]);
    }
    printf("\n");
  }

  printf("\n-------------\n");    printf("\n");
  printf("두 번째 행렬\n");
  for ( x = 0; x < row; x++){
    for ( y = 0; y < col; y++){
      matrix2[x][y] = rand() % 10; //0부터 10까지의 난수를 행렬에 삽입
      printf("%d ",matrix2[x][y]);
    }
    printf("\n");
  }
  
  printf("\n-------------\n");    printf("\n");
  printf("더해진 행렬\n");

  for ( x = 0; x < row; x++){ // 행렬의 덧셈을 수행
    for ( y = 0; y < col; y++){
      result[x][y] = matrix1[x][y] + matrix2[x][y];
      printf("%d ",result[x][y]);
    }
    printf("\n");
  }

  for (x = 0; x < row; x++){
    free(matrix1[x]);
    free(matrix2[x]);
    free(result[x]);      
  }

  free(matrix1);
  free(matrix2);
  free(result);  
}
