#include<iostream>

using namespace std;

int main()
{
    string s="hello-my-name-is SANDIP",encrypted="";
    int k=3,len=26;
    for(int i=0;i<s.length();i++)
    {
        if(isalpha(s[i]))
        {
            if(isupper(s[i]))
            {
                encrypted+=char('A'+(s[i]-'A'+k)%len);
            }
            else
            {
            encrypted+=char('a'+(s[i]-'a'+k)%len);
            }
        }
        else
        {
            encrypted+=s[i];
        }
    }
    cout<<encrypted;
    return 0;
}