#include <iostream>
#include <vector>
#include <time.h>
#include <string>

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
void lab9_23_17() {
    
    int len_A, len_B;
    int answer;
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

class Test {

public:
    Test(int &x, int &y) {
        this->x = x;
        this->y = y;
    }

    double v_long() {
        return sqrt(pow(x, 2) + pow(y, 2));
    }
    
    int get_x() {
        return x;
    }

    int get_y() {
        return y;
    }

    void set_x(int x) {
        this->x = x;
    }

    void set_y(int y) {
        this->y = y;
    }

private:
    int x;
    int y;

};

int main()
{  
    system("pause");
    return 0;
}
