# Array, Stack, and Queue
An Array, Stack, and Queue made from scratch using the Proxy Design Pattern as well as Templates in C++. 

The "Array_Base" class is an abstract class which allows for the creation of future Array-type Objects. The "Array" class inherits methods directly from the "Array_Base" class, 
while the "Stack" and "Queue" classes use Aggregation to gain access to the methods of an "Array". Due to each class being made using templates (Array, Stack, and Queue), 
they're able to take different types of primitives and work with them in similar ways. 

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Array Constructors & Methods::

-Default Constructor, 2 Initializing Constructors (One for Determining the initial size of the Array. Another for Determining initial size and the initial Primitive data
member in the Array), Copy Constructor, and Destructor. 


<---E.g. (Size Initialization) Array array(5);   (Size & Data Initialization) Array array(5, 'a');--->

-Assignment Operator (=). Allows the user to Assign the values of one Array to another using the = operator. E.g. Array2 = Array1

-Size. Returns the Current size of the Array.

-Max_Size. Returns the Maximum Size (Largest recorded size of the current Array).

-[] Operator Overload. Returns the data member at the specified location in the Array. E.g. Array[2].

-Get. Returns the data member at the specified index. If the index isn't within the range of the array, a std::out_of_range exception is thrown. E.g. Array.get(1)

-Set. Takes an Index and Data Member and sets the data member to the specified index. If the index isn't within the range of the array, 
a std::out_of_range exception will be thrown. E.g. Array.set(2, 'a')

-Resize. Resizes the current Array. The contents in the Array will remain the same whether the Array is size is increased or decreased.
If the Array is shrunken, the values above the given index will be cleared. If made larger, the contents will remain the same, and the new indexes
will be empty. E.g. Array.resize(5)

-Find. Finds the given primitive in the Array and returns the index in which it's located. If the primitive isn't found, -1 is returned instead. E.g. Array.find('a')
Also has an overloaded version which allows the user to give the initial start index of the search. E.g. Array.find('a', 1)

-bool == Operator. Checks if an Array is the same as another. E.g. if(Array1 == Array2){};

-bool != Operator. Checks if an Array is NOT the same as another. E.g. if(Array1 != Array2){};

-Fill. Adds the given primitive into the Array. E.g. Array.fill('a')

-Shrink. Shrinks the array to reclaim any unused space. E.g. Array.shrink();

-Reverse. Reverses the Contents of the Array. E.g. Array.reverse();

-Slice. Takes an index and returns an Array which contains all data from the index given, to the end of the Array. E.g. Array2 = Array1.slice(3);
Also has an overloaded method which takes both the beginning index and ending index. Returns all data in between (Non-Inclusive) E.g. Array2 = Array1.slice(1, 4);


----------------------------------------------------------------------------------------------------------------------------------------------------------------------------


Stack Constructors & Methods::

-Default Constructor, Copy Constructor, and Destructor.

-Assignment Operator. Allows the user to Assign the values of one Stack to another using the = operator. E.g. Stack2 = Stack1

-Push. Pushes a new element onto the top of the stack. E.g. Stack.push('a');

-Pop. Removes the top most element from the Stack. Throws an exception if the stack is empty. E.g. Stack.pop();

-Top. Returns the element at the top of the stack. If the stack is empty an exception is thrown. E.g. char* dataMember = Stack.top();

-is_empty. Checks to see if the Stack is empty. Returns true if empty or False if not. E.g. Stack.is_empty();

-Size. Returns the number of elements in the stack. E.g. Stack.size();

-Clear. Clears the stack of all Elements. E.g. Stack.clear();

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------


Queue Constructors & Methods:: 

-Default Constructor, Copy Constructor, and Destructor.

-Assignment Operator. Allows the user to Assign the values of one Queue to another using the = operator. E.g. Queue2 = Queue1

-Enqueue. Adds an element to the end of the Queue. E.g. Queue.enqueue('a');

-Dequeue. Removes the Top-Most element from the Queue. E.g. Queue.dequeue();

-is_Empty. Checks to see if the Queue is empty. Returns true if empty or False if not. E.g. Queue.is_empty();

-Size. Returns the number of elements in the queue. E.g. Queue.size();

-Clear. Clears the queue of all Elements. E.g. Queue.clear();



