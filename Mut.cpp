#include "Mut_Del.cpp"
#include <ctime>

int main()
{
	srand(time(0));
	GenCode A;
	A.Gens={7,10,8,3,2,3,4,9,3,2,3,4,11,3,5,3,6,3,7,15,3,8,3,9};
	long y;
	cout<<A.comp(0,y)<<" ";
	cout<<y<<endl;
	Mut_Del(A);
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
		cout<<A.Gens[cur]<<" ";
		cur++;
	}
}
