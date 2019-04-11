#include "gef.cpp"

using namespace std;

void Mut_Del(GenCode &A)
{
	if (A.Gens.size()>0)
	{
		long rn=rand()%100;
		long i=0;
		long y;
		while (rn>=0)
		{
			y=0;
			rn--;
			A.comp(i,y);
			if (y==0)
			{
				i=A.comp(i,y)+1;
			}
			else
			{
				i=y+1;
			}
			while(A.Gens[i]=='B')
			{
				i++;
			}
			if (i==A.Gens.size())
			{
				i=0;
			}
		}
		A.Gens.erase(A.Gens.begin()+i,A.Gens.begin()+A.comp(i,y)+1);
	}

}

