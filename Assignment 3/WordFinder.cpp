#include "WordFinder.h"

WordFinder::WordFinder(const string& dictionaryPath)
{
    d = new Dictionary(dictionaryPath);
    x = 0;
    y = 1;
}
//--
void WordFinder::makeWordsFromWord(const string& word)
{
    Stack < string > k;
    mwfwHelper(word, 1, k);
    int b;
}
//--
void WordFinder::mwfwHelper(const string& word, int length, Stack < string > k)
{
    cout << word << " " << word.length() << " "<< __LINE__<< endl;
    string s = word.substr(0, length);
    cout << s << endl;
    if (d->isWordPresent(s))
    {

        //cout << s << endl;
        k.push(s);

        if (length + 1 <= word.length())
        {
            mwfwHelper(word.substr(length, string::npos), 1, k);
            cout << "back to " << word << word.length() << " " << length << endl;
        }
    }
    cout << length << " : " << word.length() << endl;
    if (length + 1 <= word.length())
    {
        cout << "last:" << word << endl;
        mwfwHelper(word, length + 1, k);
        cout << "back from:" << word << endl;
    }
    cout << "exited helper " << endl;
}
//--
void WordFinder::printWords(Stack < string > k)
{
    if (!k.isEmpty())
    {
        cout << k.pop() << " ";
        printWords(k);
    }
}
