/*
 * Word.cpp
 * The definition of the word class.
 * 
 * Jacob Slaton
 * Date Created: May 16, 2014
 * Last Date Modified: May 16, 2014
 */

#include "Word.h"

Word::Word()
: mCount(1)
{
}

Word::Word(string word)
: mWord(""), mCount(1)
{
    setWord(word);
}

Word::~Word()
{
}

void Word::setWord(string word)
{
    mWord = word;
}

void Word::setCount(unsigned int count)
{
    mCount = count;
}

string Word::getWord() const
{
    return mWord;
}

unsigned int Word::getCount() const
{
    return mCount;
}

void Word::incrementCount()
{
    ++mCount;
}

bool operator ==(Word LHS, Word RHS)
{
    string leftWord = LHS.getWord();;
    string rightWord = RHS.getWord();
    for (unsigned int i = 0; i < leftWord.length(); ++i)
        leftWord[i] = toupper(leftWord[i]);
    for (unsigned int i = 0; i < rightWord.length(); ++i)
        rightWord[i] = toupper(rightWord[i]);

    return (leftWord == rightWord);
}

bool operator <(Word LHS, Word RHS)
{
    string leftWord = LHS.getWord();;
    string rightWord = RHS.getWord();
    for (unsigned int i = 0; i < leftWord.length(); ++i)
        leftWord[i] = toupper(leftWord[i]);
    for (unsigned int i = 0; i < rightWord.length(); ++i)
        rightWord[i] = toupper(rightWord[i]);

    return (leftWord < rightWord);
}

bool operator >(Word LHS, Word RHS)
{
    string leftWord = LHS.getWord();;
    string rightWord = RHS.getWord();
    for (unsigned int i = 0; i < leftWord.length(); ++i)
        leftWord[i] = toupper(leftWord[i]);
    for (unsigned int i = 0; i < rightWord.length(); ++i)
        rightWord[i] = toupper(rightWord[i]);

    return (leftWord > rightWord);
}

ostream& operator <<(ostream& out, Word src)
{
    out << src.mWord << ' ' << src.mCount;
    return out;
}
