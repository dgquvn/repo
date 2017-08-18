//
//  main.cpp
//  FizzBuzz_generic_v1
//
//  Created by Guoqiang Deng on 8/18/17.
//  Copyright © 2017 Guoqiang Deng. All rights reserved.
//

// This is the generic program for print FizzBuzz
// More details can be found in README.md 2nd problem definition

#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <vector>
using namespace std;

string strRead(const string& s);

int main(){
    ifstream inputFile("input.txt");
    vector<string> inputStr(5);
    if (inputFile.is_open()){
        for (int i = 0; i < 5; i++){
            string line;
            getline(inputFile, line);
            inputStr[i] = strRead(line);
        }
        
        inputFile.close();
    }
    
    int max_Int = stoi(inputStr[0]);
    int lower_divisor = stoi(inputStr[1]);
    int upper_divisor = stoi(inputStr[2]);
    string lower_div_lab = inputStr[3];
    string upper_div_lab = inputStr[4];
    if (lower_divisor > upper_divisor){
        swap(lower_divisor, upper_divisor);
        swap(lower_div_lab, upper_div_lab);
    }
    
    int multiple_divisor = lower_divisor * upper_divisor;
    ofstream outputFile("output.txt", ios::out);
    if (outputFile.is_open()){
        for (int i = 1; i <= max_Int; i++){
            if (i % multiple_divisor == 0)
                outputFile << lower_div_lab << upper_div_lab << "\n";
            else if (i % upper_divisor == 0)
                outputFile << upper_div_lab << "\n";
            else if (i % lower_divisor == 0)
                outputFile << lower_div_lab << "\n";
            else
                outputFile << i << "\n";
        }
        outputFile.close();
    }
    return 0;
}

string strRead(const string& s){
    auto pos = s.find('=');
    string res = s.substr(pos+1, s.size()-pos-1);
    while(res[0] == ' '){
        res.erase(res.begin());
    }
    while(res.back() == ' '){
        res.pop_back();
    }
    return res;
}
