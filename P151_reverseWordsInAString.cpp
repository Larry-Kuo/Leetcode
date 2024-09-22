class Solution {
public:
    string reverseWords(string s) {
        // Tokenize words
        string word = "";
        // Keep track of the original length
        int length = s.length(); 
        for(int i = length - 1; i >= 0; --i) {
            char c = s[i];
            if(c == ' ') {
                // Reset
                if(word != "") {
                    s += " ";
                    s += word;
                    word = "";
                }
            }
            else{
                word = c + word;
            }
        }
        // Special case for the end of the word
        if(s[0] != ' ') {
            s += " ";
            s += word;
            word = "";
        }

        return s.substr(length + 1);
    }
};