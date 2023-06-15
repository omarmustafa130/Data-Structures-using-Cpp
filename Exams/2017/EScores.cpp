#include <iostream>
using namespace std;

class GameEntry { // a game score entry
    public:
        GameEntry(const string& n="", int s=0); // constructor
        string getName() const; // get player name
        int getScore() const; // get score
    private:
        string name; // player’s name
        int score; // player’s score
};


GameEntry::GameEntry(const string& n, int s) // constructor
: name(n), score(s) { }
// accessors
string GameEntry::getName() const { return name; }
int GameEntry::getScore() const { return score; }


class Scores { // stores game high scores
    public:
        Scores(int maxEnt = 10); // constructor
        ~Scores(); // destructor
        void add(const GameEntry& e); // add a game entry
        GameEntry remove(int i); // remove the ith entry

    protected:
        int maxEntries; // maximum number of entries
        int numEntries; // actual number of entries
        GameEntry* entries; // array of game entries
};


Scores::Scores(int maxEnt) { // constructor
    maxEntries = maxEnt; // save the max size
    entries = new GameEntry[maxEntries]; // allocate array storage
    numEntries = 0; // initially no elements
}
Scores::~Scores() { // destructor
    delete[ ] entries;
}

void Scores::add(const GameEntry& e) { // add a game entry
    int newScore = e.getScore(); // score to add
    if (numEntries == maxEntries) 
    { // the array is full
        if (newScore <= entries[maxEntries-1].getScore())
            return; // not high enough - ignore
    }
    else 
        numEntries++; // if not full, one more entry
    int i = numEntries-2; // start with the next to last
    while ( i >= 0 && newScore > entries[i].getScore() ) 
    {
        entries[i+1] = entries[i]; // shift right if smaller
        i--;
    }
    entries[i+1] = e; // put e in the empty spot
}


GameEntry Scores::remove(int i) {
    GameEntry e = entries[i]; // save the removed object
    for (int j = i+1; j < numEntries; j++)
        entries[j-1] = entries[j]; // shift entries left
    numEntries--; // one fewer entry
    return e; // return the removed object
}

class EScore : public Scores
{
    private:
        float AvgScore;
    public:
        EScore(int maxEnt = 10);
        void UpdateAvgScore();
        void PrintAboveAvg();
};

EScore::EScore(int maxEnt = 10) : Scores(maxEnt), AvgScore(0)
{}
void EScore::UpdateAvgScore()
{
    float sum = 0.0;
    for(int i = 0; i<numEntries; i++)
    {
        sum+=entries[i].getScore();
    }
    AvgScore = sum / numEntries;
}
void EScore::PrintAboveAvg()
{
    for(int i = 0; i<numEntries; i++)
    {
        if(entries[i].getScore() > AvgScore)
        {
            cout<<entries[i].getName()<<"  :  "<<entries[i].getScore()<<"\n";
        }
    }
}