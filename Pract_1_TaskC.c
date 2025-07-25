#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float generateRandomNumber(float min, float max){
    float greator = 0;
    int flag = 0;
    float temp;
    if (min < 0 || max < 0) {
        if (min < max) {
            greator = min;
        } else {
            greator = max;
        }
        min -= greator;
        max -= greator;
        flag = 1;
    } else {
        temp = min;
        max = max - min;
        min = 0;
    }
    
    float number = rand() % (int)max;
    number = number + (float)rand() / (float)RAND_MAX;
    if (flag) {
        number += greator;
    } else {
        number += temp;
    }
    
    return number;
}

int main() {
    srand(time(NULL));
    
    float* temp = (float*)malloc(sizeof(float) * 100);
    float* pressure = (float*)malloc(sizeof(float) * 100);
    
    int inp;
    printf("Enter input size: ");
    scanf("%d", &inp);
    
    for (int i = 0; i < inp; i++) {
        temp[i] = generateRandomNumber(-20,50);
    }
    
    // sorting
    for(int i = 0; i < inp; i++) {
        for(int j = 0; j < i; j++) {
            if (temp[i] < temp[j]) {
                float tempo = temp[i];
                temp[i] = temp[j];
                temp[j] = tempo;
            }
        }
    }
    
    // Linear Search
    clock_t start_time, end_time;
    start_time = clock();
    int index = 0;
    for (int i = 0; i < inp; i++) {
        if (temp[i] >= 30) {
            index = i;
            break;
        }
    }
    end_time = clock();
    
    printf("Element found at index for Linear Search: %d\nTime Taken to execute: %f\n\n", index, ((double)(end_time - start_time) / CLOCKS_PER_SEC) * 1000);
    
    
    // Binary Search
    int left = 0;
    int right = inp - 1;

    start_time = clock();
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (temp[mid] >= 30) {
            index = mid;
        }

        if (temp[mid] < 30) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    end_time =clock();
    
    printf("Element found at index for Binary Search: %d\nTime Taken to execute: %f\n\n", index, ((double)(end_time - start_time) / CLOCKS_PER_SEC) * 1000);
    
    return 0;
}


