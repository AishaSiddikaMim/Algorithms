#include <stdio.h>
#include <limits.h>

#define MAX 1000

//defining some constants and variables,
int n;
int p[MAX+1]; // matrix dimensions
int dp[MAX+1][MAX+1]; // minimum number of operations
int s[MAX+1][MAX+1]; // split position
int res; //the number of scalar multiplications needed 

//first function (iterative approach to calculate the minimum number of operations required to multiply matrix chain)
void matrix_Chain_order() {
    for (int i = 1; i <= n; i++) {
        dp[i][i] = 0;  // initializes the diagonal elements of the dp matrix to 0
    }
  
    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n-l+1; i++) {
            int j = i+l-1;
            dp[i][j] = INT_MAX;
41            for (int k = i; k <= j-1; k++) {
                res = dp[i][k] + dp[k+1][j] + p[i-1]*p[k]*p[j]; 
                if (res < dp[i][j]) {
                    dp[i][j] = res; //iterates over the remaining elements
                    s[i][j] = k; //store the split position that yields the minimum cost
                }
            }
        }
    }
}

//second function (which recursively prints the optimal parentheses)
void print_optimal_combination(int i, int j) {
    if (i == j) {
        printf("A%d", i); // i is equal to j, then we have a single matrix, so we just print its index

    } 
    else {
        printf("(");
      //recursively call print_optimal_parens() on the left and right sub chains
        print_optimal_combination(i, s[i][j]);
        print_optimal_combination(s[i][j]+1, j);
        printf(")");
    }
}

int main() {
     printf("Total number of matrixes: ");
    scanf("%d", &n);
      for (int i = 0; i < n; i++){  // making the given dimensions in one arry
        int r, c;
        printf("Row and column of A%d: ", i+1);
        scanf("%d %d", &r, &c);
        printf("\n");
        p[i] = r;
        if (i+1 == n) {
            p[i+1] = c;
        }  
    }

    matrix_Chain_order(); //calling first function
    printf("The optimal association order and minimum operation: ");
    print_optimal_combination(1, n);//calling second function
    printf(" = %d operations.\n", dp[1][n]); //optimal number of operations.
    //printf("\n");
    return 0;
}