#include<stdio.h>

typedef unsigned int UINT32;

typedef unsigned char UINT8;


int main()
{
	//UINT8 v[8] = { 0 };
	//UINT8 temp[3] = { '\0' };

	UINT32 v[8] = { 0 };
	UINT8 temp[3] = { '\0' };

	FILE* fp_read = NULL;
	FILE* fp_write = NULL;
	char line[512];
	
	char* inputFileName = "read.txt";
	char* outputFileName = "write.txt";

	//fp_read = fopen("read.txt", "rt");
	fp_read = fopen(inputFileName, "rt");
	if (NULL == fp_read)
	{
		printf("open file failed !");
		return 0;
	}

	fp_write = fopen(outputFileName, "wb");
	if (NULL == fp_write)
	{
		printf("open file failed !");
		return 0;
	}

	while (NULL != fgets(line, 512, fp_read))
	{
		if (
			(line[0] >= '0' && line[0] <= '9')
			||
			(line[0] >= 'a' && line[0] <= 'f')
			||
			(line[0] >= 'A' && line[0] <= 'F')
			)
		{
			for (auto i = 0; i < 8 ; i++)
			{
				temp[0] = line[2 * i];
				temp[1] = line[2 * i + 1];
				temp[2] = '\0';
				sscanf(temp, "%x", &v[i]);
				
			}

			for (auto m = 0;m<8;m++)
			{
				printf("temp[%d] = %x\n", m, v[m]);
			}
			//fprintf(fp_write, "%02x%02x%02x%02x%02x%02x%02x%02x\n", v[7], v[6], v[5], v[4], v[3], v[2], v[1], v[0]);
			fprintf(fp_write, "%02x%02x%02x%02x%02x%02x%02x%02x\n", v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7]);
			fprintf(fp_write, "\n");
		}
		else
		{
			fprintf(fp_write, "%s", "WWWWWWW");
			fprintf(fp_write,"%s",line);
		}
	}

	fclose(fp_write);
	fp_write = NULL;
	fclose(fp_read);
	fp_read = NULL;

}