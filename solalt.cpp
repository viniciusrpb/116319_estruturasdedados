#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,aux,ans;
    vector<int> pinos;
    
    scanf("%d %d",&n,&m);
    
    for (int i=0;i<n;i++)
    {   
        scanf("%d",&aux);
        pinos.push_back(aux);
    }
    
    ans=0;
    for (int i=1;i<n;i++)
    {
        ans=ans+abs(pinos[i-1]-m);
        pinos[i]=pinos[i]+m-pinos[i-1];
        pinos[i-1]=m;
    }
    
    printf("%d\n",ans);
    
    return 0;
}
