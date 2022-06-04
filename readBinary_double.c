#include <stdio.h>
#include <stdlib.h>
#define READ_SIZE 1
#define SKIP_SIZE 18

int main(int argc, char* argv[]){
	FILE * fp = NULL;
	int i = 0;
    int j = 0;
    double data;
    int delimiter = READ_SIZE*atoi(argv[3]);
    size_t ret;

	fp = fopen(argv[1], "rb");
    int i_max = atoi(argv[2]);

	for (i=0; i < SKIP_SIZE; i++) ret = fread(&data, sizeof(double), 1, fp);
	for (i=SKIP_SIZE; i < atoi(argv[2]); i++){
        ret = fread(&data, sizeof(double), 1, fp);
        if(data<0) data=0;
        printf("%f\t",data);
        if((i-SKIP_SIZE)%delimiter==0) printf("\n");
	}
	fclose(fp);
	return 0;
}