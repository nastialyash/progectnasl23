

#include <iostream>
using namespace std;
class Vehicle {
protected:
	string brand;
	string model;
	Vehicle()
	{
		brand = "No brand";
		model = "No model";
	}
	Vehicle(string m, string b) :model{ m }, brand{ b }{}

	void PrintInfo()const{
		cout << "Brand" << brand << endl;
		cout << "Model" << model << endl;
	}

};
class Car :protected Vehicle {
	int numberOfDoors;
public:
	Car(const string& brand, const string& model, int numberOfDoors)
		: Vehicle(brand, model), numberOfDoors(numberOfDoors) {}


	void PrintInfo() const {
		Vehicle::PrintInfo();
		cout << "Type: Car, Number of Doors: " << numberOfDoors << endl;
	}
};
	class Motorcycle : public Vehicle {
	private:
		bool hasSidecar;

	public:

		Motorcycle(const string& brand, const string& model, bool hasSidecar)
			: Vehicle(brand, model), hasSidecar(hasSidecar) {}


		void PrintInfo() const {
			Vehicle::PrintInfo();
			cout << "Type: Motorcycle, Has Sidecar: " << (hasSidecar ? "Yes" : "No") << endl;
		}
	
	};
	int main()
	{

		Car myCar("Toyota", "Corolla", 4);
		
		Motorcycle myMotorcycle("Harley-Davidson", "Sportster", false);

		
		cout << "Vehicle 1 Information:\n";
		myCar.PrintInfo();

		cout << "nVehicle 2 Information:\n";
		myMotorcycle.PrintInfo();
	}
class Employee {
protected:
    string name;
    int id;

public:
  
    Employee(const string& name, int id) : name(name), id(id) {}

    void PrintInfo() const {
        cout << "Employee ID: " << id << ", Name: " << name;
    }
};

class HourlyEmployee : public Employee {
private:
    double hourlyRate;
    int hoursWorked;

public:
   
    HourlyEmployee(const string& name, int id, double hourlyRate, int hoursWorked)
        : Employee(name, id), hourlyRate(hourlyRate), hoursWorked(hoursWorked) {}

    
    double CalculateSalary() const {
        return hourlyRate * hoursWorked; 
    }

   
    void PrintHourlyInfo() const {
        PrintInfo();
        cout << ", Type: Hourly Employee, Salary: $" << CalculateSalary() << endl;
    }
};


class SalariedEmployee : public Employee {
private:
    double monthlySalary;

public:
   
    SalariedEmployee(const string& name, int id, double monthlySalary)
        : Employee(name, id), monthlySalary(monthlySalary) {}

 
    double CalculateSalary() const {
        return monthlySalary;  
    }

   
    void PrintSalariedInfo() const {
        PrintInfo();
        cout << ", Type: Salaried Employee, Salary: $" << CalculateSalary() << endl;
    }
};

int main() {
    
    HourlyEmployee hourlyWorker("John Doe", 1, 20.0, 160); 
    
    SalariedEmployee salariedWorker("Jane Smith", 2, 3000.0);  

  
    cout << "Employee Information:\n";
    hourlyWorker.PrintHourlyInfo();
    salariedWorker.PrintSalariedInfo();

}
class Animal {
public:
   
    void MakeSound() const {
        cout << "Some  animal sound" << endl;
    }
};

class Dog : public Animal {
public:
  
    void MakeSound() const {
        cout << "Woof! Woof!" << endl;
    }
};


class Cat : public Animal {
public:
    
    void MakeSound() const {
        cout << "Meow! Meow!" << endl;
    }
};

class Cow : public Animal {
public:
    
    void MakeSound() const {
        cout << "Moo! Moo!" << endl;
    }
};

int main() {
   
    Animal genericAnimal;
    Dog dog;
    Cat cat;
    Cow cow;

  
    cout << " Animal sound: ";
    genericAnimal.MakeSound();

    cout << "Dog  ";
    dog.MakeSound();

    cout << "Cat  ";
    cat.MakeSound();

    cout << "Cow  ";
    cow.MakeSound();

}