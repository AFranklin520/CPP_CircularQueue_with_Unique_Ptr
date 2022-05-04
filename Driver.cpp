//Anthony Franklin afranklin18@cnm.edu
//PROGRAM TO DEMONSTRATE CIRCULAR QUEUE USING UNIQUE_PTR
//04/17/2022
//Driver.cpp

#include "CirQueue.h"
#include "ScriptReader.h"

int main()
{

	Date today;
	cout << today.GetFormattedDate() << "\nAnthony Franklin afranklin18@cnm.edu\nFranklinP8\n";
	cout << "***** PROGRAM TO DEMONSTRATE CIRCULAR QUEUE USING UNIQUE_PTR *****\n\n";
	PersonGen* pg = new PersonGen;
	if (pg->UseFile("P8_Persons.txt"))
	{
		//Uncomment this to use a script

		/*string filename;
		cout << "Please enter the filename of the script to read from: " << endl;
		cin >> filename;
		cin.ignore();
		ScriptReader sr1(filename);*/

		CirQueue cirQ;
		//Display menu of CirQ functions
		string menu = "\n1. Print Queue State\n2. Add to Queue\n3. Print First Person\n4. Print Last Person\n5. Serve First in Queue\n6. Print Size of Queue";
		menu += "\n7. Quit Program\n";
		cout << menu;
		//Use switch or if/else if/ else to handle choices
		
		//Uncomment this to use a script
		//int scriptInput{ 1 };
		int userInput{0};
		while (userInput > 0 && userInput < 7) //while (scriptInput > 0 && scriptInput < 7)
		{
			cin >> userInput;
			cin.ignore();
			
			//Uncomment this to use a script
			//scriptInput = sr1.GetNextInt();
			unique_ptr<Person> p;
			switch (userInput) //switch (scriptInput)
			{
			case 1:
				cirQ.Show();
				cout << cirQ.ShowString();
				continue;
			case 2:
				p = make_unique<Person>(*pg->GetNewPerson());
				if (p)
				{
					cout << "Attempting to add " << p->GetName() << "\n";
					if (cirQ.Push(move(p)))
					{
						continue;
					}
					cout << "[ERROR] Unable to add new person to Queue!\n";
					continue;
				}
				else cout << "[ERROR] Unable to create new person!\n";
				continue;

			case 3:
				cout << "First in queue is " << cirQ.Front() << "\n";
				continue;
			case 4:
				cout << "Last in queue is " << cirQ.Rear() << "\n";
				continue;
			case 5:
				if (cirQ.Pop())
				{
					continue;
				}
				cout << "[ERROR] Unable to remove first person in Queue!\n";
				continue;
			case 6:
				cout << "The size of the queue is " << to_string(cirQ.Size()) << "\n";
				continue;
			case 7:
				cout << "Exiting the program now\n";
				break;
			}
		}
	}
	delete pg;
	cout << "\n\n***** Thank you for using my program, goodbye! *****\n\n";
	return 0;
}