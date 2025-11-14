// class Solution {
// public:
//     string modifyString(string s) {
//         int n=s.length();
//         for(int i=0;i<n;i++){
//             if(i-1>0 && s[i]=='?' && i+1<n){
//                 for(int j=0;j<26;j++){
//                     char ch=j+'a';
//                     if(ch==s[i-1] || ch==s[i+1]) continue;
//                     s[i]=ch;
//                     break;
//                 }
//             }
//             if(i==0 && s[i]=='?'){
//                 for(int j=0;j<26;j++){
//                     char ch=j+'a';
//                     if(ch==s[i+1]) continue;
//                     s[i]=ch;
//                     break;
//                 }
//             }
//             if(i==n-1 && s[i]=='?'){
//                 for(int j=0;j<26;j++){
//                     char ch=j+'a';
//                     if(ch==s[i-1]) continue;
//                     s[i]=ch;
//                     break;
//                 }
//             }
//         }
//         return s;
//     }
// };
class Solution {
public:
    string modifyString(string s) {
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '?') {
                for (char c = 'a'; c <= 'z'; c++) {
                    if ((i > 0 && s[i - 1] == c) || (i < n - 1 && s[i + 1] == c))
                        continue;
                    s[i] = c;
                    break;
                }
            }
        }
        return s;
    }
};
