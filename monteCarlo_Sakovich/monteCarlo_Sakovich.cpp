#include <stdio.h>
#include <time.h>
#include <random>
#include "ctime"
#include<iostream>
#include <windows.h>
#include <stdlib.h>

struct helper {
	double x;
	double y;
	double tg;
};

void monteCarlo_func();

void randomSquare();

void analyticGeometry();

int main()
{
	int a = -1;
	while (a != 0) {
		printf("Please select the action you need:\n");
		printf("1 - Find the polygon square by points\n");
		printf("2 - Find random polygon square\n");
		printf("3 - Find the square of ​​some figures given analytically\n");
		printf("4 - Exit\n");

		scanf_s("%i", &a);
		switch (a) {
		case 1:
			monteCarlo_func();

			break;
		case 2:
			randomSquare();
			break;
		case 3:
			analyticGeometry();
			break;
		case 4:
			return 0;
		}

	}

	return 0;
}
void circle() {
	printf("Please enter the radius of the circle: \n");
	double r;
	scanf_s("%lf", &r);
	double min_x, max_x, min_y, max_y, rectangle_Squre;
	int  number_Of_Internal_Points = 0;
	srand(time(NULL));
	min_x = -r * 2;
	max_x = r * 2;
	min_y = -r * 2;
	max_y = r * 2;
	rectangle_Squre = 16 * r * r;
	int number_Of_Points;
	printf("\nEnter number of points: ");
	scanf_s("%i", &number_Of_Points);
	helper point;
	HWND hWnd = GetConsoleWindow();
	HDC hDC = GetDC(hWnd);
	for (int l = 0; l < number_Of_Points; l++) {
		point.x = rand() * 1.0 / (RAND_MAX) * (max_x - min_x) + min_x;
		point.y = rand() * 1.0 / (RAND_MAX) * (max_y - min_y) + min_y;
		COLORREF color;
		if (point.x * point.x + point.y * point.y < r * r) {

			number_Of_Internal_Points++;
			color = RGB(255, 0, 0);
		}
		else {
			color = RGB(0, 255, 0);
		}
		SetPixel(hDC, point.x * 5 + 500, 100 + (100 - point.y) * 5, color);
	}
	srand(time(NULL));
	double area;
	area = rectangle_Squre * 1.0 * number_Of_Internal_Points / number_Of_Points;
	printf("\nSquire of poligon:\t%g", area);
}
void ring() {
	printf("Please enter the radius of the circle: \n");
	double R;
	scanf_s("%lf", &R);
	double min_x, max_x, min_y, max_y, rectangle_Squre;
	int  number_Of_Internal_Points = 0;
	srand(time(0));
	min_x = -R * 2;
	max_x = R * 2;
	min_y = -R * 2;
	max_y = R * 2;
	rectangle_Squre = 16 * R * R;
	printf("Please enter the radius: \n");
	double r;
	scanf_s("%lf", &r);
	int number_Of_Points;
	printf("\nPlease enter number of points: ");
	scanf_s("%i", &number_Of_Points);
	helper point;
	HWND hWnd = GetConsoleWindow();
	HDC hDC = GetDC(hWnd);
	for (int l = 0; l < number_Of_Points; l++) {
		point.x = rand() * 1.0 / (RAND_MAX) * (max_x - min_x) + min_x;
		point.y = rand() * 1.0 / (RAND_MAX) * (max_y - min_y) + min_y;

		COLORREF color;
		if ((point.x * point.x + point.y * point.y > r* r) && (point.x * point.x + point.y * point.y < R * R)) {
			number_Of_Internal_Points++;
			color = RGB(255, 0, 0);

		}
		else {

			color = RGB(0, 255, 0);
		}
		SetPixel(hDC, point.x * 5 + 500, 100 + (100 - point.y) * 5, color);
	}
	srand(time(NULL));
	double area;
	area = rectangle_Squre * 1.0 * number_Of_Internal_Points / number_Of_Points;
	printf("\nSquare of the polygon is: \t%g", area);
}
void lemniscate() {
	srand(time(NULL));
	printf("Please enter the focus: \n");
	double focus;
	scanf_s("%lf", &focus);
	double min_x, max_x, min_y, max_y, rectangle_Squre;
	int number_Of_Internal_Points = 0;
	min_x = -focus * 2;
	max_x = focus * 2;
	min_y = -focus;
	max_y = focus;
	rectangle_Squre = 4 * focus * focus;
	int number_Of_Points;
	printf("\nPlease enter number of points: ");
	scanf_s("%i", &number_Of_Points);
	helper point;
	helper focus_helper;
	focus_helper.x = focus;
	focus_helper.y = 0;
	HWND hWnd = GetConsoleWindow();
	HDC hDC = GetDC(hWnd);
	for (int l = 0; l < number_Of_Points; l++) {
		point.x = rand() * 1.0 / (RAND_MAX) * (max_x - min_x) + min_x;
		point.y = rand() * 1.0 / (RAND_MAX) * (max_y - min_y) + min_y;
		COLORREF color;
		if (sqrt((point.x - focus_helper.x) * (point.x - focus_helper.x) + (point.y - focus_helper.y) * (point.y - focus_helper.y)) * sqrt((point.x + focus_helper.x) * (point.x + focus_helper.x) + (point.y - focus_helper.y) * (point.y - focus_helper.y)) <= focus * focus) {
			number_Of_Internal_Points++;
			color = RGB(255, 0, 0);
		}
		else {
			color = RGB(0, 255, 0);
		}
		SetPixel(hDC, point.x * 5 + 500, 100 + (100 - point.y) * 5, color);
	}
	double area;
	area = rectangle_Squre * 1.0 * number_Of_Internal_Points / number_Of_Points;
	printf("\nSquare of the polygon: \t%g", area);
}
void astroid () {
	printf("Please enter the radius: \n");
	double r;
	scanf_s("%lf", &r);
	double min_x, max_x, min_y, max_y, rectangle_Squre;
	int  number_Of_Internal_Points = 0;
	srand(time(NULL));
	min_x = -r;
	max_x = r;
	min_y = -r;
	max_y = r;
	rectangle_Squre = 4 * r * r;

	int number_Of_Points;
	printf("\nPlease enter number of points: ");
	scanf_s("%i", &number_Of_Points);
	helper point;

	HWND hWnd = GetConsoleWindow();
	HDC hDC = GetDC(hWnd);
	for (int l = 0; l < number_Of_Points; l++) {
		point.x = rand() * 1.0 / (RAND_MAX) * (max_x - min_x) + min_x;
		point.y = rand() * 1.0 / (RAND_MAX) * (max_y - min_y) + min_y;
		COLORREF color;
		if (pow(point.x, 2 * 1.0 / 3) + pow(point.y, 2 * 1.0 / 3) <= pow(r, 2 * 1.0 / 3)) {
			number_Of_Internal_Points++;
			color = RGB(255, 0, 0);
		}
		else if (pow(-point.x, 2 * 1.0 / 3) + pow(-point.y, 2 * 1.0 / 3) <= pow(r, 2 * 1.0 / 3)) {
			number_Of_Internal_Points++;
			color = RGB(255, 0, 0);
		}
		else if (pow(-point.x, 2 * 1.0 / 3) + pow(point.y, 2 * 1.0 / 3) <= pow(r, 2 * 1.0 / 3)) {
			number_Of_Internal_Points++;
			color = RGB(255, 0, 0);
		}
		else if (pow(point.x, 2 * 1.0 / 3) + pow(-point.y, 2 * 1.0 / 3) <= pow(r, 2 * 1.0 / 3)) {
			number_Of_Internal_Points++;
			color = RGB(255, 0, 0);
		}
		else {
			color = RGB(0, 255, 0);
		}
		SetPixel(hDC, point.x * 5 + 500, 100 + (100 - point.y) * 5, color);
	}
	srand(time(NULL));
	double area;
	area = rectangle_Squre * 1.0 * number_Of_Internal_Points / number_Of_Points;
	printf("\nSquare of the polygon:\t%g", area);
}
void randomSquare() {
	int number_Of_Tops, number_Of_Points;

	srand(time(0));
	printf("Please enter number of tops: ");
	scanf_s("%i", &number_Of_Tops);
	helper* array_Tops = new helper[number_Of_Tops];
	for (int i = 0; i < number_Of_Tops - 1; i++) {
		array_Tops[i].x = rand() % 100 + 1;
		array_Tops[i].y = rand() % 100;

		array_Tops[i].tg = array_Tops[i].y / array_Tops[i].x * 1.0;
	}
	for (int i = 0; i < number_Of_Tops - 2; i++) {
		for (int j = 0; j < number_Of_Tops - i - 2; j++) {
			if (array_Tops[j + 1].tg > array_Tops[j].tg) {
				std::swap(array_Tops[j + 1], array_Tops[j]);
			}
			if (array_Tops[j + 1].tg == array_Tops[j].tg && array_Tops[j + 1].x > array_Tops[j].x) {
				std::swap(array_Tops[j + 1], array_Tops[j]);
			}
		}
	}
	array_Tops[number_Of_Tops - 1].x = 0;
	array_Tops[number_Of_Tops - 1].y = 0;


	printf("\nTops of polygon:\n");
	for (int i = 0; i < number_Of_Tops; i++) {
		printf("%i %f %f\n", i + 1, array_Tops[i].x, array_Tops[i].y);
	}

	printf("\nPlease enter number of points: ");
	scanf_s("%i", &number_Of_Points);
	double min_x, max_x, min_y, max_y, k, b, rectangle_Squre;
	int number_Of_Crossings = 0, number_Of_Internal_Points = 0;
	bool is_Point_Inner = false;

	min_x = array_Tops[0].x;
	max_x = array_Tops[0].x;
	min_y = array_Tops[0].y;
	max_y = array_Tops[0].y;

	//НАХОДИМ КРАЙНИЕ ТОЧКИ ДЛЯ "ОГРАНИЧИВАЮЩЕГО" ПРЯМОУГОЛЬНИКА
	for (int i = 0; i < number_Of_Tops; i++) {
		if (array_Tops[i].x > max_x) max_x = array_Tops[i].x;
		if (array_Tops[i].x < min_x) min_x = array_Tops[i].x;
		if (array_Tops[i].y > max_y) max_y = array_Tops[i].y;
		if (array_Tops[i].y < min_y) min_y = array_Tops[i].y;
	}

	rectangle_Squre = 1.0 * (max_x - min_x) * (max_y - min_y);

	helper point;
	HWND hWnd = GetConsoleWindow();
	HDC hDC = GetDC(hWnd);
	for (int l = 0; l < number_Of_Points; l++) {
		point.x = rand() * 1.0 / (RAND_MAX) * (max_x - min_x) + min_x;
		point.y = rand() * 1.0 / (RAND_MAX) * (max_y - min_y) + min_y;
		for (int i = 0; i < number_Of_Tops; i++) {
			if (i != number_Of_Tops - 1) {
				k = 1.0 * (array_Tops[i].y - array_Tops[i + 1].y) / (array_Tops[i].x - array_Tops[i + 1].x);
				b = array_Tops[i].y - 1.0 * k * array_Tops[i].x;

				if (k > 0 && k != INFINITY && point.y >= (1.0 * k * point.x + b) && ((point.y >= array_Tops[i].y && point.y <= array_Tops[i + 1].y) || (point.y <= array_Tops[i].y && point.y >= array_Tops[i + 1].y))) {
					number_Of_Crossings++;
				}
				if (k < 0 && k != -INFINITY && point.y <= (1.0 * k * point.x + b) && ((point.y >= array_Tops[i].y && point.y <= array_Tops[i + 1].y) || (point.y <= array_Tops[i].y && point.y >= array_Tops[i + 1].y))) {
					number_Of_Crossings++;
				}
				if ((k == INFINITY || k == -INFINITY) && point.x <= array_Tops[i].x && ((point.y >= array_Tops[i].y && point.y <= array_Tops[i + 1].y) || (point.y <= array_Tops[i].y && point.y >= array_Tops[i + 1].y))) {
					number_Of_Crossings++;
				}
			}
			else {
				k = 1.0 * (array_Tops[i].y - array_Tops[0].y) / (array_Tops[i].x - array_Tops[0].x);
				b = array_Tops[i].y - 1.0 * k * array_Tops[i].x;

				if (k > 0 && k != INFINITY && point.y >= (1.0 * k * point.x + b) && ((point.y >= array_Tops[i].y && point.y <= array_Tops[0].y) || (point.y <= array_Tops[i].y && point.y >= array_Tops[0].y))) {
					number_Of_Crossings++;
				}
				if (k < 0 && k != -INFINITY && point.y <= (1.0 * k * point.x + b) && ((point.y >= array_Tops[i].y && point.y <= array_Tops[0].y) || (point.y <= array_Tops[i].y && point.y >= array_Tops[0].y))) {
					number_Of_Crossings++;
				}
				if ((k == INFINITY || k == -INFINITY) && point.x <= array_Tops[i].x && ((point.y >= array_Tops[i].y && point.y <= array_Tops[0].y) || (point.y <= array_Tops[i].y && point.y >= array_Tops[0].y))) {
					number_Of_Crossings++;
				}
			}
		}
		COLORREF color;
		if (number_Of_Crossings % 2 != 0) is_Point_Inner = true;
		if (is_Point_Inner) {
			number_Of_Internal_Points++;
			color = RGB(255, 0, 0);


		}
		else {
			color = RGB(0, 255, 0);
		}
		SetPixel(hDC, point.x * 5 + 500, 100 + (100 - point.y) * 5, color);
		is_Point_Inner = false;
		number_Of_Crossings = 0;
	}

	HPEN cP = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
	POINT p;
	SelectObject(hDC, cP);
	for (int i = 0; i < number_Of_Tops - 1; i++) {
		MoveToEx(hDC, array_Tops[i].x * 5 + 500, 100 + (100 - array_Tops[i].y) * 5, &p);
		LineTo(hDC, array_Tops[i + 1].x * 5 + 500, 100 + (100 - array_Tops[i + 1].y) * 5);
	}
	MoveToEx(hDC, array_Tops[0].x * 5 + 500, 100 + (100 - array_Tops[0].y) * 5, &p);
	LineTo(hDC, array_Tops[number_Of_Tops - 1].x * 5 + 500, 100 + (100 - array_Tops[number_Of_Tops - 1].y) * 5);
	printf("Number of inner points: %i\n", number_Of_Internal_Points);
	printf("Square of the rectangle: %f\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n", rectangle_Squre);
	srand(time(NULL));
	double area;
	area = rectangle_Squre * 1.0 * number_Of_Internal_Points / number_Of_Points;
	printf("\nSquare of the polygon:\t%g", area);
	srand(time(NULL));
}
void monteCarlo_func() {

	int number_Of_Tops, number_Of_Points;
	printf("Please enter number of tops: ");
	scanf_s("%i", &number_Of_Tops);
	printf("Please enter tops of the polygon:\n");
	helper* array_Tops = new helper[number_Of_Tops];
	for (int i = 0; i < number_Of_Tops; i++) {
		printf("%i helper:\t", i + 1);
		scanf_s("%lf", &(array_Tops[i].x));
		scanf_s("%lf", &(array_Tops[i].y));
	}
	printf("\nTops of polygon:\n");
	for (int i = 0; i < number_Of_Tops; i++) {
		printf("%i %f %f\n", i + 1, array_Tops[i].x, array_Tops[i].y);
	}

	printf("\nPlease enter number of points: ");
	scanf_s("%i", &number_Of_Points);
	double min_x, max_x, min_y, max_y, k, b, rectangle_Squre;
	int number_Of_Crossings = 0, number_Of_Internal_Points = 0;
	bool is_Point_Inner = false;

	min_x = array_Tops[0].x;
	max_x = array_Tops[0].x;
	min_y = array_Tops[0].y;
	max_y = array_Tops[0].y;
	for (int i = 0; i < number_Of_Tops; i++) {
		if (array_Tops[i].x > max_x) max_x = array_Tops[i].x;
		if (array_Tops[i].x < min_x) min_x = array_Tops[i].x;
		if (array_Tops[i].y > max_y) max_y = array_Tops[i].y;
		if (array_Tops[i].y < min_y) min_y = array_Tops[i].y;
	}

	rectangle_Squre = 1.0 * (max_x - min_x) * (max_y - min_y);

	helper point;
	HWND hWnd = GetConsoleWindow();
	HDC hDC = GetDC(hWnd);
	for (int l = 0; l < number_Of_Points; l++) {
		point.x = rand() * 1.0 / (RAND_MAX) * (max_x - min_x) + min_x;
		point.y = rand() * 1.0 / (RAND_MAX) * (max_y - min_y) + min_y;

		for (int i = 0; i < number_Of_Tops; i++) {
			if (i != number_Of_Tops - 1) {

				k = 1.0 * (array_Tops[i].y - array_Tops[i + 1].y) / (array_Tops[i].x - array_Tops[i + 1].x);
				b = array_Tops[i].y - 1.0 * k * array_Tops[i].x;

				if (k > 0 && k != INFINITY && point.y >= (1.0 * k * point.x + b) && ((point.y >= array_Tops[i].y && point.y <= array_Tops[i + 1].y) || (point.y <= array_Tops[i].y && point.y >= array_Tops[i + 1].y))) {
					number_Of_Crossings++;
				}
				if (k < 0 && k != -INFINITY && point.y <= (1.0 * k * point.x + b) && ((point.y >= array_Tops[i].y && point.y <= array_Tops[i + 1].y) || (point.y <= array_Tops[i].y && point.y >= array_Tops[i + 1].y))) {
					number_Of_Crossings++;
				}
				if ((k == INFINITY || k == -INFINITY) && point.x <= array_Tops[i].x && ((point.y >= array_Tops[i].y && point.y <= array_Tops[i + 1].y) || (point.y <= array_Tops[i].y && point.y >= array_Tops[i + 1].y))) {
					number_Of_Crossings++;
				}
			}
			else {
				k = 1.0 * (array_Tops[i].y - array_Tops[0].y) / (array_Tops[i].x - array_Tops[0].x);
				b = array_Tops[i].y - 1.0 * k * array_Tops[i].x;

				if (k > 0 && k != INFINITY && point.y >= (1.0 * k * point.x + b) && ((point.y >= array_Tops[i].y && point.y <= array_Tops[0].y) || (point.y <= array_Tops[i].y && point.y >= array_Tops[0].y))) {
					number_Of_Crossings++;
				}
				if (k < 0 && k != -INFINITY && point.y <= (1.0 * k * point.x + b) && ((point.y >= array_Tops[i].y && point.y <= array_Tops[0].y) || (point.y <= array_Tops[i].y && point.y >= array_Tops[0].y))) {
					number_Of_Crossings++;
				}
				if ((k == INFINITY || k == -INFINITY) && point.x <= array_Tops[i].x && ((point.y >= array_Tops[i].y && point.y <= array_Tops[0].y) || (point.y <= array_Tops[i].y && point.y >= array_Tops[0].y))) {
					number_Of_Crossings++;
				}
			}
		}
		COLORREF color;
		if (number_Of_Crossings % 2 != 0) is_Point_Inner = true;
		if (is_Point_Inner) {
			number_Of_Internal_Points++;
			color = RGB(255, 0, 0);

		}
		else {
			color = RGB(0, 255, 0);
		}
		SetPixel(hDC, point.x * 5 + 500, 100 + (100 - point.y) * 5, color);
		is_Point_Inner = false;
		number_Of_Crossings = 0;
	}
	HPEN cP = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
	POINT p;
	SelectObject(hDC, cP);
	for (int i = 0; i < number_Of_Tops - 1; i++) {
		MoveToEx(hDC, array_Tops[i].x * 5 + 500, 100 + (100 - array_Tops[i].y) * 5, &p);
		LineTo(hDC, array_Tops[i + 1].x * 5 + 500, 100 + (100 - array_Tops[i + 1].y) * 5);
	}
	MoveToEx(hDC, array_Tops[0].x * 5 + 500, 100 + (100 - array_Tops[0].y) * 5, &p);
	LineTo(hDC, array_Tops[number_Of_Tops - 1].x * 5 + 500, 100 + (100 - array_Tops[number_Of_Tops - 1].y) * 5);
	printf("Number of internal points: %i\n", number_Of_Internal_Points);
	printf("Square of the rectangle: %f\n\n\n\n\n\n\n\n", rectangle_Squre);
	srand(time(NULL));
	double area;
	area = rectangle_Squre * 1.0 * number_Of_Internal_Points / number_Of_Points;
	printf("\nSquare of the polygon:\t%g", area);
	srand(time(NULL));

}
void analyticGeometry() {
	printf("What figure square do you want to find??\n");
	printf("1 - Circle\n");
	printf("2 - Ring\n");
	printf("3 - Lemniscate\n");
	printf("4 - Astroid\n");
	int p;
	scanf_s("%i", &p);
	switch (p) {
	case 1:
		circle();
		break;
	case 2:
		ring();
		break;
	case 3:
		lemniscate();
		break;
	case 4:
		astroid ();
	}
}