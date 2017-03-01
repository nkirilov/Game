//Николай Здравков Кирилов 
//ФН 71515
//Visual Studio 2013 Professional
//Windows 7 Ultimate 64bit
#include<iostream>
#include<fstream>
#include"Map.h"
#include"Gameplay.h"
int main()
{
	std::ifstream is("LVL1.txt", std::ios::binary);
	Gameplay a(is);
	is.close();
	a.Play();

	
	
	//system("pause");
	return 0;
}