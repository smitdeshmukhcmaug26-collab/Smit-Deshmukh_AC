#include <iostream>
#include <string>
#include <cctype>
#include <limits>
#include <iomanip>

using namespace std;

class Employee {
private:
    int empId;
    string name;
    string department;
    char grade;
    double basicSalary;
    bool isActive;
    static int employeeCount;

public:

    Employee() : isActive(true) {
        employeeCount++;
        empId = 1000 + employeeCount;
        name = "Unassigned";
        department = "Engineering";
        grade = 'D';
        basicSalary = 10001.0;
    }

    // Setters with validation
    void setName(const string& n) {
        if (!n.empty()) {
            name = n;
        } else {
            cout << "[Validation Error] Name cannot be empty!" << endl;
        }
    }
    
    void setDepartment(const string& dept) {
        if (dept == "Engineering" || dept == "HR" || dept == "Finance" || dept == "Operations") {
            department = dept;
        } else {
            cout << "[Validation Error] Invalid department '" << dept << "'." << endl;
        }
    }
    
    void setGrade(char g) {
        char upperG = toupper(g);
        if (upperG == 'A' || upperG == 'B' || upperG == 'C' || upperG == 'D') {
            grade = upperG;
        } else {
            cout << "[Validation Error] Invalid grade '" << g 
                 << "'. Allowed: 'A', 'B', 'C', 'D'." << endl;
        }
    }
    
    void setBasicSalary(double salary) {
        if (salary > 10000.0 && salary < 500000.0) {
            basicSalary = salary;
        } else {
            cout << "[Validation Error] Salary must be > 10,000 and < 5,00,000." << endl;
        }
    }
    
    void deactivate() {
        isActive = false;
    }

   
    int getEmpId() const {
        return empId;
    }

    string getName() const {
        return name;
    }

    string getDepartment() const {
        return department;
    }

    char getGrade() const {
        return grade;
    }

    double getBasicSalary() const {
        return basicSalary;
    }

    bool getIsActive() const {
        return isActive;
    }


    static int getEmployeeCount() {
        return employeeCount;
    }


    double computeAllowances() const {
        switch (grade) {
            case 'A': return 0.40 * basicSalary; // Senior / Manager (40%)
            case 'B': return 0.30 * basicSalary; // Mid-level (30%)
            case 'C': return 0.20 * basicSalary; // Junior (20%)
            case 'D': return 0.10 * basicSalary; // Trainee (10%)
            default:  return 0.0;
        }
    }

    double computeGrossSalary() const {
        return basicSalary + computeAllowances();
    }

    double computeTax() const {
        double gross = computeGrossSalary();
        if (gross <= 50000.0) {
            return 0.0;
        } else if (gross <= 100000.0) {
            return (gross - 50000.0) * 0.10; 
        } else {
            return 5000.0 + (gross - 100000.0) * 0.20; 
        }
    }

    double computeNetSalary() const {
        return computeGrossSalary() - computeTax();
    }

    void printPayslip() const {
        cout << "\n-------------- EMPLOYEE PAYSLIP --------------" << endl;
        cout << "Employee ID"   << ": " << empId << endl;
        cout <<"Name"          << ": " << name << endl;
        cout << "Department"    << ": " << department << endl;
        cout << "Grade"         << ": " << grade << endl;
        cout << "Status"        << ": " << (isActive ? "Active" : "Inactive") << endl; 
        cout << "Basic Salary"  << ": Rs. " << basicSalary << endl;
        cout << "Allowances"    << ": Rs. " << computeAllowances() << endl;
        cout << "Gross Salary"   << ": Rs. " << computeGrossSalary() << endl;
        cout << "Tax Deduction" << ": Rs. " << computeTax() << endl;
        cout << "Net Salary"     << ": Rs. " << computeNetSalary() << endl;

    }


    void acceptDetails() {
        string inName, inDept;
        char inGrade;
        double inSalary;

        cout << "\n=== Enter Details for Employee ID: " << empId << " ===" << endl;


        while (true) {
            cout << "Enter Name: ";
            getline(cin >> ws, inName);
            string prevName = name;
            setName(inName);
            if (name == inName && name != prevName) break;
        }

  
        while (true) {
            cout << "Enter Department (Engineering/HR/Finance/Operations): ";
            if (cin >> inDept) {
                string prevDept = department;
                setDepartment(inDept);
                if (department == inDept && department != prevDept) break;
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }


        while (true) {
            cout << "Enter Grade (A, B, C, D): ";
            if (cin >> inGrade) {
                char prevGrade = grade;
                setGrade(inGrade);
                if (grade == toupper(inGrade) && grade != prevGrade) break;
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        while (true) {
            cout << "Enter Basic Salary (> 10000 and < 500000): ";
            if (cin >> inSalary) {
                double prevSalary = basicSalary;
                setBasicSalary(inSalary);
                if (basicSalary == inSalary && basicSalary != prevSalary) break;
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
};


int Employee::employeeCount = 0;

int main() {

    Employee e1;
    Employee* e2 = new Employee();
    Employee* e3 = new Employee();

    e1.acceptDetails();
    e2->acceptDetails();
    e3->acceptDetails();


    e1.printPayslip();
    e2->printPayslip();
    e3->printPayslip();

    // Simulate a resignation
    e3->deactivate();
    if (!e3->getIsActive())
        cout << e3->getName() << " is no longer active. Payroll skipped." << endl;

    cout << "Total Employees : " << Employee::getEmployeeCount() << endl;

    delete e2;
    delete e3;

    return 0;
}