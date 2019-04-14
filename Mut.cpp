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
	if (b!=0)
	{
		A.Gens=A.Gens+"B";
	}
	b=0;
	n=40;
	while (n>0)
	{
		add(B);
		n--;
	}
	if (b!=0)
	{
		B.Gens=B.Gens+"B";
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
