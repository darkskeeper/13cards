#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    int i = 0;
    int *arr = new int [5];
    ifstream fin("INPUT.txt");
    if (!fin.is_open())
    {
        cout << "File cannot be opened!" << endl;
        system("pause");
        exit(1);
    }
    for ( i = 0 ; i < 5 ; i++ )
    {
        fin >> arr[i];
    }
    int *unic_cards = new int [5];
    unic_cards[0] = arr[0];
    int Nun_cards = 1;
    bool is_card_unic;
    for ( i = 1 ; i < 5 ; i++ )
    {
        is_card_unic = true;
        for ( int k = 0 ; k < Nun_cards ; k++ )
        {
            if ( arr[i] == unic_cards[k] )
            {
                is_card_unic = false;
                break;
            }
        }
        if ( is_card_unic )
        {
            unic_cards[Nun_cards++] = arr[i];
        }
    }
    int Nrepeats;
    ofstream out("OUTPUT.txt");
    if (!out.is_open())
    {
        cout << "File cannot be opened!" << endl;
        system("pause");
        exit(1);
    }
    switch( Nun_cards )
    {
    case 1:
        out << "Impossible";
        break;
    case 2:
        Nrepeats = 0;
        for ( i = 0 ; i < 5 ; i++ )
        {
            if ( arr[i] == unic_cards[0] )
            {
                Nrepeats++;
            }
        }
        if ( Nrepeats == 2 || Nrepeats == 3 )
        {
            out << "Full House";
        }
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
            {
                if ( arr[i] == unic_cards[k] )
                {
                    Nrepeats++;
                }
            }
            if ( Nrepeats == 2 )
            {
                out << "Two Pairs";
                break;
            }
            else
            {
                if ( Nrepeats == 3 )
                {
                    out << "Three of a Kind";
                    break;
                }
            }
        }
        break;
    case 4:
        out << "One Pair";
        break;
    case 5:
        int min = arr[0], max = arr[0];
        for ( i = 1 ; i < 5 ; i++ )
        {
            if ( arr[i] < min )
            {
                min = arr[i];
            }
            if ( arr[i] > max )
            {
                max = arr[i];
            }
        }
        if ( max - min == 4 )
        {
            out << "Straight";
        }
        else
        {
            out << "Nothing";
        }
        break;
    }
    out.close();
    delete []arr;
    delete []unic_cards;
    return 0;
}