#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    vector <int> cards (14, 0);
    vector <int> combs (6, 0);
    ifstream fin("INPUT.txt");
    if (!fin.is_open())
    {
        cout << "File cannot be opened!" << endl;
        system("pause");
        exit(1);
    }
    int temp;
    for ( int i = 0 ; i < 5 ; i++ )
    {
        fin >> temp;
        cards[temp]++;
    }
    fin.close();
    for ( int i = 1 ; i < 14 ; i++ )
    {
        combs[cards[i]]++;
    }
    ofstream out("OUTPUT.txt");
    if (!out.is_open())
    {
        cout << "File cannot be opened!" << endl;
        system("pause");
        exit(1);
    }
    while(true)
    {
        if (combs[1] == 5)
        {
            int min = 0, max;
            for ( int i = 1; i < 14 ; i++ )
            {
                if ( cards[i] == 1 )
                {
                    if ( min == 0 )
                    {
                        min = i;
                    }
                    else
                    {
                        max = i;
                    }
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
        if ( combs[5] == 1 )
        {
            out << "Impossible";
            break;
        }
        if ( combs[4] == 1 )
        {
            out << "Four of a Kind";
            break;
        }
        if ( combs[3] == 1 && combs[2] == 1 )
        {
            out << "Full House";
            break;
        }
        if ( combs[3] == 1 )
        {
            out << "Three of a Kind";
            break;
        }
        if ( combs[2] == 2 )
        {
            out << "Two Pairs";
            break;
        }
        out << "One Pair";
        break;
    }
    out.close();
    return 0;
}