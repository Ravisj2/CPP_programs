
#include <iostream>
using namespace std;
class Atp
{
	int a,b;
	public:
	Atp()
	{
		cout<<"iam in constructor"<<endl;
	}
	void set (int x,int y)
	{
		a=x;
		b=y;
	}
	void display()
	{
		cout<<"a="<<a<<"b="<<b<<endl;
	}
};

int main ()
	Atp *ptr =new Atp;
	ptr->set(255,678);
	ptr->display();
	delete ptr;
	return 0;
	}

