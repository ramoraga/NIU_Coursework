#include "person.h"
#include <string>

using std::string;

class Student : public Person
{
	private:
		string id;
		double gpa = 0.0;

	public:
		Student(const string&, int, const string&, double);
		virtual int sleep();
		virtual void study(int);
		
};

