#include <stdio.h>
#include <windows.h>
#include <ctime>
#include <conio.h>

int main()
{
    int i = 0, i2 = 0;
    int arr[5];
    char buff[3];
	int i3=0, sort;
	while(true)
	{
		srand(time(NULL));
		for(i=0; i<5; i++)
		{
			arr[i]=rand() % 3 + 1;
		}
		for(i=0; i<5; i++)
			printf("%d ", arr[i]);
		printf("| ");
		for(;;)
		{
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
			int Nrepeats;
			switch (N_unic_cards)
			{
			case 1:
			    printf("Impossible");
			    break;
			case 2:
			    Nrepeats=0;
			    for(i=0; i<5; i++)
			        if(arr[i]==unic_cards[0]) Nrepeats++;
			    if(Nrepeats==2||Nrepeats==3) printf("Full House");
			    else printf("Four of a Kind");
			    break;
			case 3:
				for(int i1=0; i1<N_unic_cards; i1++)
			    {
			        Nrepeats = 0;
			        for(i=0; i<5; i++)
			            if(arr[i]==unic_cards[i1]) Nrepeats++;
					if(Nrepeats==2) {printf("Two Pairs");break;}
					else if(Nrepeats==3) {printf("Three of a Kind");break;}
				}
				break;
			case 4:
				printf("One Pair");
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
			        if(is_more_1==false) {printf("Nothing"); break;}
			    }
			    if(is_more_1==true) printf("Straight");
			    break;
			}
			printf(" | ");
			break;
		}
		for(i=0; i<5; i++)
			for(int i1=0; i1<5; i1++)
				if(arr[i1]>arr[i])
				{
					sort = arr[i1];
					arr[i1] = arr[i];
					arr[i] = sort;
				}
		for(i=0; i<5; i++)
		{
			printf("%d ", arr[i]);
		}
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
		int Nrepeats;
		switch (N_unic_cards)
		{
		case 1:
		    printf("Impossible");
		    break;
		case 2:
		    Nrepeats=0;
		    for(i=0; i<5; i++)
		        if(arr[i]==unic_cards[0]) Nrepeats++;
		    if(Nrepeats==2||Nrepeats==3) printf("Full House");
		    else printf("Four of a Kind");
		    break;
		case 3:
			for(int i1=0; i1<N_unic_cards; i1++)
		    {
		        Nrepeats = 0;
		        for(i=0; i<5; i++)
		            if(arr[i]==unic_cards[i1]) Nrepeats++;
				if(Nrepeats==2) {printf("Two Pairs");break;}
				else if(Nrepeats==3) {printf("Three of a Kind");break;}
			}
			break;
		case 4:
			printf("One Pair");
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
		        if(is_more_1==false) {printf("Nothing"); break;}
		    }
		    if(is_more_1==true) printf("Straight");
		    break;
		}
		printf("\n");
		i3++;
		getch();
	}
	system("pause");
	return 0;
}
