//********************
//Matthew Aberegg
//Project 3
//CS 2401
//10/8/2015
//********************
#include "college.h"
#include<cstdlib>
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

/** @file college.cc - defines all of the college.h functions that have not already been previously defined in the college.h class. The implementation of all the functions, constructor, destructor, and copy constructor have all been defined below.
 **/

College::College(std::string s){
	name = s;
	head = NULL;
}


College::~College(){
	node * rmptr;
	while(head != NULL){
		rmptr = head;
		head = head->link();
		delete rmptr;
	}
}

/** Copy constructor allows the college to be set equal to another college. When implemented the function will copyone list of college objects to another until they have been completely copied and the new list is an exact replica of the first list.
 @param other - const College reference object, this is the original list that is being used to create the second list.
 **/
College::College(const College& other){
	if(other.head == NULL){
		head = NULL;
	}
	else{
		node * sptr;
		node * dptr;
		head = new node(other.head->data());
		dptr = head;
		sptr = other.head->link();
		while(sptr != NULL){
			dptr->set_link(new node(sptr->data()));
			dptr = dptr->link();
			sptr = sptr->link();
		}
	}
}

/** This function overwrites the = operator, this will be used throughout the main to set one list to have the same value as another list.
 @param other - other is the list that is being passed through for the second list to become equivalent to.
 @return this - will return the list created by the function
 **/
College& College::operator =(const College& other){
	if(this == &other){
		return * this;
	}
	node * rmptr;
	while(head != NULL){
		rmptr = head;
		head = head->link();
		delete rmptr;
	}
	if(other.head != NULL){
		node * sptr;
		node * dptr;
		head = new node(other.head->data());
		dptr = head;
		sptr = other.head->link();
		while(sptr != NULL){
			dptr->set_link(new node(sptr->data()));
			dptr = dptr->link();
			sptr = sptr->link();
		}
	}
	return * this;
}

/** This function will make it so you can add to the list throughout the main.
 @param c  is a course reference value that is being added to the list.
 There is no return value for this function.
 **/
void College::add(course& c){
	node * previous;
	node * cursor;
	node * newnode;
	node * tmpptr;
	if(head == NULL){
		head = new node(c);
		head->set_link(NULL);
	}else if(head->data() > c){
		cursor = head->link();
		head->set_link(new node(c));
		newnode = head->link();
		newnode -> set_link(cursor);
		previous = head;
		head = newnode;
		head -> set_link(new node (previous -> data()));
		tmpptr = head -> link();
		tmpptr -> set_link(cursor);
		delete previous;
	} else if(head -> data() < c){
		cursor = head;
		while (cursor != NULL && cursor -> data() <= c){ 
			previous = cursor;
			cursor = cursor-> link();
		}	
		if (cursor == NULL){ 
			cursor = new node (c);
			cursor -> set_link(NULL);
			previous -> set_link(cursor);
		}
		else {
			tmpptr = new node (c);
			tmpptr -> set_link(cursor);
			previous -> set_link(tmpptr);
		}
	}
}

/** The remove function allows the user to remove an object from the list.
 @param coursename - is the designated object that the user would like to remove from the list.
 There is no return value for this function
 **/
void College::remove(std::string coursename){
	node * previous;	
	node * cursor;
	if(coursename == head->data().get_course_number()){
		cursor = head;
		head = head->link();
		delete cursor;
	}
	else{
		previous = head;
		cursor = head->link();
		while(cursor != NULL && cursor->data().get_course_number() != coursename){
			previous = cursor;
			cursor = cursor->link();
		}
		if(cursor != NULL){
			previous->set_link(cursor->link());
			delete cursor;
}
}
}

/** The display function allows the user to view all of the courses currently in their list.
 @param outs - the outstream object which allows the function to print to the terminal.
 There are no return values for this function.
 **/
void College::display(std::ostream& outs){
	node * ptr;
	ptr = head;
	while(ptr != NULL){
		outs << ptr->data().get_course_number();
		outs << ", ";
		outs << ptr->data().get_grade();
		outs << ", ";
		outs << ptr->data().get_hours();
		outs << "\n";
		ptr = ptr->link();
	}
	outs << "\n";
}

/** The hours function calculates how many total hours the user is taking with the current classes in their list.
 There are no parameters for this function.
 @return hours - the total numbers of hours of the classes in the list.
 **/
double College::hours(){
	node * ptr;
	ptr = head;
	double hours = 0;
	while(ptr != NULL){
	hours = hours + ptr->data().get_hours();
	ptr = ptr->link();
	}
return hours;
}

/** The gpa function allows the user to calculate their current gpa based off of the classes and grades in their list.
 There are no parameters for this function.
 @return (sum/hours()) - invokes the hours function to calculate how many hours the user currently has to calculate their gpa.
 **/
double College::gpa(){
	node * ptr;
	ptr = head;
	double sum = 0;
	while(ptr != NULL){
	sum = sum + (ptr->data().get_number_grade() * ptr->data().get_hours());
	ptr = ptr->link();
	}
	return (sum / hours());
} 

/** The save function allows the user to save exactly what their list has to file or to the terminal.
 @param outs - the designated destination for this list to save.
 There is no return value for this function.
 **/
void College::save(std::ostream& outs){
	node * ptr;
	ptr = head;
	while(ptr != NULL){
		outs << ptr->data();
		ptr = ptr->link();
	}
}

/** The load function allows the user to access their previously saved list.
 @param ins - the designated place/file name of the list they are trying to access.
 There are no return values for this function.
 **/
void College::load(std::istream& ins){
	course tmp;
	ins >> tmp;
	node * ptr;
	ptr = new node;
	ptr -> set_data(tmp);
	ptr -> set_link(NULL);
	head = ptr;
  while (!ins.eof()){
    ins >> tmp;
		if(ins.eof())break;
		ptr -> set_link(new node);
		ptr = ptr -> link();
    ptr -> set_data(tmp);
		ptr -> set_link (NULL);
  }
}








