#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;
#define Max 100000
struct backage{
	double weight;
	double value;
}back[Max];
int n;
double u,sum = 0;
bool cmp(const struct backage p,const struct backage q){
	return p.value/p.weight>q.value/q.weight;
}
void zero_backage(){
	int i;
	for(i=0;i<n;i++){
		if(back[i].weight>u)
			break;
		//back[i].account=1;
		u-=back[i].weight;
		sum += back[i].value;
	}
	if(i<n) sum += u/back[i].weight * back[i].value;
}
int main(){
	
	cout << "输入物品数量：";
	cin >> n;
	cout << "输入背包承重：";
	cin >> u;
	srand(time(0));
	int i;
	for(i=0;i<n;i++){
		back[i].value = rand() % 10 + 1;
		back[i].weight = rand() % 10 + 1;
	}

	sort(back,back+n,cmp);
	zero_backage();
	/*for(i=0;i<n;i++){
		cout << "v:" << back[i].value << " w:" << back[i].weight << " ";
	}*/
	//cout << endl;
	cout << "最大价值"<< sum << endl;
	return 0;
}