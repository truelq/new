#include <algorithm>
#include <cmath>
#include <iostream>
#include <math.h>
#include <string>
using namespace std;
struct chengjizuida {
    int num;
    int state;
    int temp;
    double weight;
};

int main()
{
    int N, K;
    string t;
    cin >> N >> K >> t;
    //使用损失最小方案，pian分数
    int ans = 1;
    int point;
    chengjizuida nums[N];
    int temp;
    for (int i = 0; i < N; ++i) {
        temp = t[i];
        nums[i].num = temp - '0';
        nums[i].state = 0;
        //nums[i].zero = N - i - 1;
    }
    nums[0].state = -1;
    for (int i = 0; i < K; ++i) {
        for (int j = 1; j < N; ++j) {
            int zero = 0;
            int s = nums[j].num;
            for (int k = j + 1; k < N; ++k) {
                if (nums[k].state == 1)
                    break;
                ++zero;
                s = s * 10 + nums[k].num;
            }
            nums[j].temp = s;
            nums[j].weight = (double)s / pow(10, zero);
        }
        double temps = 0;
        temp = 0;
        for (int j = 1; j < N; ++j) {
            if (nums[j].state == 0) {
                if (temps < nums[j].weight) {
                    temps = nums[j].weight;
                    temp = j;
                }
            }
        }
        nums[temp].state = 1;
    }
    for (int j = 0; j < N; ++j) {
        int zero = 0;
        int s = nums[j].num;
        for (int k = j + 1; k < N; ++k) {
            if (nums[k].state == 1)
                break;
            ++zero;
            s = s * 10 + nums[k].num;
        }
        nums[j].temp = s;
        nums[j].weight = (double)s / pow(10, zero);
    }
    for(int i=0;i<N;){
        temp=nums[i].num;
        int j;
        for(j=i+1;j<N;++j){
            if(nums[j].state==1)
            break;
            temp=temp*10+nums[j].num;
        }
        i=j;
        ans*=temp;
    }
    cout<<ans;
    return 0;
}
