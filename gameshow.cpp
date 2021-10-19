#include<bits/stdc++.h>

using namespace std;

vector<int> foo;
int c;
vector<int> tab(102,-1);

int solve(int n)
{
    if(n == c)
        return 0;
    
    if(tab[n] >-1)
        return tab[n];
        
    int pega = solve(n+1)+foo[n];
    
    tab[n] = max(pega,0);
    
    return tab[n];
}

int main()
{
    int aux;
    
    scanf("%d",&c);
    
    for(int i = 0; i < c;i++)
    {
        scanf("%d",&aux);
        foo.push_back(aux);
    }
    
    printf("%d\n",100+solve(0));
    return 0;
}
