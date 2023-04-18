#include <iostream>
#include <fstream>
#include <windows.h>
#include <stdlib.h>
#include <cwchar>
#include <vector>
#include <stdio.h>
#include <ctime>
#include <map>
#include <string>
using namespace std;
class ship
{
  private: 
    int x, y, n, m, f, x1, y1, x2, y2, task, laivas, sk, k;
    char X[15][15], Y[15][15], w;
    vector <int> vec;
    vector <char> vec1;
    map <char, int> mp;
    const char* a;
  public:   
	ship():x(0),y(0),n(0),m(0),f(0),a(0),x1(0),y1(0),x2(0),y2(0),task(10),laivas(0),sk(0),k(0),w(0){}
	ship(int a,int b,int c):x(a),y(b),n(c){}
    ~ship()
	{
	delete []a;
	}
    void ivedn()
	{
    cin>>n;
    system("CLS");
    }
   	void nlygis()
	{
    	cout<<n<<" lygis"<<endl;
    }
    void laivusk()
	{
	int g, max=0, k=0;
	if(n==1) a="1lvl.txt";
    else if(n==2) a="2lvl.txt";
    else if(n==3) a="3lvl.txt";
    else if(n==4) a="4lvl.txt";
    else if(n==5) 
	{
    	m=vec[0];
    	if(m==1) a="1lvl.txt";
    	if(m==2) a="2lvl.txt";
    	if(m==3) a="3lvl.txt";
    	if(n==4) a="4lvl.txt";
	}
    ifstream df (a);
    df>>x>>y;
  	for(int i=0; i<x*y; i++) 
  	{
    	df>>w;
    	mp[w]++;
    	vec1.push_back(w);
 	}
  	for (auto it=mp.begin(); it!=mp.end(); it++){
    if(it->second>max){
      max=it->second;
      g=it->first;
    	} 
  	}
  	for(int i=0; i<vec1.size(); i++)
  	if(vec1[i]!=g) k++;
  		df.close();
		df.clear();
	}
    void random()
	{
    	srand(time(NULL));
    	for (int i=0; i<5; i++){
        sk=rand() % 4+1;
        vec.push_back(sk);
		}
	}
    void startas()
	{
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;
	cfi.dwFontSize.Y = 32;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	std::wcscpy(cfi.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
		cout<<"Noredami pradeti spauskite enter"<<endl<<endl<<endl;
		cin.ignore();
		system("CLS");
	}
    void lygis()
	{
    if(n==1) a="1lvl.txt";
    else if(n==2) a="2lvl.txt";
    else if(n==3) a="3lvl.txt";
    else if(n==4) {
    	m=vec[0];
    	if(m==1) a="1lvl.txt";
    	if(m==2) a="2lvl.txt";
    	if(m==3) a="3lvl.txt";
	}
    ifstream df (a);
    df>>x>>y;
    for(int i=0; i<x; i++)
	{
    	for(int j=0; j<y; j++)
		{
    		df>>X[i][j];
			}
	}
		df.close();
		df.clear();
	}
	void uzdengimas()
	{
		ifstream df ("blank.txt");
		df>>x2>>y2;
		for(int i=0; i<x2; i++)
		{
    		for(int j=0; j<y2; j++)
			{
    			df>>Y[i][j];
    		}
    	}
    	df.close();
    	df.clear();
	}
	void operator ++() //lygio nr.
	{
		HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
		if(n==1){
			SetConsoleTextAttribute(h, 6);
			cout<<"*** "<<n<<" lygis ***"<<endl;
			SetConsoleTextAttribute(h, 7);
		}
		else if(n==2){
			SetConsoleTextAttribute(h, 8);
			cout<<"*** "<<n<<" lygis ***"<<endl;
			SetConsoleTextAttribute(h, 7);
		}
		else if(n==3){
			SetConsoleTextAttribute(h, 10);
			cout<<"*** "<<n<<" lygis ***"<<endl;
			SetConsoleTextAttribute(h, 7);
		}
		else if(n==4){
			SetConsoleTextAttribute(h, 13);
			cout<<"*** "<<n<<" lygis ***"<<endl;
			SetConsoleTextAttribute(h, 7);
		}
		else if(n==5){
			SetConsoleTextAttribute(h, 13);
			cout<<"*** "<<sk<<" lygis ***"<<endl;
			SetConsoleTextAttribute(h, 7);
		}
	}
	void isvedlygis()
	{
    for(int i=0; i<x; i++)
	{
    	for(int j=0; j<y; j++)
		{
    		cout<<Y[i][j]<<" ";
			}
		cout<<endl;
		}
	}
	void menu()
	{
    	cout<<"*******************************"<<endl;
    	cout<<"*******************************"<<endl;
    	HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, 9);
    	cout<<"**        LAIVU MUSIS        **"<<endl;
    	cout<<"**     turite 10 spejimu     **"<<endl;
    	cout<<"**        # - laivas         **"<<endl;
    	cout<<"**        . - vanduo         **"<<endl;
    	SetConsoleTextAttribute(h, 7);
    	cout<<"* * * * * * * * * * * * * * * *"<<endl;
    	SetConsoleTextAttribute(h, 6);
    	cout<<"**        1 - 1 lygis        **"<<endl;
    	SetConsoleTextAttribute(h, 8);
    	cout<<"**        2 - 2 lygis        **"<<endl;
    	SetConsoleTextAttribute(h, 10);
    	cout<<"**        3 - 3 lygis        **"<<endl;
    	SetConsoleTextAttribute(h, 13);
    	cout<<"**        4 - 4 lygis        **"<<endl;
    	SetConsoleTextAttribute(h, 7);
    	cout<<"**   5 - atsitiktinis lygis  **"<<endl;
    	cout<<"*******************************"<<endl;
    	cout<<"*******************************"<<endl;
    	cout<<"       pasirinkite lygi:   ";
	}
	void pabaiga()
	{
		HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
		cout<<"*******************************"<<endl;
		cout<<"*******************************"<<endl;
		SetConsoleTextAttribute(h, 9);
		cout<<"**       MUSIO PABAIGA       **"<<endl;
		SetConsoleTextAttribute(h, 7);
		if(laivas==k-x-y+1) {
			SetConsoleTextAttribute(h, 14);
			cout<<"**    sveikiname laimejus!    **"<<endl;
			SetConsoleTextAttribute(h, 7);
		}
		else if(laivas==1) cout<<"**    pataikete:  "<<laivas<<" karta    **"<<endl;
		else if(laivas==0||laivas>9) cout<<"**    pataikete:  "<<laivas<<" kartu    **"<<endl;
		else cout<<"**    pataikete:  "<<laivas<<" kartus   **"<<endl;
		cout<<"*******************************"<<endl;
		cout<<"*******************************"<<endl;
	}
	int get_task()
	{
		HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, 8);
    	if(task>0&&laivas!=k-x-y+1) cout<<"Liko bandymu: "<<task<<endl;
    	SetConsoleTextAttribute(h, 7);
    	if(task==0) system("CLS");
      	return task;
    }
	void operator ++(int) //spejimas
	{
	cout<<"Iveskite eil. ir stulp. numerius: ";
	cin>>x1>>y1;
	if(x1<0||y1<0) {
		system("CLS");
		throw "ivedete neigiama numeri!   ";
	}
	if(x1>=x||y1>=y) {
		system("CLS");
		throw "per didelis numeris!    ";
	}
	if(x1==0||y1==0) {
		system("CLS");
		throw "nulinis numeris!    ";
	}
	else if(X[x1][y1]=='0'){
    	Y[x1][y1]='#';
    	X[x1][y1]='#';
 		task=task+2;
    	laivas=laivas+1;
		}
    else if(X[x1][y1]!='0' && X[x1][y1]!='L'){
    	Y[x1][y1]='.';
    	X[x1][y1]='.';
    	task=task-1;
		}
	system("CLS");	 
	}
	void pasirin()
	{
    	cout<<"*******************************"<<endl;
    	cout<<"**     1 - grizti i menu     **"<<endl;
		cout<<"**     0 - baigti zaisti     **"<<endl;
		cout<<"*******************************"<<endl;
		cin>>f;
	}
    int get_laivas()
	{
      return laivas;
	}
	int get_k()
	{
      return k-x-y+1;
    }
	int get_f()
	{
		return f;
	}
	int get_sk()
	{
		return sk;
	}
};
int main() 
{
	ship m;
	m.startas();
	m.menu();
  	m.ivedn();
  	m.random();
  	m.lygis();
  	m.laivusk();
  	m.uzdengimas();
  	++m;
  	m.isvedlygis();
  	try{
  		while(m.get_task()>0)
		{
  			m++; //spejimas
  			++m; //lygio nr.
  			m.isvedlygis();
		}
	}
  	catch(const char x[]) 
	{
  		HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, 4);
  		cout<<"Klaida: "<<x;
  		SetConsoleTextAttribute(h, 7);
  		++m;
  		m.lygis();
  	  	m.isvedlygis();
  		while(m.get_task()>0)
		{
  			m++; //spejimas
  			++m; //lygio nr.
  			m.isvedlygis();
		}
	  }
	if(m.get_task()==0)
	{
		m.pabaiga();
		m.isvedlygis();
		m.pasirin();
		if(m.get_f()==1) main();
		else return 0;
	}  
}
