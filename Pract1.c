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
    
    for (int i = 0; i < inp; i++) {
        pressure[i] = generateRandomNumber(950,1050);
    }
    
    // Linear Search
    float min = temp[0];
    clock_t start_time, end_time;
    start_time = clock();
    for (int j = 0; j < inp; j++) {
        if (temp[j] < min) {
            min = temp[j];
        }
    }
    end_time = clock();
    
    printf("Minimum temperature is: %f\nTime Taken to execute is: %f ms\n\n", min, ((double)(end_time - start_time) / CLOCKS_PER_SEC) * 1000);
    
    float max = pressure[0];
    start_time, end_time;
    start_time = clock();
    for (int j = 0; j < inp; j++) {
        if (pressure[j] > max) {
            max = pressure[j];
        }
    }
    end_time = clock();
    
    printf("Maximum pressure is: %f\nTime Taken to execute is: %f ms\n\n", max, ((double)(end_time - start_time) / CLOCKS_PER_SEC) * 1000);
    
    // Naive Search
    min = temp[0];
    start_time, end_time;
    start_time = clock();
    for (int j = 0; j < inp; j++) {
        for (int i = 0; i < inp; i++) {
            if (temp[j] < temp[i]) {
                min = temp[j];
            }
        }
    }
    end_time = clock();
    
    printf("Minimum temperature is: %f\nTime Taken to execute is: %f ms\n\n", min, ((double)(end_time - start_time) / CLOCKS_PER_SEC) * 1000);
    
    max = pressure[0];
    start_time, end_time;
    start_time = clock();
    for (int j = 0; j < inp; j++) {
        for (int i = 0; i < inp; i++) {
            if (pressure[j] < pressure[i]) {
                max = pressure[j];
            }
        }
    }
    end_time = clock();
    
    printf("Maximum pressure is: %f\nTime Taken to execute is: %f ms\n\n", max, ((double)(end_time - start_time) / CLOCKS_PER_SEC) * 1000);
    
    return 0;
}

