#pragma once
// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef _CS363_BASE_ARRAY_H	
#define _CS363_BASE_ARRAY_H	

#include <cstring>		//for size_t definition

template <typename T>
class Array_Base {

	typedef T type;

public: 
	//Default Constructor
	// Array_Base(void);

	/*
	* Copy Constructor
	* 
	* @param[in]		Source Array
	*/
	// Array_Base(const Array_Base & arr);

	/*
	* Initializing Constructor
	* 
	* @param[in]		Size or Element to Fill Array
	*/
	// Array_Base(T val);

	//Destructor
	// virtual ~Array_Base(void) {};

	/*
	* Assignment Operation
	* 
	* @param[in]		rhs			Right-Hand Side of Equal Sign
	* @return			Reference to Self	 
	*/
	const Array_Base & operator = (const Array_Base & rhs);


	/*
	* Returns the Current size of the Array
	* 
	* @return	Array Current Size
	*/
	virtual size_t size(void) const = 0;

	/*
	* Returns the Max Size of the Array
	* 
	* @return	Array Max Size
	*/
	virtual size_t max_size(void) const = 0;

	/*
	* Get the element at the given index. If the index is not within the range
	* of the array, then std::out_of_range is thrown
	* 
	* @param[in]		Index			Zero-based Location
	* @return			element
	* @exception		std::out_of_range	
	*/
	 T & operator [] (size_t index);

	/*
	* @overload
	* 
	* The returned element is not modifiable
	*/
	 const T & operator [] (size_t index) const;

	/*
	* Get the Element at the given index. If the index isn't within range of 
	* the array, then std::out_of_range is thrown
	* 
	* @param[in]		Index			Zero-based Location
	* @return		Element at Index	
	* @exception	std::out_of_range
	*/
	virtual T get (size_t index) const = 0;

	/*
	* Set the element at the given index. If the index isn't within the range
	* of the array then a std::out_of_range will be thrown
	* 
	* @param[in]		Index				Zero-based Location
	* @param[in]		element				
	* @exception		std::out_of_range
	*/
	virtual void set(size_t index, T element) = 0;

	/*
	* Find the index of the given element. If the element isn't found within
	* the array, -1 is returned. If the element is found within the array then
	* the element's index is returned.
	* 
	* @param[in]			Element			
	* @return				Index			Zero-based Location
	* @return				-1				Element not in Array
	*/
	 virtual int find (T element) const = 0;
	
	/*
	* @overload
	* 
	* This version allows you to specify the start index of the search.
	* If the start index isn't within the range of the array then a
	* std::out_of_range exception will be thrown.
	* 
	* @param[in]			Element
	* @param[in]			Starting Index
	* @return				-1					Element Not In Array
	* @exception			std::out_of_range	
	*/
	 virtual int find(T element, size_t start) const = 0;

	/*
	* Test Array for Equality
	* @param[in]			rhs			Right-Hand Side of Equal Sign
	* @return				True		Left-Hand & Right-Hand Sides are Equal
	* @return				False		Left-Hand & Right-Hand Sides aren't Equal
	*/
	 bool operator == (const Array_Base & rhs) const;

	/*
	* Test Array for Inequality
	* @param[in]			rhs			Right-Hand Side of Equal Sign
	* @return				True		Left-Hand & Right-Hand Sides are Equal
	* @return				False		Left-Hand & Right-Hand Sides aren't Equal
	*/
	 bool operator != (const Array_Base & rhs) const;

	/*
	* Add element to the Array. If the Array is full, a std::out_of_range exception
	* will be thrown
	* 
	* @param[in]			Element			
	* @exception			std::out_of_range
	*/
	 virtual void fill(T element) = 0;

	//Reverses the Elements of the Array
	 virtual void reverse() = 0;


protected:
	//Pointer to Array Data/Elements
//	T* data_;

	//Current size of the Array
//	size_t cur_size_;

	//Max Size of the Array
//	size_t max_size_;

};

#endif //!define _ARRAY_BASE_H_