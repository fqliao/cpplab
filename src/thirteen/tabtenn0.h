/*
 * tabtenn0.h
 *
 *  Created on: 2018年10月7日
 *      Author: caryliao
 */

#ifndef SRC_THIRTEEN_TABTENN0_H_
#define SRC_THIRTEEN_TABTENN0_H_

#include <string>
using std::string;

class TableTennisPlayer
{
 public:
    TableTennisPlayer(const string & _firstname = "none",
                      const string & _lastname = "none",
                      bool _hasTable = false);
    void Name() const;
    bool HasTable() const {return m_hasTable;};
    void ResetTable(bool _hasTable) {m_hasTable = _hasTable;};

 private:
    string m_firstname; //string类比使用字符数组，方便，灵活，、安全、专业
    string m_lastname;
    bool m_hasTable;
};


class RatedPlayer: public TableTennisPlayer
{
    public:
        RatedPlayer(unsigned int _rating = 0, const string & _firstname = "none",
                    const string & _lastname = "name", bool _hasTable = false);
        RatedPlayer(unsigned int _rating, const TableTennisPlayer & tp);
        unsigned int Rating() const {return m_rating;}
        void ResetRating(unsigned int _rating){m_rating = _rating;}
    private:
        unsigned int m_rating;
};

void testTabtenn0();
void testTabtenn1();

#endif /* SRC_THIRTEEN_TABTENN0_H_ */
