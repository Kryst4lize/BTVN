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
    return (a<b)?b:a;
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
void main() {
    process p[10];
    int n, totwt = 0, tottat = 0, totres = 0;
    //scan process
    printf("Enter the number of processes:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter the Process Name, Arrival Time & Burst Time:");
        scanf("%d%d%d", &p[i].pn, &p[i].arr, &p[i].bur);
        p[i].res = p[i].bur;
        p[i].star = 0, p[i].tat = 0, p[i].finish = 0, p[i].wt = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].arr > p[j].arr) {
                swapP(&p[i], &p[j]);
            }
        }
    }
    int curarr = 0, store = n, curres = p[0].res, curindex = 0;
    while (store) {
        // check if all process done
        store = 0;
        for (int j = 0; j < n; j++) {
            if (p[j].res > 0) {
                store++;
            }
        }

        // check next process in query
        for (int i = 0; i < n; i++) {
            if (p[i].res == 0) { continue; }
            int tempstore = 0;
            int tempindex = -1;
            for (int k = 0; p[k].arr < curarr; k++) {
                tempindex = k;
                if (p[k].res != 0) {
                    tempstore++;
                }
            }
            if (tempstore == 0 && tempindex < n - 1) {
                curarr = p[tempindex + 1].arr;
            }
            for (int k = 0; p[k].arr <= curarr; k++) {
                if (p[k].res == 0) { continue; }
                if (curres <= max(curres, p[k].res)) {
                    curindex = k;
                    curres = max(curres, p[k].res);
                }
            }
            // check after current time have any process remain and chooseing shortest process
            for (int k = 0; p[k].arr <= curarr; k++) {
                if (p[k].res == 0) { continue; }
                if (curres > min(curres, p[k].res)) {
                    curindex = k;
                    curres = min(curres, p[k].res);
                }
            }
            printf("current min RT is %d and current process take CPU is %d\n", curres, curindex + 1);
            printf("PName Arrtime Bursttime Start TAT Finish Waittime RT currenttime\n");
            printf("%5d%8d%10d%6d%4d%7d%9d%3d%12d\n\n", p[curindex].pn, p[curindex].arr, p[curindex].bur,
                   p[curindex].star,
                   p[curindex].tat, p[curindex].finish, p[curindex].wt, p[curindex].res, curarr);
            for (int j = 1; curindex + j < n; j++) {
                if (p[curindex + j].res == 0 && curindex + j != n - 1) { continue; }
                if (curindex + j == n - 1 && store == 1) {
                    printf("Last process %d in that the end (finish time is %d)\n", curindex + 1,
                           curarr + p[curindex].res);
                    p[curindex].star = (p[curindex].arr == 0) ? 0 : (p[curindex].star == 0) ? curarr : p[curindex].star;
                    p[curindex].wt = p[curindex].wt + (p[curindex].finish == 0) ? curarr - p[curindex].arr : curarr -
                                                                                                             p[curindex].finish;
                    p[curindex].finish = curarr + p[curindex].res;
                    p[curindex].res = 0;
                    p[curindex].tat = p[curindex].finish - p[curindex].arr;
                    curarr = p[curindex].finish;
                    break;
                }
                if (p[curindex].res - (p[curindex + j].arr - curarr) > p[curindex + j].res) {
                    printf("Transition process from %d to %d\n", curindex + 1, curindex + j + 1);
                    p[curindex].star = ((p[curindex].star == 0) ? p[curindex].arr : p[curindex].star);
                    p[curindex].res -= (p[curindex + j].arr - curarr);
                    // DO: already cover latency process
                    p[curindex].wt =
                            p[curindex].wt + (p[curindex].finish == 0) ? (curarr == 0) ? 0 : curarr -
                                                                                             p[curindex].arr
                                                                       : curarr - p[curindex].finish;
                    p[curindex].finish = p[curindex + j].arr;
                    p[curindex].tat = p[curindex].finish - p[curindex].arr;
                    curarr = p[curindex].finish;
                    store++;
                    curres = p[curindex].res;
                    break;
                }
                else
                {

                    if (p[curindex].res < p[curindex + j].arr - curarr) {
                        printf("End process %d in between process %d's arrival   (finishtime is %d)\n", curindex + 1,
                               curindex + j + 1, curarr + p[curindex].res);
                        p[curindex].star = (p[curindex].arr >= curarr) ? p[curindex].arr : (p[curindex].star == 0)
                                                                                           ? curarr
                                                                                           : p[curindex].star;
                        p[curindex].wt =
                                p[curindex].wt + (p[curindex].finish == 0) ? (curarr < p[curindex].arr) ? curarr :
                                                                             curarr - p[curindex].arr : curarr -
                                                                                                        p[curindex].finish;
                        p[curindex].finish = curarr + p[curindex].res;
                        p[curindex].res = 0;
                        curarr = p[curindex].finish;
                        p[curindex].tat = p[curindex].finish - p[curindex].arr;
                        break;
                    } else if (curindex + j == n - 1) {
                        printf("End process %d in that the end (finish time is %d)\n", curindex + 1,
                               curarr + p[curindex].res);
                        p[curindex].star = (p[curindex].arr == 0) ? 0 : (p[curindex].star == 0) ? curarr
                                                                                                : p[curindex].star;
                        p[curindex].wt = p[curindex].wt + (p[curindex].finish != 0) ? curarr -
                                                                     p[curindex].finish : (curarr < p[curindex].arr)
                                                                                          ? curarr :
                                                                                          curarr - p[curindex].arr;
                        p[curindex].finish = curarr + p[curindex].res;
                        p[curindex].res = 0;
                        p[curindex].tat = p[curindex].finish - p[curindex].arr;
                        curarr = p[curindex].finish;
                        break;
                    }
                }
            }
            printf("PName Arrtime Bursttime Start TAT Finish Waittime RT currenttime\n");
            printf("%5d%8d%10d%6d%4d%7d%9d%3d%12d\n\n", p[curindex].pn, p[curindex].arr, p[curindex].bur,
                   p[curindex].star,
                   p[curindex].tat, p[curindex].finish, p[curindex].wt, p[curindex].res, curarr);
        }
        // check if process is done but the upcoming process isn't come

    }
    // reverse the order like in table
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].pn > p[j].pn) {
                swapP(&p[i], &p[j]);
            }
        }
    }
    printf("\nPName Arrtime Bursttime Start TAT Finish Waittime");
    for (int i = 0; i < n; i++) {
        printf("\n%5d%8d%10d%6d%4d%7d%9d", p[i].pn, p[i].arr, p[i].bur, p[i].star, p[i].tat, p[i].finish, p[i].wt);
        totwt += p[i].wt;
        tottat += p[i].tat;
    }
    printf("\nAverage turnaround time: %.2f", (tottat + 0.0) / n);
    printf("\nAverage waiting time: %.2f", (totwt + 0.0) / n);
    printf("\n");
}

