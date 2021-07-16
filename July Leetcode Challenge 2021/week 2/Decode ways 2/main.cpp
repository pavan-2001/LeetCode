#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
#define endl '\n'

vector<int> numbers;

int m = 1e9 + 7;

bool helper(int temp) {
    
    if(temp < 1 || temp > 26)
        return false;
    
    return true;
}

bool helper2(int num) {
    if(num < 10 || num >= 27)
    return false;
    
    return true;
}

void myFunction(int &count, string &s, int start) {
    if(start >= s.size()){
        count++;
        // for(auto i : numbers)
        // cout<<i<<' ';
        // cout<<endl;
        return ;
    }

    int currentNum=0;

    if(s[start] != '*' && s[start] != '0') {
        currentNum = currentNum * 10 +(s[start] - '0');
        if(helper(currentNum)) {
            //numbers.push_back(currentNum);
            myFunction(count, s, start+1);
            //numbers.pop_back();
        }
        if(start + 1 < s.size()) {
            if(s[start + 1] != '*' ) {
                currentNum = currentNum * 10 + (s[start + 1] - '0');
                if(helper2(currentNum)) {
                    //numbers.push_back(currentNum);
                    myFunction(count, s, start+2);
                    //numbers.pop_back();
                }
                currentNum/=10;
            } else if(s[start+1] == '*'){
                for(int i=1;i<=9;i++) {
                    currentNum = currentNum * 10 + i;
                    if(helper2(currentNum)) {
                        //numbers.push_back(currentNum);
                        myFunction(count, s, start + 2);
                        //numbers.pop_back();
                    }
                    currentNum/=10;
                }
            }
        }
        currentNum/=10;
    } else if(s[start] == '*'){
        for(int i=1;i<=9;i++) {
            currentNum = currentNum * 10 + i;
            if(helper(currentNum)) {
                //numbers.push_back(currentNum);
                myFunction(count, s, start+1);
                //numbers.pop_back();
            }

                if(start + 1 < s.size()) {
                    if(s[start + 1] != '*') {
                        currentNum = currentNum * 10 + (s[start + 1] - '0');
                        if(helper2(currentNum)) {
                           // numbers.push_back(currentNum);
                            myFunction(count, s, start+2);
                            //numbers.pop_back();
                        }
                        currentNum/=10;
                    } else {
                        for(int j=1;j<=9;j++) {
                            currentNum = currentNum * 10 + j;
                            if(helper2(currentNum)) {
                                //numbers.push_back(currentNum);
                                myFunction(count, s, start + 2);
                                //numbers.pop_back();
                            }
                            currentNum/=10;
                        }
                    }
                }

            currentNum/=10;
        }
    }
}


class Solution {
public:
    int numDecodings(string s) {
        int count=0;
        myFunction(count, s, 0);
        return count;
    }
};

int main() {
    fast
    cout << "\033[2J\033[1;1H";
    string s="*****";
    Solution temp;
    cout<<temp.numDecodings(s)<<endl;

}