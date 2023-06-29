#include <iostream>
#include <cmath>
using namespace std;
void analyzeDividors(int num, int& outCountDivs, int& outSumDivs);
bool isPerfect(int num);
int outCountDivs, outSumDivs;
int main() {
    int M, num, sum_1, sum_2;
    cout << "Please enter a positive integer number (≥ 2): ";
    cin >> M;
    cout << "All the perfect numbers between 2 and " << M << ":\n";
    for (num = 2; num <= M; num++) {
        if(isPerfect(num))
            cout << num << " ";
    }
    cout << endl;
    cout << "All pairs of amicable numbers that are between 2 and " << M << ":\n";
    for (num = 2; num <= M; num++) {
        analyzeDividors(num, outCountDivs, outSumDivs);
        sum_1 = outSumDivs;
        analyzeDividors(sum_1, outCountDivs, outSumDivs);
        sum_2 = outSumDivs;
        if (num == sum_2 && sum_1 <= M && num < sum_1)
            cout << num << " and " << sum_1 << endl;        
    }
    return 0;
}

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs) {
    outCountDivs = 0;
    outSumDivs = 0;
    for (int div = 1; div <= sqrt(num); div++) {
        if (num % div == 0){
            outCountDivs++;
            outSumDivs = outSumDivs + div;
        }
    }
    for (int div = sqrt(num); div > 1; div--) {
        if (num % div == 0){
            if (num / div != div) {
                outCountDivs++;
                outSumDivs = outSumDivs + (num / div);
            }
        }
    }
}
bool isPerfect(int num) {
    outCountDivs = 0;
    outSumDivs = 0;
    analyzeDividors(num, outCountDivs, outSumDivs);
    return (num == outSumDivs);
}