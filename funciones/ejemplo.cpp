#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
 }
 cout<<"Los numeros son:";
 for (int i = 0; i < n; i++) {
    cout<<nums[i]<<endl;
 }

}