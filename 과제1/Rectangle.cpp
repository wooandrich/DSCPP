#include "Rectangle.h" // Rectangle.h 헤더파일을 이용
#include <iostream>	   // 입출력 헤더파일

//using namespace std;

int Rectangle::id = 0; // 클래스 Rectangle의 데이버멤버인 정적변수 id를 0으로 초기화한다.
//extern int count;
std::istream &operator>>(std::istream &is, Rectangle &r)
{
	std::cout << "x : ";
	is >> r.xLow;
	std::cout << "y : ";
	is >> r.yLow;
	std::cout << "width : ";
	is >> r.width;
	std::cout << "hight : ";
	is >> r.height;
	std::cout << "\n\n";

	return is;
}

Rectangle::Rectangle() { // 클래스 Rectangle 생성자 정의

	std::cout << ++id << "번째 Rectangle 객체 생성\n\n"; // id를 1 더한 이후 id와 입력된 문자 출력
}


Rectangle::~Rectangle() { // 파괴자 정의
	std::cout << "좌표 (" << xLow << ',' << yLow << ')' // 데이터 멤버 xLow와 yLow, 문자로 이루어진 문장 출력
		<< " Rectangle 객체 소멸\n\n";
}


std::ostream& operator <<(std::ostream& os, Rectangle& r) { // 연산자 << overloading을 통해서 다음 4개의 문장을 출력한다.
	os << "height : " << r.height << std::endl
		<< "width : " << r.width << std::endl
		<< "x : " << r.xLow << std::endl
		<< "y : " << r.yLow << std::endl << std::endl;

	return os;
}

int Rectangle::Xlow(){
	return xLow;
} // 사각형의 왼쪽아래 x좌표
int Rectangle::Ylow(){
	return yLow;
} // 사각형의 왼쪽아래 y좌표
int Rectangle::Width(){
	return width;
} // 사각형의 밑변
int Rectangle::Height(){
	return height;
} // 사각형의 높이








