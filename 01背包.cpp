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
	static int n,m;//һ����n��,���������Ϊm
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
		cout<<"���������ͼ۸�"<<endl;
		cin>>w>>v;
		g[i].setdata(w,v);

	}

//������ö��
	for(int i = 0; i < (1<<n); i++) { //��0��2^n-1��״̬
		for(int j = 0; j < n; j++) { //���������Ƶ�ÿһλ
			if(i & (1 << j)) { //�ж϶����Ƶ�jλ�Ƿ����
				value[i]=value[i]+g[j].value;
				weight[i]=weight[i]+g[j].weight;
				sum[i][j]=j;
			}

		}

	}

//�ҳ����
	static int maxvalue = value[0];
	static int maxi = 0;
	for(int i=0; i<(1<<n); i++) {
		if(weight[i]<=m&&value[i]>maxvalue) {
			maxvalue = value[i];
			maxi = i;
		}
	}

//��� 
	for(int j=0; j<(1<<n); j++) {
		if(sum[maxi][j]!=-1)
			cout<<"ѡȡ��"<<sum[maxi][j]+1<<"��"<<endl;
	}
	cout<<"������Ϊ"<<maxvalue<<endl;
}
