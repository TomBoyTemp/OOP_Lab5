#ifndef Header_H
#define	Header_H
#include <iostream>
#include <string>


class Common
{
public:
	 Common() 
	 {
		 std::cout << "Common\n" << std::endl;
	 }
	 
	 virtual ~Common() 
	 {
		 std::cout << "~Common\n" << std::endl;
	 }

	 virtual void print() const
	 {
		 std::cout << "print_Common\n" << std::endl;
	 }

	 void method1()
	 {
		 std::cout << "method1_Common\n" << std::endl;
		 method2();
	 }
	 virtual void method2()
	 {
		 std::cout << "method2_Common\n" << std::endl;
	 }
	 virtual std::string classname() {
		 return "Common";
	 }
	 virtual bool isA(std::string who) {
		 return (who == "Common");
	 }
private:
};

class Specific_correct: public Common
{
public:
	Specific_correct() {
		std::cout << "Specific_correct\n" << std::endl;
	}
	~Specific_correct() override {
		std::cout << "~Specific_correct\n" << std::endl;
	}
	void print() const  override {
		std::cout << "print_Specific_correct\n" << std::endl;
	}
	void method1()	{
		std::cout << "method1_Specific_correct\n" << std::endl;
		method2();
	}
	void method2() override {
		std::cout << "method2_Specific_correct\n" << std::endl;
	}
private:

};
class Specific_sec : public Common
{
public:
	Specific_sec() {
		std::cout << "Specific_sec\n" << std::endl;
	}
	~Specific_sec() override {
		std::cout << "~Specific_sec\n" << std::endl;
	}
	std::string classname() {
		return "Specific_thr";
	}
	bool isA(std::string who) {
		return (who == "Specific_sec" || Common::isA(who));//Здесь мы должны понимать, что данный объект является производным от общего, поэтому его можно считать общим
	}
	virtual void someMethod()
	{
		std::cout << "someMethode_Specific_sec" << std::endl;
	}
private:

};

class Specific_thr : public Specific_sec
{
public:
	Specific_thr() {
		std::cout << "Specific_thr\n" << std::endl;
	}
	~Specific_thr() override {
		std::cout << "~Specific_thr\n" << std::endl;
	}
	bool isA(std::string who) {
		return (who == "Specific_thr" || Specific_sec::isA(who));
	}
	std::string classname() {
		return "Specific_thr";
	}
	void someMethod() override
	{
		std::cout << "someMethode_Specific_thr" << std::endl;
	}
private:

};
class Common_sec
{
public:
	Common_sec()
	{
		std::cout << "Common_sec\n" << std::endl;
	}
	
	~Common_sec() 
	{
		std::cout << "~Common_sec\n" << std::endl;
	}

	void print() const
	{
		std::cout << "print_Common_sec\n" << std::endl;
	}
	void method1()
	{
		std::cout << "method1_Common_sec\n" << std::endl;
		method2();
	}
	void method2()
	{
		std::cout << "method2_Common_sec\n" << std::endl;
	}

private:

};

class Specific_incorrect: public Common_sec
{
public:
	Specific_incorrect()
	{
		std::cout << "Specific_incorrect\n" << std::endl;
	}
	void print() const 
	{
		std::cout << "print_Specific_incorrect\n" << std::endl;
	}

	~Specific_incorrect() 
	{
		std::cout << "~Specific_incorrect\n" << std::endl;
	}

	void method1()
	{
		std::cout << "method1_Specific_incorrect\n" << std::endl;
		method2();
	}

	void method2()
	{
		std::cout << "method2_Specific_incorrect\n" << std::endl;
	}

private:

};

class Object
{
public:
	Object() {
		std::cout << "Object()\n";
	}
	Object(Object* obj) {
		std::cout << "Object(Object* obj)\n";
	}
	Object(Object& obj) {
		std::cout << "Object(Object& obj)\n";
	}
	~Object() {
		std::cout << "~Object()\n";
	}
	void dump()  {
		std::cout << "dump_Object" << std::endl;
	}

private:

};


class Desc : public Object
{
public:
	Desc() {
		std::cout << "Desc()\n";
	}

	Desc(Desc* obj) {
		std::cout << "Desc(Desc* obj)\n";
	}

	Desc(Desc &obj) {
		std::cout << "Desc(Desc& obj)\n";
	}

	~Desc() {
		std::cout << "~Desc()\n";
	}
private:

};

#endif