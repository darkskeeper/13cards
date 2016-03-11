#include <stdio.h>
#include <windows.h>

int main()
{
    int i = 0, i2 = 0;
    int arr[5];
    char buff[3];
    FILE *fr, *fw;
    if ((fr = fopen("INPUT.txt", "r")) == NULL)
    {
        puts("Couldn't open file\n");
        system("pause");
        exit(1);
    }
    while(feof(fr)==0)
    {
        buff[i++] = getc(fr);
		if(buff[i-1]==' '||feof(fr)!=0)
        {
            arr[i2++] = atoi(buff);
			buff[1] = ' ';
			i=0;
        }
    }
    fclose(fr);
    int unic_cards[5];
    unic_cards[0] = arr[0];
    int N_unic_cards=1, not_unic;
    for(i=1; i < 5; i++)
    {
        not_unic=0;
        for(int i1=0; i1<N_unic_cards; i1++)
            if(arr[i]!=unic_cards[i1]) not_unic++;
        if(not_unic==N_unic_cards) unic_cards[N_unic_cards++]=arr[i];
    }
    if ((fw = fopen("OUTPUT.txt", "w")) == NULL)
    {
        puts("Couldn't open file\n");
        system("pause");
        exit(1);
    }
	int Nrepeats;
    switch (N_unic_cards)
    {
    case 1:
        fputs("Impossible", fw);
        break;
    case 2:
        Nrepeats=0;
        for(i=0; i<5; i++)
            if(arr[i]==unic_cards[0]) Nrepeats++;
        if(Nrepeats==2||Nrepeats==3) fputs("Full House", fw);
        else fputs("Four of a Kind", fw);
        break;
    case 3:
		for(int i1=0; i1<N_unic_cards; i1++)
        {
            Nrepeats = 0;
            for(i=0; i<5; i++)
                if(arr[i]==unic_cards[i1]) Nrepeats++;
            if(Nrepeats==2) {fputs("Two Pairs", fw);break;}
            else if(Nrepeats==3) {fputs("Three of a Kind", fw);break;}
        }
        break;
    case 4:
        fputs("One Pair", fw);
        break;
    case 5:
        int min=arr[0];
        for(i=1; i<5; i++)
        {
            if(arr[i]<min) min=arr[i];
        }
		bool is_more_1;
        for(i=1; i<5; i++)
        {
            is_more_1=false;
            for(int i1=0; i1<5; i1++)
            {
				if(arr[i1]==min+1) {is_more_1=true; min=arr[i1]; break;}
            }
            if(is_more_1==false) {fputs("Nothing", fw); break;}
        }
        if(is_more_1==true) fputs("Straight", fw);
        break;
    }
    fclose(fw);
    return 0;
}
