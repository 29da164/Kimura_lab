#include <stdio.h>
#include <stdlib.h>
#define READ_SIZE 8

int main(int argc, char* argv[]){
	FILE * fp = NULL;
	int i = 0;
    int j = 0;
    char data[READ_SIZE+1];
    int delimiter = READ_SIZE*atoi(argv[3]);
    size_t ret;

	fp = fopen(argv[1], "rb");
    int i_max = atoi(argv[2]);

	for (i=0; i < 16; i++) ret = fread(data, sizeof(char), 1, fp);
	for (i=16; i < atoi(argv[2]); i++){
        ret = fread(data, sizeof(char), 1, fp);
        if(i%READ_SIZE==1) {
            data[ret]='\0';
            printf("%d\t",*data);
        }
        if(i%delimiter==0) printf("\n");
	}
	fclose(fp);
	return 0;
}