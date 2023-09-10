#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX_LIMIT 2560

//crition 0
int infection(int inf1, int mort1, int res1, int inf2, int mort2, int res2){
    if (inf1 > inf2)
        return 1;
    else
        return 0;
}

//crition 1
int avgOfThreeDatas(int inf1, int mort1, int res1, int inf2, int mort2, int res2){
    if ((floor)((double)(inf1 + mort1 + res1) / (double) 3) > (floor)((double)(inf2 + mort2 + res2) / (double) 3))
        return 1;
    else
        return 0;
}

//crition 2
int avgOfInfAndMort(int inf1, int mort1, int res1, int inf2, int mort2, int res2){
    if ((floor)((double)(inf1 + mort1) / (double) 2) > (floor)((double)(inf2 + mort2) / (double) 2))
        return 1;
    else
        return 0;
}

//crition 3
int weightedAvgOfMortAndRes(int inf1, int mort1, int res1, int inf2, int mort2, int res2){
    if ((floor)((double)(mort1 * 3 + res1) / (double) 4) > (floor)((double)(mort2 * 3 + res2) / (double) 4))
        return 1;
    else
        return 0;
}

//sort based on critions
void sort(int n , int (*sortMethod)(int inf1, int mort1, int res1, int inf2, int mort2, int res2), char typeName[n][MAX_LIMIT], int inf[n], int mort[n], int res[n]){
    char swap[MAX_LIMIT];
    int temp;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (sortMethod(inf[j], mort[j], res[j], inf[j+1], mort[j+1], res[j+1]) == 0)
            {
                strcpy(swap, typeName[j]);
                strcpy(typeName[j], typeName[j+1]);
                strcpy(typeName[j+1], swap);
                temp = inf[j];
                inf[j] = inf[j+1];
                inf[j+1] = temp;
                temp = mort[j];
                mort[j] = mort[j+1];
                mort[j+1] = temp;
                temp = res[j];
                res[j] = res[j+1];
                res[j+1] = temp;
            }
            
        }
        
    }
    
}

int main(){
    int n , i ,j ,criterion ;

    //get the number of types
    scanf("%d\n" , &n);
    char typeName[n][MAX_LIMIT];
    int inf[n];
    int mort[n];
    int res[n];

    //array of crition functions
    typedef int (*sortMethod)(int inf1, int mort1, int res1, int inf2, int mort2, int res2);
    sortMethod sortMethods[4] = {&infection, &avgOfThreeDatas, &avgOfInfAndMort, &weightedAvgOfMortAndRes};

    //scan the types
    for(i=0 ; i<n ; i++)
    {
        scanf("%s %d %d %d", &typeName[i], &inf[i], &mort[i], &res[i]);
    }

    //get critertion
    scanf("%d", &criterion);
    sort(n, sortMethods[criterion], typeName, inf, mort, res);

    //print sorted
    printf("%11s%s %s %s %s\n", "", "INF", "MOR", "RES", "AVG");
    for (i = 0; i < n; i++)
    {
        int avg = (floor)((double)(inf[i] + mort[i] + res[i]) / (double) 3);
        printf("%-11s%3d %3d %3d %3d\n", typeName[i], inf[i], mort[i], res[i], avg);
    }
    
 }