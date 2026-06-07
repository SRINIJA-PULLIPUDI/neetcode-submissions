class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> s = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int n=digits.size();
        vector<string> res;
        if(n==1){
            int digit = digits[0]-'0';
            for(int i=0;i<s[digit].size();i++){
                string k = "";
                k+=s[digit][i];
                res.push_back(k);
            }
            return res;
        }if(n==2){
            int dig1 = digits[0]-'0',dig2 = digits[1]-'0';
            for(int i=0;i<s[dig1].size();i++){
                for(int j=0;j<s[dig2].size();j++){
                    string k="";
                    k+=s[dig1][i];
                    k+=s[dig2][j];
                    res.push_back(k);
                }
            }
            return res;
        }if(n==3){
            int dig1 = digits[0]-'0',dig2 = digits[1]-'0', dig3 = digits[2]-'0';
            for(int i=0;i<s[dig1].size();i++){
                for(int j=0;j<s[dig2].size();j++){
                    for(int k=0;k<s[dig3].size();k++){
                        string l="";
                        l+=s[dig1][i];
                        l+=s[dig2][j];
                        l+=s[dig3][k];
                        res.push_back(l);
                    }
                }
            }
            return res;
        }if(n==4){
            int dig1 = digits[0]-'0',dig2 = digits[1]-'0', dig3 = digits[2]-'0'
            ,dig4 = digits[3]-'0';
            for(int i=0;i<s[dig1].size();i++){
                for(int j=0;j<s[dig2].size();j++){
                    for(int k=0;k<s[dig3].size();k++){
                        for(int l=0;l<s[dig4].size();l++){
                            string m="";
                            m+=s[dig1][i];
                            m+=s[dig2][j];
                            m+=s[dig3][k];
                            m+=s[dig4][l];
                            res.push_back(m);
                        }
                    }
                }
            }
            return res;
        }
        return res;
    }
};
