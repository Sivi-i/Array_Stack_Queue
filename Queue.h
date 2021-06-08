// -*- C++ -*-

//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
 //==============================================================================

#ifndef _CS363_QUEUE_H_
#define _CS363_QUEUE_H_

#include "Array.h"
#include <exception>

// COMMENT You should use aggregation instead of inheritance since logically
// a queue is not an array.

//RESPONSE: Changed Queue from Direct Array Inheritance to Aggregation

template <typename T>
class Queue  
{
public:

class empty_exception : public std::exception
{
public:
	/// Default constructor.
	empty_exception(void)
		: std::exception() { }

	/**
	 * Initializing constructor.
	 *
	 * @param[in]      msg         Error message.
	 */
	empty_exception(const char* msg)
		: std::exception(msg) { }
};
	//Default Constructor
	Queue(void);

	//Copy Constructor
	Queue(const Queue & q);

	//Destructor
	~Queue(void);

	/*
	* Assignment Operator
	* 
	* @param[in]	rhs				Right-hand side of operator
	* @return		Reference to self
	*/
	const Queue & operator = (const Queue & rhs);

	/*
	*Adds Element to the Top of the List
	* 
	* @param[in]	element
	*/
	void enqueue(T element);


	/**
	 * Remove the top-most element from the stack.
	 *
	 * @exception      empty_exception    The Queue is empty.
	 */
	void dequeue(void);

	//Checks if the Queue is Empty
	bool is_empty(void) const;

	//Number of Elements in the Queue
	size_t size(void) const;

	/// Remove all elements from the Queue.
	void clear(void);


protected:
	Array <T> arr;
};


#include "Queue.inl"

#include "Queue.cpp"

#endif
