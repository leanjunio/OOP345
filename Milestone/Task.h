// Task.h
// A Task object manages a single Item on the assembly line
// Task inherits from class Item and contains the following additional information:
// 
// m_orders – is a double ended queue with new CustomerOrders coming in one side and exiting out the other once filled.
// m_pNextTask – a pointer to the next task on the assembly line

#ifndef _TASK_H
#define _TASK_H

#include <deque>
#include "CustomerOrder.h"
#include "Item.h"

class Task : public Item
{
    std::deque<CustomerOrder> m_orders;
    
};
#endif // ! _TASK_H