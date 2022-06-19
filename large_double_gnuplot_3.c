#include <stdio.h>
#include <stdlib.h>
#define READ_SIZE 1
#define SKIP_SIZE 0x3907

int main(int argc, char* argv[]){
	FILE * fp = NULL;
	FILE * fp2 = NULL;
	long i = 0;
    long j = 0;
    char cdata;
    double ddata;
    float fdata;

    size_t ret;

	fp = fopen(argv[1], "rb");
	fp2 = fopen(argv[2], "w");
    long i_max = atol(argv[3]);

	/* skip header data */
    for (i=0; i < SKIP_SIZE; i++) ret = fread(&ddata, 1, 1, fp);

    /* read payload */
	for (i=SKIP_SIZE; i < atol(argv[3]); i++){

        ret = fread(&fdata, 4, 1, fp);
        if(fdata>100 || fdata<0) fdata=0;
        if(((i-SKIP_SIZE)/atol(argv[4]))%2==0) {
            fprintf(fp2,"%d %d %f\n",(i-SKIP_SIZE)/atol(argv[4]), (i-SKIP_SIZE)%atol(argv[4]), fdata);
            if((i-SKIP_SIZE)%atol(argv[4])==atol(argv[4])-1) fprintf(fp2,"\n");
        }
	}
	fclose(fp);
	fclose(fp2);
	return 0;
}