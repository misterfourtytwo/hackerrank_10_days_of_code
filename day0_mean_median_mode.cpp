#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>      // std::setprecision

using namespace std;

const int N = 100000;
int n;
int numbers[N];

long double _calculate_mean(){
    long double sum = 0;
    for (int i = 0; i< n; i++) {
        sum += numbers[i];
    }
    return sum / n;
}

long double _calculate_median() {
    sort(numbers, numbers + n);
    
    // cout << "sorted:" << endl;
    // for (int i = 0; i< n; i++) {
    //     cout << numbers[i] <<" ";
    // }
    // cout << endl;
    
    return n % 2 ? 
        numbers[n / 2] : 
        static_cast<long double>(numbers[n/2-1] + numbers[n/2])/2;
}

int _calculate_mode() {
    
//    cout << "sorted?:" << endl;
//    for (int i = 0; i< n; i++) {
//        cout << numbers[i] <<" ";
//    }
    // cout << endl;
    
    int answer = numbers[0];
    int answer_count = -1;
    
    int current_num = numbers[0];
    int current_count = 0;    
    
    for (int i = 0; i <n; i++)
    {
        if (current_num != numbers[i]) {
            if (current_count > answer_count) {
		// cout << "current_count:" << current_count << " current_num:" << current_num;
                answer = current_num;
                answer_count = current_count;
            }
            current_num = numbers[i];
            current_count = 0;
        } 
        current_count ++;
    }

    if (current_count > answer_count) {
    	// cout << "current_count:" << current_count << " current_num:" << current_num;
	answer = current_num;
	answer_count = current_count;
    }
            
    return answer;
}

int main() {
    cin >> n;
    for (int i = 0; i<n; i++){
        cin >> numbers[i];
    }
    
    cout << fixed;
    cout << setprecision(1) <<_calculate_mean() << endl;
    cout << setprecision(1)<<_calculate_median() << endl;
    cout << _calculate_mode() << endl;
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

