/*
Problem statement
You're given a string 'STR' containing ‘0’, ‘1’ and ‘?’ special characters. 
Your task is to generate all the strings that are possible by replacing the 
special character ‘?’, with either of the characters ‘0’ or ‘1’.
*/


#include <bits/stdc++.h> 
void ans(string &str, int ind, string &s, vector<string> &result){

    if(ind == str.size()){
        result.push_back(s);
        return;
    }

    if(str[ind] != '?'){
        s += str[ind];
        ans(str, ind + 1 , s, result);
        s.pop_back();
    }
    else{
        s.push_back('0');
        ans(str, ind + 1, s, result);
        s.pop_back(); // backtrack

        s.push_back('1');
        ans(str, ind + 1, s, result);
        s.pop_back(); // backtrack
    }
}

vector<string> binaryStrings(string &str) {
    vector<string> result;
    string s = "";
    ans(str, 0, s, result);
    return result;
}