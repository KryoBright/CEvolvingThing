//#include "gef.cpp"

string genr(int h)
{
	if ((h!=9)and(h!=11)and(h!=1))
	{
		h=rand()%h+1;
	}
	if (h==11)
	{
		h=rand()%5+2;
	}
	string s=" ";
	if (h==1)
	{
		s[0]=(char)(rand()%8+50);
		s="1"+s;
		return s;
	}
	else if (h<6)
	{
		s[0]=(char)(h+48);
		s=s+genr(1);
		return s;
	}
	else if (h==6)
	{
		s="6"+genr(1)+genr(3);
		return s;
	}
	else if (h<9)
	{
		s[0]=(char)(h+48);
		s=s+genr(3)+genr(3);
		return s;
	}
	else if (h==9)
	{
		s="9"+genr(8)+genr(8);
		return s;
	}
}

void add(GenCode &A)
{
	string r="";
	if (A.Gens.size()<200)
	{
		if (A.Gens.size()==0)
		{
			A.Gens=A.Gens+genr(11);
		}
		else
		{
			long e=rand()%100;
			long y=0;
			long i=0;
			while (e>0)
			{
				e--;
				y=0;
				A.comp(i,y);
				if (y==0)
				{
					i=A.comp(i,y)+1;
				}
				else
				{
					i=y+1;
				}
				if (i==A.Gens.size())
				{
					i=0;
				}
			}
			if (i!=0)
			{
				r=A.Gens.substr(0,i);
			}
			long b=0;
			long p=rand()%20;
			if (p==0)
			{
				r=r+genr(9)+"B";
				b++;
			}
			else
			{
				r=r+genr(11);
			}
			r=r+A.Gens.substr(i,A.Gens.length()-i);
			A.Gens=r;
		}
	}
}

void rep(GenCode &A)
{
	if (A.Gens.size()!=0)
	{
		long e=rand()%200;
		long y=0;
		long i=0;
		while (e>0)
		{
			e--;
			if ((A.Gens[i]=='9')or(A.Gens[i]=='B'))
			{
				e++;
			}
			i++;
			if (i==A.Gens.size())
			{
				i=0;
			}
		}
		string r=A.Gens.substr(0,i);
		if ((i==0)or(A.Gens[i-1]!='1'))
		{
			r=r+genr((int)A.Gens[i]-48);
			r=r+A.Gens.substr(A.comp(i,y)+1,A.Gens.length()-A.comp(i,y));
		}
		else
		{
			r=r+(char)(rand()%9+49);
			r=r+A.Gens.substr(i+1,A.Gens.length()-i);
		}
		A.Gens=r;
	}
}

Mut_all(GenCode &A)
{
	double p;
	do
	{
		p=rand()*1.0/RAND_MAX;
		int var=rand()%3;
		if (var==0)
		{
			add(A);
		}
		if (var==1)
		{
			Mut_Del(A);
		}
		if (var==2)
		{
			rep(A);
		}
	}
	while (p<0.01);
}
