/*****************************************************************************

A Singleton is an elegant way of maintaining global state, but we should always question whether we need global state. Singleton pattern offers several advantages over global variables because it does the following:

1. Enforces that only one instance of the class can be instantiated.
2. Allows control over the allocation and destruction of the object.
3. Provides thread-safe access to the object's global state.
4. Prevents the global namespace from being polluting.



We do not want the singleton by copied so that there is only one instance. This can be achieved by declaring a private copy constructor and a private assignment operator.
The getInstance() method should return a reference rather than a pointer. This blocks a client from deleting the object. Also, by making destructor private, we can achieve the same effect.

****************************************************************/
#include <iostream>

class Singleton
{
public:
	static Singleton& getInstance(); 

private:
	Singleton() {std::cout << "Ctor\n";};
	~Singleton() {std::cout << "Dtor\n";};
	Singleton(const Singleton&);
	const Singleton& operator=(const Singleton&);
	static Singleton instance;
};

Singleton* Singleton::instance = 0;
Singleton& Singleton::getInstance() 
{
	
		if(!instance) 
		{
		instance = new Singleton();
		cout << "getInstance(): First instance\n";
		return instance;
		}
		else 
		{
		cout << "getInstance(): previous instance\n";
		return instance;
		}
}

int main()
{
	Singleton &s1; = Singleton::getInstance();
	Singleton &s2; = Singleton::getInstance();
	return 0;
}