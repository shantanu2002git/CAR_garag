#include <iostream>
#include <string>
using namespace std;

class node
{
public:
  int id;
  int price;
  string name;
  string color;
  double mileage;
  double rating;
  bool isElectric;
  int wheels;
  node *next;

  node(int id, int price, string name, string color, double mileage, double rating, bool isElectric, int wheels)
      : id(id), price(price), name(name), color(color), mileage(mileage), rating(rating),
        isElectric(isElectric), wheels(wheels), next(nullptr) {}
};

class car
{
private:
  node *head;

public:
  car() : head(nullptr) {}

  bool isDuplicateID(int id)
  {
    node *temp = head;
    while (temp != nullptr)
    {
      if (temp->id == id)
      {
        return true;
      }
      temp = temp->next;
    }
    return false;
  }

  void in(int id, int price, string name, string color, double mileage, double rating, bool isElectric, int wheels)
  {
    if (isDuplicateID(id))
    {
      cout << "Duplicate car ID: " << id << ". Car not inserted." << endl;
      return;
    }

    node *newNode = new node(id, price, name, color, mileage, rating, isElectric, wheels);

    if (head == nullptr)
    {
      head = newNode;
    }
    else
    {
      node *temp = head;
      while (temp->next != nullptr)
      {
        temp = temp->next;
      }
      temp->next = newNode;
    }
  }

  void get(int id)
  {
    node *temp = head;
    while (temp != nullptr)
    {
      if (temp->id == id)
      {
        cout << "ID: " << temp->id << ", Name: " << temp->name << ", Price: " << temp->price
             << ", Color: " << temp->color << ", Mileage: " << temp->mileage
             << ", Rating: " << temp->rating << ", Electric: " << (temp->isElectric ? "Yes" : "No")
             << ", Wheels: " << temp->wheels << endl;
        return;
      }
      temp = temp->next;
    }
    cout << "Car not found with ID: " << id << endl;
  }

  void remove(int id)
  {
    node *temp = head;
    node *prev = nullptr;

    while (temp != nullptr && temp->id != id)
    {
      prev = temp;
      temp = temp->next;
    }

    if (temp == nullptr)
    {
      cout << "Car not found with ID: " << id << endl;
      return;
    }

    if (prev == nullptr)
    {
      head = temp->next;
    }
    else
    {
      prev->next = temp->next;
    }

    delete temp;
    cout << "Car with ID " << id << " removed successfully." << endl;
  }

  void list()
  {
    node *temp = head;
    while (temp != nullptr)
    {
      cout << "ID: " << temp->id << ", Name: " << temp->name << ", Price: " << temp->price
           << ", Color: " << temp->color << ", Mileage: " << temp->mileage
           << ", Rating: " << temp->rating << ", Electric: " << (temp->isElectric ? "Yes" : "No")
           << ", Wheels: " << temp->wheels << endl;
      temp = temp->next;
    }
  }

  ~car()
  {
    while (head != nullptr)
    {
      node *temp = head;
      head = head->next;
      delete temp;
    }
  }
};

int main()
{
  car garage;

  // Sample usage
  garage.in(1, 20000, "Toyota", "Red", 25.5, 4.2, false, 4);
  garage.in(2, 25000, "Honda", "Blue", 28.3, 4.5, true, 4);
  garage.in(3, 30000, "Ford", "Black", 22.1, 4.0, false, 2);
  garage.in(4, 35000, "BMW", "White", 20.7, 4.8, true, 4);
  garage.in(4, 35000, "BMW", "White", 20.7, 4.8, true, 4);

  cout << "List of cars in the garage:" << endl;
  garage.list();

  cout << "\nDetails of car with ID 2:" << endl;
  garage.get(2);

  cout << "\nRemoving car with ID 1..." << endl;
  garage.remove(1);

  cout << "\nList of cars after removal:" << endl;
  garage.list();

  return 0;
}
