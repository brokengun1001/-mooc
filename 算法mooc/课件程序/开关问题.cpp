#include<cstring>
#include<string>
#include<iostream>
using namespace std;

int getBit(char c,int i){
	return (c>>i)&1;
} 

void setBit(char &c,int i,int v){
	if(v==1){
		c|=(1<<i); 
	}
	else{
		c&=~(1<<i);
	}
}

void Flip(char &c,int i){
	 c ^= (1<<i);
}

void OutputResult(int t,char result[]){
	cout<<"PUZZLE #"<<t<<endl;
	for(int i = 0;i < 5;i++){
		for(int j = 0;j < 6;j++){
			cout<<getBit(result[i],j);
			if(j<5)cout<<" ";
		}
		cout<<endl;
	}
}

int main(){
	char oriLight[5] = {0};
	char Light[5] = {0};
	char result[5] = {0};
	int T;
	cin>>T;
	for(int t = 1;t<=T;t++){
		for(int i = 0;i < 5;i ++){
			for(int j = 0;j < 6;j ++){
				int s;
				cin>>s;
				setBit(oriLight[i],j,s);
			}
		}
		for(int n = 0;n < 64;n++){
			memcpy(Light,oriLight,sizeof(oriLight));
			int switchs = n;
			for(int i = 0;i < 5;i++){
				result[i] = switchs;
				for(int j = 0;j<6;j++){
					if(getBit(switchs,j)){
						if(j>0)Flip(Light[i],j-1);
						Flip(Light[i],j);
						if(j<5)Flip(Light[i],j+1);
					}
				}
				if(i<5)
					Light[i+1] ^= switchs;
				switchs = Light[i];
			}
			if(Light[4] == 0){
				OutputResult(t,result);
				break;
			}
		}
		
	}
}
