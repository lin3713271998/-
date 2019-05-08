#include<iostream>
#include <bits/stdc++.h>
#include<algorithm>
#include<cstring>
using namespace std;
class goods {
	public:
		int weight;
		int value;
		goods() {
		}

		void setdata(int w,int v) {
			weight = w;
			value = v;
		}
		void display() {
			cout<<weight<<" "<<value<<endl;
		}
};

int main() {
	static int n,m;//一共有n个,最大载重量为m
	cin>>n>>m;
	int sum[(1<<n)][(1<<n)];
	int value[(1<<n)];
	int weight[(1<<n)];
	memset(sum,-1,sizeof(sum));
	memset(value,0,sizeof(value));
	memset(weight,0,sizeof(weight));
	goods g[n];
	for(int i=0; i<n; i++) {
		int w,v;
		cout<<"输入重量和价格"<<endl;
		cin>>w>>v;
		g[i].setdata(w,v);

	}

//二进制枚举
	for(int i = 0; i < (1<<n); i++) { //从0～2^n-1个状态
		for(int j = 0; j < n; j++) { //遍历二进制的每一位
			if(i & (1 << j)) { //判断二进制第j位是否存在
				value[i]=value[i]+g[j].value;
				weight[i]=weight[i]+g[j].weight;
				sum[i][j]=j;
			}

		}

	}

//找出最大
	static int maxvalue = value[0];
	static int maxi = 0;
	for(int i=0; i<(1<<n); i++) {
		if(weight[i]<=m&&value[i]>maxvalue) {
			maxvalue = value[i];
			maxi = i;
		}
	}

//输出 
	for(int j=0; j<(1<<n); j++) {
		if(sum[maxi][j]!=-1)
			cout<<"选取第"<<sum[maxi][j]+1<<"项"<<endl;
	}
	cout<<"总重量为"<<maxvalue<<endl;
}
