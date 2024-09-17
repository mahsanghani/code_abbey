#include <iostream>

using namespace std;

consteval int get_value() {
    return 3;
}

int main() {
    constexpr int value = get_value();
    cout << "value: " << value << endl;
    return 0;
}