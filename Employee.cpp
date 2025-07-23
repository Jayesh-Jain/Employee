#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class employee {
public:
    employee();

    employee(const string& empId, const string& name, unsigned long int salary, int age,
             const string& title, const string& email)
        : id(empId), employee_name(name), employee_salary(salary),
          employee_age(age), employee_title(title), employee_email(email) {}

    string getId() const { return id; }
    string getName() const { return employee_name; }
    unsigned long int getSalary() const { return employee_salary; }
    int getAge() const { return employee_age; }
    string getTitle() const { return employee_title; }
    string getEmail() const { return employee_email; }

    void display() const {
        cout << "ID: " << id << ", Name: " << employee_name
             << ", Salary: " << employee_salary
             << ", Age: " << employee_age
             << ", Title: " << employee_title
             << ", Email: " << employee_email << endl;
    }

private:
    string id;
    string employee_name;
    unsigned long int employee_salary{};
    int employee_age{};
    string employee_title;
    string employee_email;
};

employee::employee(){
}

class Company {
public:
    Company();

    void getAllEmployees();
    int getEmployeesByNameSearch(const string& strPattern, vector<employee>& lstResult);
    int getEmployeeById(const string& strID, employee& emp);
    void getHighestSalaryOfEmployees(unsigned long int& ulHighestSal);
    void createEmployee(const string& empId, const string& name, unsigned long int salary, int age, const string& title, const string& email);
    void deleteEmployeeById(const string& strID);
    void getTop10HighestEarningEmployeeNames();
    bool isValidEmployeeDetails(const string& empId, const string& name, unsigned long int salary, int age, const string& title, const string& email);

private:
    vector<employee> lstEmployees;
};

Company::Company(){
}

bool Company::isValidEmployeeDetails(const string& empId, const string& name, unsigned long int salary, int age, const string& title, const string& email){
    if(!empId.empty()
        && !name.empty()
        && !title.empty()
        && !email.empty()
        && salary > 0
        && age > 16 && age < 75
        )
        {
            if(!lstEmployees.empty()){
                auto it = lstEmployees.begin();
    
                while (it != lstEmployees.end())
                {
                    if(it->getId() == empId )
                        return false;
                    ++it;
                }
            }
            return true;
        }
    
    return false;
}

void Company::createEmployee(const string& empId, const string& name, unsigned long int salary, int age, const string& title, const string& email) {
    if (isValidEmployeeDetails(empId, name, salary, age, title, email)) {
        employee emp(empId, name, salary, age, title, email);
        auto it = lstEmployees.begin();
        while (it != lstEmployees.end() && it->getSalary() >= emp.getSalary()){
            ++it;
        }
        lstEmployees.insert(it, emp);
    } else {
        cout << "Employee not created due to insufficient information" << endl;
    }
}

void Company::getAllEmployees() {
    if (lstEmployees.empty()) {
        cout << "No employees found!" << endl;
        return;
    }
    for (const auto& emp : lstEmployees) {
        emp.display();
    }
}

int Company::getEmployeesByNameSearch(const string& strPattern, vector<employee>& lstResult) {
    lstResult.clear();
    for (const auto& emp : lstEmployees) {
        if (emp.getName().find(strPattern) != string::npos) {
            lstResult.push_back(emp);
        }
    }
    if(lstResult.empty())
        return 1;
        
    return 0;
}

int Company::getEmployeeById(const string& strID, employee& emp) {
    for (const auto& e : lstEmployees) {
        if (e.getId() == strID) {
            emp = e;
            return 0;
        }
    }
    cout << "Employee with ID " << strID << " not found." << endl;
    return 1;
}

void Company::getHighestSalaryOfEmployees(unsigned long int& ulHighestSal) {
    ulHighestSal = 0;
    for (const auto& emp : lstEmployees) {
        ulHighestSal = max(ulHighestSal, emp.getSalary());
    }
}

void Company::deleteEmployeeById(const string& strID) {
    auto it = lstEmployees.begin();
    
    while (it != lstEmployees.end())
    {
         if(it->getId() == strID)
            break;
        ++it;
    }
    if (it != lstEmployees.end()) {
        lstEmployees.erase(it);
        cout << "Employee with ID " << strID << " deleted." << endl;
    } else {
        cout << "Employee with ID " << strID << " not found." << endl;
    }
}

void Company::getTop10HighestEarningEmployeeNames(){
    if((int)lstEmployees.size() < 10){
        getAllEmployees();
        return;
    }
        
   for (int i = 0; i < 10; ++i) {
        lstEmployees[i].display();
    }
    
    return;
}

int main() {
    Company comp;

    // Add employees
    comp.createEmployee("d005f39a-beb8-4390-afec-fd54e91d94ee", "Jill Jenkins", 139082, 48, "Financial Advisor", "jillj@company.com");
    comp.createEmployee("5255f1a5-f9f7-4be5-829a-134bde088d17", "Bill Bob", 89750, 24, "Documentation Engineer", "billBob@company.com");
    comp.createEmployee("4a3a170b-22cd-4ac2-aad1-9bb5b34a1507", "Tiger Nixon", 320800, 61, "Vice Chair Executive Principal of Chief Operations Implementation Specialist", "tnixon@company.com");
    comp.createEmployee("a3f5c47e-8d67-4a1b-b2ef-dc89d1b2c0aa", "Emma Watson", 185000, 32, "HR Manager", "emmaw@company.com");
comp.createEmployee("bd3e21c9-7415-4f63-b29c-8c5b2d45a912", "John Doe", 97500, 29, "Software Engineer", "johnd@company.com");
comp.createEmployee("c46f83b2-22e5-4a07-96a7-4e5fba2b9fbb", "Sophia Brown", 210500, 41, "Chief Marketing Officer", "sophiab@company.com");
comp.createEmployee("d51b9739-67af-4e6c-9e6e-7b41b9128f2a", "David Johnson", 152000, 37, "Senior Data Scientist", "davidj@company.com");
comp.createEmployee("e9ab8c61-52fb-48cb-b7ec-b60ab5cd47da", "Michael Smith", 189000, 45, "IT Director", "michaels@company.com");
comp.createEmployee("f23c5a4d-65d2-41c5-a9cc-3cd4e5b1b2a5", "Isabella Martinez", 145750, 33, "Financial Analyst", "isabellam@company.com");
comp.createEmployee("125c78fa-36b2-4d7f-81ad-9ab84b74f2e1", "Liam White", 232400, 50, "VP of Engineering", "liamw@company.com");
comp.createEmployee("2c54c7d9-32ef-41f8-8a7c-0e4a2cbf1cd9", "Olivia Green", 110000, 27, "UI/UX Designer", "oliviag@company.com");
comp.createEmployee("3e76b5d4-98c4-43f5-94b9-38e7cbef54e9", "James Anderson", 268000, 55, "Chief Technology Officer", "jamesa@company.com");
comp.createEmployee("4f87b2d1-47d6-4d8b-a83e-2e4fcb7f3d8a", "Mia Johnson", 102500, 26, "Business Analyst", "miaj@company.com");
comp.createEmployee("56e4d8b2-2b3e-4e84-8b6e-3e5fcb2a9f4e", "Lucas Davis", 131500, 34, "Project Manager", "lucasd@company.com");
comp.createEmployee("6a54b3d2-98e4-42a7-93e8-3b7fcba4d2f3", "Ava Wilson", 95000, 23, "Junior Developer", "avaw@company.com");
comp.createEmployee("7f32c4d2-63b4-4e9a-85e4-3c7bcfa3d7a9", "Mason Taylor", 173200, 39, "Cloud Architect", "masont@company.com");
comp.createEmployee("8b63d2e1-75f4-4b9d-92e3-3a9bfc7e4f8a", "Charlotte Thomas", 119000, 28, "QA Lead", "charlottet@company.com");
comp.createEmployee("91c3b7e2-4a6b-4e8f-83d2-3f7bca9e2f1b", "Ethan Harris", 207500, 44, "Product Manager", "ethanh@company.com");
comp.createEmployee("a8b4e6c2-34f2-4c8b-95e7-3b6acfe2d8f4", "Amelia Clark", 138900, 31, "Network Engineer", "ameliac@company.com");
comp.createEmployee("b9c3e4d2-57f4-4d9b-84e6-3d5bca7e9f4a", "Logan Lewis", 147600, 38, "Security Specialist", "loganl@company.com");
comp.createEmployee("c2e4b7d2-3a6e-4b8d-93f2-3f6bce7d1a9f", "Harper Allen", 99000, 25, "Support Engineer", "harpera@company.com");
comp.createEmployee("d3b5f8e2-64f3-4b7d-86e9-3b5acfe3f8a4", "Benjamin Walker", 184300, 42, "DevOps Engineer", "benjaminw@company.com");
comp.createEmployee("e4f6b9c2-73a4-4c8e-91e8-3f4bca8e7f9d", "Evelyn Scott", 202000, 46, "Operations Manager", "evelyns@company.com");


    cout << "\nAll Employees:\n";
    comp.getAllEmployees();


    // Search employees by pattern
    vector<employee> searchResult;
    if (comp.getEmployeesByNameSearch("ill", searchResult) == 0) {
        cout << "\nSearch result for 'ill':\n";
        for (const auto& e : searchResult) {
            e.display();
        }
    } else {
        cout << "\nNo employees found with the name pattern 'Bob'.\n";
    }

    // Get employee by ID
    employee e;
    if (comp.getEmployeeById("4a3a170b-22cd-4ac2-aad1-9bb5b34a1507", e) == 0) {
        cout << "\nEmployee with ID 4a3a170b-22cd-4ac2-aad1-9bb5b34a1507:\n";
        e.display();
    }

    // Get highest salary
    unsigned long int highestSalary;
    comp.getHighestSalaryOfEmployees(highestSalary);
    cout << "\nHighest Salary: " << highestSalary << endl;

    // Delete an employee
    comp.deleteEmployeeById("4a3a170b-22cd-4ac2-aad1-9bb5b34a1507");

    cout << "\nEmployees after deletion:\n";
    comp.getAllEmployees();

    //Get Top 10 employees with highest Salary
    cout << "\n Top 10 Salary Employees:\n";
    comp.getTop10HighestEarningEmployeeNames();
    
    
    //-----------------Negative TestCases--------------------//
    
    //Create Employee with duplicate id
    comp.createEmployee("e4f6b9c2-73a4-4c8e-91e8-3f4bca8e7f9d", "Evelyn Scott", 202000, 46, "Operations Manager", "evelyns@company.com");
    
    //Create Employee with no mail-id
    comp.createEmployee("e4f6b9c2-73a4-4c8e-91e8-3f4bca8e7f93", "Eve Sott", 20210, 46, "Operations Manager", "");
    
    //Search for employee with wrong id
    employee em;
    if (comp.getEmployeeById("4a3a1-22cd-4ac2-aad1-9bb5b34a1507", em) == 0) {
        cout << "\nEmployee with ID 4a3a1-22cd-4ac2-aad1-9bb5b34a1507:\n";
        em.display();
    }

    return 0;

}
