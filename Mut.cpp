#include "Mut_Del.cpp"
#include "Mut_add.cpp"
#include "Cross.cpp"
#include "Const.cpp"
#include <ctime>

int main()
{
	freopen("Code.cpp", "w", stdout);
	srand(time(0));
	GenCode A,B,R;
	long b=0;
	long n=40;
	while (n>0)
	{
		add(A);
		n--;
	}
	if (b!=0)
	{
		A.Gens=A.Gens+"B";
	}
	b=0;
	n=40;
	while (n>0)
	{
		add(B);
		n--;
	}
	if (b!=0)
	{
		B.Gens=B.Gens+"B";
	}

	R=cross(A,B);
	cout<<endl;
	n=3;
	while (n>0)
	{
		Mut_all(R);
		n--;
	}
	cout<<endl;
	rout(R);
}

unsigned long long tester(
	const char * pfile,
	const char * ofile,
	const char * ifile,
	const std::string & prog,
	const std::vector<std::vector<long long>> & a,
	const std::vector<unsigned long long> & x
)
{
	std::ofstream pstream(pfile);
	
	pstream << prog << '\n';
	
	system("gnome-terminal -x sh -c 'g++ -std=c++17 -o main *.cpp'");
	
	char check[(int)1e9];
	std::vector<unsigned long long> y(a.size());
	
	unsigned long long unic_ans = 0;
	unsigned long long r_ans = 0;
	
	for(unsigned long long i = 0; i < a.size(); ++i)
	{
		std::ifstream ostream(ofile);
		std::ofstream istream(ifile);
		
		istream << a[i].size() << '\n';
		for(unsigned long long j = 0; j < a[i].size(); ++i)
		{
			istream << a[i][j] << ' ';
		}
		
		system("gnome-terminal -x sh -c './main'");
		
		ostream >> y[i];
		
		unic_ans += check[y[i]];
		r_ans += y[i] == x[i];
		
		check[y[i]] = true;
	}
	
	return r_ans + unic_ans;
}

unsigned long long fitness(
	const char * pfile,
	const char * ofile,
	const std::string & prog,
	const std::vector<std::vector<long long>> & a,
	const std::vector<unsigned long long> & x
)
{
	return tester(pfile, ofile, prog, a, x);
}