#include <iostream>
#include <string>

using namespace std;
/*Please enter weight (in pounds): 135
Please enter height (in inches): 71
The weight status is: Normal*/
//1 pound is 0.453592 kilograms and 1 inch is 0.0254 meters.

int main(){

    float weight, height, weight_kg, height_m, BMI;
    string status;
   
    cout << "Please enter weight (in pounds): ";
    cin >> weight;
    cout << "Please enter height (in inches): ";
    cin >> height;

    weight_kg = weight * 0.453592;
    height_m = height * 0.0254;
    BMI = weight_kg / (height_m * height_m);

    if (BMI < 18.5)
        status = "Underweight";
    else if ((18.5 <= BMI) && (BMI < 25))
        status = "Normal";
    else if ((25 <= BMI) && (BMI < 30))
        status = "Overweight";
    else
        status = "Obese";
    
    cout << "The weight status is: " << status << endl;

    return 0;
}