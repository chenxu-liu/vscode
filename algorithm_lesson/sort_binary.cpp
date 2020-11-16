#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstdlib>
using namespace std;
void quick_sort(int *num, int l, int r) {//快速排序
    if (r < l) return ;
    int x = l, y = r, z = num[l]; //以第一个元素为枢纽轴
    while (x < y) {                  
        while (x < y && num[y] >= z) y--;//从左面找到第一个比枢纽轴小的元素
        if (x < y) num[x++] = num[y];    //将它放到空位上
        while (x < y && num[x] <= z) x++;//从右面找到第一个比枢纽轴大的元素
        if (x < y) num[y--] = num[x]; //将它放到空位上
    }
    num[x] = z;
    quick_sort(num, l, x - 1);  
    quick_sort(num, x + 1, r);
    return ;
}

int binarySearch(int *nums, int target,int n) {
    int left = 0, right = n-1;

    while(left!= right) {
        int mid = left+((right-left)>>1);
        if (nums[mid] < target) {
            left = mid+1;
        } else if (nums[mid] >= target) {
            right = mid;
        }
    }
    return (nums[left]==target ? left : -1);
}
int main(){
    int num,temp,search_num;
    cout << "输入生成数据的规模:";
    cin >> num;
    cout << "输入查询的数字:";
    cin >> search_num;
    FILE *fp;
    if((fp=fopen("input.txt","w+"))==NULL)
    {
        printf("The file %s can not be opened.\n","input.txt");
        return 0;
    }
    //生成数据
    srand(time(0));
    for(int i = 0; i < num; i++) {
        temp = rand() % num;
        fprintf(fp,"%d ",temp);
    }
    int mmap[num];
    //将数据使用快速排序
     rewind(fp);
    for(int i = 0; i < num; i++) {
        fscanf(fp,"%d ",&temp);
       // printf("%d ",temp);
        mmap[i] = temp;
    }
    quick_sort(mmap,0,num-1);
    int flag = binarySearch(mmap,search_num,num);
    cout << "数的位置（以0开始，-1为未找到）:"<< flag << endl;
    for(int i = 0; i < num; i++){
        printf("%d ", mmap[i]);
    }
    FILE *fp1;
    if((fp1=fopen("output.txt","wb"))==NULL)
    {
        printf("The file %s can not be opened.\n","output.txt");
        return 0;
    }
    for(int i = 0; i < num; i++) {
       fprintf(fp1,"%d ",mmap[i]);
    }
    fclose(fp);
    fclose(fp1);
    return 0;
}