Compile the code and run the exe.

The code implements a simple ilustration of employess and company using two classes:

employee – Represents a single employee.

Company – Manages a collection of employees using a vector<employee>.

Class: employee
Data members:

id (string)

employee_name (string)

employee_salary (unsigned long int)

employee_age (int)

employee_title (string)

employee_email (string)

Functions:

Constructor: Initializes employee details.

Getters: getId(), getName(), getSalary(), etc.

display(): Prints employee details in a formatted line.

Class: Company
Data member:

vector<employee> lstEmployees – Stores all employees.

Functions:

createEmployee() – Adds a new employee to the vector.

getAllEmployees() – Displays all employees.

getEmployeesByNameSearch() – Finds employees whose names contain a given substring.

getEmployeeById() – Retrieves an employee by ID.

getHighestSalaryOfEmployees() – Finds the highest salary among employees.

deleteEmployeeById() – Removes an employee by ID.

(Optional) getTop10HighestSalaryEmployees() – Displays top 10 highest-paid employees (if added).
