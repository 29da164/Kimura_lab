#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ROW 320

int main(int argc, char* argv[]){
	FILE * fp = NULL;
	int i = 0;
    int j = 0;

	fp = fopen(argv[1], "rb");
    long data[200000];
    int i_max = atoi(argv[2]);

	fread(data, i_max, sizeof(int), fp);
	for (i=32; i < i_max; i++){
        if(i%2==1){
            if(data[i]>0) printf("1\t");
            if(data[i]<=0) printf("0\t");
            j++;
        }
        if(j==atoi(argv[3])){
            printf("\n");
            j=0;
        }
	}
	fclose(fp);
	return 0;
}