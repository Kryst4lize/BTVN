#include<stdio.h>
#include<stdlib.h>
int ps[1000]={2,1,5,2,0,0,6,3};
int time[1000][100];
int uses[1000][100];
int table[1000][100]; //1000 is value, 100 is page frames
int fault[1000];
void init(){
    for (int i=0;i<1000;i++){
        fault[i]=-1;
        for (int j=0;j<100;j++){
            table[i][j]=-1;
            time[i][j]=-1;
            uses[i][j]=-1;
        }
    }
}
void print(int frames,int number){
    int count=0;
    for (int i=0;i<frames;i++){
        for (int j=0;j<number;j++){
            if (table[j][i]==-1){
                printf("   ");
            }
            else {printf("%3d",table[j][i]);}
        }
        printf("\n");
    }
    for (int j=0;j<number;j++){
        if (fault[j]==1){
            count++;
            printf("  *");
        } else {
            printf("   ");
        }
    }
    printf("\nPage faults in this algorithm : %d page faults",count);
}
void FIFO(int frames,int number){
    printf("FIFO\n");
    for (int turn=0;turn<number;turn++)
    {
        // check: you can find ps in frames or not, check1: all frame is full or not
        int check=0,check1=0, min=1001;
        //Filling empty frame or found ps in frames
        for (int search=0;search<frames;search++)
        {
            if (table[turn][search]==-1)
            {
                for (int i=turn;i<number;i++){
                    table[i][search]=ps[turn];
                    time[i][search]=turn;
                }
                fault[turn]=1;
                check1=1;
                break;
            }
            else if (table[turn][search]==ps[turn])
            {
                check = 1;
                break;
            }
        }
        // Need to swap
        if (!check && !check1)
        {
            for (int search=0;search<frames;search++){
                min=(min>time[turn][search]?time[turn][search]:min);
            }
            //over the normal
            for (int search=0;search<frames;search++)
            {
                if (time[turn][search]==min)
                {
                    for (int i=turn;i<number;i++){
                        table[i][search]=ps[turn];
                        time[i][search]=turn;
                    }
                    fault[turn]=1;
                }
            }
        }
    }
}
void LRU(int frames,int number){
    printf("LRU\n");
    for (int turn=0;turn<number;turn++)
    {
        // check: you can find ps in frames or not, check1: all frame is full or not
        int check=0,check1=0, min=1001;
        //Filling empty frame or found ps in frames
        for (int search=0;search<frames;search++)
        {
            if (table[turn][search]==-1)
            {
                for (int i=turn;i<number;i++){
                    table[i][search]=ps[turn];
                    uses[i][search]=turn;
                }
                fault[turn]=1;
                check1=1;
                break;
            }
            else if (table[turn][search]==ps[turn])
            {
                for (int i=turn;i<number;i++){
                    uses[i][search]=turn;
                }
                check = 1;
                break;
            }
        }
        // Need to swap
        if (!check && !check1)
        {
            //finding page need to swap
            for (int search=0;search<frames;search++){
                min=(min>uses[turn][search]?uses[turn][search]:min);
            }
            //searching the page need to swap
            for (int search=0;search<frames;search++)
            {
                if (uses[turn][search]==min)
                {
                    for (int i=turn;i<number;i++){
                        table[i][search]=ps[turn];
                        uses[i][search]=turn;
                    }
                    fault[turn]=1;
                    break;
                }
            }
        }
    }
}
void OPT(int frames,int number){
    printf("OPT\n");
    for (int turn=0;turn<number;turn++)
    {
        // check: you can find ps in frames or not, check1: all frame is full or not
        int check=0,check1=0, max=-2;
        //Filling empty frame or found ps in frames
        for (int search=0;search<frames;search++)
        {
            if (table[turn][search]==-1)
            {
                for (int i=turn;i<number;i++){
                    table[i][search]=ps[turn];
                }
                fault[turn]=1;
                check1=1;
                break;
            }
            else if (table[turn][search]==ps[turn])
            {
                check = 1;
                break;
            }
        }
        // Need to swap
        if (!check && !check1)
        {
            fault[turn]=1;
            //initialize check frames in that turn
            int check[frames];
            for (int i=0;i<frames;i++) {
                check[i]=1001;
            }
            // find page need to swap
            for (int i=0;i<frames;i++){
                for (int j=turn+1;j<number;j++){
                    if (table[turn][i]==ps[j]){
                        check[i]=j;
                        break;
                    }
                }
            }
            for (int search=0;search<frames;search++){
                max=(max<check[search]?check[search]:max);
            }
            //searching the page need to swap
            for (int search=0;search<frames;search++)
            {
                if (check[search]==max)
                {
                    //printf("%d\n",ps[turn]);
                    for (int i=turn;i<number;i++){
                        table[i][search]=ps[turn];
                    }
                    break;
                }
            }
        }
    }
}
void print(int &choice,int &number,int &frames){
    printf("--- Page Replacement algorithm ---\n");
    printf("1. Default reference sequence\n");
    printf("2. Manual input sequence\n");
    scanf("%d",&choice);
    while(choice != 1 && choice != 2){
        printf("Error command, please type again (1 or 2) :");
        scanf("%d",&choice);
    }
    if (choice == 1){}
    else {
        printf("Number of input sequence :");
        scanf("%d",&number);
        printf("Input sequence : ");
        for (int i=0;i<number;i++){
            scanf("%d",&ps[i]);
        }
    }
    //Algorithm input
    printf("--- Page Replacement algorithm ---\n");
    printf("Input page frames :");
    scanf("%d",&frames);
    printf("1. FIFO algorithm\n2. OPT algorithm\n3. LRU algorithm\n");
    scanf("%d",&choice);
    while(choice != 1 && choice != 2 && choice!=3){
        printf("Error command, please type again (1,2 or 3) :");
        scanf("%d",&choice);
    }
}
int main(){
    init();
    //initialize reference sequence;
    int choice,frames,number=8;
    print(choice,number,frames);
    if (choice==1){
        FIFO(frames,number);
    } else if (choice==2){
        OPT(frames,number);
    }
    else if (choice==3){
        LRU(frames,number);
    }
    print(frames,number);
}
