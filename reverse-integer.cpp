class Solution {
public:
    int reverse(int number) {

      int answer = 0;
      while(number!=0)
      {
        int digit = number % 10;

      if((answer>INT_MAX/10) || (answer<INT_MIN/10))
      {
        return 0;
      }


        answer = (answer*10) + digit ;
        number = number / 10;
      }

      return answer;

    }
    
};
