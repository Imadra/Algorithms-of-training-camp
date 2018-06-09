#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//structure defining
typedef struct {
	char countryName[60];
	int populationData[70];
	int populationGrowth[70];
	float percentageChange[70];
	int totalIncreasing;
	int totalDecreasing;
	float averagePopulation;
	float overallGrowth;
} populationData;

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	//file loading
	FILE *file;
	file = fopen("PopulationData.txt", "r");
	if (file == NULL) {
		printf("Problem opening file.");
		return 1;
	}
	printf("file opened successfully\n");
	//reading from files
	populationData Asia[6];
	int i, j;
	for (i = 0; i < 5; i++) {
		fscanf(file, "%s", Asia[i].countryName);
		printf("%s ", Asia[i].countryName);
		for (j = 0; j < 66; j++) {
			fscanf(file, "%i", &Asia[i].populationData[j]);
			printf("%i  ", Asia[i].populationData[j]);
		}
		printf("\n");
	}

	strcpy(Asia[5].countryName, "Region");
	printf("%s ", Asia[5].countryName);

	int sum[66];
	for (i = 0; i < 66; i++) {
		sum[i] = 0;
		for (j = 0; j < 5; j++) {
			sum[i] = sum[i] + Asia[j].populationData[i];
		}
		Asia[5].populationData[i] = sum[i];
		printf("%i  ", Asia[5].populationData[i]);
	}
	printf("\n\n");
	//population growth
	for (j = 0; j < 6; j++) {
		printf("The population growth of %s: ", Asia[j].countryName);
		for (i = 1; i < 66; i++) {
			Asia[j].populationGrowth[i] = Asia[j].populationData[i]
					- Asia[j].populationData[i - 1];
			printf("%i  ", Asia[j].populationGrowth[i]);
		}
		printf("\n");
	}
	printf("\n");
	//percentage change
	for (j = 0; j < 6; j++) {
		printf("The percentage change of %s: ", Asia[j].countryName);
		for (i = 1; i < 66; i++) {
			Asia[j].percentageChange[i] = ((float) Asia[j].populationGrowth[i]
					/ Asia[j].populationData[i - 1]) * 100;
			printf("%.3f percent  ", Asia[j].percentageChange[i]);
		}
		printf("\n");

	}
	printf("\n");
	//total increase & total decrease
	for (i = 0; i < 6; i++) {
		int tincrease = 0, tdecrease = 0;
		for (j = 1; j < 66; j++) {
			if (Asia[i].populationGrowth[j] > 0) {
				tincrease++;
			}
			if (Asia[i].populationGrowth[j] < 0) {
				tdecrease++;
			}
		}
    	Asia[i].totalIncreasing = tincrease;
		Asia[i].totalDecreasing = tdecrease;
		printf("the total number of years when the population was increasing, for %s: %i\n", Asia[i].countryName, Asia[i].totalIncreasing);
		printf("the total number of years when the population was decreasing, for %s: %i\n", Asia[i].countryName, Asia[i].totalDecreasing);
	}
	printf("\n");

	//average population
    int totalpopulation=0;
    for (i=0; i<6; i++){
     for (j = 0; j < 66; ++j) {
		totalpopulation=totalpopulation+Asia[i].populationData[j];
	}Asia[i].averagePopulation=(float)totalpopulation/66;
	printf("the average population of %s is %.3f\n",Asia[i].countryName, Asia[i].averagePopulation);
    }
    printf("\n");

    //overal growth
    for (i = 0; i < 6; ++i) {
		Asia[i].overallGrowth=(float)(Asia[i].populationData[65]-Asia[i].populationGrowth[0])/Asia[i].populationData[0] *100;
		printf("Overall growth of %s is %.3f percent\n", Asia[i].countryName, Asia[i].overallGrowth);
	}
    printf("\n");

    //Sorting of populations in the year 2015
   int min, temp;
    for (i=0; i<6; i++){
    	for(j=i;j<6;j++){
    if(Asia[min].populationData[65]>Asia[j].populationData[65]){
    	min=j;
    }Asia[j]=temp;
    Asia[j]=Asia[min];
    Asia[min]=temp;
    	}
    }
	fclose(file);
	return EXIT_SUCCESS;
}
