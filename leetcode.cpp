
class Solution {
public:
    string longestPalindrome(string s) 
    {
        string T;// Transform S to T
        for(int i = 0; i < s.size(); i++)
            T += "#" + s.substr(i , 1);

        T.push_back('#');

        vector<int> P( T.size() , 0); // Array to record longest palindrome
        int center = 0, boundary = 0, maxLen = 0, resCenter = 0;

        for(int i = 1; i < T.size()-1; i++) {
            int iMirror = 2 * center - i; // calc mirror i = center-(i-center)
            P[i] = (boundary > i) ? min( boundary - i, P[iMirror]) : 0; // shortcut
            while (i-1-P[i] >= 0 && 
                i + 1 + P[i] <= T.size()-1 && 
                T[i + 1 + P[i]] == T[i - 1 -P[i]]) // Attempt to expand palindrome centered at i
                
                P[i]++;
            
            if( i + P[i] > boundary ) { // update center and boundary
                center = i;
                boundary = i + P[i];
            }

            if( P[i] > maxLen ) { // update result
                maxLen = P[i];
                resCenter = i;
            }    
        }
        return s.substr((resCenter - maxLen)/2, maxLen);
    }
};



class Solution {

public:
    string longestPalindrome(string s){
        string T;
        for (int i = 0; i < s.size(); i++){
            T += "#" + substring(i, 1);
        }
        T += "#";
        vector<int> P (T.size(), 0);
        int center = 0, boundary = 0, maxlen = 0, resCenter = 0;
        for (int i = 0; i < T.size(); i ++){
            int iMirror = 2 * center - i;
            P[i] = (boundary > i) ? min(boundary - i, P[mirror]) : 0;

            while ( (i - 1 - P[i] >= 0) &&
                i + 1 + P[i] <= T.size() - 1 && 
                T[i + 1 + P[i]] == T[i - 1 - P[i]])
                P[i] ++
            if (i + P[i] > boundry){
                boundry = i + P[i];
                center = i;

            }
            if (P[i] > maxlen){
                maxlen = P[i];
                resCenter = i;
            }


        }
        return s.substr((resCenter - maxlen)/ 2, maxlen)
    }
}