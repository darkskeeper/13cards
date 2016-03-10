#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int i;
    int *arr = new int [5];
    QFile file("C:\\Users\\yuhoa\\Documents\\Qt\\ezpoker\\input.txt");
    if (!file.open(QIODevice::Text | QIODevice::ReadOnly)) return 0;
    QByteArray ba = file.readLine();
    file.close();
    QList<QByteArray> baList = ba.split(' ');
    for (int i=0;i<baList.size();i++)
    {
      arr[i]=baList[i].toInt();
    }
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
    QFile file1("C:\\Users\\yuhoa\\Documents\\Qt\\ezpoker\\output.txt");
    if(!file1.open(QIODevice::Append)) return 0;
    QTextStream out(&file1);
    switch (t)
    {
    case 1:
        out << "IMPOSSIBLE!";
        break;
    case 2:
        t1=0;
        for(i=0; i<5; i++)
            if(arr[i]==sc[0]) t1++;
        if(t1==2||t1==3) out<<"Full House";
        else out<<"Four of a Kind";
        break;
    case 3:
        for(int i1=0; i1<t; i1++)
        {
            t1=0;
            for(i=0; i<5; i++)
                if(arr[i]==sc[i1]) t1++;
            if(t1==2) {out<<"Two Pairs";break;}
            else if(t1==3) {out<<"Three of a Kind";break;}
        }
        break;
    case 4:
        out<<"One Pair";
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
            if(t1==0) {out<<"Nothing"; break;}
        }
        if(t1!=0) out<<"Straight";
        break;
    }
    file1.close();
    return a.exec();
}
