class Solution
{
public:
    int minThrow(int N, int arr[])
    {
       unordered_map<int,int>snake;
       unordered_map<int,int>ladder;
       
       for(int i=0;i<(2*N)-1;i+=2)
       {
           if(arr[i]>arr[i+1])
           {
               snake[arr[i]]=arr[i+1];
           }
           else
           {
               ladder[arr[i]]=arr[i+1];
           }
       }
       
       int moves=0;
       bool found=false;
       
       queue<int>q;
       q.push(1);
       
       while(!q.empty()&&found==false)
       {
           int size=q.size();
           moves++;
           
           while(size--)
           {
               int front=q.front();
               q.pop();
               
               for(int dice=1;dice<=6;dice++)
               {
                   if(front+dice==30)
                   {
                       found=true;
                       break;
                   }
                   else if(front+dice<30&&ladder[front+dice])
                   {
                       if(ladder[front+dice]==30)
                       {
                           found=true;
                           break;
                       }
                       q.push(ladder[front+dice]);
                   }
                   else if(front+dice<30&&snake[front+dice])
                   {
                       if(snake[front+dice]==30)
                       {
                           found=true;
                           break;
                       }
                       q.push(snake[front+dice]);
                   }
                   else if(front+dice<30&&!snake[front+dice]&&!ladder[front+dice])
                   {
                       q.push(front+dice);
                   }
               }
               if(found==true)
               {
                   break;
               }
           }
           if(found==true)
           {
              break;
           }
       }
       
       if(found==true)
       {
           return moves;
       }
       else
       {
          return -1;   
       }
    }
};
