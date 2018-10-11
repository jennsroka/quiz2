//********************
//Matthew Aberegg
//Project 3
//CS 2401
//10/8/2015
//********************

#include <iostream>
#include <fstream>
#include <string>
#include "course.h"
#include "node.h"
/** @file college.h - the header file for the college.cc file. This designates all of the necessary functions for this class. Any functions not defined here will be further defined in the college.cc class.
 **/

#ifndef COLLEGE_H
#define COLLEGE_H


class College{
	public:
	College(std::string s);
	~College();
	College(const College& other);
	College& operator =(const College& other);
	void add(course& c);
	void remove(std::string coursename);
	void display(std::ostream& outs);
	double hours();
	double gpa();
	void save(std::ostream& outs);
	void load(std::istream& ins);
	private:
	std::string name;
	node * head;




};
#endif
