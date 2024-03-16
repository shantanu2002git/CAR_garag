
### 1. Encapsulation:
- **Usage**: Encapsulation is evident in the classes `node` and `car`.
  - In the `node` class:
    - Private member variables (`id`, `price`, `name`, `color`, `mileage`, `rating`, `isElectric`, `wheels`) encapsulate the internal state of a car node.
    - Constructor (`node(int id, int price, string name, string color, double mileage, double rating, bool isElectric, int wheels)`) encapsulates the process of initializing a car node.
  - In the `car` class:
    - Private member variable (`head`) encapsulates the head of the linked list of car nodes.
    - Member functions (`isDuplicateID()`, `in()`, `get()`, `remove()`, `list()`) encapsulate operations related to managing the car garage.

### 2. Abstraction:
- **Usage**: Abstraction is employed to hide complex implementation details and provide a simple interface for interacting with objects.
  - In the `car` class:
    - Member functions (`in()`, `get()`, `remove()`, `list()`) abstract away the details of linked list manipulation, allowing users to interact with the garage without needing to understand its internal structure.
    - Users interact with the `car` object using high-level operations such as adding, retrieving, removing, and listing cars, without needing to know how these operations are implemented internally.

### 3. Modularity:
- **Usage**: The code is organized into modular units (classes and functions), promoting code reusability and maintainability.
  - Each class (`node` and `car`) encapsulates related functionality within itself.
  - Each member function in the `car` class performs a specific task, promoting a clear separation of concerns.

### 4. Constructors and Destructors:
- **Usage**: Constructors are used to initialize objects of the `node` class with specific values. Destructors ensure proper cleanup of dynamically allocated memory.
  - Constructor: `node(int id, int price, string name, string color, double mileage, double rating, bool isElectric, int wheels)`
  - Destructor: `~car()`

### 5. Modifiers and Accessors:
- **Usage**: Getters and setters are not explicitly defined in the code, but member functions like `in()`, `get()`, `remove()`, and `list()` serve as accessors and modifiers to interact with the internal state of the `car` class.

### 6. Object Instantiation and Usage:
- **Usage**: Objects of the `car` class (`garage`) are instantiated and used to manage the car garage system.
  - Objects are created using the default constructor: `car garage;`.
  - Member functions of the `car` class are invoked on the `garage` object to perform operations like adding, retrieving, and removing cars.

### 7. Dynamic Memory Allocation:
- **Usage**: Dynamic memory allocation is used to create and manage linked list nodes.
  - `new` operator is used to dynamically allocate memory for new nodes in the `in()` method.
  - `delete` operator is used to deallocate memory for nodes in the destructor (`~car()`).

Overall, the code demonstrates the effective use of object-oriented programming concepts such as encapsulation, abstraction, modularity, constructors/destructors, modifiers/accessors, object instantiation, and dynamic memory allocation to implement a car garage system. These concepts contribute to code organization, reusability, and maintainability.
