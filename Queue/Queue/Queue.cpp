#include <iostream>
#include "Queue.h"
#define  maxSize 100

void main()
{
	//*****************//
	//arrQueue
	//*****************//
	int N;
	std::cout<<"Please input the number(N<="<<maxSize<<")"<<"of elements:";
	std::cin>>N;
	arrQueue<int> qu(maxSize);
	for (int i=0;i<N;i++){
		int element;
		std::cin>>element;
		qu.insertQueue(element);
	}
	int item=0;
	qu.insertQueue(item);
	qu.getFront(item);
	std::cout<<item;
	qu.deQueue(item);
	qu.getFront(item);
	std::cout<<item;



	//****************//
	//linkQueue
	//****************//
	linkQueue<int> lqu;
	if(lqu.isEmpty()){
		std::cout<<"Empty"<<std::endl;
	};
	int M;
	std::cout<<"Please input the number(M) of elements:";
	std::cin>>M;
	for(int i=0;i<M;i++){
		int data;
		std::cin>>data;
		lqu.inlinkQueue(data);
	}
	int item;
	lqu.delinkQueue(item);
	lqu.getFront(item);
	std::cout<<item;
	
	system("pause");



}