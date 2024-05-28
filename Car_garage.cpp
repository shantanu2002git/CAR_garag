#include <iostream>
#include <string>
using namespace std;

// Base class Vehicle to demonstrate inheritance
class Vehicle {
protected:
    int id;  // Encapsulation: protected member, accessible within derived classes
    int price;  
    string name;  
    string color;  
    double mileage; 
    double rating;  
    bool isElectric;  
    int wheels;  

public:
    Vehicle(int id, int price, string name, string color, double mileage, double rating, bool isElectric, int wheels)
        : id(id), price(price), name(name), color(color), mileage(mileage), rating(rating),
          isElectric(isElectric), wheels(wheels) {}

    virtual void display() const {  // Polymorphism: virtual function for runtime polymorphism
        cout << "ID: " << id << ", Name: " << name << ", Price: " << price
             << ", Color: " << color << ", Mileage: " << mileage
             << ", Rating: " << rating << ", Electric: " << (isElectric ? "Yes" : "No")
             << ", Wheels: " << wheels << endl;
    }

    int getId() const {  // Encapsulation: public method to access private member
        return id;
    }

    int getPrice() const { return price; } // Getter method for price
    string getName() const { return name; } // Getter method for name
    string getColor() const { return color; } 
    double getMileage() const { return mileage; } 
        double getRating() const { return rating; } 
    bool getIsElectric() const { return isElectric; } 
    int getWheels() const { return wheels; } 

    void updateAttributes(const string& newName, int newPrice, const string& newColor,
                          double newMileage, double newRating, bool newElectric, int newWheels) {
        name = newName;  // Encapsulation: updates encapsulated data members through a public method
        price = newPrice;
        color = newColor;
        mileage = newMileage;
        rating = newRating;
        isElectric = newElectric;
        wheels = newWheels;
    }
};

// Derived class Car
class Car : public Vehicle {  // Inheritance: Car inherits from Vehicle
public:
    Car(int id, int price, string name, string color, double mileage, double rating, bool isElectric, int wheels)
        : Vehicle(id, price, name, color, mileage, rating, isElectric, wheels) {}  // Using base class constructor
};

// Node class for linked list
class Node {
public:
    Vehicle* vehicle;  // Encapsulation: uses Vehicle object
    Node* next;

    Node(Vehicle* v) : vehicle(v), next(nullptr) {}
};

// Linked list class
class Garage {
private:
    Node* head;  // Encapsulation: private data member

public:
    Garage() : head(nullptr) {}

    bool isDuplicateID(int id) const {  // Encapsulation: method to check for duplicate IDs
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->vehicle->getId() == id) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void insertVehicle(Vehicle* vehicle) {  // Encapsulation: public method to modify private member (head)
        if (isDuplicateID(vehicle->getId())) {
            cout << "Duplicate vehicle ID: " << vehicle->getId() << ". Vehicle not inserted." << endl;
            return;
        }

        Node* newNode = new Node(vehicle);

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void displayVehicle(int id) const {  // Encapsulation: public method to access private member (head)
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->vehicle->getId() == id) {
                temp->vehicle->display();  // Polymorphism: calls display() method on Vehicle
                return;
            }
            temp = temp->next;
        }
        cout << "Vehicle not found with ID: " << id << endl;
    }

    void removeVehicle(int id) {  // Encapsulation: public method to modify private member (head)
        Node* temp = head;
        Node* prev = nullptr;

        while (temp != nullptr && temp->vehicle->getId() != id) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Vehicle not found with ID: " << id << endl;
            return;
        }

        if (prev == nullptr) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }

        delete temp->vehicle;  // Encapsulation: deleting dynamically allocated memory
        delete temp;
        cout << "Vehicle with ID " << id << " removed successfully." << endl;
    }

    void listVehicles() const {  // Encapsulation: public method to access private member (head)
        Node* temp = head;
        while (temp != nullptr) {
            temp->vehicle->display();  // Polymorphism: calls display() method on Vehicle
            temp = temp->next;
        }
    }

    void editVehicle(int id) {  // Encapsulation: public method to modify private member (head)
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->vehicle->getId() == id) {
                cout << "Choose The Option" << endl;
                cout << "1. Name" << endl;
                cout << "2. Price" << endl;
                cout << "3. Color" << endl;
                cout << "4. Mileage" << endl;
                cout << "5. Rating" << endl;
                cout << "6. Electric" << endl;
                cout << "7. Wheels" << endl;
                cout << "9. Update all fields" << endl;
                cout << "0. Exit" << endl;

                int option;
                cin >> option;

                switch (option) {
                case 1: {
                    string newName;
                    cin >> newName;
                    temp->vehicle->updateAttributes(newName, temp->vehicle->getPrice(), temp->vehicle->getColor(),
                                                     temp->vehicle->getMileage(), temp->vehicle->getRating(),
                                                     temp->vehicle->getIsElectric(), temp->vehicle->getWheels());
                    cout << "Name updated successfully." << endl;
                    break;
                }
                case 2: {
                    int newPrice;
                    cin >> newPrice;
                    temp->vehicle->updateAttributes(temp->vehicle->getName(), newPrice, temp->vehicle->getColor(),
                                                     temp->vehicle->getMileage(), temp->vehicle->getRating(),
                                                     temp->vehicle->getIsElectric(), temp->vehicle->getWheels());
                    cout << "Price updated successfully." << endl;
                    break;
                }
                case 3: {
                    string newColor;
                    cin >> newColor;
                    temp->vehicle->updateAttributes(temp->vehicle->getName(), temp->vehicle->getPrice(), newColor,
                                                     temp->vehicle->getMileage(), temp->vehicle->getRating(),
                                                     temp->vehicle->getIsElectric(), temp->vehicle->getWheels());
                    cout << "Color updated successfully." << endl;
                    break;
                }
                case 4: {
                    double newMileage;
                    cin >> newMileage;
                    temp->vehicle->updateAttributes(temp->vehicle->getName(), temp->vehicle->getPrice(), temp->vehicle->getColor(),
                                                     newMileage, temp->vehicle->getRating(),
                                                     temp->vehicle->getIsElectric(), temp->vehicle->getWheels());
                    cout << "Mileage updated successfully." << endl;
                    break;
                }
                case 5: {
                    double newRating;
                    cin >> newRating;
                    temp->vehicle->updateAttributes(temp->vehicle->getName(), temp->vehicle->getPrice(), temp->vehicle->getColor(),
                                                     temp->vehicle->getMileage(), newRating,
                                                     temp->vehicle->getIsElectric(), temp->vehicle->getWheels());
                    cout << "Rating updated successfully." << endl;
                    break;
                }
                case 6: {
                    bool newElectric;
                    cin >> newElectric;
                    temp->vehicle->updateAttributes(temp->vehicle->getName(), temp->vehicle->getPrice(), temp->vehicle->getColor(),
                                                     temp->vehicle->getMileage(), temp->vehicle->getRating(),
                                                     newElectric, temp->vehicle->getWheels());
                    cout << "Electric updated successfully." << endl;
                    break;
                }
                case 7: {
                    int newWheels;
                    cin >> newWheels;
                    temp->vehicle->updateAttributes(temp->vehicle->getName(), temp->vehicle->getPrice(), temp->vehicle->getColor(),
                                                     temp->vehicle->getMileage(), temp->vehicle->getRating(),
                                                     temp->vehicle->getIsElectric(), newWheels);
                    cout << "Wheels updated successfully." << endl;
                    break;
                }
                case 9: {
                    string newName;
                    int newPrice;
                    string newColor;
                    double newMileage;
                    double newRating;
                    bool newElectric;
                    int newWheels;

                    cout << "Enter new details: " << endl;
                    cin >> newName >> newPrice >> newColor >> newMileage >> newRating >> newElectric >> newWheels;

                    temp->vehicle->updateAttributes(newName, newPrice, newColor, newMileage, newRating, newElectric, newWheels);

                    cout << "All fields updated successfully." << endl;
                    break;
                }
                case 0: {
                    return;
                }
                default:
                    cout << "Invalid option. Please try again." << endl;
                    break;
                }
            }
            temp = temp->next;
        }
        cout << "Vehicle not found with ID: " << id << endl;
    }

    ~Garage() {  // Encapsulation: destructor to clean up dynamic memory
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp->vehicle;
            delete temp;
        }
    }
};

int main() {
    Garage garage;

    // Sample usage
    garage.insertVehicle(new Car(1, 20000, "Toyota", "Red", 25.5, 4.2, false, 4));
    garage.insertVehicle(new Car(2, 25000, "Honda", "Blue", 28.3, 4.5, true, 4));
    garage.insertVehicle(new Car(3, 30000, "Ford", "Black", 22.1, 4.0, false, 2));
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
