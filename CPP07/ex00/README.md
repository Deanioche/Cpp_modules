**CPP07_ex00**

**expected questions**

1. Can you explain the purpose of the ::swap, ::min, and ::max functions, and why they are implemented as template functions?
    - The ::swap function is a function template that can be used to swap the values of two variables of any type, as long as the type has a copy constructor and a copy assignment operator defined.
    - The ::min and ::max functions are templates that takes two constant references to objects of the same type and returns the one with the smaller/larger value respectively.
    - These functions are implemented as templates because it allows them to be used with any type that supports assignment and comparison operations.

2. How does the swap function template work and why is it more efficient than a manually written swap function for a specific class?
    - The swap function template swaps the values of two variables using a temporary variable. It works by creating a copy of the first variable, storing its value in a temporary variable, then copying the value of the second variable into the first variable, and finally copying the value of the temporary variable into the second variable.
    - It is more efficient than a manually written swap function for a specific class because it can take advantage of move semantics in C++11 and later, which allows moving of resources instead of copying them, resulting in less memory and CPU usage.

3. What are the advantages of using constant references for the arguments in the min and max function templates?
    - By using constant references, the min and max function templates avoid making unnecessary copies of the objects passed to them, which can be both time-consuming and memory-intensive, especially for large or complex objects.
    - Constant references also guarantee that the passed objects are not modified, making the function more predictable and safer.

4. How the include guard '#ifndef','#define','#endif' is working and how it prevents redefinition of function?
    - The include guard is a preprocessor directive that prevents the contents of a header file from being defined multiple times in the same program. This is done by using a preprocessor macro, usually in the form of #ifndef WHATEVER_HPP, #define WHATEVER_HPP, and #endif.
    - At the top of the code the #ifndef checks if the macro WHATEVER_HPP has not been defined yet and #define WHATEVER_HPP declares it, this means that if this file is included again, the preprocessor will not process the contents of the file again and #endif mark the end of this guard.

5. How the code demonstrate the use of the templates and the difference between the int and string types, and why the :: operator is needed?
    - The code demonstrates the use of the template functions by using them to swap values and find the minimum and maximum of int and string types.
    - The code uses the :: operator when calling the functions to explicitly specify the global namespace, in case there are other functions with the same name in the current or any nested namespace. This is a good practice to avoid confusion and to make sure that the global functions are called.