
//************CircularQueue CLass******************

class CQueue
	{
	public:
		int			size;					//size of Circular Queue array
		Customer	cQueue[4];				//Circular Queue array
		int			front;					//Circular Queue pointer front
		int			rear;					//Circular Queue pointer rear
		int			count;					//count no of items stored in Circular Queue

	public :
		int			isEmpty();				//whether the Circular Queue is Empty
		int			isFull();				//whether the Circular Queue is Full
		int			enqueue(Customer value);//Enqueue value in the Circular Queue
		Customer	dequeue();				//Enqueue value from the Circular Queue
					CQueue();				//Constructor of Circular Queue Class
		
   };

//************End Circular Queue CLass**************

//**Circular Queue CLass Member Function deffinitions***

//////////////////////////////////////////////
/////// isEmpty function deffinition
int	CQueue::isEmpty()
	{
	if(count == 0)						//When Circular Queue is Empty, difference
    	return 1;						//of rear & front will be 1
	else
    	return 0;
    }
/////// end isEmpty function deffinition

//////////////////////////////////////////////
/////// isFull function deffinition
int	CQueue::isFull()
	{
	if(count >= size)					//Circular Queue will be Full when rear is equal
    	return 1;						//or greater than max index value
	else
    	return 0;
    }
/////// end isFull function deffinition

//////////////////////////////////////////////
/////// enqueue function deffinition
int	CQueue::enqueue(Customer value)
	{
	if(! isFull())						//if Circular Queue is not full
      	{		
		cQueue[rear] = value;			//Store the value and increacse rear position
		rear = (rear+1)%size;			//set rear to 0 if its value increases from size
		count++;						//count inserted values		
		return 1;
		}
	else								//if Circular Queue Array is full
   		{
		cout<<"Sorry!!!"<<endl;
		cout<<"There is no spase on sofa"<<endl;
   		return 0;
		}
	}
/////// end enqueue function deffinition

//////////////////////////////////////////////
/////// dequeue function deffinition
Customer	CQueue::dequeue()
	{
	if(! isEmpty())						//if Circular Queue is not empty
		{
		count--;
		front = (front+1)%size;
		return cQueue[front];			//return the value
		}
	else
		return cQueue[front];
	}
/////// end dequeue function deffinition

//////////////////////////////////////////////
/////// Constructor deffinition
	CQueue::CQueue()
	{
	front = -1;
	rear  =  0;
	size  =  4;
	count =  0;
	}
/////// end Constructor deffinition

//**End Circular Queue CLass Member Function deffinitions***
