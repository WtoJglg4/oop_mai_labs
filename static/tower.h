#pragma once
/********************************************************************
 *          ЛАБОРАТОРНАЯ РАБОТА №1 ПО ООП 4 СЕМЕСТР                 *
 *------------------------------------------------------------------*
 * Project Type  : Win64 Console Application                        *
 * Project Name  : Laba_OOP_1                                       *
 * File Name     : tower.h                                          *
 * Programmer(s) : Глазов Вадим М3О-209Б-22           				*
 * Modifyed By   :                                                  *
 * Created       : 14/04/2023                                       *
 * Last Revision : 14/04/2023                                       *
 * Comment(s)    : ПРОСТЕЙШАЯ ИЕРАРХИЯ КЛАССОВ						*
 *******************************************************************/

 /*-----------------------------------------------------------------------*/
 /*                         Т И П Ы    Д А Н Н Ы Х                        */
 /*-----------------------------------------------------------------------*/

 /*-----------------------  Класс Location -------------------------*/
class Location {
	protected:		
		int x;							//координата X
		int y;							//координата Y

	public:
		Location(int InitX, int InitY); //конструктор
		~Location();                    //деструктор
		int GetX();						//получить X координату точки
		int GetY();						//получить Y координату точки
};

/*-----------------------  Класс Point ----------------------------------*/
class Point : public Location{
	protected:							
		bool visible;					//видимость точки

	public:
		Point(int InitX, int InitY);		//конструктор
		~Point();							//деструктор

		bool IsVisible();					//является видимой
		void MoveTo(int NewX, int NewY);	//переместить
		void Drag(int Step); 				//буксировка

		// static
		void Show();						//показать 
		void Hide();						//скрыть
};

/*-----------------------  Класс Tower ----------------------------------*/
class Tower : public Point {
	protected:
		int BaseLength;						//длина фундамента
		int ObservationRadius;				//радиус смотровой площадки
		int TotalHigh;						//общая высота
	public:
		Tower(int InitX, int InitY, int BaseLength, int ObservationRadius, int TotalHigh);	
		~Tower();
		void Show();
		void Hide();
		void Draw(HPEN pen);				//нарисовать башню с заданными параметрами
		
		//static
		void MoveTo(int NewX, int NewY);
		void Drag(int Step);
	

};