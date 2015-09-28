#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

int myatoi(string str){
	int result = 0;
	int flag = 1;
	const char* mychar = str.c_str();
	if(!str.empty() && *mychar != '\0'){
		while(*mychar != '\0'){
			if(*mychar == ' '){
				mychar++;
			}
			else if(*mychar == '+' && *(mychar+1) >= '0' && *(mychar+1) <= '9'){
				mychar++;
				break;
			}
			else if(*mychar == '-' && *(mychar+1) >= '0' && *(mychar+1) <= '9'){
				flag = -1;
				mychar++;
				break;
			}
			else if(*mychar >= '0' && *mychar <= '9'){
				break;
			}
			else{
				return 0;
			}
		}

		while(*mychar != '0' && *mychar >= '0' && *mychar <= '9'){
			if(flag == 1 && (result > INT_MAX/10 || result == INT_MAX/10 && *mychar > '7')){
				return INT_MAX;
			}
			if(flag == -1 && (result > INT_MAX/10 || result == INT_MAX/10 && *mychar > '8')){
				return INT_MIN;
			}
			result = result*10 + *mychar - '0';
			mychar++;
		}

	}
	return result*flag;
}

vector<int> atovec(string str){
	vector<int> result;
	const int n = str.size();
	int start = 0, i = 0;
	while(str[i] != '\0'){
		if(str[i] == ' ' && start == i){
			start++;
			i++;
		}
		else if(str[i] == ' ' && start != i){
			result.push_back(myatoi(str.substr(start, i)));
			start = i;
		}
		else{
			i++;
		}
	}
	if(start != i){
		result.push_back(myatoi(str.substr(start, i)));
	}
	return result;
}

vector<vector<int> > ato2Dvec(string str){
	vector<vector<int> > result;
	int count = 0;
	result.push_back(vector<int>());
	int start = 0, i = 0;
	while(str[i] != '\0'){
		if(str[i] == ';'){
			result.push_back(atovec(str.substr(start, i)));
			i++;
			start = i;
		}
		else{
			i++;
		}
	}
	if(start != i){
		result.push_back(atovec(str.substr(start, i)));
	}
	return result;
}

int main(){
	vector<vector<int> > arr;
	string str;
	getline(cin, str);
	arr = ato2Dvec(str);

	for(int i=0; i<arr.size(); i++){
		for(int j=0; j<arr[i].size(); j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
