#include "rocket.h"
#include <stdio.h>

void PrintNCharacters(const char* character, int times, bool spaceAtEnd);
void NormalDraw(int height);
void InverseDraw(int height);

Rocket::Rocket(int height){
	m_height = height;
}

void Rocket::SetHeight(int height){
	m_height = height;
}

void Rocket::Draw(bool inversion) const{
	if(m_height == 0)
		return;

	if(inversion == false)
		NormalDraw(m_height);
	else
		InverseDraw(m_height);
}

void NormalDraw(int height){
	int middle = height - 1;  
	
//Dibujamos el pico
	PrintNCharacters(" ", middle, false);
	PrintNCharacters("|", 1, true);
	
//Dibujamos el cuerpo	
	for(int i = 0; i < height; i++){
		PrintNCharacters(" ", middle - i, false);
		PrintNCharacters("x", 2 * i + 1, true);
	}
	
//Dibujamos los pies si la altura es mayor a 1
	if(height != 1){	
		PrintNCharacters("x", 1, false);
		PrintNCharacters(" ", middle - 1, false);
		PrintNCharacters("x", 1, false);
		PrintNCharacters(" ", middle - 1, false);
		PrintNCharacters("x", 1, true);
	}
}

void InverseDraw(int height){
	int middle = height - 1;  
	
//Dibujamos los pies si la altura es mayor a 1
	if(height != 1){
		PrintNCharacters("x", 1, false);
		PrintNCharacters(" ", middle - 1, false);
		PrintNCharacters("x", 1, false);
		PrintNCharacters(" ", middle - 1, false);
		PrintNCharacters("x", 1, true);
	}
	
//Dibujamos el cuerpo	
	for(int i = height - 1; i >= 0; i--){
		PrintNCharacters(" ", middle - i, false);
		PrintNCharacters("x", 2 * i + 1, true);
	}

//Dibujamos el pico
	PrintNCharacters(" ", middle, false);
	PrintNCharacters("|", 1, true);
}

void PrintNCharacters(const char* character, int times, bool spaceAtEnd){
	for(int i = 0; i < times; i++)
 		printf(character);
 
 	if(spaceAtEnd == true)
 		printf("\n");
}

