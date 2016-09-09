#include<iostream>
#include<string>
#include<cstdio>

typedef long long ll;
ll n,m;
int flag;  //���ֱ����ǳ��ֹ���Ԫ��

ll cal(ll i,ll j)
{
    return  i*i+100000*i+j*j-100000*j+i*j;
}
ll fun(ll x)
{
    ll num=0;
    ll i,l,r,midd;
    for(i=1; i<=n; i++)// ��ÿһ��ö�� 
    {
        l=1,r=n+1;  //��Ҫ��С��x�ĸ���
        midd=(l+r)>>1;
        while(l<r)
        {
            if(cal(midd,i)>=x) r=midd;
            else l=midd+1;
            midd=(l+r)>>1;
        }
        num+=midd-1;  //�п���һ��Ҳû��l=1������Ϊ0
    }
    return num;
}
int main()
{
    int tes;
    scanf("%d",&tes);
    while(tes--)
    {
        scanf("%lld%lld",&n,&m);
        ll left,right,mid;
        left=-1e12,right=1e12;
        mid=(left+right)>>1;
        while(left<right)
        {
            if(fun(mid)>=m) right=mid;
            else left=mid+1;
            mid=(left+right)>>1;
        }
        //�ҵ�ָʵ������m+1����������С�ģ�mid-1��Ϊ��
        printf("%lld\n",mid-1);
    }
    return 0;
}
