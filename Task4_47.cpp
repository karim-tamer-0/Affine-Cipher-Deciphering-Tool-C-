
#include <iostream>
#include <cstring>
using namespace std;


int main()
{
    const int alphabetsize = 26;                                                //The number of letters in the English alphabet
    int a;                                                                      //The key (a)
    int b;                                                                      //The key (b)
    int textSize = 0;                                                           //The variable that stores the number of letters of the ciphered text entered 
    char ciphText[1000];                                                        //The array that stores the ciphered text entered by the user

    char alphabet[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };

    int indexCiph[1000];                                                        //Gets the position of the deciphered letter entered frthe alphabet (before applying the mod formula)
    int deCiph = 0;                                                             //Stores the inverse of the key a (a^-1)
    int indexdeCiph[1000];                                                      //Stores the position of the letters after being deciphered  
    int index[1000];                                                            //Stores the index of deciphered letter
    bool test = 1;


    cout << "Enter the first key (a): ";
    cin >> a;

    cout << endl;

    cout << "Enter the second key (b): ";
    cin >> b;



    for (int i = 0;i < 30;i++)
    {
        if (1 == ((a * i) % alphabetsize))                                      //Gets the inverse of the key a (a^-1)
        {
            deCiph = i;
        }
    }
    cout << endl;
    cout << "The inverse of the key (a) is: " << deCiph << endl;
    cout << endl << endl << endl;



    cout <<"\t"<<"  " << "Enter the ciphered text (in CAPS): ";
    cin >> ciphText;                                                            //The ciphered text is entered       
    


    textSize = strlen(ciphText);                                                //Gets the number of letters entered by the user
     
    cout << endl << endl << endl << endl;



    for (int i = 0; i < textSize; i++)
    {
        for (int j = 0;j < alphabetsize;j++)
        {
            if (ciphText[i] == alphabet[j])
            {
                test = 0;                                                       //Checks if the entered text is all in CAPS or not
            }
        }
    }



    if (test == 1)
    {
        cout <<"\t"<<"\t" << "\t" << "\t" << "----------------------------------------------------" << endl;
        cout <<"\t"<<"\t" << "\t" << "\t" << "INVALID, RE-ENTER THE CIPHERED TEXT USING CAPS ONLY" << endl;
        cout <<"\t"<<"\t" << "\t" << "\t" << "----------------------------------------------------" << endl;
        cout << endl << endl << endl << endl << endl << endl << endl;
    }



    else
    {
        for (int i = 0; i < textSize; i++)
        {
            for (int j = 0;j < alphabetsize;j++)
            {
                if (ciphText[i] == alphabet[j])
                {
                    index[i] = (((deCiph * (j - b))) % alphabetsize);           //Gets the position of the deciphered letter in the alphabet
                }

            }

            indexdeCiph[i] = index[i];                                          //Stores the position of the deciphered letter in the array "indexdeCiph"
            if (index[i] < 0)
            {
                indexdeCiph[i] = (alphabetsize + index[i]);                     //Gets the position of the deciphered letter if its index is negative
            }

        }

        cout << endl;


        cout << "\t" << "\t" << "\t" << "\t" << "   " << "************************************" << endl;
        cout << "\t" << "\t" << "\t" << "\t" << "   " << "The deciphered text is: ";
       

        for (int i = 0; i < textSize; i++)
        {
            cout << alphabet[indexdeCiph[i]];                                   //Displays the deciphered text 
        }
        cout << endl;

        cout << "\t" << "\t" << "\t" << "\t" << "   " << "************************************" << endl;
        
        cout << endl << endl << endl << endl << endl;
        cout << endl << endl << endl;
    }


    return 0;
}
