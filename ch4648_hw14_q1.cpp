#include <iostream>
#include <vector>
using namespace std;
vector<int> Find(vector<int> a);

int main() {
    vector<int> input = {1, 13, 24, -26, 72, 15, 27, 38};
    vector<int> result = Find(input);
    
    cout << "Min: " << result[0] << ", Max: " << result[1] << endl;

    return 0;
}

vector<int> Find(vector<int> a) {
    int size = a.size();
    vector<int> result(2);

    if (size == 1) {
        result[0] = a[0];
        result[1] = a[0];
        return result;
    } 

    if (size == 2) {
        result[0] = min(a[0], a[1]);
        result[1] = max(a[0], a[1]);
        return result;
    } 
    
    int mid = size / 2;
    vector<int> left_result = Find(vector<int>(a.begin(), a.begin() + mid));
    vector<int> right_result = Find(vector<int>(a.begin() + mid, a.end()));

    result[0] = min(left_result[0], right_result[0]);
    result[1] = max(left_result[1], right_result[1]);

    return result;
}