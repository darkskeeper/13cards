#include <QCoreApplication>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int i;
    int *arr = new int [5];
    for(i=0; i<5; i++)
        cin>>arr[i];
        //arr[i]=qrand() % 13;
    for(i=0; i < 5; i++)
        cout<<arr[i];
    cout<<endl;
    int *sc = new int [5];
    sc[0] = arr[0];
    int t=1, t1;
    for(i=1; i < 5; i++)
    {
        t1=0;
        for(int i1=0; i1<t; i1++)
            if(arr[i]!=sc[i1]) t1++;
        if(t1==t) sc[t++]=arr[i];
    }
    switch (t)
    {
    case 1:
        cout << "IMPOSSIBLE!";
        break;
    case 2:
        t1=0;
        for(i=0; i<5; i++)
            if(arr[i]==sc[0]) t1++;
        if(t1==2||t1==3) cout<<"Full House";
        else cout<<"Four of a Kind";
        break;
    case 3:
        for(int i1=0; i1<t; i1++)
        {
            t1=0;
            for(i=0; i<5; i++)
                if(arr[i]==sc[i1]) t1++;
            if(t1==2) {cout<<"Two Pairs";break;}
            else if(t1==3) {cout<<"Three of a Kind";break;}
        }
        break;
    case 4:
        cout<<"One Pair";
        break;
    case 5:
        int min1=arr[0];
        for(i=1; i<5; i++)
        {
            if(arr[i]<min1) min1=arr[i];
        }
        for(i=1; i<5; i++)
        {
            t1=0;
            for(i=0; i<5; i++)
            {
                if(arr[i]==min1+1) t1=1;
            }
            if(t1==0) {cout<<"Nothing"; break;}
        }
        if(t1!=0) cout<<"Straight";
        break;
    }
    return a.exec();
}
