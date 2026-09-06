class Solution {
public:
    bool isHappy(int n) {
        int fast = sumOfSquare(n);
        int slow = n;

        while(slow != fast){
            fast = sumOfSquare(fast);
            fast = sumOfSquare(fast);
            slow = sumOfSquare(slow);

        }

        return fast == 1;
    }

private:
    int sumOfSquare(int n){
        int output = 0;
        while( n!=0){
            output += (n%10)*(n%10);
            n /= 10;
        }

        return output;
    }
};

