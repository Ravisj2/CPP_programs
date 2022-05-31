#include <iostream>
using namespace std;
class first
{
	private:
	int  prival;
	protected:
	int proval;
	public:
	int pubval;
};
class second: public first
{
	int result;
	public:
	void set ()
	{
		proval=100;
		pubval=200;
		result=proval+pubval;
	}
	void display ()
	{
		cout<<result<<endl;
	}
};
int main()
{
	second obj;
	obj. set();
	obj.display();
	return 0;
}

