#include<bits/stdc++.h>
using namespace std;
int codeword[50],temp[50],temp2[50];
int n,r,store;
char parity;
string message,message2;
void sent_data();
void sender_code();
void reciever_code();
int Parity_check(int x);

void sender_code()
{
    cout<<"\n\tEnter the Message : ";
    cin>>message;
    n=message.size();
    cout<<"\n\t\tParity Type: e (for even)/ o (for odd) : ";
    cin>>parity;

    r=0;
    while((n+r+1)>pow(2,r))
        r++;
    cout<<"\n\tnumber of redundant bits : "<<r<<endl;
    cout<<"\n\tNumber of Bits in Codeword : "<<n+r<<endl;

    for(int i=0; i<message.size(); i++)
    {
        if(message[i] == '1')
            temp[i]=1;
        else
            temp[i]=0;
        // cout<<temp[i]<<"  "<<i<<endl;
    }

    int j=0;
    for(int i=(n+r); i>0; i--)
    {

        if((i & (i - 1)) != 0&&j<=n)
        {
            codeword[i] =temp[j];
            j++;
            // cout<<i<<" "<<codeword[i]<<endl;
        }
        else
        {
            codeword[i] = Parity_check(i);
            // cout<<codeword[i]<<" "<<i<<endl;
        }

    }

    cout<<"\n\tCodeword :"<<endl;
    for(int i=(n+r); i>0; i--)
        cout<<codeword[i]<<" ";
    cout<<endl;
}
int Parity_check(int x)
{
    //cout<<x<<endl;
    bool flag = true;
    int bit;
    if(x == 1)
    {
        bit = codeword[x+2];
        for(int j=x+3; j<=(n+r); j++)
        {
            if(j%2)
            {
                bit ^= codeword[j];
            }
        }
    }
    else
    {
        bit = codeword[x+1];
        //cout<<bit<<endl;
        for(int i=x; i<=(n+r); i++)
        {
            if(flag)
            {
                if(i==x || i==x+1)
                    bit = codeword[x+1];
                else
                    bit ^= codeword[i];
            }
            //cout<<bit<<endl;
            if((i+1)%x == 0)
                flag = !flag;
        }
    }
    if(parity == 'O' || parity == 'o')
        return !bit;
    else
        return bit;
}
void reciever_code()
{
    int check=0,press;
    cout<<"\n\tpress for Error Detected OR press 0 for exit"<<endl;
    cout<<"\n\t press 1 for Single Bit Error: "<<endl;
    cout<<"\t press 2 for Double Bit Error: "<<endl;
    cout<<"\t press 3 for No Error: "<<endl;
    cout<<"\t Enter press: ";
    cin>>press;
    cout<<"\n\tEnter the received codeword : ";
    cin>>message2;
    //cout<<message2.size()<<" "<<n+r<<endl;
    for(int i=0; i<message2.size(); i++)
    {
        if(message2[i] == '1')
            temp2[i]=1;
        else
            temp2[i]=0;
        // cout<<temp2[i]<<" ";
    }
    for(int i=0,j=(n+r); i<message2.size(); i++,j--)
    {

        if(temp2[i] == codeword[j])
        {
            check++;
            //  cout<<temp2[i]<<" "<<codeword[i]<<" ";
        }
        else
        {
            store=i;
            //cout<<i<<endl;
        }
    }
    if(press==3)
    {
        system("color 2F");
        if(check==(n+r))
        {
            cout<<"\tNO Error in Codeword "<<endl;
        }
    }
    else if(check==(n+r)-1)
    {
        system("color 4F");
        cout<<"\tError Detected in Position: "<<store+1<<endl;
        cout<<"\tAfter Correcting Codeword is: ";
        for(int i=(n+r); i>0; i--)
            cout<<codeword[i]<<" ";
        cout<<endl;

    }
    else
    {
        system("color 4F");
        cout<<"\tSorry Can not find 2 bit error:)"<<endl;
        cout<<"\tError Detected in Position: "<<store+1<<endl;
        cout<<"\tAfter Correcting Codeword is: ";
        for(int i=(n+r); i>0; i--)
            cout<<codeword[i]<<" ";
        cout<<endl;

    }
    sent_data();

}

///**********Again Sent Data***********
void sent_data()

{

    cout<<"\n\tpress 1 for sent data OR press 0 for exit\t\n\n"<<endl;
    cout<<"\t Enter press: ";
    int press;
    cin>>press;
    cout<<endl;
    if(press==1)
    {
        cout<<"\tSender Sent  : "<<endl;
        sender_code();
        cout<<"Receiver: "<<endl;
        reciever_code();
    }
    else
    {

        cout<<"\texit the program\n"<<endl;
        cout<<"\t******THANK YOU******"<<endl;
        return ;
    }
}
///********Main Function***********
int main()
{
    system("color 3F");
    cout<<"\t****PROJECT****\n\n"<<endl;
    cout<<"\t****Hamming Code With Bitwise operations****\n\n"<<endl;
    sent_data();
    return 0;
}



