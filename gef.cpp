#include <iostream>
#include <vector>

using namespace std;

struct GenCode
{
	vector<long>Gens;
	long comp(long compb,long &y)
	{
		if (compb==Gens.size())
		{
			return Gens.size();
		}
		if (Gens[compb]==3)
		{
			return compb+1;
		}
		if ((Gens[compb]==2)or(Gens[compb]==4)or(Gens[compb]==6)or(Gens[compb]==10)or(Gens[compb]==12)or(Gens[compb]==13))
		{
		   	return comp(compb+1,y);																		 
		}
		if ((Gens[compb]==5)or(Gens[compb]==8)or(Gens[compb]==9))
		{
			long p=comp(compb+1,y);
			return comp(p+1,y);
		}
		if ((Gens[compb]==7))
		{
			long t=compb;
			while (Gens[t]!=11)
			{
				t++;
			}
			y=t+1;
			t=comp(t,y);
			return t;
		}
		if (Gens[compb]==11){
			long t=compb;
			while (Gens[t]!=15)
			{
				t++;
			}
			return t;
		}
		return compb;
	}
};


