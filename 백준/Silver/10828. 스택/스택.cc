#include <iostream>
#include <string>
#include <vector>

using namespace std;

pair<string, string> GetFirstAndLastWorld(const string& _str)
{
	size_t spacePos = _str.find(' ');

	if (spacePos == string::npos) // 띄어쓰기가 존재하지 않는다면
	{
		return { _str, " "};
	}
	else
	{
		string strFirst, strLast;
		strFirst = _str.substr(0, spacePos);
		strLast = _str.substr(spacePos + 1);
		return { strFirst, strLast };
	}
}

int main() 
{
	int iCnt = 0;
	cin >> iCnt;
	cin.ignore();

	vector<string> strings;
	vector<string> resultStrs;

	for (int i = 0; i < iCnt; i++)
	{
		string sCin;
		getline(std::cin, sCin);
		if(!sCin.empty())
			strings.emplace_back(sCin);
	}

	for(const auto& iter : strings)
	{
		pair<string, string> strPair;
		strPair = GetFirstAndLastWorld(iter);

		if ("push" == strPair.first)
		{
			resultStrs.emplace_back(strPair.second);
		}
		else if ("top" == strPair.first)
		{
			if (true == resultStrs.empty())
				cout << "-1" << endl;
			else
				cout << resultStrs.back() << endl;
		}
		else if ("size" == strPair.first)
		{
			cout << resultStrs.size() << endl;
		}
		else if ("empty" == strPair.first)
		{
			if (true == resultStrs.empty())
				cout << "1" << endl;
			else
				cout << "0" << endl;
		}
		else if ("pop" == strPair.first)
		{
			if (true == resultStrs.empty())
				cout << "-1" << endl;
			else
			{
				cout << resultStrs.back() << endl;
				resultStrs.pop_back();
			}
		}
		else
			return 0;
	}
	return 0;
}
