/*******************************************************************
 * Copyright (C) Jerry Jiang
 *               
 * File Name   : iter_swap02.cpp
 * Author      : Jerry Jiang
 * Create Time : 2012-3-26 23:58:29
 * Mail        : jbiaojerry@gmail.com
 * Blog        : http://blog.csdn.net/jerryjbiao 
 *               
 * Description : 简单的程序诠释C++ STL算法系列之十六                   
 *               变易算法 : 迭代器交换iter_swap
 *
 ******************************************************************/
 
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
#include <ostream>
#include <iterator>
 
using namespace std;
 
int main( )
{
   deque<int> deq1;
   deque<int>::iterator d1_Iter;
   ostream_iterator<int> otpt(cout," ");
 
   deq1.push_back ( 2 );
   deq1.push_back ( 4 );
   deq1.push_back ( 9 );
 
   //通过copy输出队列初始序列
   cout << "The deque is:\n";
   copy(deq1.begin(), deq1.end(), otpt);
 
   //通过iter_swap算法交换队列中第一个和最后一个元素
   iter_swap(deq1.begin() , --deq1.end());
 
   //输出通过iter_swap交换后的队列
   cout << "\n\nThe deque of CInts with first & last elements swapped is:\n ";
   copy(deq1.begin(), deq1.end(), otpt);
 
   //通过swap交换算法还原队列中的元素
   swap (*deq1.begin(), *(deq1.end()-1));
 
   cout << "\n\nThe deque of CInts with first & last elements swapped back is:\n ";
   copy(deq1.begin(), deq1.end(), otpt);
   cout << endl;
   
   cout << "*********************************" << endl;
 
 
   // 通过iter_swap交换vector和deque两个不同容器中的元素
   vector <int> v1;
   deque <int> deq2;
 
   //初始化容器v1
   for ( size_t i = 0 ; i <= 3 ; ++i )
   {
      v1.push_back( i );
   }
 
   //初始化队列deq2
   for ( size_t ii = 4 ; ii <= 5 ; ++ii )
   {
      deq2.push_back( ii );
   }
 
   cout << "\nVector v1 is : " ;
   copy(v1.begin(), v1.end(), otpt);
   
   cout << "\nDeque deq2 is : " ;
   copy(deq2.begin(), deq2.end(), otpt);
   cout << endl;
   
   //交换容器v1和队列deq2的第一个元素
   //iter_swap( v1.begin(), deq2.begin() );
   swap(v1.front(),deq2.front());
   cout << "\n\nAfter exchanging first elements,\n vector v1 is:  " ;
   copy(v1.begin(), v1.end(), otpt);
 
   cout << " \n deque deq2 is: ";
   copy(deq2.begin(), deq2.end(), otpt);
 
   cout << endl;
 
   system("pause");
   return 0;
}
