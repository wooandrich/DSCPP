#pragma once // 헤더파일 전체의 재정의를 막는다.

#include <iostream> // 입출력 헤더파일

class Rectangle // 클래스 Rectangle를 생성

{
private: // 다음 5개의 멤버들은 데이터 멤버들이다
	static int id; // id는 생성된 객체의 갯수를 알려준다
	int width; // width는 사각형의 길이
	int height; // height는 사각형의 높이
	int xLow, yLow; // xLow,yLow는 사각형 왼쪽하단 모서리 좌표

	

public: // 다음 2개의 멤버들은 멤버 함수이다.

	Rectangle(); // 생성자
	~Rectangle(); // 파괴자이다.
	int Xlow();
	int Ylow();
	int Width();
	int Height();
	
	friend std::istream& operator >>(std::istream&, Rectangle&); // >> 연산자에 대한 overload함수 구현
	friend std::ostream& operator <<(std::ostream&, Rectangle&); // << 연산자에 대한 overload함수, 객체의 private 데이터 멤버에 접근할 수 있도록 friend함수를 지정

};

class Size
{
private:

	int left_x1; 
	int rigit_x1;
	int left_y1;
	int right_y1;
	/* left_x1,left_y1은 객체 r1의 왼쪽 아래 모서리 x좌표
	right_x1,right_y1은 객체 r1의 오른쪽 위에 모서리 y좌표*/

	int left_x2;
	int rigit_x2;
	int left_y2;
	int right_y2;
	/* left_x2,left_y2은 객체 r2의 왼쪽 아래 모서리 x좌표
	right_x2,right_y2은 객체 r2의 오른쪽 위에 모서리 y좌표*/

public:
	void size_1(Rectangle r1, Rectangle r2);
	/* 객체 r1와 r2의 왼쪽 아래 모서리좌표와 오른쪽 위 모서리좌표를 가져와
	겹치는 넓이를 출력하는 함수를 만든다. */
};