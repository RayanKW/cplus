### Object oriented programming

#### Classes

- classes are fundamental and without which we cannot be able to write any OOP program.
- it is an abstract data type that is defined by the user which has object(s) and function(S) that are used to work with it.
- has pole and the functions are called methods.
  - the general outlook is:
    class<name>{
    private: here we define private methods and variables that are obbly acccesible inside this class

        public: here we define methods and variables that are accessible.
        }

- this private public/private enforces encapsulation and security plus data integrity.

##### Class fields

- class fields are:
  - they can have any other type than the type of the same class, but they are initialised only once using the constructor.
  - they can be described with the const modifier but they are initialized only once (using the constructor) and cannot be change
  - they can be described with static modifierbut not as auto, ext and register
- classes can be global(described outside any block) and local(declared inside a block)

##### features of local classes.

- inside local classes you can use type, static and ext variables, ext functions and enumeration objs from the scope in which it is
  descibed; it is forbiden to use automatic vars from this scope
- A local class cannot have a static element
- the methids of this class can only be described inside the class
- if one class is nested in another class they do not have any special access rights to each other's elementsand can access them
  according to the general rules.
