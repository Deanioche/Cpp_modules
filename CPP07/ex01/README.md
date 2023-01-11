### **CPP07_ex01**

**expected question**

1. Can you explain how the iter function template works? How does it iterate over the elements of an array and apply a function to each element?
	- The iter function template works by iterating over each element of an array using a for loop. It takes the pointer to an array, the length of the array, and a pointer to a function as its parameters. The function pointer is used to apply a function to each element of the array. The function passed to iter is called with each element of the array as an argument, modifying the element as necessary.

2. Can you explain how the display function template works? How does it display the elements of an array passed to it?
	- The display function template is a simple function that takes a single argument of any type T and output it to the console by overloading the operator <<, this way any type T that has an overloaded operator << will be able to be displayed by this function.

3. What is the purpose of the function pointer being passed to the iter function? How is it used to apply a function to each element of an array?
	- The purpose of the function pointer being passed to the iter function is to allow the user to apply a specific operation to each element of the array. This function pointer is used as a callback function which will be applied to each element of the array by iter function.

---

**key points**

The iter function is a generic function template that can work with arrays of any type, as long as the type has a suitable output operator defined.

The iter function takes a pointer to an array, the length of the array, and a pointer to a function. The function pointer passed to iter is used to apply a function to each element of the array.

The display function is also a generic function template which takes a single argument of any type and output it to the console.

The example uses several specific arrays of different types (int, char, double, float, std::string) and for each of them it calls iter function with an appropriate display function.

With the current implementation, the iter function is able to work only with arrays and the length has to be computed by the caller.