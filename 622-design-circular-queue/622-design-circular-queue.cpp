class MyCircularQueue {
public:
    vector<int> arr;
    int front;
    int rear;
    int size;
    MyCircularQueue(int k) {
        for(int i=0;i<k;i++){
            arr.push_back(-1);
        }
        front = 0;
        rear = -1;
        size = k;
    }
    
    bool enQueue(int value) {
        if(rear < size-1){ 
            rear++;
            if(arr[rear]==-1){
                arr[rear] = value;
                return true;
            }
            else {
                rear--;
                return false; 
            }
        }
        else if(rear == size - 1){
            rear = 0;
            if(arr[rear]==-1){
                arr[rear] = value;
                return true;
            }
            else {
                rear = size - 1;
                return false;
            }
        }
        return false;
          
    }
    
    bool deQueue() {
        if(arr[front] != -1) {
            arr[front] = -1;
            if(front == size -1) front = 0;
            else{
                front++;
            }
            return true;
        }
        return false;
        
    }
    
    int Front() {
        if(arr[front] != -1) return arr[front];
        return -1;
    }
    
    int Rear() {
        if(rear == -1) return -1;
        else if(arr[rear] != -1) return arr[rear];
        return -1;
        
    }
    
    bool isEmpty() {
      
        if(rear == -1) return true;
        else if(arr[rear]==-1) return true;
        return false;
    }
    
    bool isFull() {
        if(rear == size - 1){
            if(front == 0) return true;
            else return false;
        }
        else if(rear + 1 == front && arr[rear] != -1) return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */