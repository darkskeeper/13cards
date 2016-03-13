#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	int i = 0;
	int *arr = new int [5];
	char *filestr = new char [20], *numstr = new char[5];
	ifstream fin("INPUT.txt");
	if (!fin.is_open())
		cout << "File cannot be opened!\n";
	for ( i = 0 ; i < 5 ; i++ )
        fin >> arr[i];
	int *unic_cards = new int [5];
	unic_cards[0] = arr[0];
	int Nun_cards = 1, Nnotun_cards;
	for ( i = 1 ; i < 5 ; i++ )
	{
		Nnotun_cards = 0;
		for ( int k = 0 ; k < Nun_cards ; k++ )
			if ( arr[i] != unic_cards[k] )
				Nnotun_cards++;
		if ( Nnotun_cards == Nun_cards )
			unic_cards[Nun_cards++] = arr[i];
	}
	int Nrepeats;
	ofstream out("OUTPUT.txt");
	switch( Nun_cards )
	{
	case 1:
		out << "Impossible";
		break;
	case 2:
		Nrepeats = 0;
		for ( i = 0 ; i < 5 ; i++ )
			if ( arr[i] == unic_cards[0] )
				Nrepeats++;
		if ( Nrepeats == 2 || Nrepeats == 3 )
			out << "Full House";
		else
		{
			out << "Four of a Kind";
		}
		break;
	case 3:
		for ( int k = 0; k < Nun_cards ; k++ )
		{
			Nrepeats = 0;
			for ( i = 0 ; i < 5 ; i++ )
				if ( arr[i] == unic_cards[k] )
					Nrepeats++;
			if ( Nrepeats == 2 )
			{
				out << "Two Pairs";
				break;
			}
			else if ( Nrepeats == 3 )
			{
				out << "Three of a Kind";
				break;
			}
		}
		break;
	case 4:
		out << "One Pair";
		break;
	case 5:
		int min = arr[0];
		for ( i = 1 ; i < 5 ; i++ )
			if ( arr[i] < min )
				min = arr[i];
		bool is_add1;
		for ( i = 1 ; i < 5 ; i++ )
		{
			is_add1 = false;
			for ( int k = 0 ; k < 5 ; k++ )
				if ( arr[k] == min + 1 )
				{
					min = arr[k];
					is_add1 = true;
					break;
				}
			if ( is_add1 == false )
			{
				out << "Nothing";
				break;
			}
		}
		if ( is_add1 == true ) out << "Straight";
		break;
	}
	out.close();
    return 0;
}