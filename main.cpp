#include <iostream>
#include <cctype>
#include <string>

class Searcher {
private:
    int* arr;
    int size;

public:
    Searcher(int* array, int len) {
        size = len;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = array[i];
        }
    }

    ~Searcher() {
        delete[] arr;
    }

    int search(const std::string& key) {
        if (isNumber(key)) {
            int num = std::stoi(key);
            if (num >= 0 && num < size) {
                return num;
            }
            else {
                std::cout << "Число для поиска выходит за пределы массива." << std::endl;
                return -1;
            }
        }
        else if (isSymbol(key)) {
            if (key[0] == '-') 
                std::cout << "Число для поиска выходит за пределы массива." << std::endl;
    
            else 
            std::cout << "Символ не может быть использован для поиска." << std::endl;
            return -1;
        }
        else if (isLetter(key)) {
            std::cout << "Буква не может быть использована для поиска." << std::endl;
            return -1;
        }
        else {
            std::cout << "Некорректный символ для поиска." << std::endl;
            return -1;
        }
    }

private:
    bool isNumber(const std::string& str) {
        for (char c : str) {
            if (!std::isdigit(c)) {
                return false;
            }
        }
        return true;
    }

    bool isSymbol(const std::string& str) {
        for (char c : str) {
            if (!std::isalpha(c) && !std::isdigit(c)) {
                return true;
            }
        }
        return false;
    }

    bool isLetter(const std::string& str) {
        for (char c : str) {
            if (!std::isalpha(c)) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    int n;
    std::cout << "Введите размер массива: ";
    std::cin >> n;

    int* arr = new int[n];

    std::cout << "Введите элементы массива: ";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::string key;
    std::cout << "Введите ключ для поиска: ";
    std::cin >> key;

    Searcher searcher(arr, n);
    int result = searcher.search(key);

    if (result != -1) {
        std::cout << "Элемент найден: arr[" << result << "] = " << arr[result] << std::endl;
    }
    else {
        std::cout << "Элемент не найден" << std::endl;
    }

    delete[] arr;

    return 0;
}
