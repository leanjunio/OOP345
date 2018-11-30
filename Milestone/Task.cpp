#include "Task.h"

// Receive a single record (one line) from the input file for Item instantiation
// Set m_pNextTask to empty state
// 
Task::Task(const std::string& record)
    : Item(record),
      m_pNextTask(nullptr)
{
}

// Runs a single cycle of the assembly line for the current task
// If there are CustomerOrders in the queue, it will verify the status of the last CustomerOrder and fill it
// if the order contains the Item specified by the current Task
// 
void Task::runProcess(std::ostream& os)
{
    if (!m_orders.empty())
        if (m_orders.back().getItemFillState(Item::getName()) == false) // if the CustomerOrder at the back is not yet filled...
            m_orders.back().fillItem(*this, os);                        // fill the item with current task
}

// Moves the last CustomerOrder in the queue to the next task on the assembly line if the orders fill state for the current Item is true
// 
bool Task::moveTask()
{
    if (m_orders.empty())
        return false;

    if (m_orders.back().getItemFillState(Item::getName()) == true)  // If the fill state for current is True...
    {
        *m_pNextTask += std::move(m_orders.back());      // Move the last CustomerOrder from the current m_orders object to the nextTask
        m_orders.pop_back();                                    // remove the moved CustomerOrder from the current m_orders
    }
}   

// Store the provided task's reference into the m_pNextTask pointer
// 
void Task::setNextTask(Task& task)
{
    m_pNextTask = &task;
}

// Removes the last CustomerOrder from the queue, places it in the parameter and returns true
// If the queue is empty, return false
// 
bool Task::getCompleted(CustomerOrder& co)
{
    if (m_orders.empty())
        return false;
    else
    {
        co = std::move(m_orders.back());
        return true;
    }
}

// Writes the name of the Item the current Task is responsible for into the parameter
// 
void Task::validate(std::ostream& os)
{
    os << Item::getName() << " --> ";
    if (m_pNextTask != nullptr) 
        os << m_pNextTask->getName();
    os << std::endl;
}
// Moves the parameter onto the front of the CustomerOrder queue
// 
Task& Task::operator+=(CustomerOrder&& co)
{
    m_orders.push_front(co);
    return *this;
}