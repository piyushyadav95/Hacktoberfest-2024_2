#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int carry = 0;
        
        // Reverse both strings to make addition easier (from least significant to most significant bit)
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        int n = max(a.size(), b.size());
        
        for (int i = 0; i < n; i++) {
            int bitA = i < a.size() ? a[i] - '0' : 0;
            int bitB = i < b.size() ? b[i] - '0' : 0;
            
            // Add corresponding bits and carry
            int sum = bitA + bitB + carry;
            
            // Add the sum's least significant bit to the result
            result += to_string(sum % 2);
            
            // Update carry (if sum is 2 or 3, we have a carry of 1)
            carry = sum / 2;
        }
        
        // If there's a leftover carry, add it to the result
        if (carry) {
            result += '1';
        }
        
        // Reverse the result to get the correct binary sum
        reverse(result.begin(), result.end());
        
        return result;
    }
};

int main() {
    Solution sol;
    
    // Example binary numbers
    string a = "1010";
    string b = "1101";
    
    string sum = sol.addBinary(a, b);
    cout << "Sum of " << a << " and " << b << " is " << sum << endl;
    
    return 0;
}
