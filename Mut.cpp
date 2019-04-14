#include "Mut_Del.cpp"
#include "Mut_add.cpp"
#include "Cross.cpp"
#include "Const.cpp"
#include <ctime>

int main()
{
	freopen("Code.cpp", "w", stdout);
	srand(time(0));
	GenCode A,B,R;
	long b=0;
	long n=40;
	while (n>0)
	{
		add(A);
		n--;
	}
	b=0;
	n=40;
	while (n>0)
	{
		add(B);
		n--;
	}
	R=cross(A,B);
	cout<<endl;
	n=3;
	while (n>0)
	{
		Mut_all(R);
		n--;
	}
	cout<<endl;
	rout(R);
}
