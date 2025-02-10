#include <string>
#include <vector>

using namespace std;

void Input(int* _changeLen, string _inputLen)
{
    int idx = 0;
    int lenChar[4] = {};
    for(int i = 0; i < _inputLen.size(); i++)
    {
        if(':' != _inputLen[i])
        {    
            lenChar[idx] = _inputLen[i] - '0';
            ++idx;
        }
    }
    _changeLen[0] = (lenChar[0] * 10) + lenChar[1];
    _changeLen[1] = (lenChar[2] * 10) + lenChar[3];
}

void Opening(int* _myOpStart, int* _myOpEnd, int* _vidioLen, int* _currentPos)
{
   // 시작이 같을 때 초가 더 크다면
    bool bStartCondition = (_myOpStart[0] == _currentPos[0] && _myOpStart[1] <= _currentPos[1]);
    if(bStartCondition)
    {
        // End와도 분이 같을 때 더 작다면 true
        if(_myOpEnd[0] == _currentPos[0])
            bStartCondition =  (_myOpEnd[1] >= _currentPos[1]) ? true : false;
        else if(_myOpEnd[0] < _currentPos[0])
        {
            if(!(_vidioLen[0] == _myOpEnd[0] && _vidioLen[1] == _myOpEnd[1]))
                bStartCondition = false;
        }
    }
    
    // 끝 분이 같을 때 끝 초가 더 크다면
    bool bEndCondition 
        = (_myOpEnd[0] == _currentPos[0] && _myOpEnd[1] >= _currentPos[1]) ? true : false;
    if(bEndCondition)
    {
        // 시작 분이 같을 때 시작 초가 더 크다면
        if(_myOpStart[0] == _currentPos[0])
            bEndCondition =  (_myOpStart[1] <= _currentPos[1]) ? true : false;
        else if(_myOpStart[0] >= _currentPos[0])
        {   
            if(!(_myOpStart[0] == 0 && _myOpStart[1] == 0))
                bEndCondition = false;
        }
    }
    // 시작 분보다 크거나 끝 분 보다 작다면
    bool bBetweenCondition 
        = (_myOpStart[0] < _currentPos[0] && _myOpEnd[0] > _currentPos[0]) ? true : false;
    
    // 이 중 하나라도 true 라면 Opening 마지막으로 이동
    if(bStartCondition || bEndCondition || bBetweenCondition)
    {
        int A = _myOpEnd[0];
        int B = _myOpEnd[1];
        _currentPos[0] = A;
        _currentPos[1] = B;
    }
}

void Prev(int* _videoLen, int* _currentPos)
{
    // 10초 뒤로 이동
    int minute = _currentPos[0];
    int second = _currentPos[1];
    
    int videoMinute = 0;  
    int videoSecond = 10; 
    
    // 만약 초가 마이너스라면
    if(second < videoSecond && videoMinute == minute)
    {
        minute = 0;
        second = 0;
    }
   else
   {
       second -= 10;
        if (0 > second)
        {
            minute -= 1;
            second = 60 + second;
        }
   }
    
    _currentPos[0] = minute;
    _currentPos[1] = second;
}

void Next(int* _videoLen, int* _currentPos)
{
    // 10초 뒤로 이동
    int minute = _currentPos[0];
    int second = _currentPos[1];
    
    // 마지막 영상의 10초 전
    int videoMinute = _videoLen[0];       
    int videoSecond = _videoLen[1] - 10;  
    
     if (0 > videoSecond)
    {
         videoMinute -= 1;
         videoSecond = 60 + videoSecond;
    }
    
    // 분이 같고 초가 넘거나 분이 넘으면 마지막 영상으로 이동
    if(minute == videoMinute && second > videoSecond || minute > videoMinute)
    {
        int videoA = _videoLen[0];
        int videoB = _videoLen[1];
        _currentPos[0] = videoA;
        _currentPos[1] = videoB;
    }
    else
    {   
        second += 10;
        // 60초 이상이라면 분 더하기
        if(second >= 60)
        {
            minute += (second / 60);
            second = (second % 60);
        }
        
        _currentPos[0] = minute;
        _currentPos[1] = second;
    }
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) 
{
    string answer = "";
    
    int myVideo_len[2], myPos[2], myOpStart[2], myOpEnd[2];
    
    // char 변환
    Input(myVideo_len, video_len);
    Input(myPos, pos);
    Input(myOpStart, op_start);
    Input(myOpEnd, op_end);
    
    for(const auto& iter : commands)
    {
        Opening(myOpStart, myOpEnd, myVideo_len, myPos);
        
        if("prev" == iter)
            Prev(myVideo_len, myPos);
        
        else if("next" == iter)
            Next(myVideo_len, myPos);
        
        Opening(myOpStart, myOpEnd, myVideo_len, myPos);
    }
    
    // 분 결과
    if(myPos[0] < 10)
    {   
        answer = '0' + to_string(myPos[0]) + ':';
    }
    else if(myPos[0] >= 10)
    {    
        answer = to_string(myPos[0]) + ':';
    }
    
    // 시간 결과
    if(myPos[1] < 10)
    {    
        answer += '0' + to_string(myPos[1]);
    }
    else if(myPos[1] >= 10)
    {    
        answer += to_string(myPos[1]);
    }
    
    return answer;
}

