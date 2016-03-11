#include <stdio.h>
#include <windows.h>

void main()
{
    int i = 0, i2 = 0;
    int arr[5];
    char buff[3];
    FILE *fr, *fw;
    if ((fr = fopen("INPUT.TXT", "r")) == NULL)
    {
        puts("Couldn't open file\n");
        system("pause");
        exit(1);
    }
    while(feof(fr)==0)
    {
        buff[i++] = getc(fr);
        if(buff[i-1]==' ')
        {
            arr[i2++] = atoi(buff);
	    buff[1] = ' ';
	    i=0;
        }
    }
    fclose(fr);
    int sc[5];
    sc[0] = arr[0];
    int t=1, t1;
    for(i=1; i < 5; i++)
    {
        t1=0;
        for(int i1=0; i1<t; i1++)
            if(arr[i]!=sc[i1]) t1++;
        if(t1==t) sc[t++]=arr[i];
    }
    if ((fw = fopen("OUTPUT.TXT", "w")) == NULL)
    {
        puts("Couldn't open file\n");
        system("pause");
        exit(1);
    }
    switch (t)
    {
    case 1:
        fputs("IMPOSSIBLE!", fw);
        break;
    case 2:
        t1=0;
        for(i=0; i<5; i++)
            if(arr[i]==sc[0]) t1++;
        if(t1==2||t1==3) fputs("Full House", fw);
        else fputs("Four of a Kind", fw);
        break;
    case 3:
        for(int i1=0; i1<t; i1++)
        {
            t1=0;
            for(i=0; i<5; i++)
                if(arr[i]==sc[i1]) t1++;
            if(t1==2) {fputs("Two Pairs", fw);break;}
            else if(t1==3) {fputs("Three of a Kind", fw);break;}
        }
        break;
    case 4:
        fputs("One Pair", fw);
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
            if(t1==0) {fputs("Nothing", fw); break;}
        }
        if(t1!=0) fputs("Straight", fw);
        break;
    }
    fclose(fw);
}
