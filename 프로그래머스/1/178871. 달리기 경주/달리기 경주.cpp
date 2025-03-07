#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) 
{
    vector<string> answer;
    
    map<string, int> maps;
    
    for(int i = 0; i < players.size(); i++)
        maps[players[i]] = i;
    
    for(int i = 0;i < callings.size();i++)
    {
        string calling = callings[i];
		int rank = maps[calling];

		string temp = players[rank - 1];
		players[rank - 1] = players[rank];
		players[rank] = temp;

		maps[calling] = rank - 1;
		maps[temp] = rank;  
    }
    
    return players;
}