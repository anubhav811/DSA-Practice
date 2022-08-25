class Solution {
public:
    int rotatedDigits(int n) {
        int count = 0;
        for(int i=1; i<=n; i++)
        {
            bool flag = false;
            int num = i;
            while(num > 0)
            {
                int d = num%10;
                if(d == 3 || d == 4 || d == 7)
                {
                    flag = false;
                    break;
                }
                if(d == 2 || d == 5 || d == 6 || d == 9)
                    flag = true;
                
                num = num/10;
            }
            if(flag) count++;
        }
        return count;

    }
};