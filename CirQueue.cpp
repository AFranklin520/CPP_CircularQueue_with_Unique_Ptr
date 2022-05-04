//Anthony Franklin afranklin18@cnm.edu
//PROGRAM TO DEMONSTRATE CIRCULAR QUEUE USING UNIQUE_PTR
//04/17/2022
//CirQueue.cpp

#include "CirQueue.h"

CirQueue::CirQueue()
{
    //Open logger, write 
    logger.open("FranklinP8_Script2_log.txt");
    if (logger.is_open())
    {
        cout << "CircularQ_log.txt has been successfully created!";
        Date today;
        logger << today.GetFormattedDate() << "\nAnthony Franklin afranklin18@cnm.edu\nFranklinP8\n";
        logger << "***** PROGRAM TO DEMONSTRATE CIRCULAR QUEUE USING UNIQUE_PTR *****\n\n";
    }
    else cout << "[ERROR] Unable to create log file!";

}

bool CirQueue::Empty()
{
    return !(count > 0);
}

bool CirQueue::Full()
{
    return !(count < SIZE);
}

void CirQueue::Show()
{
    //check if empty and report in logger if so
    //Else print how many in queue and list names several to line in logger
    if (Empty()) logger << "The queue is empty.\n";
    else
    {
        logger << "There are " << count << " Persons in the queue: \n";
        int pCount{ 0 };
        for (const auto& p : pArray)
        {
            if (pCount == 4)
            {
                logger << "\n";
                pCount = 0;
            }
            if(p) logger << p->GetName() << "        ";
            pCount++;
        }
        logger << "\n";
    }
}

string CirQueue::ShowString()
{
    //check if empty and report in cout if so
    //Else print how many in queue and list names several to line in cout
    if(Empty()) return "The queue is empty.\n";
    else
    {
        string temp;
        temp.append("There are " + to_string(count) + " Persons in the queue: \n");
        int pCount{ 0 };
        for (const auto& p : pArray)
        {
            if (pCount == 4)
            {
                temp.append("\n");
                pCount = 0;
            }
            if(p) temp.append(p->GetName() + "        ");
            pCount++;
        }
        temp.append("\n");
        return temp;
    }
}

bool CirQueue::Push(unique_ptr<Person> p)
{
    //If full return false; don't push
    if (Full()) return false;
    //Else if empty first and last = p
    else if (Empty())
    {
        logger << "Adding " << p->GetName() << "\n";
        cout << "Adding " << p->GetName() << "\n";
        pArray[last] = move(p);
        first = last;
        count++;
        return true;
    }
    //Else add to end of queue with move
    //wrap to front if necessary
    last++;
    if (!(last < SIZE)) last = 0;
    logger << "Adding " << p->GetName() << "\n";
    cout << "Adding " << p->GetName() << "\n";
    pArray[last] = move(p);
    count++;
    return true;
}

bool CirQueue::Pop()
{
    //If empty return false
    if (Empty()) return false;
    //Otherwise return first and log GetName()
    if (!(first < SIZE)) first = 0;
    if (pArray[first])
    {
        logger << "Removing the first person in the queue: " << pArray[first]->GetName() << "\n";
        cout << "Removing the first person in the queue: " << pArray[first]->GetName() << "\n";
        pArray[first].reset();
        count--;
        first++;
        return true;
    }
    return false;
}

string CirQueue::Front()
{
    //If empty return "Queue is empty" or so
    if (Empty())
    {
        logger << "The queue is empty.\n";
        return "The queue is empty.\n";
    }
    //Else return first->GetName()
    else if (pArray[first])
    {
        logger <<"First in queue is " << pArray[first]->GetName() << "\n";
        return pArray[first]->GetName();
    }
}

string CirQueue::Rear()
{
    //If empty return "Queue is empty" or so
    if (Empty())
    {
        logger << "The queue is empty.\n";
        return "The queue is empty.\n";
    }
    //Else return last->GetName()
    else if(pArray[last])
    {
        logger << "Last in queue is " << pArray[last]->GetName() << "\n";
        return pArray[last]->GetName();
    }
}

int CirQueue::Size()
{
    //return size for cout/log
    logger << "The size of the queue is " << to_string(count) << "\n";
    return count;
}
