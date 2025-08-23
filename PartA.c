#include <stdio.h>
#include <time.h>

#define N 50
#define CAP 850.0

typedef struct {
    int id;
    double w, p, ratio;
} Item;

void swap(Item *a, Item *b){ Item t=*a; *a=*b; *b=t; }

void sort_by_weight(Item a[], int n){
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-1-i;j++)
            if(a[j].w > a[j+1].w) swap(&a[j], &a[j+1]);
}

void sort_by_profit(Item a[], int n){
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-1-i;j++)
            if(a[j].p < a[j+1].p) swap(&a[j], &a[j+1]);
}

void sort_by_ratio(Item a[], int n){
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-1-i;j++){
            double r1 = a[j].w==0?1e18:a[j].p/a[j].w;
            double r2 = a[j+1].w==0?1e18:a[j+1].p/a[j+1].w;
            if(r1 < r2) swap(&a[j], &a[j+1]);
        }
}

double run_frac(Item a[], int n){
    double cap = CAP, profit=0.0;
    for(int i=0;i<n && cap>0; i++){
        if(a[i].w==0){ profit += a[i].p; continue; }
        if(a[i].w <= cap){ profit += a[i].p; cap -= a[i].w; }
        else { profit += a[i].p * (cap/a[i].w); cap = 0; }
    }
    return profit;
}

int main(){
    double W[N] = {7,0,30,22,80,94,11,81,70,64,59,18,0,36,3,8,15,42,9,0,42,47,52,32,26,48,55,6,29,84,2,4,18,56,7,29,93,44,71,3,86,66,31,65,0,79,20,65,52,13};
    double P[N] = {360,83,59,130,431,67,230,52,93,125,670,892,600,38,48,147,78,256,63,17,120,164,432,35,92,110,22,42,50,323,514,28,87,73,78,15,26,78,210,36,85,189,274,43,33,10,19,389,276,312};

    Item items[N];
    for(int i=0;i<N;i++){ items[i].id=i+1; items[i].w=W[i]; items[i].p=P[i]; items[i].ratio = (W[i]==0)?1e18:(P[i]/W[i]); }

    clock_t s,e; 

    // Strategy 1: Minimum Weight
    Item A[N]; for(int i=0;i<N;i++) A[i]=items[i];
    s=clock(); sort_by_weight(A,N); double prof1=run_frac(A,N); e=clock();
    double t1=(double)(e-s)/CLOCKS_PER_SEC;

    // Strategy 2: Maximum Profit
    Item B[N]; for(int i=0;i<N;i++) B[i]=items[i];
    s=clock(); sort_by_profit(B,N); double prof2=run_frac(B,N); e=clock();
    double t2=(double)(e-s)/CLOCKS_PER_SEC;

    // Strategy 3: Profit/Weight Ratio
    Item C[N]; for(int i=0;i<N;i++) C[i]=items[i];
    s=clock(); sort_by_ratio(C,N); double prof3=run_frac(C,N); e=clock();
    double t3=(double)(e-s)/CLOCKS_PER_SEC;

    printf("Total Profit (Min-Weight): %.2f\n", prof1);
    printf("Total Profit (Max-Profit): %.2f\n", prof2);
    printf("Total Profit (Profit/Weight): %.2f\n", prof3);
    printf("Times: %f  %f  %f (sec)\n", t1,t2,t3);
    return 0;
}