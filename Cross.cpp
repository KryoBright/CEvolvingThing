GenCode cross(GenCode A,GenCode B)
{
	long b=0;
	long b1=1;
	long i,j;
	while (b!=b1)
	{
		long e=rand()%100;
		long y=0;
		i=0;
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
			while(A.Gens[i]=='B')
			{
				i++;
			}
			if (i==A.Gens.size())
			{
				i=0;
			}
		}
		j=0;
		e=rand()%100;
		y=0;
		while (e>0)
		{
			e--;
			y=0;
			B.comp(j,y);
			if (y==0)
			{
				i=B.comp(j,y)+1;
			}
			else
			{
				j=y+1;
			}
			while(B.Gens[j]=='B')
			{
				j++;
			}
			if (j==B.Gens.size())
			{
				j=0;
			}
		}
		b=0;
		long k=i;
		while (k<A.Gens.size())
		{
			if (A.Gens[k]=='B')
			{
				b++;
			}
			if (A.Gens[k]=='9')
			{
				b++;
			}
			k++;
		}
		b1=0;
		k=j;
		while (k<A.Gens.size())
		{
			if (A.Gens[k]=='B')
			{
				b1++;
			}
			if (A.Gens[k]=='9')
			{
				b1++;
			}
			k++;
		}
	}
	GenCode tmp;
	tmp.Gens=A.Gens.substr(0,i)+B.Gens.substr(j,B.Gens.length()-j);
	return tmp;
}
