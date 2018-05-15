//Sk. Mashfiqur Rahman
//Oklahoma State University

#include <stdio.h>
#include <stdlib.h>

void main()
{
    float A[100][100]; // increase the array element size for higher nxn matrix
    float B[100];
    float m;
    float X[100];
    int i,j,r,c,n,a,b;

  //matrix formation

    printf("Enter the number of rows and columns of tridiagonal matrix:\n");
    scanf("%d%d",&r,&c);
    printf("Enter the value of sub-diagonal,diagonal, and super-diagonal of the tridiagonal matrix:\n");
    scanf("%d%d%d",&a,&b,&n);
    printf("\nEnter the values of B vector:\n");
    for (i=0;i<r;i++)
    {
        scanf("%f",&B[i]);
    }

    for (i=0;i<c;i++)
    for (j=0;j<r;j++)
      {
          if (i==j) A[i][j]=b;
          else if (j==(i+1)) A[i][j]=n;
          else if (i==(j+1)) A[i][j]=a;
          else A[i][j]=0;
      }
     printf("\nThe elements of the matrix are:\n");

     for(i=0;i<r;i++)
      {
         for (j=0;j<c;j++)
          {
              printf("%4.2f", A[i][j]);
              printf("\t");
          }
          printf("\n");
      }

  //forward elimination

    for (i=1;i<r;i++)
     {
      m = A[i][i-1]/A[i-1][i-1];
      A[i][i] = A[i][i] - (m * A[i-1][i]);
      B[i] = B[i] - (m * B[i-1]);
     }

  //backward substitution

     X[r-1]=B[r-1]/A[r-1][r-1];

     for(i=r-2;i>=0;i--)
    {
      X[i]=(B[i]-A[i][i+1]*X[i+1])/A[i][i];
    }
      printf("\nSolution of X is:\n");
      for (i=0;i<r;i++)
      printf("%4.2f\n",X[i]);
}
