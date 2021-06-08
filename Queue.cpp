
// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

template <typename T>
Queue <T>::Queue(void) {
	
}

template <typename T>
Queue <T>::Queue(const Queue<T> & q) {
	arr.resize(q.arr.cur_size_);

	for (int i = 0; i < arr.size(); i++) {
		arr.set(i, q.arr.get(i));
	}
}

template <typename T>
Queue <T>::~Queue(void) {
	arr.~Array();	
}

template <typename T>
const Queue <T> & Queue<T>::operator = (const Queue <T> & rhs) {
	
	arr.resize(rhs.cur_size_);

	for (int i = 0; i < arr.size(); i++) {
		arr.set(i, rhs.arr.get(i));
	}
}

template <typename T>
void Queue <T>::enqueue(T element) {
    // COMMENT This approach can work, but its design is very expensive. You
    // should find a better design that tries to use as much space as possible
    // while minimizing the amount of copying that must occur.

	//RESPONSE: Instead of creating a temp Queue, I used the Resize Method from the
	//Aggregated Array to add an extra index to the end of the Queue. Furthermore,
	//I used the Aggregated Array's set() method to move each element +1 indexes over. 
	//Lastly, the new element is added to index 0 of the resized Array/Queue.
    
	
	int j = 1;
	arr.resize(arr.size() + 1);

	for (int i = arr.size(); i < 1; i--) {
		arr.set(i, arr.get(arr.size() - j));
		j++;
	}

	arr.set(0, element);
}

template <typename T>
void Queue <T>::dequeue(void){
    // COMMENT This line of code will not compile if T cannot be assigned
    // the value of NULL, which should never be used.

	//RESPONSE: Changed from setting data to NULL to using the Aggregated Array's resize method.
	arr.resize(arr.size()-1);
}


template <typename T>
void Queue <T>::clear(void) {
	for (int i = 0; i < arr.size(); i++) {
		arr.set(i, 0);
	}
	arr.resize(0);
}
