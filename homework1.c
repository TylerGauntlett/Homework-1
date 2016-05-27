// Name: Tyler Gauntlett
// Course: Systems Software
// Date: 5/26/2016

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void getBasicAssemblly();
char* getOPCode(int code);

struct {
	int op;
	int l;
	int m;
}instruction;


int main() {

	getBasicAssemblly();
	
	return 0;
}

void getBasicAssemblly() {
	FILE *inputFile, *outputFile;
	char outputFileName[] = "inputToBasicAssembly.txt";
	char *mode = "r";
	int line = 0;

	inputFile = fopen("mcode.txt", mode);
	outputFile = fopen(outputFileName, "w");

	if (inputFile == NULL)
	{
		perror("Error");
	}
	else {
		struct instruction;

		fprintf(outputFile, "Line\tOP\tL\tM\n");
		while (!feof(inputFile))
		{
			fscanf(inputFile, "%d", &instruction.op);
			fscanf(inputFile, "%d", &instruction.l);
			fscanf(inputFile, "%d", &instruction.m);

			fprintf(outputFile, "%d\t", line);
			fprintf(outputFile, "%s\t", getOPCode(instruction.op));
			fprintf(outputFile, "%d\t", instruction.l);
			fprintf(outputFile, "%d\t\n", instruction.m);

			line++;
		}
	}

	fclose(inputFile);
	fclose(outputFile);
}

char* getOPCode(int code) {

	switch (code) {
	case 1:
		return "lit";
	case 2:
		return "opr";
	case 3:
		return "lod";
	case 4:
		return "sto";
	case 5:
		return "cal";
	case 6:
		return "inc";
	case 7:
		return "jpc";
	case 8:
		return "wrt";
	default:
		return "Invalid code.";
	}
}
