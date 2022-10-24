/*######################################
# University of Information Technology #
# IT007 Operating System               #
# Le Thanh Minh, 21520063              #
# File: sjf.c                         #
######################################*/

#include<stdio.h>
void swap (int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

int min(int a,int b){
    return (a>b)?b:a;
}

int max(int a,int b){
    return (a>b)?a:b;
}

typedef struct P {
    int pn,arr, bur,star, finish, tat, wt,res;
} process;

void swapP(process *a,process *b){
    swap(&(a->arr),&(b->arr));
    swap(&(a->bur),&(b->bur));
    swap(&(a->pn),&(b->pn));
    swap(&(a->finish),&(b->finish));
    swap(&(a->star),&(b->star));
    swap(&(a->tat),&(b->tat));
    swap(&(a->res),&(b->res));
}
void main(){
    int pn[10],queue[10000];
    int idxqueue=0,totalcount=0;
    process p[10];
    process c[10];
    int  i, n;
    int totwt=0, tottat=0,totres=0;

    printf("Enter the number of processes:");
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        printf("Enter the Process Name, Arrival Time & Burst Time:");
        scanf("%d%d%d", &p[i].pn, &p[i].arr, &p[i].bur);
        p[i].res=p[i].bur;
        totalcount+=p[i].bur;
        c[i]=p[i];
    }
    int curarr=0;
    int minbank=p[0].res,done=n,bank=0;
    while (done!=0) {
        // pn,arr, bur,star, finish, tat, wt,res
        for (int i = 0; i < n; i++) {
            int choke;
            if (p[i].arr >= curarr) {
                p[i].star = (p[i].star == 0) ? p[i].arr : p[i].star;
                p[i].wt = p[i].wt + (p[i].finish <= 0) ? (p[i].arr - curarr) : curarr - p[i].finish;
                p[i].finish = (p[i + 1].arr == 0) ? (curarr + p[i].res) : curarr + (p[i + 1].arr - p[i].arr) < p[i + 1].arr ?
                                                                          curarr + p[i].res : curarr + (p[i + 1].arr - p[i].arr);

            }
        }
    }

    // reverse the order like in table
    for (int i=0 ; i<n; i++){
        for (int j =i+1; j<n ; j++){
            if (p[i].pn>p[j].pn){
                swapP(&p[i],&p[j]);
            }
        }
    }
    printf("\nPName Arrtime Bursttime Start TAT Finish");
    for(i=0;i<n;i++) {
        printf("\n%5d%8d%10d%6d%4d%7d",p[i].pn,p[i].arr,p[i].bur,p[i].star,p[i].tat,p[i].finish);
        totwt+=p[i].wt;
        tottat+=p[i].tat;
        totres+=p[i].wt;
    }
    printf("\nAverage turnaround time: %.2f",(tottat+0.0)/n);
    printf("\nAverage waiting time: %.2f",(totwt+0.0)/n);
    printf("\nAverage response time: %.2f",(totres+0.0)/n);
    printf("\n");
}

