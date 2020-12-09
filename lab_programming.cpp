#include <iostream>
#include <vector>
#include <time.h>
#include <string>
#include <fstream>
#include <algorithm>

using std::vector;

//FUNC FOR LB 9
int* create_array(int& len) {
    int* array = new int[len];
    for (int i = 0; i < len; ++i) {
        std::cout << "INPUT ARR[" << i << "]: ";
        std::cin >> array[i];
    }

    return array;
}
void output_array(int*& array, int& len) {
    for (int i = 0; i < len; ++i) {
        std::cout << array[i] << '\t';
    }
}

//FUNC FOR LB 10
bool func_23_17(vector<int>& arr, const int& len) {
    int count_null = 0;
    int count_minus = 0;
    for (int i = 0; i < len; ++i) {
        if (arr[i] == 0) ++count_null;
        if (arr[i] < 0) ++count_minus;
    }

    if (count_null < count_minus) return true;
    else return false;
}
void fill_vector(vector<int>& vec, int& len) {
    for (int i = 0; i < len; ++i) {
        vec.push_back(rand() % 3 - 1);
        std::cout << vec[i] << '\t';
    }
    std::cout << '\n';
}
int counting_of_answer(vector<int> &arr) {
    int answer;
    if (func_23_17(arr, arr.size())) {
        answer = 1;
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] < 0) answer *= arr[i];
        }
    }
    else {
        answer = 0;
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] == 0) answer += i;
        }
    }
    return answer;
}

//FUNC FOR LB 11
double lab11_recursion(int n) {
    if (n == 2) return 1. / n;
    else return lab11_recursion(n - 2.) + (n - 1.) / n;
}

//MAIN FUNC FOR LB
void lab17_9() {
    int count = 0;
    double sum = 0;
    int n, m;

    std::cout << "INPUT N: ";
    std::cin >> n;
    std::cout << "INPUT M: ";
    std::cin >> m;

    double** arr = new double* [n];
    for (int i = 0; i < n; ++i) {
        arr[i] = new double[m];
        for (int k = 0; k < m; ++k) {
            std::cout << "INPUT arr[" << i << "][" << k << "]: ";
            std::cin >> arr[i][k];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < m; ++k) {
            if (abs(arr[i][k] - 5) <= 1.2) {
                sum += arr[i][k];
                ++count;
            }
        }
    }

    std::cout << "COUNT = " << count << std::endl;
    std::cout << "SUM = " << sum << std::endl;
}
void lab8_6_v() {
    int n;
    int sum = 0;
    std::cout << "INPUT N: ";
    std::cin >> n;

    std::vector<std::vector<int>> arr;
    arr.resize(n);
    srand(time(0));
    for (int i = 0; i < n; ++i) {
        arr[i].resize(n);
        for (int k = 0; k < n; ++k) {
            arr[i][k] = rand() % 10;
        }
    }

    std::cout << "\nARRAY BEFORE:\n";
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < n; ++k) {
            char ch = '\t';
            std::string s = "\t";
            std::cout << arr[i][k] << '\t';
        }
        std::cout << std::endl;
    }

    std::cout << "\nARRAY AFTER:\n";

    bool desired_element = true;
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < n; ++k) {
            if (desired_element) {
                desired_element = false;
                sum += arr[i][k];
                arr[i][k] = 0;
            }
            else desired_element = true;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < n; ++k) {
            std::cout << arr[i][k] << "\t";
        }
        std::cout << std::endl;
    }

    std::cout << "SUM = " << sum << std::endl;
}
void lab10_23_17() {
    
    int len_A, len_B;
    std::cout << "INPUT LEN A: ";
    std::cin >> len_A;
    std::cout << "INPUT LEN B: ";
    std::cin >> len_B;

    vector<int> A;
    vector<int> B;
    fill_vector(A, len_A);
    srand(time(NULL));
    fill_vector(B, len_B);
    
    std::cout << "Answer for A: " << counting_of_answer(A) << '\n';
    std::cout << "Answer for B: " << counting_of_answer(B) << '\n';  
}
void lab11() {
//VAR 17 LAB 
    int n;
    std::cout << "INPUT N: ";
    std::cin >> n;
    std::cout << "ANSWER: " << lab11_recursion(n) << '\n';
}
void lab12() {
    // * -> +
    std::string str;
    std::cout << "INPUT STRING: ";
    std::getline(std::cin, str);
    bool have = false;
    for (int i = 0; i < str.size(); ++i) {
        if (have && str[i] == '*') str[i] = '+';
        if ((!have && str[i] == '*' && i != 0 && str[i - 1] == ' ') ||
            (i == 0 && str[i] == '*')
            ) have = true;
    }

    std::cout << str << '\n';
}
void lab12_defense() {
   
}
void lab13() {
    //work with file (input, output)
    const char* file_name = "f.txt";
    double answer = 1;

    std::ofstream out_file(file_name);
    if (!out_file.is_open()) {
        std::cout << "Can't open file!";
        return;
    }
    int count_number;
    double num;
    std::cout << "How many numbers do you want to enter: ";
    std::cin >> count_number;
    for (int i = 0; i < count_number; ++i) {
        std::cout << "Input number: ";
        std::cin >> num;
        out_file << num << std::endl;
    }
    out_file.close();
    
    
    std::string str_of_num;
    std::ifstream in_file(file_name);
    if (in_file.is_open()) {
        while (std::getline(in_file, str_of_num)) {
            answer *= std::atof(str_of_num.c_str());
        }
    } else {
        std::cout << "Can't open file\n";
        return;
    }
    in_file.close();
    std::cout << "Answer: " << answer << '\n';
}
void lab13_defense() {
    const char* file_name = "f.txt";

    std::ofstream out_file(file_name, std::ostream::app);
    if (out_file.is_open()) {
        std::string str_1, str_2, str_3;
        std::cout << "Input e: ";
        std::getline(std::cin, str_1);
        std::cout << "Input n: ";
        std::getline(std::cin, str_2);
        std::cout << "Input d: ";
        std::getline(std::cin, str_3);
        out_file << str_1;
        out_file << str_2;
        out_file << str_3;
    }
    else std::cout << "\nCan't open file!\n";

}
using std::vector;
using std::string;

const vector<string> ZNAKI = { "dafault", "�������","�������","����","����","�����","��������",
                               "���","���","����","����","��������","�������" };
class Znak {
    string firstName;
    string lastName;
    vector<int> dateOfB;
    int znak;

public:
    Znak(string firstName, string lastName, vector<int> dateOfB, int znakId) {
        this->firstName = firstName;
        this->lastName = lastName;
        this->dateOfB = dateOfB;
        this->znak = znakId;
    }

    bool operator<(const Znak& rhs)
    {
        return this->getIntZnak() < rhs.getIntZnak();
    }

    [[nodiscard]] string getFirstName() const noexcept { return this->firstName; }
    [[nodiscard]] string getLastName() const noexcept { return this->lastName; }
    [[nodiscard]] string getZnak() const noexcept { return ZNAKI[this->znak]; }
    [[nodiscard]] int getIntZnak() const noexcept { return this->znak; }
    [[nodiscard]] vector<int> getdateOfB() const noexcept { return this->dateOfB; }

    void setFirstName(string value) { this->firstName = value; }
    void setLastName(string value) { this->lastName = value; }
    void setZnak(int value) { this->znak = value; }
    void setdateOfB(vector<int> array) { this->dateOfB = array; }

};


void setUserData(int id, vector<Znak>& arr) {
    string firstName;
    string lastName;
    int znak_id;
    vector<int> dateOfB;
    int int_value;
    std::cout << "������� ���: ";
    std::cin >> firstName;
    arr[id].setFirstName(firstName);
    std::cout << "������� �������: ";
    std::cin >> lastName;
    arr[id].setLastName(lastName);
    std::cout << "������� ����� ����� �������: ";
    std::cin >> znak_id;
    arr[id].setZnak(znak_id);
    std::cout << "���� ��������: ";
    std::cin >> int_value;
    dateOfB.push_back(int_value);
    std::cout << "����� ��������: ";
    std::cin >> int_value;
    dateOfB.push_back(int_value);
    std::cout << "��� ��������: ";
    std::cin >> int_value;
    dateOfB.push_back(int_value);
    arr[id].setdateOfB(dateOfB);
}
void showUsers(vector<Znak>& users) {
    for (int i = 0; i < users.size(); ++i) {
        std::cout << "\nUSER �" << i << '\n';
        std::cout << "����: " << users[i].getZnak() << '\n';
        std::cout << "��� � �������: " << users[i].getFirstName() << " " << users[i].getLastName() << '\n';
        vector <int> date = users[i].getdateOfB();
        std::cout << "���� ��������: " << date[0] << " " << date[1] << " " << date[2] << "\n\n";
    }
}
void showUsersMonth(vector<Znak> const& users, int month) {
    bool have = false;
    for (int i = 0; i < users.size(); ++i) {
        if ((users[i].getdateOfB())[1] == month) {
            have = true;
            std::cout << "\nUSER �" << i << '\n';
            std::cout << "����: " << users[i].getZnak() << '\n';
            std::cout << "��� � �������: " << users[i].getFirstName() << " " << users[i].getLastName() << '\n';
            vector <int> date = users[i].getdateOfB();
            std::cout << "���� ��������: " << date[0] << " " << date[1] << " " << date[2] << "\n\n";
        }
    }

    if (!have) std::cout << "��� ����� �������������.\n";
}
void saveDataToFile(vector<Znak> const& users, const char* file_name) {
    std::ofstream out_file(file_name);
    if (out_file.is_open()) {
        for (int i = 0; i < users.size(); ++i) {
            string user = "";
            vector<int> dateOfB = users[i].getdateOfB();
            user = users[i].getFirstName() + " "
                + users[i].getLastName() + " "
                + std::to_string(users[i].getIntZnak()) + " "
                + std::to_string(dateOfB[0]) + " " + std::to_string(dateOfB[1]) + " " + std::to_string(dateOfB[2]);
            out_file << user << '\n';
            /*out_file << users[i].getFirstName() << '\n';
            out_file << users[i].getLastName() << '\n';
            out_file << std::to_string(users[i].getIntZnak()) << '\n';
            out_file << std::to_string(dateOfB[0]) << '\n';
            out_file << std::to_string(dateOfB[1]) << '\n';
            out_file << std::to_string(dateOfB[2]) << '\n';*/
        }
        out_file.close();
    }
    else {
        std::cout << "Cant open file!\n";
    }
}
void loadDataFromFile(vector<Znak>& users, const char* file_name) {
    std::ifstream in_file(file_name);
    if (in_file.is_open()) {
        string str;
        while (std::getline(in_file, str)) {
            string data;
            vector<string> user;
            for (int i = 0; i < str.size(); ++i) {
                if (str[i] != ' ' && i + 1 != str.size()) {
                    data += str[i];
                }
                if (str[i] == ' ' || i + 1 == str.size()) {
                    user.push_back(data);
                    data = "";
                }
            }
            string firstName = user[0];
            string lastName = user[1];
            int znak_id = std::atoi(user[2].c_str());
            vector<int> dateOfB = { std::atoi(user[3].c_str()),
                                   std::atoi(user[4].c_str()),
                                   std::atoi(user[5].c_str()) };
            Znak new_user(firstName, lastName, dateOfB, znak_id);
            users.push_back(new_user);
        }
    }
    in_file.close();
}

void lab29() {
    vector<Znak> users; const char* file_name = "test.txt";
    while (true) {
        std::cout << "��� �� ������ �������?"
            "\n1: �������� �������������."
            "\n2: ������������� ������������."
            "\n3: ���������� �������������."
            "\n4: ���������� ������������� �� ������ ��������."
            "\n5: ������� ������������."
            "\n6: ��������� ������ �� �����."
            "\n7: ��������� ������ � ����."
            "\n8: ����������� ������ ������������� �� ������ �������."
            "\n9: �����."
            "\n�����: ";

        int answer;
        std::cin >> answer;
        if (answer == 9) break;
        if (answer == 6) loadDataFromFile(users, file_name);
        if (users.size() == 0 && (answer == 2 || answer == 3 || answer == 4 || answer == 5 || answer == 7 || answer == 8)) {
            std::cout << "������������ ��� �� ���������!\n\n";
        }
        else {
            if (answer == 8) std::sort(users.begin(), users.end());
            if (answer == 7) saveDataToFile(users, file_name);
            if (answer == 5) {
                showUsers(users);
                int answerId;
                std::cout << "������ ������������ ������ �������? (������� ��� �����): ";
                std::cin >> answerId;
                users.erase(users.begin() + answerId);
            }
            if (answer == 4) {
                int month;
                std::cout << "������� �����: ";
                std::cin >> month;
                showUsersMonth(users, month);
            }
            if (answer == 3) {

                showUsers(users);
            }
            if (answer == 2) {
                showUsers(users);
                int answerId;
                std::cout << "������ ������������ ������ �������������? (������� ��� �����): ";
                std::cin >> answerId;
                setUserData(answerId, users);
            }
        }

        if (answer == 1) {
            int quantity = 0;
            std::cout << "������� ������������� ��������? ";
            std::cin >> quantity;
            for (int i = 0; i < quantity; ++i) {
                vector<int> dateOfB = { 0, 0, 0 };
                Znak newUser("default", "default", dateOfB, 0);
                users.push_back(newUser);
                setUserData(users.size() - 1, users);
                std::cout << '\n';
            }
        }

    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    lab29();
    system("pause");
    return 0;
}

