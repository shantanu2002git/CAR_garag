Detailed description of my project "Vehicle Management System," according to the given code : 

## Project: Vehicle Management System

### Objective:
The Vehicle Management System (VMS) is designed to manage a collection of vehicles in a garage. It allows users to insert, display, edit, and remove vehicles from the garage. The system ensures data encapsulation, inheritance, and polymorphism to create a robust and maintainable codebase.

### Components:
1. **Vehicle Class**:
   - **Attributes**: ID, Price, Name, Color, Mileage, Rating, Electric (boolean), Wheels.
   - **Methods**:
     - Constructor to initialize vehicle attributes.
     - `display()` to output vehicle details.
     - Getter methods to access protected attributes.
     - `updateAttributes()` to update vehicle details.

2. **Car Class**:
   - Inherits from `Vehicle` class.
   - Utilizes the base class constructor to initialize car-specific attributes.

3. **Node Class**:
   - Represents a node in a linked list.
   - Contains a `Vehicle` pointer and a pointer to the next `Node`.

4. **Garage Class**:
   - Manages a collection of vehicles using a singly linked list of `Node` objects.
   - **Methods**:
     - `insertVehicle()`: Adds a new vehicle to the list if its ID is unique.
     - `isDuplicateID()`: Checks for duplicate vehicle IDs.
     - `displayVehicle()`: Displays details of a vehicle by ID.
     - `removeVehicle()`: Removes a vehicle by ID.
     - `listVehicles()`: Lists all vehicles in the garage.
     - `editVehicle()`: Allows editing of a vehicle's attributes by ID.
   - Destructor to clean up dynamically allocated memory.

### Features:
1. **Encapsulation**:
   - Protected members in the `Vehicle` class ensure that vehicle attributes are not directly accessible from outside the class.
   - Public getter methods provide controlled access to these attributes.

2. **Inheritance**:
   - The `Car` class inherits from the `Vehicle` class, demonstrating a simple inheritance model.

3. **Polymorphism**:
   - The `display()` method in the `Vehicle` class is virtual, allowing derived classes to override it if needed.
   - The `Garage` class uses polymorphism to handle vehicles of different types uniformly.

### Functionality:
1. **Inserting Vehicles**:
   - Vehicles can be added to the garage with unique IDs.
   - Duplicate IDs are not allowed.

2. **Displaying Vehicles**:
   - Details of a specific vehicle can be displayed using its ID.
   - All vehicles in the garage can be listed.

3. **Editing Vehicles**:
   - Vehicles' attributes (name, price, color, mileage, rating, electric, wheels) can be edited by their ID.
   - Provides options to update individual attributes or all attributes at once.

4. **Removing Vehicles**:
   - Vehicles can be removed from the garage by their ID.

### Sample Usage:
- Insert several vehicles into the garage.
- Display the details of a specific vehicle.
- List all vehicles in the garage.
- Remove a vehicle by ID and confirm its removal by listing vehicles again.
- Edit a vehicle's attributes and confirm the updates by listing vehicles again.

### Code Usage Example:
```cpp
int main() {
    Garage garage;

    // Sample usage
    garage.insertVehicle(new Car(1, 20000, "Toyota", "Red", 25.5, 4.2, false, 4));
    garage.insertVehicle(new Car(2, 25000, "Honda", "Blue", 28.3, 4.5, true, 4));
    garage.insertVehicle(new Car(3, 30000, "Ford", "Black", 22.1, 4.0, false, 2));
    garage.insertVehicle(new Car(4, 35000, "BMW", "White", 20.7, 4.8, true, 4));
    garage.insertVehicle(new Car(5, 35000, "Audi", "Silver", 18.9, 4.6, true, 4));

    cout << "List of cars in the garage:" << endl;
    garage.listVehicles();

    cout << "\nDetails of car with ID 2:" << endl;
    garage.displayVehicle(2);

    cout << "\nRemoving car with ID 1..." << endl;
    garage.removeVehicle(1);

    cout << "\nList of cars after removal:" << endl;
    garage.listVehicles();

    cout << "\nEditing car with ID 4" << endl;
    garage.editVehicle(4);
    cout << "\nList of cars after update:" << endl;
    garage.listVehicles();

    return 0;
}
```

### Summary:
The Vehicle Management System effectively demonstrates the use of object-oriented programming concepts such as encapsulation, inheritance, and polymorphism. It provides a comprehensive solution for managing a collection of vehicles, allowing for easy addition, modification, display, and removal of vehicle records.
