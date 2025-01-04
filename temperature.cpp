#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool is_digit_or_sign(char znak) {
    return (isdigit(znak) || znak == '+' || znak == '-');
}

int find_smallest_abs_value(vector<int>& nums) {
    sort(nums.begin(), nums.end(), [](int a, int b) {
        return abs(a) < abs(b) || (abs(a) == abs(b) && a > b);
    });
    return nums[0];
}

int main() {
    int n;
    cin >> n;
    cin.ignore();

    string temps;
    getline(cin, temps);

    vector<int> numbers;
    string temp;

    for (size_t i = 0; i < temps.length(); ++i) {
        if (is_digit_or_sign(temps[i])) {
            temp += temps[i];
        } else if (!temp.empty()) {
            numbers.push_back(stoi(temp));
            temp.clear();
        }
    }
    if (!temp.empty()) {
        numbers.push_back(stoi(temp));
    }

    if (!numbers.empty()) {
        cout << find_smallest_abs_value(numbers) << endl;
    } else {
        cout << "0" << endl;
    }

    return 0;
}
