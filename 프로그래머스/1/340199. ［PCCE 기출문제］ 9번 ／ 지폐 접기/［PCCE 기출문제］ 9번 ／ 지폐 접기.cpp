#include <string>
#include <vector>

using namespace std;

int Compare(vector<int>& _wallet, vector<int>& _bill)
{
    int result = 0;
    
    while(true)
    {
        int* bigResult = _bill[0] > _bill[1] ? &_bill[0] : &_bill[1];
    
        // 번갈아가며 둘 중 하나가 들어가는 지 확인
        bool bCheck = 
           _wallet[0] >= _bill[0] && _wallet[1] >= _bill[1] || 
            _wallet[1] >= _bill[0] && _wallet[0] >= _bill[1];
      
        // 만약 들어가는 구조라면 return;
        if(bCheck)
           return result;
    
        // 그렇지 않다면 가장 큰 값을 뽑아서 접기
        *bigResult = *bigResult / 2;
        
        ++result;
    }
}

int solution(vector<int> wallet, vector<int> bill) 
{
    int answer = 0;
    
    answer = Compare(wallet, bill);
    
    return answer;
}