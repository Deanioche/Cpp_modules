### **cpp07**

[[ **ex00** ]](./ex00)
- Function Template
    - When implementing a function, it is clear that what the function does, but the datatype is ambiguous. ( Any type can be called as a argument of the function. )

        함수를 구현할 때, 기능은 확실하지만 데이터 타입은 모호하게 만들어 모든 타입에 대해 사용할 수 있게 만들 수 있다.

- :: operator
    - there is no difference whether or not the "::" is used before the function name.

        함수 이름 앞에 "::"가 붙든 안붙든 차이가 없다.

    - The :: operator is used to specify the global namespace, but since the functions are defined in the global namespace by default, it is not necessary to include the :: operator before the function names.

        :: 연산자는 글로벌 네임스페이스를 지정하는 데 사용되지만 함수는 기본적으로 글로벌 네임스페이스에 정의되므로 함수 이름 앞에 :: 연산자를 포함할 필요는 없다.

    - The main point of using :: in this code is that the programmer wants to make sure that these functions are not being overriden by any other function with the same name in the current or any nested namespace, by making a call to the global one.

        이 코드에서 ::를 사용하는 주된 이유는 프로그래머가 글로벌 네임스페이스에 호출을 함으로써 현재 네임스페이스나 중첩된 네임스페이스에서 동일한 이름을 가진 다른 함수에 의해 이러한 함수가 재정의되지 않도록 하기 위함이다.

    - Also it's good practice to use the :: operator when calling global functions to avoid confusion, If at some point a new function with the same name is defined in the current namespace, it would take precedence over the global function if the :: operator wasn't used.
        또한 혼동을 피하기 위해 글로벌 함수를 호출할 때 :: 연산자를 사용하는 것이 좋습니다. 어느 시점에서 동일한 이름의 새 함수가 현재 네임스페이스에 정의되면 :: 연산자를 사용하지 않으면 글로벌 함수보다 우선한다.

---

[[ **ex01** ]](./ex01)
- function pointer
    Function pointers are useful when you want to use a callback function to perform an operation, or when you want to pass a function as an argument to another function, like in the example of the iter function provided before, where the callback function is passed as argument, then iter function applies it to each element of the array.

    함수 포인터는 콜백 함수를 사용하여 연산을 수행하거나 이전에 제공된 반복 함수의 예와 같이 함수를 인수로 전달하고 싶을 때 유용하며, 이때 반복 함수는 배열의 각 요소에 적용한다.

    ```c++
    #include <iostream>

    // Function to be used with the function pointer
    void printNumber(int x) {
        std::cout << "The number is: " << x << std::endl;
    }

    int main() {
        // Declaring a function pointer
        void (*pfn)(int);

        // Assigning the address of the function to the function pointer
        pfn = &printNumber;

        // Calling the function using the function pointer
        (*pfn)(5); // Output: "The number is: 5"

        // You can also call the function using the function pointer directly
        pfn(10); // Output: "The number is: 10"
    }
    ```

- print(T const &t)
    로 받는게 있는데, iter는 iterable 객체 안의 값들을 순차로 참조하면서 값을 바꿀수 있어야 하기 때문에 template에 const를 붙이면 안된다.

---

[[ **ex02** ]](./ex02)