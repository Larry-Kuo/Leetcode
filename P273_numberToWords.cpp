class Solution {
public:
    string numberToWords(int num) {
        if(num == 0)    return "Zero";

        string ans;
        vector<int> suffix {0, 1000, 1000000, 1000000000};
        map<int, string> convert;
        int cnt = 0;
        convert = {
            {0, ""},
            {1, "One"},
            {2, "Two"},
            {3, "Three"},
            {4, "Four"},
            {5, "Five"},
            {6, "Six"},
            {7, "Seven"},
            {8, "Eight"},
            {9, "Nine"},
            {10, "Ten"},
            {11, "Eleven"},
            {12, "Twelve"},
            {13, "Thirteen"},
            {14, "Fourteen"},
            {15, "Fifteen"},
            {16, "Sixteen"},
            {17, "Seventeen"},
            {18, "Eighteen"},
            {19, "Nineteen"},
            {20, "Twenty"},
            {30, "Thirty"},
            {40, "Forty"},
            {50, "Fifty"},
            {60, "Sixty"},
            {70, "Seventy"},
            {80, "Eighty"},
            {90, "Ninety"},
            {100, "Hundred"},
            {1000, "Thousand"},
            {1000000, "Million"},
            {1000000000, "Billion"}
        };
        while(num > 0){
            int chunk = num % 1000;
            num /= 1000;
            if(cnt >= 1 && chunk > 0){
                ans = convert[suffix[cnt]] + " " + ans;
            }
            if(chunk % 100 <= 20 && chunk % 100 > 0){
                ans = convert[chunk % 100] + " " + ans;
            }
            else if(chunk > 0){
                int tens = ((chunk/10) % 10) * 10;
                int digits = chunk % 10;
                if(digits > 0){
                    ans = convert[digits] + " " + ans;
                }
                if(tens > 0){
                    ans = convert[tens] + " " + ans;
                }
            }
            chunk /= 100;
            if(chunk > 0){
                ans = convert[chunk] + " " + convert[100] + " " + ans;
            }
            cnt ++;
        }
        return ans.substr(0, ans.length() - 1);
    }
};