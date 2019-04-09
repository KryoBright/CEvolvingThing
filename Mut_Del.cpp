#include "gef.cpp"

using namespace std;

void Mut_Del(GenCode &A)
{
	long rn=rand()%200;
	long i=0;
	long li=0;
	long y;
	while (rn>=0)
	{
		y=0;
		if (i!=A.comp(i,y))
		{
			rn=rn-A.comp(i,y)+i;
		}
		if (y==0)
		{

			li=i;
			i=A.comp(i,y);
			i++;

		}
		else
		{
			i=y;
			li=i;
		}
		if (i>A.Gens.size())
		{
			i=0;
		}
	}
	A.Gens.erase(A.Gens.begin()+li,A.Gens.begin()+A.comp(li,y)+1);

}

