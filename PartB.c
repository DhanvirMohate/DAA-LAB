#include <stdio.h>
#include <string.h>

typedef struct{
    int s, f, p;
    char name[6];
} Act;

void swap(Act *a, Act *b){ Act t=*a; *a=*b; *b=t; }

void sort_by_finish(Act a[], int n){
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-1-i;j++)
            if(a[j].f > a[j+1].f) swap(&a[j], &a[j+1]);
}

int main(){
    Act a[] = {
        {1,4,10,"A1"}, {3,5,15,"A2"}, {0,6,14,"A3"}, {5,7,12,"A4"},
        {3,9,20,"A5"}, {5,9,30,"A6"}, {6,10,32,"A7"}, {8,11,28,"A8"},
        {8,12,30,"A9"}, {2,14,40,"A10"}, {12,16,45,"A11"}
    };
    int n = sizeof(a)/sizeof(a[0]);
    sort_by_finish(a,n);

    int total = 0;
    int lastFinish = -1;
    printf("Selected activities:\n");
    for(int i=0;i<n;i++){
        if(a[i].s >= lastFinish){
            printf("%s [%d,%d] profit=%d\n", a[i].name, a[i].s, a[i].f, a[i].p);
            total += a[i].p;
            lastFinish = a[i].f;
        }
    }
    printf("Total Profit = %d\n", total);
    return 0;
}