#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct points
{
       float weight;
       int x;
       int y;
};

void printPoints(struct points *p, int n);
int deletePoint(struct points *p, int n);

int main() {
    struct points p[] = {3,1,2, 1,4,-5, 10,0,1, 2,-5,4, 7,7,7};
    int n = sizeof(p)/sizeof(p[0]);
    printPoints(p,n);
    
    do{
        n=deletePoint(p,n);
        printPoints(p,n);
    }while(n!=1);
    
    return 0;
}

void printPoints(struct points *p, int n){
    printf("Points:\n");
    for(int i=0; i<n; i++)
    {
        printf("Weight: %.1f \t x: %d \t y: %d \n", p[i].weight, p[i].x, p[i].y);
    }
    printf("\n");
}

int deletePoint(struct points *p, int n){
    //min weight
    int indexMin=0, size=n;
    float pointMin=p[0].weight;
    for (int i=0;i<n;i++){
        if(p[i].weight<pointMin){
            pointMin=p[i].weight;
            indexMin=i;
        }
    }
    printf("min: %.1f\n",pointMin);
    
    struct points tmp=p[indexMin];
    p[indexMin]=p[n-1];
    p[n-1]=tmp;
    
    if(n==2){
        p[0].weight+=p[1].weight;
        size--;
        return size;
    }
    float distanceMin=sqrtf(powf((p[n-2].x - p[n-1].x), 2) + powf((p[n-2].y - p[n-1].y), 2)),distance;
    
    for (int i = n-2; i >= 0; i--)
    {
        distance = sqrtf(powf((p[i].x - p[n-1].x), 2) + powf((p[i].y - p[n-1].y), 2));
        printf("distance1: %.1f\n",distance);
        if(distance<distanceMin){
            indexMin=i;
            distanceMin=distance;
        }
    }
    printf("\nMin distance: %.1f\n",distanceMin);
    
    p[indexMin].weight+=p[n-1].weight;
    size--;
   
    return size;
}
