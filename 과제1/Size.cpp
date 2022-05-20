#include <iostream>
#include "Rectangle.h"

void Size::size_1(Rectangle r1, Rectangle r2)
{
	
    left_x1 = r1.Xlow(); 
	rigit_x1 = r1.Xlow() + r1.Width();
	left_y1 = r1.Ylow();
	right_y1 = r1.Ylow() + r1.Height();
	/* left_x1,left_y1은 객체 r1의 왼쪽 아래 모서리 x,y좌표
	right_x1,right_y1은 객체 r1의 오른쪽 위에 모서리 x,y좌표*/

	left_x2 = r2.Xlow();
	rigit_x2 = r2.Xlow() + r2.Width();
	left_y2 = r2.Ylow();
	right_y2 = r2.Ylow() + r2.Height();
	/* left_x2,left_y2은 객체 r2의 왼쪽 아래 모서리 x,y좌표
	right_x2,right_y2은 객체 r2의 오른쪽 위에 모서리 x,y좌표*/

	int count = 0; // 넓이
	int row = 0; // 전체 행렬의 행 사이즈
	int column = 0; // 전체 행렬의 열 사이즈

    if(rigit_x1 >= rigit_x2){
		column += rigit_x1;
	}	
	else{
		column += rigit_x2;
	}
	/* 객체 r1의 오른쪽 위 x좌표가 객체 r2의 오른쪽 위 x좌표보다 크거나 같으면
	 전체 행렬의 열 크기를 객체 r1의 오른쪽 위 x좌표로 한다.
	 반대일때는 r2의 오른쪽 위 x좌표로 한다.  */

	if(right_y1 >= right_y2){
		row += right_y1;
	}
	else{
		row += right_y2;
	}
	/* 객체 r1의 오른쪽 위 y좌표가 객체 r2의 오른쪽 위 y좌표보다 크거나 같으면
	 전체 행렬의 행 크기를 객체 r1의 오른쪽 위 y좌표로 한다.
	 반대일때는 r2의 오른쪽 위 y좌표로 한다.  */
	
	int **arr = new int*[row+1];

	for(int i = 0;i<=row;i++)
		arr[i] = new int[column+1];
	/* 이중포인터를 사용하여 크기가 row+1, column+1인
	행렬을 만든다. */
	

	for(int i = left_y1;i<right_y1;i++){
		for(int j = left_x1;j<rigit_x1;j++){
			arr[i][j] += 1;
		}
	}
	/* 객체 r1의 왼쪽 아래 모서리부터 오른쪽 위 모서리까지
	반복문을 돌려 1씩 더한다 */

	for(int i = left_y2;i<right_y2;i++){
		for(int j = left_x2;j<rigit_x2;j++){
			arr[i][j] += 1;
		}
	}
	/* 객체 r2의 왼쪽 아래 모서리부터 오른쪽 위 모서리까지
	반복문을 돌려 1씩 더한다 */
	
	for(int i = 0;i<=row;i++)
		for(int j = 0;j<=column;j++)
			if(arr[i][j] ==2){
				count += 1;
			}
    /* 전체 행렬을 탐색하여 값이 2라면 count를 1씩 늘린다 */
	if(count >= 1)
		std::cout << "객체 r1과 객체 r2의 겹치는 넓이는 : " << count << " 입니다." << std::endl << std::endl;
	else
		std::cout << "객체 r1과 객체 r2는 겹치는 넓이가 없습니다." << std::endl << std::endl;
	/* 넓이인 count가 1 이상이면 넓이를 출력하고 0이면 겹치는 넓이가 없다고 출력한다. */

    for(int i = 0; i<=row;i++)
		delete[] arr[i];
	
	delete[] arr;
	/* 2차원 배열 할당 해제 */
};
