// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Stack
//


template <typename T>
Stack <T>::Stack (void)
{
	arr.data_ = 0;
	arr.cur_size_ = 0;
	arr.max_size_ = 0;
}

//
// Stack
//
template <typename T>
Stack <T>::Stack (const Stack & stack)
{
	arr.resize(stack.size());
	for (int i = 0; i < arr.size(); i++) {
		arr.set(i, stack.arr.get(i));
	}
}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void)
{
	arr.~Array();
}

//
// push
//
template <typename T>
void Stack <T>::push(T element)
{
    // COMMENT Creating new copy of the array just to push the element is very
    // expensive. You should find a better design that will be less expensive.

	//RESPONSE: Instead of creating a temp Queue, I used the Resize Method from the
	//Aggregated Array to add an extra index to the end of the Queue. Furthermore,
	//I used the Aggregated Array's set() method to move each element +1 indexes over. 
	//Lastly, the new element is added to index 0 of the resized Array/Stack.
    
	int j = 1;
	arr.resize(arr.size() + 1);

	for (int i = arr.size(); i < 1; i--) {
		arr.set(i, arr.get(arr.size() - j));
		j++;
	}

	arr.set(0, element);

}

//
// pop
//
template <typename T>
void Stack <T>::pop (void)
{
    // COMMENT Creating new copy of the array just to pop the element is very
    // expensive. You should find a better design that will be less expensive.

	//RESPONSE: Changed from creating a Copy Array to moving each element -1 indexes
	//using the Aggregated Array's set method. Furthermore, after each element has been
	//moved, the resize method shorters the size of the Stack.
    
	for (int i = 0; i < arr.size()-1; i++) {
		arr.set(i, arr.get(i+1));
	}

	arr.resize(arr.size() - 1);

	
}


//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{

	arr.resize(rhs.size());
	for (int i = 0; i < arr.size(); i++) {
		arr.set(i, rhs.arr.get(i));
	}
}

//
// clear
//
template <typename T>
void Stack <T>::clear(void)
{
	for (int i = 0; i < arr.size(); i++) {
		arr.set(i, 0);
	}
	arr.resize(0);
}


