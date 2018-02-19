#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
using namespace std;

int GetBit(char c,int i){
	return (c>>i)&1;
}

void SetBit(char &c,int i,int v){
	if(v == 1){
		c |= (1<<i);
	}
	else{
		c &= ~(1<<i);
	}
}

void Flip(char &c,int i){
	c ^= (1<<i);
}

int main(){
	string str,str2;
	char c1 = 0,c2 = 0,c3[100] = {0},c4 = 0;
	cin>>str>>str2;
	for(int i = 0;i<str.length();i++){
		SetBit(c1,i,str[i]);
		SetBit(c4,i,str2[i]);
	}
	c2 = c1;
	int min = 10000000;
	for(int n = 0;n<2^str.length();n++){
		c3 = n;
		int num = 0;
		for(int i = 0;i<str.length();i++){
			if(GetBit(c3,i)){
				if(i>0)Flip(c2,i-1);
				Flip(c2,i);
				if(i<str.length()-1)Flip(c2,i+1);
				num ++;
			}
		}
		if(c2 == c4){
			if(num<min)min = num;
		}
	}
	if(min != 10000000)cout<<min;
	else cout<<"impossible";
	return 0;
}
