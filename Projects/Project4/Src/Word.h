/*
 * Word.h
 * A simple class that stores a word and has a counter.
 * 
 * Jacob Slaton
 * Date Created: May 16, 2014
 * Last Date Modified: May 16, 2014
 */
#pragma once

#include <ostream>
#include <string>
using std::ostream;
using std::string;

class Word
{
        string mWord;
        unsigned int mCount;
    public:
        /*
         * Initializes the word object with an empty string.
         */
        Word();

        /*
         * Initializes the word object with word.
         */
        Word(string word);

        /*
         * Cleans up the word object.
         */
        virtual ~Word();

        /*
         * Sets the word in the word object.
         * @param word the string to be stored in the word object
         */
        void setWord(string word);

        /*
         * Sets the count in the word object.
         * @param count the unsinged int to be stored in the word object
         */
        void setCount(unsigned int count);

        /*
         * Gets the word stored in the word object.
         * @return the word stored in the word object
         */
        string getWord() const;

        /*
         * Gets the count stored in the word object.
         * @return the count stored in the word object
         */
        unsigned int getCount() const;

        /*
         * Increments the count stored in the word object by 1.
         */
        void incrementCount();

        /*
         * Checks to see if the words stored in LHS and RHS are the same.
         * The check is case insensitive.
         * @return true if the words are the same, else false
         */
        friend bool operator ==(Word LHS, Word RHS);

        /*
         * Checks to see if the word stored in LHS is less than RHS.
         * The check is case insensitive.
         * @return true if the LHS is less than RHS, else false
         */
        friend bool operator <(Word LHS, Word RHS);

        /*
         * Checks to see if the word stored in LHS is greater than RHS.
         * The check is case insensitive.
         * @return true if the LHS is greater than RHS, else false
         */
        friend bool operator >(Word LHS, Word RHS);

        /*
         * Outputs the contents of the word obeject in the format "WORD COUNT".
         * @param out the stream to be outputed to
         * @param src the word to be outputed
         * @return the ostream that was outputed to
         */
        friend ostream& operator <<(ostream& out, Word src);
    protected:
    private:
};
