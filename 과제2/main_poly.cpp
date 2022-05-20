#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

class Polynomial;  // 전방선언

class Term { 
	friend Polynomial;
	friend istream& operator>>(istream& in, Polynomial& p);  // 다항식을 입력 받는 >> 연산자 오버로딩
	friend ostream& operator<<(ostream& out, Polynomial& p);  // 다항식을 출력 받는 << 연산자 오버로딩
private:
	float coef;  // 계수
	int exp;  // 지수
};

class Polynomial {
private:
	Term* termArray;  // 지수 계수를 넣을 배열
	int capacity = 1;  // termArray의 최대크기
	int terms = 0;  // termArray의 배열 현위치

public:
	Polynomial();  // 생성자
	friend istream& operator>>(istream& is, Polynomial& p);  // 다항식을 입력 받는 >> 연산자 오버로딩
	friend ostream& operator<<(ostream& os, Polynomial& p);   // 다항식을 출력 받는 << 연산자 오버로딩
	void NewTerm(const float Coef, const int Exp);  // termArray의 현위치인 term에 지수와 계수를 추가
	Polynomial operator*(Polynomial& b);  // 객체 A와 B를 곱한 것을 반환한다.
	void Array_sort();  // 지수를 기준으로 내림차순으로 버블정렬함
	int Eval(int x);  // x값을 입력해서 값을 반환
};

Polynomial::Polynomial() 
{
	
	termArray = new Term[capacity]; // termArray를 크기가 capacity인 배열로 새로 할당
}

void Polynomial::NewTerm(const float Coef, const int Exp)
{
	if (terms == capacity)  // termArray가 꽉 차면 두배로 확장
	{
		capacity *= 2;
		Term* temp = new Term[capacity];  // 새 배열 
		copy(termArray, termArray + terms, temp);  // termArray에 있던 내용을 새 termArray로 옮김
		delete[] termArray;  // 전에 termArray 메모리 반환
		termArray = temp;
	}
	
	termArray[terms].coef = Coef;
	termArray[terms++].exp = Exp;
    // 배열에 값을 넣고 term을 1 올림
}

istream& operator>>(istream& is, Polynomial& p)  // 입력 >> 연산자 오버로딩
{
    string strINPUT;
    vector<int> VecNUM;

    getline(cin, strINPUT);

   string strNUM = "";
   for(int i =0; i<strINPUT.length();i++)
   {
      if(strINPUT.at(i) == ' ')
      {
         VecNUM.push_back(atoi(strNUM.c_str()));
         strNUM = "";
      }
      else
      {
         strNUM += strINPUT.at(i);
         continue;
      }
   }
   VecNUM.push_back(atoi(strNUM.c_str()));
  


   for(int i=0;i<VecNUM.size() / 2 ;i++)
   {

      p.NewTerm(VecNUM[2*i],VecNUM[2*i + 1]);

   }

   return is;
   /* getline으로 입력을 받고 vector에 넣는다. vector에 넣고 
   vector사이즈만큼 반복문을 돌려서 NewTerm에 할당한다. */
}

void Polynomial::Array_sort()
{
   for(int i =0; i<terms;i++)
      for(int j = i+1;j<terms;j++)
         if(termArray[i].exp < termArray[j].exp)
         {
            Term temp = termArray[i];
            termArray[i] = termArray[j];
            termArray[j] = temp;
         }
    for(int i =0; i<terms;i++)
      for(int j = i+1;j<terms;j++)
        if(termArray[i].exp == termArray[j].exp)
        {
            termArray[i].coef += termArray[j].coef;
            termArray[j].coef = 0;
        }
}
/* 지수를 기준으로 내림차순으로 버블정렬을 하여 정렬을 하고 
    이중반복문을 돌려 지수가 같다고 같은 지수의 계수를 더하고 한쪽의 계수는 0으로 만든다 */

ostream& operator<<(ostream& os, Polynomial& p)  // 출력 << 연산자 오버로딩
{
	p.Array_sort();  // 지수기준으로 내림차순 정렬

	for (int i = 0; i < p.terms; i++) 
	{
        if(p.termArray[i].coef)
            os << p.termArray[i].coef;
		if (p.termArray[i].exp != 0)
            os << "x^"; // 
		if (p.termArray[i].exp)
            os << p.termArray[i].exp;  
		if (i != p.terms - 1 && p.termArray[i+1].coef > 0)
            os << " + "; 
	}
	os << endl;


	return os;
    /* 객체의 terms만큼 반복을 하여 객체의 계수를 출력하고 지수가 0이 아니면 x^을 출력 후 지수를 출력한다. */
}



Polynomial Polynomial::operator*(Polynomial &b) // 객체 a * b 연산자 오버로딩
{
    Polynomial c;
    int aPos = 0;
    int bPos = 0;
    for (aPos; aPos < terms; aPos++)
    {
        for (bPos; bPos < b.terms; bPos++)
        {
            int place = -1;
            int tempcoef = termArray[aPos].coef*b.termArray[bPos].coef;
            int tempexp = termArray[aPos].exp+b.termArray[bPos].exp;
            for (int i = 0; i < c.terms; i++)
                if (c.termArray[i].exp == tempexp)
                    place = i;
            if(place==-1)
                c.NewTerm(tempcoef, tempexp);
            else
                c.termArray[place].coef += tempcoef;
        }
    }
    return c;
    /* aPos와 bPos를 객체의 terms가 될때까지 이중반복문을 돌려 place를 먼저 찾는 인덱스가 없을 때 -1이라 해놓고
    계수의 곱을 tempcoef 지수의 합을 tempexp라도 선언하고 반복문을 돌려 인덱스와 지수가 같으면 place에 할당하고 
    지수가 없으면 NewTerm을 이용해서 새로 추가, 같은 지수가 있으면 기존 객체 계수에 더한다. */
}

int Polynomial::Eval(int x)  // x에 값을 대입한 결과 계산
{
	int eval = 0;

	for (int i = 0; i < terms; i++) 
	{
		eval += termArray[i].coef * pow(x, termArray[i].exp);
	}

	return eval;

    /* 반복문을 돌려 객체 계수에 입력한 x의 객체지수승 만큼 곱하여 더해준다. */
}

int main()
{
	
	Polynomial a, b, c;  // a,b,c 생성
	int x;  // 다항식의 x에 대입할 
    cout << "A(X) = ";
	cin >> a;
    cout << "B(X) = ";
	cin >> b;
    cout << "A(x) = " << a;
    cout << "B(x) = " << b;
	c = a * b; // 객체 a와 b를 곱함
	cout << "A X B = " << c;
    cout << "대입할 x값을 입력하세요 : "; 
	cin >> x;
	cout << "A("<<x<<") = "<<a.Eval(x)<<endl;
    cout << "B("<<x<<") = "<<b.Eval(x)<<endl;
    cout << "C("<<x<<") = "<<c.Eval(x)<<endl;
	
	

	return 0;
}