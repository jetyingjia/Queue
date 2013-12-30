#ifndef _Queue_hpp_
#define _Queue_hPP_

//Queue ADT
template<typename T>
class Queue
{
public:
	T data;
	Queue<T> *next;
	Queue<T>(){};
	Queue<T>(T info,Queue<T>* nextVlaue=NULL){
		data=info;
		next=nextVlaue;
	}
	bool insertQueue(T item);    //insert item
	bool deQueue(T &item);       //return the head element and remove it from the queue
	bool getFront(T &item);      //return the head element
	bool isEmpty();              //return true if the Queue is empty
	bool isFull();               //return true if the Queue is full


};

//**********************//
//arrQueue ADT
//*********************//
template<typename T>
class arrQueue: public Queue<T>
{
private:
	int mSize;
	int front,rear;
	T *qu;
public:
	bool insertQueue(T item);    //insert item
	bool deQueue(T &item);       //return the head element and remove it from the queue
	bool getFront(T &item);      //return the head element
	bool isEmpty();              //return true if the Queue is empty
	bool isFull();               //return true if the Queue is full
	arrQueue(int size){
		mSize=size+1;             //Waste a storage space to judge the queue is empty or full
		front=rear=0;
		qu=new T[mSize];
	}
	~arrQueue(){
		delete [] qu;
	}
};


//Insert an element
template<typename T>
bool arrQueue<T>::insertQueue(T item){
	if (((rear+1)%mSize)==front){
		std::cout<<"The Queue is full:";
		return false;
	}
	qu[rear]=item;
	rear=(rear+1)%mSize;
	return true;
}


//delete an element and return it
template<typename T>
bool arrQueue<T>::deQueue(T &item){
	if(front==rear){
		std::cout<<"The Queue is empty: ";
		return false;
	}
	item=qu[front];
	front=(front+1)%mSize;
	return true;
}

//Get the head element
template<typename T>
bool arrQueue<T>::getFront(T &item){
	if (front==rear){
		std::cout<<"The Queue is empty: ";
		return false;
	}
	item=qu[front];
	return true;

}

//isEmpty
template<typename T>
bool arrQueue<T>::isEmpty(){
	if(front==rear){
		return true;
	}
	return false;
}

//isFull
template<typename T>
bool arrQueue<T>::isFull(){
	if(((rear+1)%mSize)==front){
		return true;
	}
	return false;
}

//***********************//
//linkQueue
//***********************//
template<typename T>
class linkQueue: public Queue<T>
{
private:
	int size;
	Queue<T> *front,*rear;
public:
	bool inlinkQueue(T item);    //insert item
	bool delinkQueue(T &item);       //return the head element and remove it from the queue
	bool getFront(T &item);      //return the head element
	bool isEmpty();              //return true if the Queue is empty
	//bool isFull();               //return true if the Queue is full
	linkQueue(){
		size=0;
		front=rear=NULL;
	}
	~linkQueue(){};
};

//insert item
template<typename T>
bool linkQueue<T>::inlinkQueue(T item){
	if(rear==NULL){
		front=rear=new Queue<T>(item,NULL);
	}
	else{
		rear->next=new Queue<T>(item,NULL);
		rear=rear->next;
	}
	size++;
	return true;
}

//delete item
template<typename T>
bool linkQueue<T>::delinkQueue(T &item){
	if(size==0){
		std::cout<<"The linkQueue is empty: ";
		return false;
	}
	Queue<T> *temp;
	item=front->data;
	temp=front;
	front=front->next;
	delete temp;
	if(front==NULL){
		rear=NULL;
	}
	size--;
	return true;
}
//Get head element
template<typename T>
bool linkQueue<T>::getFront(T &item){
	if(size==0){
		std::cout<<"The linkQueue is empty: ";
		return false;
	}
	item=front->data;
	return true;
}

//isEmpty
template<typename T>
bool linkQueue<T>::isEmpty(){
	if(size==0){
		return true;
	}
	return false;

}
#endif