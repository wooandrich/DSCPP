#include <iostream> // 입출력 헤더파일
#include "Rectangle.h" // Rectangle.h 헤더파일을 이용
#include "Rectangle.cpp" // 링커오류로 추가해야됨
#include "Size.cpp"

int main()
{ 

	Rectangle r1; // 객체 r1생성
	
	std::cin >> r1; // 객체 r1을 입력
	std::cout << r1; // 객체 r1을 출력  
	
	Rectangle* r2 = new Rectangle; // 객체 r2 생성
	
	std::cin >> *r2; // 객체 r2를 입력1
	
	std::cout << *r2; // 객체 r2를 출력

	Size r3; // 겹치는 영역을 만들기 위한 객체를 생성

	r3.size_1(r1,*r2); // 객체 r1과 r2의 모서리 좌표를 통하여 사각형의 겹치는 넓이를 객체 r3를 통해 출력
	

	delete r2; // new로 만들어진 객체 r2를 삭제하기 위해서는 delete를 사용해야하고 파괴자 함수가 호출된다.

}