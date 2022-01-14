class MyCircularDeque
{
    
    vector<int> arr;
    int front=0;
    int rear=0;
    int c=0;
    int size;
    
    public:
    MyCircularDeque(int k)
    {
        arr.resize(k);
        size=k;
    }
    
   
    bool insertFront(int value)
    {
        if(!isFull())
        {
            front=(front-1+size)%size;
            arr[front]=value;
            c++;
            return true;
        }
        return false;
    }
    
    bool insertLast(int value)
    {
        if(!isFull())
        {
            arr[rear]=value;
            rear=(rear+1)%size;
            c++;
            return true;
        }
        return false;
    }
    
    
    bool deleteFront()
    {
        if(!isEmpty())
        {
            front=(front+1)%size;
            c--;
            return true;
        }
        return false;
    }
    
    
    bool deleteLast()
    {
        if(!isEmpty())
        {
            rear=(rear-1+size)%size;
            c--;
            return true;
        }
        return false;
    }
    
    
    int getFront()
    {
        if(!isEmpty())
        {
            cout<<front<<" "<<arr[(front+1)%size]<<endl;
            return arr[(front)%size];
        }
        return -1;
    }
    
   
    int getRear()
    {
         if(!isEmpty())
         {
            return arr[(rear-1+size)%size];
         }
        return -1;
    }
    
   
    bool isEmpty()
    {
        return c==0;
    }
    
    
    bool isFull()
    {
         return c==size;
    }
};
