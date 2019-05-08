#include<iostream>
#include<string>
using namespace std;
class Monster {
	public:
		int life=30;
	public:
		virtual void hurted(int m) {
		}
};
class birdman:public Monster {
	public:
		int life=30;
		virtual void hurted(int m) {
			cout<<"鸟人生命值减"<<m<<"!!"<<endl;
			life = life-m;
		}
};
class flashfish:public Monster {
	public:
		int life=30;
		virtual void hurted(int m) {
			cout<<"飞鱼生命值减"<<m<<"!!"<<endl;
			life = life-m;
		}
};
class arms {
	public:
		int m;
		arms(int l=10):m(l) {
		}

		void display() {
			cout<<"m:"<<m<<endl;
		}

};
class woodkinef:public arms {
	public:
		woodkinef(int l=20):arms(l) {
		}

};

class ironkinef:public arms {
	public:
		ironkinef(int l=30):arms(l) {
		}

};
class Role {
	public:
		int life;
		arms a;
		Role(int l,arms ar):life(l),a(ar) {
		}
		virtual void usearms(Monster *p) {
			p->hurted(a.m);
		}
};
int main() {
	arms a;
	woodkinef w;
	ironkinef i;
	birdman *b = new birdman;
	flashfish *f = new flashfish;

	Role r1(40,w);
	Role r2(40,i);
	Role r3(40,a);

	r3.usearms(b);
	r1.usearms(b);
	r2.usearms(f);
}
