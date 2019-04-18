#include <ctime>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <unistd.h>

using namespace std;

struct GenCode
{
	string Gens="";
	long fit;
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
			long t=y+1;
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
		s[0]=(char)(rand()%5+50);
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
			long p=rand()%8;
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
			r=r+(char)(rand()%5+50);
			r=r+A.Gens.substr(i+1,A.Gens.length()-i);
		}
		A.Gens=r;
	}
}

void Mut_all(GenCode &A)
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
	while (p<0.5);
}

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
				j=B.comp(j,y)+1;
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
				b--;
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
				b1--;
			}
			k++;
		}
	}
	GenCode tmp;
	tmp.Gens=A.Gens.substr(0,i)+B.Gens.substr(j,B.Gens.length()-j);
	return tmp;
}

string show(GenCode A,long &i)
{
	string r=" ";
	if (A.Gens[i]=='1')
	{
		r[0]='A';
		r=r+A.Gens[i+1];
		i+=2;
		return r;
	}
	if (A.Gens[i]=='2')
	{
		i++;
		r="++"+show(A,i);
		return r;
	}
	if (A.Gens[i]=='3')
	{
		i++;
		r="--"+show(A,i);
		return r;
	}
	if (A.Gens[i]=='4')
	{
		i++;
		r="cin >> "+show(A,i);
		return r;
	}
	if (A.Gens[i]=='5')
	{
		i++;
		r="cout << "+show(A,i)+"<<endl";
		return r;
	}
	if (A.Gens[i]=='6')
	{
		i++;
		r=show(A,i)+"="+show(A,i);
		return r;
	}
	if (A.Gens[i]=='7')
	{
		i++;
		r="("+show(A,i)+")>("+show(A,i)+")";
		return r;
	}
	if (A.Gens[i]=='8')
	{
		i++;
		r="("+show(A,i)+")!=("+show(A,i)+")";
		return r;
	}
	if (A.Gens[i]=='9')
	{
		i++;
		r="while(("+show(A,i)+")and("+show(A,i)+")){ \n if(clock()*1.0/CLOCKS_PER_SEC>0.05){break;} ";
		return r;
	}
	if (A.Gens[i]=='B')
	{
		r="}";
		i++;
		return r;
	}
}

void rout(GenCode A)
{
	ofstream fout("Code.cpp");
	fout<<""
	    "#include <iostream>\n"
	    "#include <cmath>\n"
	    "#include <ctime>\n\n"

	    "using namespace std;\n\n"

	    "int main()\n"
	    "{\n"
	    "freopen(\"ofile.txt\",\"w\",stdout);\n"
	    "freopen(\"ifile.txt\",\"r\",stdin);\n"
	    "long A2=0;\n"
	    "long A3=0;\n"
	    "long A4=0;\n"
	    "long A5=0;\n"
	    "long A6=0;\n"
	    "long A7=0;\n"
	    "long A8=0;\n"
	    "long A9=0;\n";
	long i=0;
	while (i<A.Gens.length())
	{
		fout<<show(A,i)<<";"<<endl;
	}
	fout<<"return 0;\n}";
	fout.close();
}

void gen(std::vector<std::vector<long long>> & a,
         std::vector<unsigned long long> & x)
{
	long n=3;
	long h=0;
	vector<long long>p;
	while (h<n)
	{
		p.clear();
		long j=rand()%10+1;
		long u=rand()%200;
		long i=0;
		bool t=false;
		long ps=-1;
		while (i<j)
		{
			if ((rand()%(j-i))or(t))
			{
				p.push_back(rand()%200);
			}
			else
			{
				t=true;
				p.push_back(u);
				ps=i;
			}
			i++;
		}
		x.push_back(ps);
		a.push_back(p);
		h++;
	}
}


unsigned long long tester(
  const char * ifile,
  const char * ofile,
  const std::vector<std::vector<long long>> & a,
  const std::vector<unsigned long long> & x
)
{
	system("g++ Code.cpp -o main.exe");
	char check[1000000];
	std::vector<unsigned long long> y(a.size());

	unsigned long long unic_ans = 0;
	unsigned long long r_ans = 0;

	for(unsigned long long i = 0; i < a.size(); ++i)
	{

		ofstream istream(ifile);

		istream << a[i].size() << '\n';
		for(unsigned long long j = 0; j < a[i].size(); ++j)
		{
			istream << a[i][j] << ' ';
		}


		if (!system("main.exe"))
		{

			ifstream ostream(ofile,ios::in);

			ostream >> y[i];

			y[i]=0;

			unic_ans += !check[y[i]];
			r_ans += y[i] == x[i];

			check[y[i]] = true;
		}
		else return -1;
	}

	return r_ans + unic_ans;
}

unsigned long long fitness(
  const char * ifile,
  const char * ofile,
  const std::vector<std::vector<long long>> & a,
  const std::vector<unsigned long long> & x
)
{
	return tester(ifile, ofile,  a, x);
}

int main()
{
	srand(time(0));
	long am=4;//Number of remaining after selection
	GenCode *B=new GenCode[am];
	multimap<long,GenCode>r;
	vector<vector<long long>> a;
	vector<unsigned long long> x;
	//Test generator;
	long n=100;//Number of iterations;
	long i=0;
	while (i<am)
	{
		long t=0;
		while (t<10)
		{
			add(B[i]);
			t++;
		}
		i++;
	}
	i=0;
	long k=0;
	while (i<n)
	{
		r.clear();
		a.clear();
		x.clear();
		gen(a,x);
		k=0;
		while (k<am)
		{
			rout(B[k]);
			B[k].fit=fitness("ifile.txt","ofile.txt",a,x);
			remove("Code.cpp");
			r.insert(make_pair(-B[k].fit,B[k]));
			k++;
		}
		k=0;
		GenCode tmp;
		while (k<am-1)
		{
			tmp=cross(B[k],B[k+1]);
			rout(tmp);
			tmp.fit=fitness("ifile.txt","ofile.txt",a,x);
			r.insert(make_pair(-tmp.fit,tmp));
			remove("Code.cpp");
			k++;
		}
		tmp=cross(B[k],B[0]);
		rout(tmp);
		tmp.fit=fitness("ifile.txt","ofile.txt",a,x);
		r.insert(make_pair(-tmp.fit,tmp));
		remove("Code.cpp");
		k=0;
		while (k<am)
		{
			tmp=B[k];
			Mut_all(tmp);
			rout(tmp);
			tmp.fit=fitness("ifile.txt","ofile.txt",a,x);
			r.insert(make_pair(-tmp.fit,tmp));
			remove("Code.cpp");
			k++;
		}
		k=0;
		while (k<am)
		{
			tmp=(*r.begin()).second;
			r.erase(r.begin());
			B[k]=tmp;
			k++;
		}

		cout<<B[0].fit;
		i++;
	}
	rout(B[0]);
}


