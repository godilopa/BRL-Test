#include <stdio.h>
#include <cstdlib> 
#include <cstring>
#include "rocket.h"

void CheckConsoleAparms(int argc, char* args[], int& size, bool& inv);

int main(int argc, char* args[]){
	int rocketSize = 0;
	bool inversion = false;

	CheckConsoleAparms(argc, args, rocketSize, inversion);

	Rocket* rocket = new Rocket(rocketSize);
	rocket->Draw(inversion);

	return 0;
}

void CheckConsoleAparms(int argc, char* args[], int& size, bool& inv){

	if(argc < 2 || strcmp(args[1],"--help") == 0)
		printf("Write -l + sizeOfRocket + -i (Optional: Rocket Inversion) \n");
	else if (strcmp(args[1], "-l") == 0)
	{		
		size = atoi(args[2]);
							
		if(size <= 0 || size > 40){
			printf("Size parameter is wrong: Between 1 and 30 \n");
			size = 0;
			}
		
		if(argc > 3){		
			if(strcmp(args[3], "-i") == 0)
				inv = !strcmp(args[3], "-i");
			else
				printf("Inversion parameter is wrong \n");
		}
	}
	else{
		printf("Write --help to see options \n");	
	}
}
