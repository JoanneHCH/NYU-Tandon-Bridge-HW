#include <iostream>
using namespace std;

int main(){
	
    int n, count, rem, even_count = 0, odd_count = 0;
    cout << "Please input a positive integer n: ";
    cin >> n;

    for (count = 1; count <= n; count++){
        int num = count;
        while (num > 0){
            rem = num % 10;
            if(rem % 2 == 0)
                even_count++;
            else
                odd_count++;
            num = num / 10;
        }
        
        if(even_count > odd_count)
            cout << count << endl;   

        even_count = 0; 
        odd_count = 0;  
    }
    
    return 0;
}