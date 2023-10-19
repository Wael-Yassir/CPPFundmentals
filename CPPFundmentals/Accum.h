#pragma once

template <class T>
class Accum
{
private:
	T total;

public:
	Accum(T start) : total(start) {};
	T operator+=(T const& t) { return total = total + t; }
	T GetTotal() const { return total; }
};


// template specialization allow you to run run specific code for specific type

template <>
class Accum<Person>
{
private:
	int total;

public:
	Accum(int start) : total(start) {};
	int operator+=(Person const& p) { return total = total + p.GetNumber(); }
	int GetTotal() const { return total; }
};