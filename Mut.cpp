#include "Mut_Del.cpp"
#include "Mut_add.cpp"
#include <ctime>

int main()
{
	srand(time(0));
	GenCode A;
	long b=0;
	long n=5;
	while (n>0)
	{
		long p=rand()%20;
		if (p==0)
		{
			b++;
			A.Gens=A.Gens+genr(9);
		}
		else if ((p<b+20-n)and(b>0))
		{

			A.Gens=A.Gens+"B";
			b--;
		}
		else
		{
			A.Gens=A.Gens+genr(6);
		}
		n--;
	}
	cout<<A.Gens<<endl;
	add(A);
	cout<<A.Gens<<endl;
	rep(A);
	cout<<A.Gens<<endl;
		long y;
		cout<<A.comp(0,y)<<" ";
		cout<<y<<endl;
		while (A.Gens.size()>0)
		{
		Mut_Del(A);
		cout<<A.Gens<<endl;
	}
		long cur=0;
	/*	while (cur<A.Gens.size())
		{
			cur=A.comp(cur,y);
			cout<<endl<<cur<<" ";
			cur++;
		}*/
		cur=0;
		while (cur<A.Gens.size())
		{
			cout<<A.Gens[A.comp(cur,y)]<<endl;
			cur=A.comp(cur,y)+1;
		}
		cout<<A.Gens;
}
