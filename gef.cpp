#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct GenCode
{
	string Gens="";
	long comp(long compb,long &y)
	{
		if (compb>=Gens.size())
		{
			return Gens.size();
		}
		if (Gens[compb]=='1')
		{
			return compb+1;
		}
		if ((Gens[compb]=='2')or(Gens[compb]=='3')or(Gens[compb]=='4')or(Gens[compb]=='5'))
		{
			return comp(compb+1,y);
		}
		if ((Gens[compb]=='6')or(Gens[compb]=='7')or(Gens[compb]=='8'))
		{
			long p=comp(compb+1,y);
			return comp(p+1,y);
		}
		if (Gens[compb]=='9')
		{
			long p=comp(compb+1,y);
			y=comp(p+1,y);
			long t=y;
			while((Gens[t]!='B')and(t<Gens.length()))
			{
				t++;
			}
			if (t==Gens.length())
			{
				t--;
			}
			return t;
		}
		return compb;
	}
};


