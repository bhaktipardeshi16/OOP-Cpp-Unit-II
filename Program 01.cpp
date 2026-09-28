// ==================== UNIT I ====================

// 1. Smart Agriculture Sensor Monitor

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class SoilSensor {
private:
    string sensorId;
    double moistureLevel;
    string timestamp;

public:
    SoilSensor(string id, double moisture, string time)
        : sensorId(id), moistureLevel(moisture), timestamp(time) {}

    void readSensor(double newMoisture, string newTime) {
        moistureLevel = newMoisture;
        timestamp = newTime;
    }

    void displayData() const {
        cout << "Sensor: " << sensorId
             << " | Moisture: " << moistureLevel << "%"
             << " | Time: " << timestamp << endl;
    }
};

int main() {
    vector<SoilSensor> farmSensors;

    farmSensors.emplace_back("S001", 45.2, "08:00");
    farmSensors.emplace_back("S002", 52.8, "08:00");
    farmSensors.emplace_back("S003", 38.5, "08:00");

    cout << "=== Morning Sensor Readings ===" << endl;

    for (const auto& sensor : farmSensors) {
        sensor.displayData();
    }

    farmSensors[0].readSensor(47.5, "09:00");

    cout << "\n=== Updated Reading ===" << endl;
    farmSensors[0].displayData();

    return 0;
}


// 2. Student Attendance Management System

#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int rollNo;
    string name;
    int totalDays;
    int presentDays;

public:
    Student(int r, string n)
        : rollNo(r), name(n), totalDays(0), presentDays(0) {}

    void markAttendance(bool isPresent) {
        totalDays++;

        if (isPresent) {
            presentDays++;
        }
    }

    double getAttendancePercentage() const {
        if (totalDays == 0) {
            return 0.0;
        }

        return (presentDays * 100.0) / totalDays;
    }

    void display() const {
        cout << "Roll: " << rollNo
             << " | Name: " << name
             << " | Attendance: "
             << getAttendancePercentage() << "%" << endl;
    }
};

int main() {
    Student s1(101, "Rahul");
    Student s2(102, "Priya");

    s1.markAttendance(true);
    s1.markAttendance(true);
    s1.markAttendance(false);

    s2.markAttendance(true);
    s2.markAttendance(true);
    s2.markAttendance(true);

    cout << "=== Attendance Report ===" << endl;

    s1.display();
    s2.display();

    return 0;
}


// 3. E-Commerce Product Catalog

#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    int productId;
    string productName;
    double price;
    int stockQuantity;
    static int totalProducts;

public:
    Product(int id, string name, double p, int stock)
        : productId(id), productName(name),
          price(p), stockQuantity(stock) {
        totalProducts++;
    }

    inline int getId() const {
        return productId;
    }

    inline string getName() const {
        return productName;
    }

    inline double getPrice() const {
        return price;
    }

    void updateStock(int quantity) {
        stockQuantity = quantity;
    }

    static int getTotalProducts() {
        return totalProducts;
    }

    void display() const {
        cout << "ID: " << productId
             << " | Product: " << productName
             << " | Price: Rs. " << price
             << " | Stock: " << stockQuantity << endl;
    }

    ~Product() {
        totalProducts--;
    }
};

int Product::totalProducts = 0;

int main() {
    Product p1(1001, "Laptop", 55000, 15);
    Product p2(1002, "Mouse", 450, 50);
    Product p3(1003, "Keyboard", 1200, 30);

    cout << "=== Product Catalog ===" << endl;

    p1.display();
    p2.display();
    p3.display();

    cout << "\nTotal Products in Catalog: "
         << Product::getTotalProducts() << endl;

    return 0;
}


// ==================== UNIT II ====================

// 1. Employee Payroll System

#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    int empId;
    string name;
    string department;

public:
    Employee(int id, string n, string dept)
        : empId(id), name(n), department(dept) {}

    void displayBasicInfo() const {
        cout << "ID: " << empId
             << " | Name: " << name
             << " | Department: " << department;
    }

    virtual double calculateSalary() const = 0;

    virtual ~Employee() = default;
};

class FullTimeEmployee : public Employee {
private:
    double monthlySalary;

public:
    FullTimeEmployee(int id, string n, string dept, double salary)
        : Employee(id, n, dept), monthlySalary(salary) {}

    double calculateSalary() const override {
        return monthlySalary;
    }

    void display() const {
        displayBasicInfo();

        cout << " | Type: Full-Time | Salary: Rs. "
             << calculateSalary() << endl;
    }
};

class PartTimeEmployee : public Employee {
private:
    double hourlyRate;
    int hoursWorked;

public:
    PartTimeEmployee(int id, string n, string dept,
                     double rate, int hours)
        : Employee(id, n, dept),
          hourlyRate(rate), hoursWorked(hours) {}

    double calculateSalary() const override {
        return hourlyRate * hoursWorked;
    }

    void display() const {
        displayBasicInfo();

        cout << " | Type: Part-Time | Salary: Rs. "
             << calculateSalary() << endl;
    }
};

class Intern : public Employee {
private:
    double stipend;

public:
    Intern(int id, string n, string dept, double stipendAmount)
        : Employee(id, n, dept), stipend(stipendAmount) {}

    double calculateSalary() const override {
        return stipend;
    }

    void display() const {
        displayBasicInfo();

        cout << " | Type: Intern | Stipend: Rs. "
             << calculateSalary() << endl;
    }
};

int main() {
    FullTimeEmployee f1(101, "Amit", "IT", 65000);
    PartTimeEmployee p1(102, "Sneha", "HR", 250, 120);
    Intern i1(103, "Rohan", "Marketing", 15000);

    cout << "=== Employee Payroll ===" << endl;

    f1.display();
    p1.display();
    i1.display();

    return 0;
}


// 2. Digital Payment Gateway

#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

class PaymentMethod {
protected:
    string transactionId;
    double amount;

public:
    PaymentMethod(string tid, double amt)
        : transactionId(tid), amount(amt) {}

    virtual bool processPayment() const = 0;

    virtual ~PaymentMethod() = default;
};

class CreditCardPayment : public PaymentMethod {
private:
    string maskedCardNumber;

public:
    CreditCardPayment(string tid, double amt, string card)
        : PaymentMethod(tid, amt), maskedCardNumber(card) {}

    bool processPayment() const override {
        cout << "Credit-card transaction "
             << transactionId
             << " for Rs. " << amount
             << " using " << maskedCardNumber
             << " completed." << endl;

        return true;
    }
};

class UPIPayment : public PaymentMethod {
private:
    string upiId;

public:
    UPIPayment(string tid, double amt, string upi)
        : PaymentMethod(tid, amt), upiId(upi) {}

    bool processPayment() const override {
        cout << "UPI transaction "
             << transactionId
             << " for Rs. " << amount
             << " from " << upiId
             << " completed." << endl;

        return true;
    }
};

class NetBankingPayment : public PaymentMethod {
private:
    string bankName;

public:
    NetBankingPayment(string tid, double amt, string bank)
        : PaymentMethod(tid, amt), bankName(bank) {}

    bool processPayment() const override {
        cout << "Net-banking transaction "
             << transactionId
             << " for Rs. " << amount
             << " through " << bankName
             << " completed." << endl;

        return true;
    }
};

int main() {
    vector<unique_ptr<PaymentMethod>> payments;

    payments.push_back(
        make_unique<CreditCardPayment>(
            "TXN001", 2500, "XXXX-XXXX-1234"));

    payments.push_back(
        make_unique<UPIPayment>(
            "TXN002", 1200, "student@upi"));

    payments.push_back(
        make_unique<NetBankingPayment>(
            "TXN003", 5000, "Example Bank"));

    cout << "=== Payment Gateway ===" << endl;

    for (const auto& payment : payments) {
        payment->processPayment();
    }

    return 0;
}


// 3. Vehicle Fleet Management

#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

class Vehicle {
protected:
    string vehicleId;
    string registrationNumber;
    double fuelLevel;

public:
    Vehicle(string vid, string reg)
        : vehicleId(vid),
          registrationNumber(reg),
          fuelLevel(100.0) {}

    void startEngine() const {
        cout << "Vehicle " << vehicleId
             << " engine started." << endl;
    }

    void refuel(double amount) {
        fuelLevel += amount;

        if (fuelLevel > 100.0) {
            fuelLevel = 100.0;
        }
    }

    virtual void displayInfo() const {
        cout << "Vehicle ID: " << vehicleId
             << " | Registration: " << registrationNumber
             << " | Fuel: " << fuelLevel << "%" << endl;
    }

    virtual ~Vehicle() = default;
};

class Truck : public Vehicle {
private:
    double cargoCapacity;

public:
    Truck(string vid, string reg, double capacity)
        : Vehicle(vid, reg), cargoCapacity(capacity) {}

    void displayInfo() const override {
        cout << "Truck | ";
        Vehicle::displayInfo();

        cout << "Cargo capacity: "
             << cargoCapacity << " tonnes" << endl;
    }
};

class DeliveryVan : public Vehicle {
private:
    int packageCount;

public:
    DeliveryVan(string vid, string reg, int packages)
        : Vehicle(vid, reg), packageCount(packages) {}

    void displayInfo() const override {
        cout << "Delivery Van | ";
        Vehicle::displayInfo();

        cout << "Packages loaded: "
             << packageCount << endl;
    }
};

class Bike : public Vehicle {
private:
    bool hasDeliveryBox;

public:
    Bike(string vid, string reg, bool hasBox)
        : Vehicle(vid, reg), hasDeliveryBox(hasBox) {}

    void displayInfo() const override {
        cout << "Delivery Bike | ";
        Vehicle::displayInfo();

        cout << "Delivery box: "
             << (hasDeliveryBox ? "Available" : "Not available")
             << endl;
    }
};

int main() {
    Truck truck("T001", "MH12AB1234", 10);
    DeliveryVan van("V001", "MH12CD5678", 25);
    Bike bike("B001", "MH12EF9012", true);

    cout << "=== Vehicle Fleet ===" << endl;

    truck.displayInfo();
    van.displayInfo();
    bike.displayInfo();

    truck.startEngine();
    van.startEngine();
    bike.startEngine();

    return 0;
}


// ==================== UNIT III ====================

// 1. CAD Shape Drawing System

#include <iostream>
#include <vector>
using namespace std;

class Shape {
public:
    virtual void draw() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    void draw() const override {
        cout << "Drawing Circle with radius "
             << radius << endl;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w)
        : length(l), width(w) {}

    void draw() const override {
        cout << "Drawing Rectangle "
             << length << " x " << width << endl;
    }
};

class Triangle : public Shape {
private:
    double base;
    double height;

public:
    Triangle(double b, double h)
        : base(b), height(h) {}

    void draw() const override {
        cout << "Drawing Triangle with base "
             << base << " and height " << height << endl;
    }
};

int main() {
    vector<Shape*> shapes;

    Circle c(5);
    Rectangle r(10, 6);
    Triangle t(8, 4);

    shapes.push_back(&c);
    shapes.push_back(&r);
    shapes.push_back(&t);

    cout << "=== CAD Drawing System ===" << endl;

    for (const auto& shape : shapes) {
        shape->draw();
    }

    return 0;
}


// 2. Complex Number Calculator

#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0, double i = 0)
        : real(r), imag(i) {}

    Complex operator+(const Complex& other) const {
        return Complex(
            real + other.real,
            imag + other.imag
        );
    }

    Complex operator-(const Complex& other) const {
        return Complex(
            real - other.real,
            imag - other.imag
        );
    }

    Complex operator*(const Complex& other) const {
        return Complex(
            real * other.real - imag * other.imag,
            real * other.imag + imag * other.real
        );
    }

    void display() const {
        cout << real;

        if (imag >= 0)
            cout << " + " << imag << "i";
        else
            cout << " - " << -imag << "i";

        cout << endl;
    }
};

int main() {
    Complex c1(4, 3);
    Complex c2(2, 5);

    Complex sum = c1 + c2;
    Complex difference = c1 - c2;
    Complex product = c1 * c2;

    cout << "First Complex Number: ";
    c1.display();

    cout << "Second Complex Number: ";
    c2.display();

    cout << "Addition: ";
    sum.display();

    cout << "Subtraction: ";
    difference.display();

    cout << "Multiplication: ";
    product.display();

    return 0;
}


// 3. Input Validation Service

#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class InputValidator {
public:
    static void validateAge(int age) {
        if (age < 0 || age > 120) {
            throw invalid_argument("Invalid age.");
        }
    }

    static void validateEmail(const string& email) {
        if (email.find('@') == string::npos) {
            throw invalid_argument("Invalid email address.");
        }
    }

    static void validatePassword(const string& password) {
        if (password.length() < 8) {
            throw invalid_argument(
                "Password must contain at least 8 characters."
            );
        }
    }
};

int main() {
    try {
        InputValidator::validateAge(25);
        InputValidator::validateEmail("student@example.com");
        InputValidator::validatePassword("password123");

        cout << "All inputs are valid." << endl;
    }
    catch (const exception& error) {
        cout << "Validation Error: "
             << error.what() << endl;
    }

    return 0;
}


// ==================== UNIT IV ====================

// 1. Student Record File System

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

struct Student {
    int rollNo;
    char name[50];
    double marks;
};

int main() {
    Student student;

    ofstream output("students.txt");

    if (!output) {
        cerr << "Unable to open file." << endl;
        return 1;
    }

    output << "101 Rahul 85.5\n";
    output << "102 Priya 91.0\n";
    output << "103 Amit 78.5\n";

    output.close();

    ifstream input("students.txt");

    if (!input) {
        cerr << "Unable to open file for reading." << endl;
        return 1;
    }

    cout << "=== Student Records ===" << endl;

    int roll;
    string name;
    double marks;

    while (input >> roll >> name >> marks) {
        cout << "Roll: " << roll
             << " | Name: " << name
             << " | Marks: " << marks << endl;
    }

    input.close();

    return 0;
}


// 2. Server Log Analyzer

#include <fstream>
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    ofstream output("server.log");

    output << "INFO Server started\n";
    output << "ERROR Database connection failed\n";
    output << "INFO User logged in\n";
    output << "WARNING High memory usage\n";
    output << "ERROR File not found\n";
    output << "INFO Request completed\n";

    output.close();

    ifstream input("server.log");

    if (!input) {
        cerr << "Unable to open log file." << endl;
        return 1;
    }

    map<string, int> logCount;
    string level;
    string message;

    while (input >> level) {
        getline(input, message);
        logCount[level]++;
    }

    input.close();

    cout << "=== Server Log Analysis ===" << endl;

    for (const auto& item : logCount) {
        cout << item.first
             << " : " << item.second << endl;
    }

    return 0;
}


// 3. Binary File for Fixed-Size Records

#include <fstream>
#include <iostream>
using namespace std;

struct ImageMetadata {
    int width;
    int height;
    char format[10];
};

int main() {
    ImageMetadata image1 = {1920, 1080, "JPEG"};
    ImageMetadata image2 = {1280, 720, "PNG"};
    ImageMetadata image3 = {800, 600, "BMP"};

    ofstream output(
        "images.bin",
        ios::binary
    );

    if (!output) {
        cerr << "Unable to open binary file." << endl;
        return 1;
    }

    output.write(
        reinterpret_cast<const char*>(&image1),
        sizeof(ImageMetadata)
    );

    output.write(
        reinterpret_cast<const char*>(&image2),
        sizeof(ImageMetadata)
    );

    output.write(
        reinterpret_cast<const char*>(&image3),
        sizeof(ImageMetadata)
    );

    output.close();

    ifstream input(
        "images.bin",
        ios::binary
    );

    if (!input) {
        cerr << "Unable to open binary file for reading."
             << endl;
        return 1;
    }

    ImageMetadata item{};
    int recordNo = 1;

    cout << "=== Image Metadata ===" << endl;

    while (input.read(
        reinterpret_cast<char*>(&item),
        sizeof(ImageMetadata))) {

        cout << "Record " << recordNo++
             << ": "
             << item.width << " x "
             << item.height
             << " | " << item.format
             << endl;
    }

    input.close();

    return 0;
}


// ==================== UNIT V ====================

// 1. Secure Banking Transaction Module

#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class InsufficientFundsException : public exception {
private:
    double balance;
    double requestedAmount;

public:
    InsufficientFundsException(
        double currentBalance,
        double requested)
        : balance(currentBalance),
          requestedAmount(requested) {}

    const char* what() const noexcept override {
        return "Insufficient balance for withdrawal.";
    }

    double getBalance() const {
        return balance;
    }

    double getRequestedAmount() const {
        return requestedAmount;
    }
};

class BankAccount {
private:
    int accountNumber;
    string holderName;
    double balance;

public:
    BankAccount(
        int number,
        string name,
        double openingBalance)
        : accountNumber(number),
          holderName(name),
          balance(openingBalance) {

        if (openingBalance < 0.0) {
            throw invalid_argument(
                "Opening balance cannot be negative."
            );
        }
    }

    void deposit(double amount) {
        if (amount <= 0.0) {
            throw invalid_argument(
                "Deposit amount must be positive."
            );
        }

        balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= 0.0) {
            throw invalid_argument(
                "Withdrawal amount must be positive."
            );
        }

        if (amount > balance) {
            throw InsufficientFundsException(
                balance, amount
            );
        }

        balance -= amount;
    }

    void display() const {
        cout << "Account: " << accountNumber
             << " | Holder: " << holderName
             << " | Balance: Rs. " << balance
             << endl;
    }
};

int main() {
    try {
        BankAccount account(
            1001,
            "Rahul",
            5000.0
        );

        account.deposit(2000.0);
        account.withdraw(1500.0);
        account.withdraw(10000.0);
    }
    catch (const InsufficientFundsException& error) {
        cout << "Transaction failed: "
             << error.what() << endl;

        cout << "Available balance: Rs. "
             << error.getBalance() << endl;

        cout << "Requested amount: Rs. "
             << error.getRequestedAmount() << endl;
    }
    catch (const exception& error) {
        cout << "System error: "
             << error.what() << endl;
    }

    return 0;
}


// 2. Generic Sorting Service

#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T>
void sortItems(vector<T>& values) {
    for (size_t i = 0; i < values.size(); i++) {

        for (size_t j = i + 1;
             j < values.size(); j++) {

            if (values[j] < values[i]) {
                T temp = values[i];
                values[i] = values[j];
                values[j] = temp;
            }
        }
    }
}

template <typename T>
void displayItems(const vector<T>& values) {
    for (const auto& value : values) {
        cout << value << " ";
    }

    cout << endl;
}

int main() {
    vector<int> ids{
        64, 34, 25, 12, 22, 11, 90
    };

    vector<double> scores{
        3.14, 2.71, 1.41, 9.99, 0.50
    };

    vector<string> cities{
        "Pune", "Mumbai", "Nashik", "Aurangabad"
    };

    cout << "Integer IDs before sorting: ";
    displayItems(ids);

    sortItems(ids);

    cout << "Integer IDs after sorting: ";
    displayItems(ids);

    cout << "Scores before sorting: ";
    displayItems(scores);

    sortItems(scores);

    cout << "Scores after sorting: ";
    displayItems(scores);

    cout << "Cities before sorting: ";
    displayItems(cities);

    sortItems(cities);

    cout << "Cities after sorting: ";
    displayItems(cities);

    return 0;
}


// 3. Template-Based Stack

#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

template <typename T>
class Stack {
private:
    T* data;
    int capacity;
    int topIndex;

public:
    explicit Stack(int size)
        : capacity(size), topIndex(-1) {

        if (size <= 0) {
            throw invalid_argument(
                "Stack capacity must be positive."
            );
        }

        data = new T[capacity];
    }

    Stack(const Stack&) = delete;
    Stack& operator=(const Stack&) = delete;

    ~Stack() {
        delete[] data;
    }

    void push(const T& value) {
        if (topIndex == capacity - 1) {
            throw overflow_error("Stack overflow.");
        }

        data[++topIndex] = value;
    }

    T pop() {
        if (topIndex < 0) {
            throw underflow_error("Stack underflow.");
        }

        return data[topIndex--];
    }

    bool isEmpty() const {
        return topIndex < 0;
    }

    void display() const {
        for (int i = topIndex; i >= 0; i--) {
            cout << data[i] << " ";
        }

        cout << endl;
    }
};

int main() {
    try {
        Stack<int> integerStack(5);

        integerStack.push(10);
        integerStack.push(20);
        integerStack.push(30);

        cout << "Integer stack: ";
        integerStack.display();

        cout << "Popped: "
             << integerStack.pop() << endl;

        Stack<string> commandStack(3);

        commandStack.push("Open file");
        commandStack.push("Edit text");
        commandStack.push("Save file");

        cout << "Command stack: ";
        commandStack.display();
    }
    catch (const exception& error) {
        cout << "Error: "
             << error.what() << endl;
    }

    return 0;
}


// ==================== UNIT VI ====================

// 1. Employee Directory and Salary Lookup

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

class Employee {
public:
    string name;
    int age;
    double salary;

    Employee(string n, int a, double s)
        : name(n), age(a), salary(s) {}
};

int main() {
    vector<Employee> staff{
        {"Alice", 30, 70000},
        {"Bob", 25, 50000},
        {"Charlie", 35, 80000},
        {"Diana", 28, 60000}
    };

    map<string, double> salaryByName;

    for (const auto& employee : staff) {
        salaryByName[employee.name] =
            employee.salary;
    }

    sort(
        staff.begin(),
        staff.end(),
        [](const Employee& first,
           const Employee& second) {
            return first.age < second.age;
        }
    );

    cout << "=== Employees Sorted by Age ==="
         << endl;

    for (const auto& employee : staff) {
        cout << employee.name
             << " | Age: " << employee.age
             << " | Salary: Rs. "
             << employee.salary << endl;
    }

    string query = "Bob";

    auto found = salaryByName.find(query);

    if (found != salaryByName.end()) {
        cout << "\nSalary of " << query
             << ": Rs. "
             << found->second << endl;
    }

    auto highestPaid = max_element(
        staff.begin(),
        staff.end(),
        [](const Employee& first,
           const Employee& second) {
            return first.salary < second.salary;
        }
    );

    cout << "Highest-paid employee: "
         << highestPaid->name
         << " | Rs. "
         << highestPaid->salary << endl;

    return 0;
}


// 2. Web Server Log Analysis

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
using namespace std;

struct LogEntry {
    string ip;
    string request;
};

int main() {
    vector<LogEntry> logs{
        {"192.168.1.1", "GET /index.html"},
        {"192.168.1.2", "POST /api/data"},
        {"192.168.1.1", "GET /about.html"},
        {"192.168.1.3", "GET /contact.html"},
        {"192.168.1.1", "GET /products.html"},
        {"192.168.1.2", "GET /api/users"},
        {"192.168.1.1", "POST /api/order"},
        {"192.168.1.4", "GET /index.html"},
        {"192.168.1.1", "GET /services.html"},
        {"192.168.1.2", "GET /api/products"}
    };

    map<string, int> requestCount;

    for (const auto& entry : logs) {
        requestCount[entry.ip]++;
    }

    vector<pair<string, int>> ranked(
        requestCount.begin(),
        requestCount.end()
    );

    sort(
        ranked.begin(),
        ranked.end(),
        [](const auto& first,
           const auto& second) {
            return first.second > second.second;
        }
    );

    cout << "=== Request Count by IP Address ==="
         << endl;

    for (const auto& item : ranked) {
        cout << item.first
             << " : " << item.second
             << " requests" << endl;
    }

    return 0;
}


// 3. Student Grade Analytics

#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
using namespace std;

int main() {
    vector<double> marks{
        85.5, 92.0, 78.5, 88.0,
        95.5, 72.0, 89.5, 91.0
    };

    double total =
        accumulate(
            marks.begin(),
            marks.end(),
            0.0
        );

    double average =
        total / marks.size();

    cout << "Average: "
         << average << endl;

    cout << "Minimum: "
         << *min_element(
                marks.begin(),
                marks.end())
         << endl;

    cout << "Maximum: "
         << *max_element(
                marks.begin(),
                marks.end())
         << endl;

    sort(marks.begin(), marks.end());

    cout << "\nMarks in ascending order: ";

    for (double mark : marks) {
        cout << mark << " ";
    }

    cout << endl;

    priority_queue<double> topPerformers(
        marks.begin(),
        marks.end()
    );

    cout << "\nTop three marks:" << endl;

    for (int i = 0;
         i < 3 && !topPerformers.empty();
         i++) {

        cout << topPerformers.top() << endl;
        topPerformers.pop();
    }

    set<double> uniqueMarks(
        marks.begin(),
        marks.end()
    );

    cout << "\nUnique marks: ";

    for (double mark : uniqueMarks) {
        cout << mark << " ";
    }

    cout << endl;

    map<char, int> gradeDistribution;

    for (double mark : marks) {
        if (mark >= 90)
            gradeDistribution['A']++;
        else if (mark >= 80)
            gradeDistribution['B']++;
        else if (mark >= 70)
            gradeDistribution['C']++;
        else
            gradeDistribution['D']++;
    }

    cout << "\nGrade distribution:"
         << endl;

    for (const auto& item : gradeDistribution) {
        cout << "Grade "
             << item.first
             << ": "
             << item.second
             << " student(s)"
             << endl;
    }

    return 0;
}
