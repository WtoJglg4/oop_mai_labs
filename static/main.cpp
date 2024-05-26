/********************************************************************
 *          ЛАБОРАТОРНАЯ РАБОТА №1 ПО ООП 4 СЕМЕСТР                 *
 *------------------------------------------------------------------*
 * Project Type  : Win64 Console Application                        *
 * Project Name  : Laba_OOP_1                                       *
 * File Name     : Laba_OOP_1.СPP                                   *
 * Programmer(s) : Глазов Вадим М3О-209Б-22                         *
 * Modifyed By   :                                                  *
 * Created       : 13/04/2024                                       *
 * Last Revision : 14/04/2024                                       *
 * Comment(s)    : ПРОСТЕЙШАЯ ИЕРАРХИЯ КЛАССОВ						*
 *******************************************************************/
#include <windows.h>
#include <iostream>    
using namespace std;

#include "tower.h" 
#include "tower.cpp" 

#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)    //макрос для определения кода нажатой клавиши
HDC hdc;	//контекст устройства

// g++ main.cpp -o main.exe -lgdi32
int main()
{
	system("color F0");
	hdc = GetDC(GetConsoleWindow());

	Point point(100, 100);
	point.Show();

	while (true) {
		if (KEY_DOWN(VK_NUMPAD1)) break;
	}
	
	point.MoveTo(1000, 700);

	while (true) {
		if (KEY_DOWN(VK_NUMPAD2)) break; 	//цифра 2
	}
			

	point.Drag(50); //перемещение фигуры, выход по 3
	while (true) {
		if (KEY_DOWN(VK_NUMPAD3)) break; //цифра 3
	}		

	point.Hide();


	Tower tower(500, 700, 120, 50, 700);
	tower.Show();

	while (true) {
		if (KEY_DOWN(VK_NUMPAD1)) break;
	}
	
	tower.MoveTo(1000, 700);

	while (true) {
		if (KEY_DOWN(VK_NUMPAD2)) break; 	//цифра 2
	}
			

	tower.Drag(50); //перемещение фигуры, выход по 3
	while (true) {
		if (KEY_DOWN(VK_NUMPAD3)) break; //цифра 3
	}		
	ReleaseDC(GetConsoleWindow(), hdc);
}