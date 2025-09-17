#include <stdio.h>
#include <limits.h>

int MaxCrossing(int A[], int low, int mid, int high) {
    int left_sum = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= low; i--) {
        sum += A[i];
        if (sum > left_sum) {
            left_sum = sum;
        }
    }

    int right_sum = INT_MIN;
    sum = 0;
    for (int j = mid + 1; j <= high; j++) {
        sum += A[j];
        if (sum > right_sum) {
            right_sum = sum;
        }
    }

    return left_sum + right_sum;
}

int MaxSubArray(int A[], int low, int high) {
    if (low == high) {
        return A[low];
    }

    int mid = (low + high) / 2;

    int left_sum = MaxSubArray(A, low, mid);
    int right_sum = MaxSubArray(A, mid + 1, high);
    int cross_sum = MaxCrossing(A, low, mid, high);

    if (left_sum >= right_sum && left_sum >= cross_sum)
        return left_sum;
    else if (right_sum >= left_sum && right_sum >= cross_sum)
        return right_sum;
    else
        return cross_sum;
}

void runTest(int test_id, int A[], int n, int expected) {
    if (n == 0) {
        printf("Test %d: Empty array - Expected %d, Got 0 - %s\n",
               test_id, expected,
               (expected == 0 ? "PASS" : "FAIL"));
        return;
    }

    int result = MaxSubArray(A, 0, n - 1);
    printf("Test %d: Expected %d, Got %d - %s\n",
           test_id, expected, result,
           (result == expected ? "PASS" : "FAIL"));
}

int main() {
    int test1[] = {2, 1, 3, 4};
    runTest(1, test1, 4, 10);

    int test2[] = {2, 2, 2, 2};
    runTest(2, test2, 4, 8);

    int test3[] = {1, 5, 2, 3};
    runTest(3, test3, 4, 11);

    int test4[] = {6, 7, 8};
    runTest(4, test4, 3, 21);

    int test5[] = {1, 2, 3, 2, 1};
    runTest(5, test5, 5, 9);

    int test6[] = {1, 1, 1, 1, 1};
    runTest(6, test6, 5, 5);

    int test7[] = {4, 2, 3, 1};
    runTest(7, test7, 4, 10);

    int test8[] = {};
    runTest(8, test8, 0, 0);

    int test9[] = {1, 2, 3};
    runTest(9, test9, 3, 6);


    #define SIZE 1000
    static int test10[SIZE];
    for (int i = 0; i < SIZE; i++) {
        test10[i] = i + 1;
    }

    runTest(10, test10, SIZE, 500500);

    return 0;
}
