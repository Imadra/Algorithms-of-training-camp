#include <stdio.h>
#include <stdlib.h>
//structure defining
typedef struct
{
    char countryName[60];
    int populationData[70];
    int populationGrowth[70];
    float percentageChange[70];
    int totalIncreasing;
    int totalDecreasing;
    float averagePopulation;
    int overallGrowth;
} populationData;
int main(void)
{
    setvbuf(stdout, NULL, _IONBF, 0);
    //file loading
    FILE *file;
    file = fopen("PopulationData.txt", "r");
    if (file == NULL)
    {
        printf("Problem opening file.");
        return 1;
    }
    printf("file opened successfully\n");
//reading from files
    populationData Asia[6];
    int i,j;
    for (i=0; i<5; i++)
    {
        fscanf (file, "%s", Asia[i].countryName);
        printf("%s ", Asia[i].countryName);
        for (j=0; j<66; j++)
        {
            fscanf(file, "%i", &Asia[i].populationData[j]);
            printf("%i ", Asia[i].populationData[j]);
        }
        printf("\n");
    }
//data for the region
    Asia[5].countryName[0]='R';
    Asia[5].countryName[1]='e';
    Asia[5].countryName[2]='g';
    Asia[5].countryName[3]='i';
    Asia[5].countryName[4]='o';
    Asia[5].countryName[5]='n';
    printf("%s", Asia[5].countryName);
    int sum[66];
    for (i=0; i<66; i++)
    {
        sum[i]=0;
        for(j=0; j<5; j++)
        {
            sum[i]=sum[i]+Asia[j].populationData[i];
        }
        Asia[5].populationData[i]=sum[i];
        printf("%i ", Asia[6].populationData[i]);
    }
//population growth
    for (j=0; j<6; j++)
    {
        for (i=0; i<65; i++)
        {
            Asia[j].populationGrowth[i]=Asia[j].populationData[i+1]-Asia[j].populationData[i];
            printf("%i", Asia[j].populationGrowth[i]);
        }
    }

    fclose (file);
    return EXIT_SUCCESS;
}
