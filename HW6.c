#include <stdio.h>

// Function to return the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int n, int W, int values[], int weights[]) {
    int dp[n + 1][W + 1];

    // Initialize the first row and first column
    for (int w = 0; w <= W; w++) {
        dp[0][w] = 0;
    }

    for (int i = 1; i <= n; i++) {
        dp[i][0] = 0;
        
        for (int w = 1; w <= W; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int n;
    
    // Take user input for the number of items
    printf("Number of items:\n");
    scanf("%d", &n);

    int values[n], weights[n];

    // Take user input for the values of items
    printf("Item values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }

    // Take user input for the weights of items
    printf("Item weights:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }

    int W;
    // Take user input for the knapsack weight capacity
    printf("Knapsack weight capacity:\n");
    scanf("%d", &W);
    
    // Compute the maximum value and print the result
    int maxValue = knapsack(n, W, values, weights);
    printf("Answer: Maximum value:\n%d\n", maxValue);
    
    return 0;
}
