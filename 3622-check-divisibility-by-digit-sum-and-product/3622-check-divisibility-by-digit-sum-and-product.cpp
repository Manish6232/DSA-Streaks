class Solution {
public:
    bool checkDivisibility(int n) {
        int original = n;
        int digitSum=0;
        int digitProduct=1;
        while (n>0){
            int digit = n%10; // 99%10 = 09
            digitSum += digit;
            digitProduct *= digit;
            n /= 10; // 99/10 = 9
        }
        int divisor = digitSum +digitProduct;
        return original % divisor == 0;
    }
};