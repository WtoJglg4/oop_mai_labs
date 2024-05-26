/********************************************************************
 *          ЛАБОРАТОРНАЯ РАБОТА №1 ПО ООП 4 СЕМЕСТР                 *
 *------------------------------------------------------------------*
 * Project Type  : Win64 Console Application                        *
 * Project Name  : Laba_OOP_1                                       *
 * File Name     : tower.СPP                                        *
 * Programmer(s) : Глазов Вадим М3О-209Б-22                         *
 * Modifyed By   :                                                  *
 * Created       : 14/04/2024                                       *
 * Last Revision : 14/04/2024                                       *
 * Comment(s)    : ПРОСТЕЙШАЯ ИЕРАРХИЯ КЛАССОВ						*
 *******************************************************************/
#include <iostream>
#include <windows.h>
#include "tower.h"				// объявление классов
using namespace std;

extern HDC hdc;      			// объявление  контекста устройства
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
const int timeToSleep = 250; 	// время для задержки экрана в мс


/*----------------------------------------------------------------*/
/*             Р Е А Л И З А Ц И Я    М Е Т О Д О В               */
/*----------------------------------------------------------------*/

/*----------------------------------------*/
/*        МЕТОДЫ КЛАССА Location          */
/*----------------------------------------*/
//конструктор
Location:: Location(int InitX, int InitY) {
	x = InitX;
	y = InitY;
};

//деструктор
Location:: ~Location() {
};

//получить X координату точки
int Location:: GetX() {
	return x;
};//Location:: GetX()	

//получить Y координату точки
int Location:: GetY() {
	return y;
};


/*----------------------------------------*/
/*        МЕТОДЫ КЛАССА Point             */
/*----------------------------------------*/

//конструктор
Point:: Point(int InitX, int InitY) : Location(InitX, InitY) {
	visible = false;
}

//деструктор
Point:: ~Point(){
}

// показать точку
void Point:: Show() {
	visible = true;
	SetPixel(hdc, x+1, y, RGB(255, 0, 0));//рисуем синим цветом или фона
	SetPixel(hdc, x-1, y, RGB(255, 0, 0));//рисуем синим цветом или фона
	SetPixel(hdc, x, y+1, RGB(255, 0, 0));//рисуем синим цветом или фона
	SetPixel(hdc, x, y-1, RGB(255, 0, 0));//рисуем синим цветом или фона
	SetPixel(hdc, x-1, y-1, RGB(255, 0, 0));//рисуем синим цветом или фона
	SetPixel(hdc, x-1, y+1, RGB(255, 0, 0));//рисуем синим цветом или фона
	SetPixel(hdc, x+1, y-1, RGB(255, 0, 0));//рисуем синим цветом или фона
	SetPixel(hdc, x+1, y+1, RGB(255, 0, 0));//рисуем синим цветом или фона
	SetPixel(hdc, x, y, RGB(255, 0, 0));//рисуем синим цветом или фона
	// SetPixel(hdc, x, y, RGB(255, 0, 0));//рисуем синим цветом или фона
}


//скрыть точку
void Point:: Hide() {
	visible = false;

	SetPixel(hdc, x+1, y, RGB(255, 255, 255));//рисуем синим цветом или фона
	SetPixel(hdc, x-1, y,RGB(255, 255, 255));//рисуем синим цветом или фона
	SetPixel(hdc, x, y+1, RGB(255, 255, 255));//рисуем синим цветом или фона
	SetPixel(hdc, x, y-1, RGB(255, 255, 255));//рисуем синим цветом или фона
	SetPixel(hdc, x-1, y-1, RGB(255, 255, 255));//рисуем синим цветом или фона
	SetPixel(hdc, x-1, y+1, RGB(255, 255, 255));//рисуем синим цветом или фона
	SetPixel(hdc, x+1, y-1, RGB(255, 255, 255));//рисуем синим цветом или фона
	SetPixel(hdc, x+1, y+1, RGB(255, 255, 255));//рисуем синим цветом или фона
	SetPixel(hdc, x, y, RGB(255, 255, 255));//рисуем синим цветом или фона
	// SetPixel(hdc, x, y, RGB(255, 255, 255)); //рисуем синим цветом или фона

}

//светимость точки
bool Point:: IsVisible() {
	return visible;
};

//переместить точку
void Point:: MoveTo(int NewX, int NewY) {
	Hide();		//скрыть точку
	x = NewX;
	y = NewY;
	Show();		//показать точку
};

//буксировка
void Point:: Drag(int Step) {
	//получение координат точки
	int figX = GetX();
	int figY = GetY();

	//бесконечный цикл
	while (true) {
		if (KEY_DOWN(VK_ESCAPE)) break;	//esc - выход

		//перемещение фигуры в зависимости от нажатой стрелки
		if (KEY_DOWN(VK_LEFT)) figX -= Step;

		if (KEY_DOWN(VK_RIGHT)) figX += Step;

		if (KEY_DOWN(VK_UP)) figY -= Step;

		if (KEY_DOWN(VK_DOWN)) figY += Step;

		MoveTo(figX, figY);
		Sleep(timeToSleep);
	}
}

Tower:: Tower(int InitX, int InitY, int InitBaseLength, int InitObservationRadius, int InitTotalHigh) : Point(InitX, InitY) {
	BaseLength = InitBaseLength;
	ObservationRadius = InitObservationRadius;
	TotalHigh = InitTotalHigh;
}

Tower:: ~Tower() {
}

void Tower:: MoveTo(int NewX, int NewY) {
	Hide();
	x = NewX;
	y = NewY;
	Show();
}

void Tower:: Draw(HPEN pen){
	SelectObject(hdc, pen);

	// фундамент
	Rectangle(hdc, x - BaseLength / 2 , y - BaseLength / 8, x + BaseLength / 2 , y + BaseLength / 8);
	int ObservationHigh = TotalHigh * 7 / 10;	//координаты центра смотровой площадки
	
	//смотровая площадка 
	Ellipse(hdc, x - ObservationRadius, y - ObservationHigh - ObservationRadius, x + ObservationRadius, y - ObservationHigh + ObservationRadius);
	Rectangle(hdc, x - ObservationRadius / 2 , y - ObservationHigh + ObservationRadius, x + ObservationRadius / 2 , y - ObservationHigh + 3 * ObservationRadius / 2);
	Rectangle(hdc, x - ObservationRadius / 4 , y - ObservationHigh - 5 * ObservationRadius / 3, x + ObservationRadius / 4 , y - ObservationHigh - ObservationRadius);
	
	//сама башня
	MoveToEx(hdc, x - BaseLength / 4, y - BaseLength / 8, NULL);
	LineTo(hdc, x - ObservationRadius / 4, y - ObservationHigh + 3 * ObservationRadius / 2);

	MoveToEx(hdc, x + BaseLength / 4, y - BaseLength / 8, NULL);
	LineTo(hdc, x + ObservationRadius / 4, y - ObservationHigh + 3 * ObservationRadius / 2);

	//шпиль
	MoveToEx(hdc,  x - ObservationRadius / 8, y - ObservationHigh - 5 * ObservationRadius / 3, NULL);
	LineTo(hdc, x , y - TotalHigh);
	LineTo(hdc, x + ObservationRadius / 8, y - ObservationHigh - 5 * ObservationRadius / 3);

}

void Tower::  Show() {
	visible = true;
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	Draw(pen);
}

void Tower:: Hide() {
	visible = false;
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	Draw(pen);
}

void Tower:: Drag(int Step) {
	//получение координат точки
	int figX = GetX();
	int figY = GetY();

	//бесконечный цикл
	while (true) {
		if (KEY_DOWN(VK_ESCAPE)) break;	//esc - выход

		//перемещение фигуры в зависимости от нажатой стрелки
		if (KEY_DOWN(VK_LEFT)) figX -= Step;

		if (KEY_DOWN(VK_RIGHT)) figX += Step;

		if (KEY_DOWN(VK_UP)) figY -= Step;

		if (KEY_DOWN(VK_DOWN)) figY += Step;

		MoveTo(figX, figY);
		Sleep(timeToSleep);
	}
}

