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
		r="cout << "+show(A,i);
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
		r="while(("+show(A,i)+")and("+show(A,i)+")){";
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
	cout<<""
	"#include <iostream>\n"
	"#include <cmath>\n\n"
	
	"using namespace std;\n\n"
	
	"int main()\n"
	"{\n"
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
		cout<<show(A,i)<<";"<<endl;
	}
	cout<<"}";
}
