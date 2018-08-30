#include<stdio.h>
#include<algorithm>
using namespace std;
int ans[100],mx;
int main()
{
    int n,t,p;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&t,&p);
        if(ans[i%100]>mx)mx=ans[i%100];
        else ans[i%100]=mx;
        ans[(i+t)%100]=max(ans[(i+t)%100],ans[i%100]+p);
    }
    printf("%d",max(mx,ans[(n+1)%100]));
    return 0;
}

